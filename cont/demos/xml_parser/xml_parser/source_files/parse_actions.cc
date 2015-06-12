
@begin
include "xml_parser.h"
@end

/*
 * constants and definitions
 */

const unsigned max_number_string_length = 12;

// - callers of declaration parse action functions -
const unsigned c_decl_parse_action_cnt = 9;
bool(*xml_pa_decl_callers[c_decl_parse_action_cnt])(xml_parser_s &_this) =
{/*{{{*/
  pa_null,
  pa_null,
  pa_null,
  pa_null,
  pa_decl_version,
  pa_decl_encoding,
  pa_decl_standalone,
  pa_string,
  pa_string,
};/*}}}*/

// - callers of parse action functions -
const unsigned c_parse_action_cnt = 16;
bool(*xml_pa_callers[c_parse_action_cnt])(xml_parser_s &_this) =
{/*{{{*/
  pa_null,
  pa_null,
  pa_null,
  pa_null,
  pa_null,
  pa_null,
  pa_close,
  pa_data,
  pa_open,
  pa_null,
  pa_self_close,
  pa_data,
  pa_attribute,
  pa_identifier,
  pa_string,
  pa_string,
};/*}}}*/

/*
 * functions implementing parse actions of parser
 */

bool pa_null(xml_parser_s &_this)
{/*{{{*/
  cassert(0);

  return true;
}/*}}}*/

bool pa_close(xml_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  string_rb_tree_s &name_tree = _this.name_tree;
  element_array_s &elements = _this.elements;
  ui_array_s &element_stack = _this.element_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = (lse.terminal_end - lse.terminal_start) - 1;
  char *name_data = source_string.data + lse.terminal_start + 1;

  // - process tag name string -
  unsigned name_idx = name_tree.get_idx_char_ptr_insert(name_length,name_data);

  // - remove element from element stack -
  unsigned element_idx = element_stack.pop();

  // - ERROR -
  if (name_idx != elements[element_idx].name_idx)
  {
    cassert(0);
  }

  return true;
}/*}}}*/

bool pa_data(xml_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  ref_parser_s &ref_parser = _this.ref_parser;
  string_s &ref_string = _this.ref_string;
  string_array_s &data_array = _this.data_array;
  element_array_s &elements = _this.elements;
  ui_array_s &element_stack = _this.element_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned data_length = (lse.terminal_end - lse.terminal_start) - 2;
  char *data_data = source_string.data + lse.terminal_start + 1;

  unsigned data_idx;

  // - process references -
  switch (ref_parser.process_references(data_length,data_data,ref_string))
  {
  case c_ref_return_modified:
    {
      data_idx = data_array.used;

      // - process modified string -
      data_array.push_blank();
      data_array.last().swap(ref_string);
    }
    break;
  case c_ref_return_original:
    {
      data_idx = data_array.used;

      // - process original string -
      data_array.push_blank();
      data_array.last().set(data_length,data_data);
    }
    break;
  case c_ref_return_error:
  default:
    return false;
  }

  // - insert data to element -
  if (element_stack.used != 0)
  {
    element_s &parent_element = elements[element_stack.last()];

    parent_element.data_idxs.push(data_idx);
    parent_element.cont_types.push(c_cont_type_data);
  }

  return true;
}/*}}}*/

bool pa_open(xml_parser_s &_this)
{/*{{{*/
  element_array_s &elements = _this.elements;
  unsigned &identifier_idx = _this.identifier_idx;
  ui_array_s &element_stack = _this.element_stack;

  // *****

  // - create new element -
  elements.push_blank();
  unsigned element_idx = elements.used - 1;
  element_s &element = elements.last();

  // - set element properties -
  element.name_idx = identifier_idx;
  element.next_idx = c_idx_not_exist;

  // - if parent element exists -
  if (element_stack.used != 0)
  {
    unsigned parent_idx = element_stack.last();
    element_s &parent_element = elements[parent_idx];

    // - set element parent -
    element.parent_idx = parent_idx;

    // - if there are any elements in parent -
    if (parent_element.element_idxs.used != 0)
    {
      unsigned prev_idx = parent_element.element_idxs.last();

      elements[prev_idx].next_idx = element_idx;
      element.prev_idx = prev_idx;
    }
    else
    {
      element.prev_idx = c_idx_not_exist;
    }

    // - insert element to parent indexes -
    parent_element.element_idxs.push(element_idx);
    parent_element.cont_types.push(c_cont_type_element);
  }
  else
  {
    // - ERROR -
    cassert(elements.used == 1);

    element.parent_idx = c_idx_not_exist;
    element.prev_idx = c_idx_not_exist;
  }

  // - push element to element stack -
  element_stack.push(element_idx);

  return true;
}/*}}}*/

