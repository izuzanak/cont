
@begin
include "xml_browse.h"
@end

/*
 * methods of generated structures
 */

// -- br_attribute_s --
@begin
   methods br_attribute_s
@end

// -- br_element_s --
@begin
   methods br_element_s
@end

unsigned br_element_s::__attr_by_name(unsigned a_name_idx)
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  ui_array_s &attribute_idxs = xml.elements[element_idx].attribute_idxs;
  attribute_array_s &attributes = xml.attributes;

  if (attribute_idxs.used != 0)
  {
    unsigned *ai_ptr = attribute_idxs.data;
    unsigned *ai_ptr_end = ai_ptr + attribute_idxs.used;
    do {
      if (attributes[*ai_ptr].name_idx == a_name_idx)
      {
        return *ai_ptr;
      }
    } while(++ai_ptr < ai_ptr_end);
  }

  return c_idx_not_exist;
}/*}}}*/

