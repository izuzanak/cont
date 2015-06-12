
#ifndef __XML_PARSER_H
#define __XML_PARSER_H

@begin
include "struct.h"
@end

/*
 * declaration parse constants
 */

const unsigned c_decl_rule_cnt = 9;
const unsigned decl_rule_head_idxs[c_decl_rule_cnt] = {9, 10, 11, 11, 12, 12, 12, 13, 13, };
const unsigned decl_rule_body_lengths[c_decl_rule_cnt] = {1, 2, 2, 1, 3, 3, 3, 1, 1, };

/*
 * declaration LALR parse table
 */

#define decl_blank c_idx_not_exist
#define DECL_SHIFT(VALUE) VALUE
#define DECL_REDUCE(VALUE) c_decl_lalr_table_reduce_base + VALUE
#define DECL_GOTO(VALUE) VALUE

const unsigned c_decl_lalr_table_reduce_base = 0x80000000;
const unsigned c_decl_terminal_plus_nonterminal_cnt = 14;
const unsigned decl_lalr_state_cnt = 17;

const unsigned decl_lalr_table[decl_lalr_state_cnt*c_decl_terminal_plus_nonterminal_cnt] = {
       decl_blank,       decl_blank,       decl_blank,    DECL_SHIFT(3),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,     DECL_GOTO(1),     DECL_GOTO(2),       decl_blank,       decl_blank,
       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
       decl_blank,       decl_blank,    DECL_SHIFT(4),       decl_blank,    DECL_SHIFT(6),    DECL_SHIFT(7),    DECL_SHIFT(8),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,     DECL_GOTO(5),       decl_blank,
       decl_blank,       decl_blank,   DECL_REDUCE(3),       decl_blank,   DECL_REDUCE(3),   DECL_REDUCE(3),   DECL_REDUCE(3),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
       decl_blank,       decl_blank,   DECL_REDUCE(2),       decl_blank,   DECL_REDUCE(2),   DECL_REDUCE(2),   DECL_REDUCE(2),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,    DECL_SHIFT(9),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,   DECL_SHIFT(10),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,   DECL_SHIFT(11),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
   DECL_SHIFT(13),   DECL_SHIFT(14),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,    DECL_GOTO(12),
   DECL_SHIFT(13),   DECL_SHIFT(14),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,    DECL_GOTO(15),
   DECL_SHIFT(13),   DECL_SHIFT(14),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,    DECL_GOTO(16),
       decl_blank,       decl_blank,   DECL_REDUCE(4),       decl_blank,   DECL_REDUCE(4),   DECL_REDUCE(4),   DECL_REDUCE(4),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
       decl_blank,       decl_blank,   DECL_REDUCE(7),       decl_blank,   DECL_REDUCE(7),   DECL_REDUCE(7),   DECL_REDUCE(7),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
       decl_blank,       decl_blank,   DECL_REDUCE(8),       decl_blank,   DECL_REDUCE(8),   DECL_REDUCE(8),   DECL_REDUCE(8),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
       decl_blank,       decl_blank,   DECL_REDUCE(5),       decl_blank,   DECL_REDUCE(5),   DECL_REDUCE(5),   DECL_REDUCE(5),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
       decl_blank,       decl_blank,   DECL_REDUCE(6),       decl_blank,   DECL_REDUCE(6),   DECL_REDUCE(6),   DECL_REDUCE(6),       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,       decl_blank,
};

/*
 * parse constants
 */

const unsigned c_rule_cnt = 16;
const unsigned rule_head_idxs[c_rule_cnt] = {10, 11, 11, 12, 12, 13, 13, 13, 16, 14, 14, 14, 15, 17, 18, 18, };
const unsigned rule_body_lengths[c_rule_cnt] = {1, 2, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 3, 1, 1, 1, };

/*
 * LALR parse table
 */

#define blank c_idx_not_exist
#define SHIFT(VALUE) VALUE
#define REDUCE(VALUE) c_lalr_table_reduce_base + VALUE
#define GOTO(VALUE) VALUE

const unsigned c_lalr_table_reduce_base = 0x80000000;
const unsigned c_terminal_plus_nonterminal_cnt = 19;
const unsigned lalr_state_cnt = 22;