bool pa_self_close(xml_parser_s &_this)
{/*{{{*/
  ui_array_s &element_stack = _this.element_stack;

  // *****

  // - remove element from element stack -
  element_stack.pop();

  return true;
}/*}}}*/

bool pa_attribute(xml_parser_s &_this)
{/*{{{*/
  attribute_array_s &attributes = _this.attributes;
  element_array_s &elements = _this.elements;
  unsigned &identifier_idx = _this.identifier_idx;
  unsigned &string_idx = _this.string_idx;
  ui_array_s &element_stack = _this.element_stack;

  // *****

  // - create new attribute -
  attributes.push_blank();
  unsigned attribute_idx = attributes.used - 1;
  attribute_s &attribute = attributes.last();

  // - parent element index -
  unsigned parent_idx = element_stack.last();
  element_s &parent_element = elements[parent_idx];

  // - set attribute properties -
  attribute.name_idx = identifier_idx;
  attribute.value_idx = string_idx;
  attribute.parent_idx = parent_idx;
  attribute.next_idx = c_idx_not_exist;

  // - if there are any attributes in parent -
  if (parent_element.attribute_idxs.used != 0)
  {
    unsigned prev_idx = parent_element.attribute_idxs.last();

    attributes[prev_idx].next_idx = attribute_idx;
    attribute.prev_idx = prev_idx;
  }
  else
  {
    attribute.prev_idx = c_idx_not_exist;
  }

  // - insert attribute to element -
  parent_element.attribute_idxs.push(attribute_idx);

  return true;
}/*}}}*/

bool pa_identifier(xml_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  string_rb_tree_s &name_tree = _this.name_tree;
  unsigned &identifier_idx = _this.identifier_idx;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = (lse.terminal_end - lse.terminal_start);
  char *name_data = source_string.data + lse.terminal_start;

  // - process identifier string -
  identifier_idx = name_tree.get_idx_char_ptr_insert(name_length,name_data);

  return true;
}/*}}}*/

bool pa_string(xml_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  ref_parser_s &ref_parser = _this.ref_parser;
  string_s &ref_string = _this.ref_string;
  string_array_s &data_array = _this.data_array;
  unsigned &string_idx = _this.string_idx;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned string_length = (lse.terminal_end - lse.terminal_start) - 2;
  char *string_data = source_string.data + lse.terminal_start + 1;

  // - process references -
  switch (ref_parser.process_references(string_length,string_data,ref_string))
  {
  case c_ref_return_modified:
    {
      string_idx = data_array.used;

      // - process modified string -
      data_array.push_blank();
      data_array.last().swap(ref_string);
    }
    break;
  case c_ref_return_original:
    {
      string_idx = data_array.used;

      // - process original string -
      data_array.push_blank();
      data_array.last().set(string_length,string_data);
    }
    break;
  case c_ref_return_error:
  default:
    return false;
  }

  return true;
}/*}}}*/

bool pa_decl_version(xml_parser_s &_this)
{/*{{{*/
  unsigned &version_idx = _this.version_idx;
  unsigned &string_idx = _this.string_idx;

  // *****

  version_idx = string_idx;

  return true;
}/*}}}*/

bool pa_decl_encoding(xml_parser_s &_this)
{/*{{{*/
  unsigned &encoding_idx = _this.encoding_idx;
  unsigned &string_idx = _this.string_idx;

  // *****

  encoding_idx = string_idx;

  return true;
}/*}}}*/

bool pa_decl_standalone(xml_parser_s &_this)
{/*{{{*/
  unsigned &standalone_idx = _this.standalone_idx;
  unsigned &string_idx = _this.string_idx;

  // *****

  standalone_idx = string_idx;

  return true;
}/*}}}*/