const unsigned lalr_table[lalr_state_cnt*c_terminal_plus_nonterminal_cnt] = {
       blank,       blank,    SHIFT(9),       blank,    SHIFT(6),    SHIFT(7),       blank,       blank,       blank,    SHIFT(3),       blank,     GOTO(1),     GOTO(2),     GOTO(4),       blank,       blank,     GOTO(5),     GOTO(8),       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,    SHIFT(9),       blank,    SHIFT(6),    SHIFT(7),       blank,       blank,       blank,   SHIFT(10),       blank,       blank,       blank,    GOTO(11),       blank,       blank,     GOTO(5),     GOTO(8),       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,   REDUCE(4),       blank,   REDUCE(4),   REDUCE(4),       blank,       blank,       blank,   REDUCE(4),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,    SHIFT(9),   SHIFT(14),       blank,   SHIFT(15),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(12),    GOTO(13),       blank,    GOTO(16),       blank,
       blank,       blank,   REDUCE(6),       blank,   REDUCE(6),   REDUCE(6),       blank,       blank,       blank,   REDUCE(6),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,   REDUCE(7),       blank,   REDUCE(7),   REDUCE(7),       blank,       blank,       blank,   REDUCE(7),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,   REDUCE(8),   REDUCE(8),       blank,   REDUCE(8),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,  REDUCE(13),  REDUCE(13),       blank,  REDUCE(13),  REDUCE(13),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,   REDUCE(3),       blank,   REDUCE(3),   REDUCE(3),       blank,       blank,       blank,   REDUCE(3),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,   REDUCE(5),       blank,   REDUCE(5),   REDUCE(5),       blank,       blank,       blank,   REDUCE(5),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,    SHIFT(9),   SHIFT(14),       blank,   SHIFT(15),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(17),    GOTO(13),       blank,    GOTO(16),       blank,
       blank,       blank,  REDUCE(10),       blank,  REDUCE(10),  REDUCE(10),       blank,       blank,       blank,  REDUCE(10),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,  REDUCE(11),       blank,  REDUCE(11),  REDUCE(11),       blank,       blank,       blank,  REDUCE(11),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(18),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,   REDUCE(9),       blank,   REDUCE(9),   REDUCE(9),       blank,       blank,       blank,   REDUCE(9),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
   SHIFT(20),   SHIFT(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(19),
       blank,       blank,  REDUCE(12),  REDUCE(12),       blank,  REDUCE(12),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,  REDUCE(14),  REDUCE(14),       blank,  REDUCE(14),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,  REDUCE(15),  REDUCE(15),       blank,  REDUCE(15),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
};

// - element content types -
enum
{
  c_cont_type_element = 0,
  c_cont_type_data,
};

// - reference terminal ids -
enum
{
  c_ref_term_text = 0,
  c_ref_term_any_ref,

  c_ref_term_lt,
  c_ref_term_gt,
  c_ref_term_amp,
  c_ref_term_apos,
  c_ref_term_quot,

  c_ref_term_end,
};

// - reference process return value -
enum
{
  c_ref_return_modified = 0,
  c_ref_return_original,
  c_ref_return_error,
};

// - forward declaration of parser -
typedef class xml_parser_s xml_parser_s;

/*
 * definition of generated structures
 */

// -- attribute_s --
@begin
   struct
   <
   unsigned:name_idx
   unsigned:value_idx

   unsigned:parent_idx
   unsigned:prev_idx
   unsigned:next_idx
   >
   attribute_s;
@end

// -- attribute_array_s --
@begin
   array<attribute_s> attribute_array_s;
@end

// -- element_s --
@begin
   struct
   <
   unsigned:name_idx

   ui_array_s:attribute_idxs
   ui_array_s:element_idxs
   ui_array_s:data_idxs
   bc_array_s:cont_types

   unsigned:parent_idx
   unsigned:prev_idx
   unsigned:next_idx
   >
   element_s;
@end

// -- element_array_s --
@begin
   array<element_s> element_array_s;
@end

// -- ref_parser_s --
@begin
   struct
   <
   pointer:xml_parser_ptr

   bc_pointer:src_data
   unsigned:src_length

   string_rb_tree_s:reference_tree
   string_array_s:reference_values
   >

   additions
{
  inline void create_reference(unsigned a_ref_length,const char *a_ref_data,unsigned a_val_length,const char *a_val_data);
  unsigned recognize_terminal(unsigned &input_idx);
  unsigned process_references(unsigned a_length,const char *a_data,string_s &a_string);
}

   ref_parser_s;
@end

// -- xml_parser_s --
@begin
   struct
   <
   $// - parse, source string -
   string_s:source_string

   ref_parser_s:ref_parser
   string_s:ref_string

   $// - xml declaration strings -
   unsigned:version_idx
   unsigned:encoding_idx
   unsigned:standalone_idx

   string_rb_tree_s:name_tree
   string_array_s:data_array
   attribute_array_s:attributes
   element_array_s:elements

   $// - error records -
   ui_array_s:error_code

   $// - temporary indexes -
   unsigned:identifier_idx
   unsigned:string_idx

   ui_array_s:element_stack

   $// - parse, index of lexical analyzer -
   unsigned:input_idx
   unsigned:old_input_idx

   $// - parse, LALR stack -
   lalr_stack_s:lalr_stack
   >

   additions
{
  unsigned decl_recognize_terminal();
  unsigned recognize_terminal();
  bool decl_parse_source();
  bool parse_source();
  bool parse_memory(unsigned a_length,const char *a_data);
  void process_errors();
}

   xml_parser_s;
@end

/*
 * definitions of global functions
 */

// - script_parser global functions -

/*!
 * \brief print line of input source string, on which was error detected, and mark error position on it
 * \param source_string - reference to input source string
 * \param begin - position of error begin
 */
void print_error_show_line(string_s &source_string,unsigned begin);

/*!
 * \brief print input source string line, on which is char positioned
 * \param source_string - reference to input source string
 * \param char_pos - position of character in source input string
 */
void print_error_line(string_s &source_string,unsigned char_pos);

/*
 * inline methods of generated structures
 */

// -- attribute_s --
@begin
   inlines attribute_s
@end

// -- attribute_array_s --
@begin
   inlines attribute_array_s
@end

// -- element_array_s --
@begin
   inlines element_array_s
@end

// -- element_s --
@begin
   inlines element_s
@end

// -- ref_parser_s --
@begin
   inlines ref_parser_s
@end

inline void ref_parser_s::create_reference(unsigned a_ref_length,const char *a_ref_data,unsigned a_val_length,const char *a_val_data)
{/*{{{*/
  unsigned ref_idx = reference_tree.get_idx_char_ptr_insert(a_ref_length,a_ref_data);

  while (reference_values.used <= ref_idx)
  {
    reference_values.push_blank();
  }

  reference_values[ref_idx].set(a_val_length,a_val_data);
}/*}}}*/

// -- xml_parser_s --
@begin
   inlines xml_parser_s
@end

@begin
include "parse_actions.h"
@end

#endif

