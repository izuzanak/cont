
@begin
include "xml_parser.h"
@end

/*
 * methods of generated structures
 */

// -- attribute_s --
@begin
   methods attribute_s
@end

// -- attribute_array_s --
@begin
   methods attribute_array_s
@end

// -- element_array_s --
@begin
   methods element_array_s
@end

// -- element_s --
@begin
   methods element_s
@end

// -- ref_parser_s --
@begin
   methods ref_parser_s
@end

unsigned ref_parser_s::recognize_terminal(unsigned &input_idx)
{/*{{{*/
#define GET_NEXT_REF_CHAR() \
{\
   if (input_idx < src_length) {\
      in_char = (unsigned char)src_data[input_idx];\
   }\
   else {\
      in_char = '\0';\
   }\
}

#define CLOSE_REF_CHAR(RET_TERM_IDX) \
{\
   if (in_char == '\0') {\
      return RET_TERM_IDX;\
   }\
\
   input_idx++;\
}

   unsigned short in_char;

// - STATE 0 - 
   GET_NEXT_REF_CHAR();

   if (in_char == 0)
      goto state_1_label;

   if (in_char >= 1 && in_char < 38)
      goto state_3_label;

   if (in_char == 38)
      goto state_2_label;

   if (in_char >= 39 && in_char < 257)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 1 - 
state_1_label:
   CLOSE_REF_CHAR(7);
   GET_NEXT_REF_CHAR();

   if (in_char < 38)
      goto state_3_label;

   if (in_char >= 39 && in_char < 257)
      goto state_3_label;

   return 7;

// - STATE 2 - 
state_2_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char >= 60 && in_char < 97)
      goto state_8_label;

   if (in_char == 97)
      goto state_4_label;

   if (in_char >= 98 && in_char < 103)
      goto state_8_label;

   if (in_char == 103)
      goto state_5_label;

   if (in_char >= 104 && in_char < 108)
      goto state_8_label;

   if (in_char == 108)
      goto state_6_label;

   if (in_char >= 109 && in_char < 113)
      goto state_8_label;

   if (in_char == 113)
      goto state_7_label;

   if (in_char >= 114 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 3 - 
state_3_label:
   CLOSE_REF_CHAR(0);
   GET_NEXT_REF_CHAR();

   if (in_char < 38)
      goto state_3_label;

   if (in_char >= 39 && in_char < 257)
      goto state_3_label;

   return 0;

// - STATE 4 - 
state_4_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_9_label;

   if (in_char >= 60 && in_char < 109)
      goto state_8_label;

   if (in_char == 109)
      goto state_10_label;

   if (in_char >= 110 && in_char < 112)
      goto state_8_label;

   if (in_char == 112)
      goto state_11_label;

   if (in_char >= 113 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 5 - 
state_5_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_9_label;

   if (in_char >= 60 && in_char < 116)
      goto state_8_label;

   if (in_char == 116)
      goto state_12_label;

   if (in_char >= 117 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 6 - 
state_6_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_9_label;

   if (in_char >= 60 && in_char < 116)
      goto state_8_label;

   if (in_char == 116)
      goto state_13_label;

   if (in_char >= 117 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 7 - 
state_7_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_9_label;

   if (in_char >= 60 && in_char < 117)
      goto state_8_label;

   if (in_char == 117)
      goto state_14_label;

   if (in_char >= 118 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 8 - 
state_8_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_9_label;

   if (in_char >= 60 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 9 - 
state_9_label:
   CLOSE_REF_CHAR(1);
   return 1;

// - STATE 10 - 
state_10_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_9_label;

   if (in_char >= 60 && in_char < 112)
      goto state_8_label;

   if (in_char == 112)
      goto state_15_label;

   if (in_char >= 113 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 11 - 
state_11_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_9_label;

   if (in_char >= 60 && in_char < 111)
      goto state_8_label;

   if (in_char == 111)
      goto state_16_label;

   if (in_char >= 112 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 12 - 
state_12_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_17_label;

   if (in_char >= 60 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 13 - 
state_13_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_18_label;

   if (in_char >= 60 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 14 - 
state_14_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_9_label;

   if (in_char >= 60 && in_char < 111)
      goto state_8_label;

   if (in_char == 111)
      goto state_19_label;

   if (in_char >= 112 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 15 - 
state_15_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_20_label;

   if (in_char >= 60 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 16 - 
state_16_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_9_label;

   if (in_char >= 60 && in_char < 115)
      goto state_8_label;

   if (in_char == 115)
      goto state_21_label;

   if (in_char >= 116 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 17 - 
state_17_label:
   CLOSE_REF_CHAR(3);
   return 3;

// - STATE 18 - 
state_18_label:
   CLOSE_REF_CHAR(2);
   return 2;

// - STATE 19 - 
state_19_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_9_label;

   if (in_char >= 60 && in_char < 116)
      goto state_8_label;

   if (in_char == 116)
      goto state_22_label;

   if (in_char >= 117 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 20 - 
state_20_label:
   CLOSE_REF_CHAR(4);
   return 4;

// - STATE 21 - 
state_21_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_23_label;

   if (in_char >= 60 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 22 - 
state_22_label:
   CLOSE_REF_CHAR(c_idx_not_exist);
   GET_NEXT_REF_CHAR();

   if (in_char < 59)
      goto state_8_label;

   if (in_char == 59)
      goto state_24_label;

   if (in_char >= 60 && in_char < 257)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 23 - 
state_23_label:
   CLOSE_REF_CHAR(5);
   return 5;

// - STATE 24 - 
state_24_label:
   CLOSE_REF_CHAR(6);
   return 6;

}/*}}}*/

unsigned ref_parser_s::process_references(unsigned a_length,const char *a_data,string_s &a_string)
{/*{{{*/

  // - setup source string -
  src_data = (bc_pointer)a_data;
  src_length = a_length;

  // - create character buffer -
  bc_array_s buffer;
  buffer.init();

  unsigned text_idx = c_idx_not_exist;
  unsigned input_idx = 0;
  bool running = true;

#define PROCESS_REFERENCES_ERROR(ERROR) \
{/*{{{*/\
  xml_parser_s &xml_parser = *((xml_parser_s *)xml_parser_ptr);\
  string_array_s &data_array = xml_parser.data_array;\
  ui_array_s &error_code = xml_parser.error_code;\
\
  unsigned string_idx = data_array.used;\
  data_array.push_blank();\
  data_array.last().set(a_length,a_data);\
\
  error_code.push(ERROR);\
  error_code.push(a_data - xml_parser.source_string.data);\
  error_code.push(string_idx);\
  error_code.push(old_input_idx);\
}/*}}}*/

  do {
    unsigned old_input_idx = input_idx;
    unsigned ret_term = recognize_terminal(input_idx);

    // - PARSE ERROR unrecognized terminal -
    if (ret_term == c_idx_not_exist)
    {
      buffer.clear();

      PROCESS_REFERENCES_ERROR(c_error_XML_REFERENCE_UNRECOGNIZED_TERMINAL);
      return c_ref_return_error;
    }

    // - end of string -
    if (ret_term == c_ref_term_end)
    {
      if (text_idx != c_idx_not_exist && text_idx != 0)
      {
        // - append text to buffer -
        buffer.append(old_input_idx - text_idx,src_data + text_idx);
        text_idx = c_idx_not_exist;
      }

      running = false;
    }

    // - not end of string -
    else
    {
      if (text_idx != c_idx_not_exist)
      {
        // - append text to buffer -
        buffer.append(old_input_idx - text_idx,src_data + text_idx);
        text_idx = c_idx_not_exist;
      }

      switch (ret_term)
      {
        case c_ref_term_text:
          text_idx = old_input_idx;
          break;
        case c_ref_term_any_ref:
          {
            unsigned ref_length = (input_idx - old_input_idx) - 2;
            const char *ref_data = src_data + old_input_idx + 1;

            // - retrieve reference index -
            unsigned ref_idx = reference_tree.get_idx_char_ptr(ref_length,ref_data);

            // - ERROR -
            if (ref_idx == c_idx_not_exist)
            {
              buffer.clear();

              PROCESS_REFERENCES_ERROR(c_error_XML_UNDEFINED_REFERENCE);
              return c_ref_return_error;
            }

            // - append reference value to buffer -
            string_s &ref_value = reference_values[ref_idx];
            buffer.append(ref_value.size - 1,ref_value.data);
          }
          break;
        case c_ref_term_lt:
          buffer.push('<');
          break;
        case c_ref_term_gt:
          buffer.push('>');
          break;
        case c_ref_term_amp:
          buffer.push('&');
          break;
        case c_ref_term_apos:
          buffer.push('\'');
          break;
        case c_ref_term_quot:
          buffer.push('"');
          break;
      }
    }
  } while(running);

  // - buffer is not empty -
  if (buffer.used != 0)
  {
    // - append terminate character to buffer -
    buffer.push('\0');

    a_string.clear();
    a_string.data = buffer.data;
    a_string.size = buffer.used;

    return c_ref_return_modified;
  }
  else
  {
    buffer.clear();

    return c_ref_return_original;
  }
}/*}}}*/

// -- xml_parser_s --
@begin
   methods xml_parser_s
@end

#define GET_NEXT_CHAR() \
{\
  if (input_idx < source_string_length) {\
    in_char = (unsigned char)source_string[input_idx];\
  }\
  else {\
    in_char = '\0';\
  }\
}

#define CLOSE_CHAR(RET_TERM_IDX) \
{\
  if (in_char == '\0') {\
    return RET_TERM_IDX;\
  }\
  \
  input_idx++;\
}

unsigned xml_parser_s::decl_recognize_terminal()
{/*{{{*/
   unsigned source_string_length = source_string.size - 1;
   unsigned short in_char;

// - STATE 0 - 
   GET_NEXT_CHAR();

   if (in_char >= 8 && in_char < 14)
      goto state_9_label;

   if (in_char == 32)
      goto state_9_label;

   if (in_char == 34)
      goto state_1_label;

   if (in_char == 39)
      goto state_2_label;

   if (in_char == 60)
      goto state_3_label;

   if (in_char == 61)
      goto state_4_label;

   if (in_char == 63)
      goto state_5_label;

   if (in_char == 101)
      goto state_6_label;

   if (in_char == 115)
      goto state_7_label;

   if (in_char == 118)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 1 - 
state_1_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 34)
      goto state_1_label;

   if (in_char == 34)
      goto state_10_label;

   if (in_char >= 35 && in_char < 257)
      goto state_1_label;

   return c_idx_not_exist;

// - STATE 2 - 
state_2_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 39)
      goto state_2_label;

   if (in_char == 39)
      goto state_11_label;

   if (in_char >= 40 && in_char < 257)
      goto state_2_label;

   return c_idx_not_exist;

// - STATE 3 - 
state_3_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 63)
      goto state_12_label;

   return c_idx_not_exist;

// - STATE 4 - 
state_4_label:
   CLOSE_CHAR(7);
   return 7;

// - STATE 5 - 
state_5_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 62)
      goto state_13_label;

   return c_idx_not_exist;

// - STATE 6 - 
state_6_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 110)
      goto state_14_label;

   return c_idx_not_exist;

// - STATE 7 - 
state_7_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 116)
      goto state_15_label;

   return c_idx_not_exist;

// - STATE 8 - 
state_8_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101)
      goto state_16_label;

   return c_idx_not_exist;

// - STATE 9 - 
state_9_label:
   CLOSE_CHAR(8);
   GET_NEXT_CHAR();

   if (in_char >= 8 && in_char < 14)
      goto state_9_label;

   if (in_char == 32)
      goto state_9_label;

   return 8;

// - STATE 10 - 
state_10_label:
   CLOSE_CHAR(1);
   return 1;

// - STATE 11 - 
state_11_label:
   CLOSE_CHAR(0);
   return 0;

// - STATE 12 - 
state_12_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 120)
      goto state_17_label;

   return c_idx_not_exist;

// - STATE 13 - 
state_13_label:
   CLOSE_CHAR(2);
   return 2;

// - STATE 14 - 
state_14_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 99)
      goto state_18_label;

   return c_idx_not_exist;

// - STATE 15 - 
state_15_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 97)
      goto state_19_label;

   return c_idx_not_exist;

// - STATE 16 - 
state_16_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 114)
      goto state_20_label;

   return c_idx_not_exist;

// - STATE 17 - 
state_17_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 109)
      goto state_21_label;

   return c_idx_not_exist;

// - STATE 18 - 
state_18_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 111)
      goto state_22_label;

   return c_idx_not_exist;

// - STATE 19 - 
state_19_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 110)
      goto state_23_label;

   return c_idx_not_exist;

// - STATE 20 - 
state_20_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 115)
      goto state_24_label;

   return c_idx_not_exist;

// - STATE 21 - 
state_21_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 108)
      goto state_25_label;

   return c_idx_not_exist;

// - STATE 22 - 
state_22_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 100)
      goto state_26_label;

   return c_idx_not_exist;

// - STATE 23 - 
state_23_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 100)
      goto state_27_label;

   return c_idx_not_exist;

// - STATE 24 - 
state_24_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 105)
      goto state_28_label;

   return c_idx_not_exist;

// - STATE 25 - 
state_25_label:
   CLOSE_CHAR(3);
   return 3;

// - STATE 26 - 
state_26_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 105)
      goto state_29_label;

   return c_idx_not_exist;

// - STATE 27 - 
state_27_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 97)
      goto state_30_label;

   return c_idx_not_exist;

// - STATE 28 - 
state_28_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 111)
      goto state_31_label;

   return c_idx_not_exist;

// - STATE 29 - 
state_29_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 110)
      goto state_32_label;

   return c_idx_not_exist;

// - STATE 30 - 
state_30_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 108)
      goto state_33_label;

   return c_idx_not_exist;

// - STATE 31 - 
state_31_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 110)
      goto state_34_label;

   return c_idx_not_exist;

// - STATE 32 - 
state_32_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 103)
      goto state_35_label;

   return c_idx_not_exist;

// - STATE 33 - 
state_33_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 111)
      goto state_36_label;

   return c_idx_not_exist;

// - STATE 34 - 
state_34_label:
   CLOSE_CHAR(4);
   return 4;

// - STATE 35 - 
state_35_label:
   CLOSE_CHAR(5);
   return 5;

// - STATE 36 - 
state_36_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 110)
      goto state_37_label;

   return c_idx_not_exist;

// - STATE 37 - 
state_37_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101)
      goto state_38_label;

   return c_idx_not_exist;

// - STATE 38 - 
state_38_label:
   CLOSE_CHAR(6);
   return 6;

}/*}}}*/

unsigned xml_parser_s::recognize_terminal()
{/*{{{*/
   unsigned source_string_length = source_string.size - 1;
   unsigned short in_char;

// - STATE 0 - 
   GET_NEXT_CHAR();

   if (in_char == 0)
      goto state_1_label;

   if (in_char >= 8 && in_char < 14)
      goto state_9_label;

   if (in_char == 32)
      goto state_9_label;

   if (in_char == 33)
      goto state_2_label;

   if (in_char == 34)
      goto state_3_label;

   if (in_char == 39)
      goto state_4_label;

   if (in_char == 47)
      goto state_5_label;

   if (in_char == 61)
      goto state_6_label;

   if (in_char == 62)
      goto state_7_label;

   if (in_char >= 65 && in_char < 91)
      goto state_8_label;

   if (in_char == 95)
      goto state_8_label;

   if (in_char >= 97 && in_char < 123)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 1 - 
state_1_label:
   CLOSE_CHAR(9);
   return 9;

// - STATE 2 - 
state_2_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 45)
      goto state_10_label;

   return c_idx_not_exist;

// - STATE 3 - 
state_3_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 34)
      goto state_3_label;

   if (in_char == 34)
      goto state_11_label;

   if (in_char >= 35 && in_char < 257)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 4 - 
state_4_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 39)
      goto state_4_label;

   if (in_char == 39)
      goto state_12_label;

   if (in_char >= 40 && in_char < 257)
      goto state_4_label;

   return c_idx_not_exist;

// - STATE 5 - 
state_5_label:
   CLOSE_CHAR(3);
   GET_NEXT_CHAR();

   if (in_char >= 65 && in_char < 91)
      goto state_13_label;

   if (in_char == 95)
      goto state_13_label;

   if (in_char >= 97 && in_char < 123)
      goto state_13_label;

   return 3;

// - STATE 6 - 
state_6_label:
   CLOSE_CHAR(6);
   return 6;

// - STATE 7 - 
state_7_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 60)
      goto state_7_label;

   if (in_char == 60)
      goto state_14_label;

   if (in_char >= 61 && in_char < 257)
      goto state_7_label;

   return c_idx_not_exist;

// - STATE 8 - 
state_8_label:
   CLOSE_CHAR(2);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 59)
      goto state_8_label;

   if (in_char >= 65 && in_char < 91)
      goto state_8_label;

   if (in_char == 95)
      goto state_8_label;

   if (in_char >= 97 && in_char < 123)
      goto state_8_label;

   return 2;

// - STATE 9 - 
state_9_label:
   CLOSE_CHAR(7);
   GET_NEXT_CHAR();

   if (in_char >= 8 && in_char < 14)
      goto state_9_label;

   if (in_char == 32)
      goto state_9_label;

   return 7;

// - STATE 10 - 
state_10_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 45)
      goto state_15_label;

   return c_idx_not_exist;

// - STATE 11 - 
state_11_label:
   CLOSE_CHAR(1);
   return 1;

// - STATE 12 - 
state_12_label:
   CLOSE_CHAR(0);
   return 0;

// - STATE 13 - 
state_13_label:
   CLOSE_CHAR(4);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 59)
      goto state_13_label;

   if (in_char >= 65 && in_char < 91)
      goto state_13_label;

   if (in_char == 95)
      goto state_13_label;

   if (in_char >= 97 && in_char < 123)
      goto state_13_label;

   return 4;

// - STATE 14 - 
state_14_label:
   CLOSE_CHAR(5);
   return 5;

// - STATE 15 - 
state_15_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 45)
      goto state_15_label;

   if (in_char == 45)
      goto state_16_label;

   if (in_char >= 46 && in_char < 257)
      goto state_15_label;

   return c_idx_not_exist;

// - STATE 16 - 
state_16_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 45)
      goto state_15_label;

   if (in_char == 45)
      goto state_17_label;

   if (in_char >= 46 && in_char < 257)
      goto state_15_label;

   return c_idx_not_exist;

// - STATE 17 - 
state_17_label:
   CLOSE_CHAR(8);
   return 8;

}/*}}}*/

bool xml_parser_s::decl_parse_source()
{/*{{{*/

  // - reset lalr stack -
  lalr_stack.clear();
  lalr_stack.push(0);

  input_idx = 0;
  unsigned ret_term = c_idx_not_exist;

  do
  {

    // - retrieve next terminal symbol -
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;
      ret_term = decl_recognize_terminal();

      // - PARSE ERROR unrecognized terminal -
      if (ret_term == c_idx_not_exist)
      {
        error_code.push(c_error_XML_UNRECOGNIZED_TERMINAL);
        error_code.push(old_input_idx);

        return false;
      }

      // - skip terminals -
      if (ret_term == 8) {
         ret_term = c_idx_not_exist;
      }
    }

    // - retrieve of action from table of actions -
    unsigned parse_action = decl_lalr_table[lalr_stack.last().lalr_state*c_decl_terminal_plus_nonterminal_cnt + ret_term];

    // - PARSE ERROR wrong syntax -
    if (parse_action == c_idx_not_exist)
    {
      error_code.push(c_error_XML_SYNTAX_ERROR);
      error_code.push(old_input_idx);

      return false;
    }

    // - action SHIFT -
    if (parse_action < c_decl_lalr_table_reduce_base)
    {
      if (ret_term == 2)
      {
        break;
      }

      // - insertion of state, and terminal position in source string -
      lalr_stack.push(parse_action,old_input_idx,input_idx);
      ret_term = c_idx_not_exist;
    }

    // - action REDUCE-
    else
    {
      parse_action -= c_decl_lalr_table_reduce_base;

      // - call of assigned function to reduction -
      if (xml_pa_decl_callers[parse_action] != pa_null)
      {
        if (!xml_pa_decl_callers[parse_action](*this))
        {
          return false;
        }
      }

      // - remove of rule body from lalr_stack -
      lalr_stack.used -= decl_rule_body_lengths[parse_action];

      // - insert of new automat state to stack -
      unsigned goto_val = decl_lalr_table[lalr_stack.last().lalr_state*c_decl_terminal_plus_nonterminal_cnt + decl_rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(1);

  return true;
}/*}}}*/

bool xml_parser_s::parse_source()
{/*{{{*/

  // - reset lalr stack -
  lalr_stack.clear();
  lalr_stack.push(0);

  // - revert to last '>' character -
  input_idx -= 1;
  unsigned ret_term = c_idx_not_exist;

  do
  {

    // - retrieve next terminal symbol -
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;
      ret_term = recognize_terminal();

      // - PARSE ERROR unrecognized terminal -
      if (ret_term == c_idx_not_exist)
      {
        error_code.push(c_error_XML_UNRECOGNIZED_TERMINAL);
        error_code.push(old_input_idx);

        return false;
      }

      // - skip terminals -
      if (ret_term == 7 || ret_term == 8) {
         ret_term = c_idx_not_exist;
      }
    }

    // - retrieve of action from table of actions -
    unsigned parse_action = lalr_table[lalr_stack.last().lalr_state*c_terminal_plus_nonterminal_cnt + ret_term];

    // - PARSE ERROR wrong syntax -
    if (parse_action == c_idx_not_exist)
    {
      error_code.push(c_error_XML_SYNTAX_ERROR);
      error_code.push(old_input_idx);

      return false;
    }

    // - action SHIFT -
    if (parse_action < c_lalr_table_reduce_base)
    {
      if (ret_term == 9)
      {
        break;
      }

      // - insertion of state, and terminal position in source string -
      lalr_stack.push(parse_action,old_input_idx,input_idx);
      ret_term = c_idx_not_exist;
    }

    // - action REDUCE-
    else
    {
      parse_action -= c_lalr_table_reduce_base;

      // - call of assigned function to reduction -
      if (xml_pa_callers[parse_action] != pa_null)
      {
        if (!xml_pa_callers[parse_action](*this))
        {
          return false;
        }
      }

      // - remove of rule body from lalr_stack -
      lalr_stack.used -= rule_body_lengths[parse_action];

      // - insert of new automat state to stack -
      unsigned goto_val = lalr_table[lalr_stack.last().lalr_state*c_terminal_plus_nonterminal_cnt + rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(1);

  return true;
}/*}}}*/

bool xml_parser_s::parse_memory(unsigned a_length,const char *a_data)
{/*{{{*/

  // - clear xml parser -
  clear();

  // - copy source string -
  source_string.create(a_length + 1);
  memcpy(source_string.data,a_data,a_length);
  source_string.data[a_length] = '<';

  // - set reference xml parser pointer -
  ref_parser.xml_parser_ptr = this;

  // - create predefined references -
  ref_parser.create_reference(4,"test",strlen("Testing reference"),"Testing reference");

  // - reset xml declaration strings -
  version_idx = c_idx_not_exist;
  encoding_idx = c_idx_not_exist;
  standalone_idx = c_idx_not_exist;

  // - parse declaration string -
  if (!decl_parse_source())
  {
    return false;
  }

  // - test xml version -
  if (version_idx == c_idx_not_exist)
  {
    error_code.push(c_error_XML_UNDEFINED_XML_VERSION);
    error_code.push(old_input_idx);

    return false;
  }

  if (!data_array[version_idx].compare_char_ptr(strlen("1.0"),"1.0"))
  {
    error_code.push(c_error_XML_UNSUPPORTED_XML_VERSION);
    error_code.push(old_input_idx);
    error_code.push(version_idx);

    return false;
  }

  // - test input data encoding -
  if (encoding_idx == c_idx_not_exist)
  {
    error_code.push(c_error_XML_UNDEFINED_INPUT_DATA_ENCODING);
    error_code.push(old_input_idx);

    return false;
  }

  if (!data_array[encoding_idx].compare_char_ptr(strlen("UTF-8"),"UTF-8"))
  {
    error_code.push(c_error_XML_UNSUPPORTED_INPUT_DATA_ENCODING);
    error_code.push(old_input_idx);
    error_code.push(encoding_idx);

    return false;
  }

  // - parse rest of xml file -
  if (!parse_source())
  {
    return false;
  }

  return true;
}/*}}}*/

void xml_parser_s::process_errors()
{/*{{{*/
  if (error_code.used != 0)
  {
    unsigned *ei_ptr = error_code.data;
    unsigned *ei_ptr_end = ei_ptr + error_code.used;
    unsigned error_idx = 1;

    do
    {
      unsigned source_pos = ei_ptr[1];

      fprintf(stderr," ---------------------------------------- \n");

      switch (*ei_ptr)
      {
      case c_error_XML_UNRECOGNIZED_TERMINAL:
        fprintf(stderr,"%u. PARSE ERROR: on line: %u\n",error_idx,source_string.get_character_line(source_pos));
        print_error_show_line(source_string,source_pos);
        fprintf(stderr,"\nXML data unrecognized terminal\n");

        ei_ptr += 2;
        break;
      case c_error_XML_SYNTAX_ERROR:
        fprintf(stderr,"%u. PARSE ERROR: on line: %u\n",error_idx,source_string.get_character_line(source_pos));
        print_error_show_line(source_string,source_pos);
        fprintf(stderr,"\nXML data syntax error\n");

        ei_ptr += 2;
        break;
      case c_error_XML_REFERENCE_UNRECOGNIZED_TERMINAL:
        fprintf(stderr,"%u. PARSE ERROR: in string begining on line: %u\n",error_idx,source_string.get_character_line(source_pos));
        print_error_line(source_string,source_pos);
        fprintf(stderr,"\n");
        print_error_show_line(data_array[ei_ptr[2]],ei_ptr[3]);
        fprintf(stderr,"\nUnrecognized reference terminal in input data\n");

        ei_ptr += 4;
        break;
      case c_error_XML_UNDEFINED_REFERENCE:
        fprintf(stderr,"%u. PARSE ERROR: in string begining on line: %u\n",error_idx,source_string.get_character_line(source_pos));
        print_error_line(source_string,source_pos);
        fprintf(stderr,"\n");
        print_error_show_line(data_array[ei_ptr[2]],ei_ptr[3]);
        fprintf(stderr,"\nUndefined reference in input data\n");

        ei_ptr += 4;
        break;
      case c_error_XML_UNDEFINED_XML_VERSION:
        fprintf(stderr,"%u. PARSE ERROR: on line: %u\n",error_idx,source_string.get_character_line(source_pos));
        print_error_line(source_string,source_pos);
        fprintf(stderr,"\nUndefined XML file version\n");

        ei_ptr += 2;
        break;
      case c_error_XML_UNSUPPORTED_XML_VERSION:
        fprintf(stderr,"%u. PARSE ERROR: on line: %u\n",error_idx,source_string.get_character_line(source_pos));
        print_error_line(source_string,source_pos);
        fprintf(stderr,"\nUnsupported XML file version %s.\n",data_array[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      case c_error_XML_UNDEFINED_INPUT_DATA_ENCODING:
        fprintf(stderr,"%u. PARSE ERROR: on line: %u\n",error_idx,source_string.get_character_line(source_pos));
        print_error_line(source_string,source_pos);
        fprintf(stderr,"\nUndefined input data encoding\n");

        ei_ptr += 2;
        break;
      case c_error_XML_UNSUPPORTED_INPUT_DATA_ENCODING:
        fprintf(stderr,"%u. PARSE ERROR: on line: %u\n",error_idx,source_string.get_character_line(source_pos));
        print_error_line(source_string,source_pos);
        fprintf(stderr,"\nUnsupported input data encoding %s.\n",data_array[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      default:
        cassert(0);
      }
    }
    while(++error_idx,ei_ptr < ei_ptr_end);

    fprintf(stderr," ---------------------------------------- \n");

  }
}/*}}}*/

/*
 * global functions
 */

void print_error_show_line(string_s &source_string,unsigned begin)
{/*{{{*/
  debug_assert(begin < source_string.size);

  // - find begin of line -
  char *lb_ptr = source_string.data + source_string.get_character_line_begin(begin);
  char *le_ptr = source_string.data + source_string.get_character_line_end(begin);

  char tmp_char = *le_ptr;
  *le_ptr = '\0';
  fprintf(stderr,"%s\n",lb_ptr);
  *le_ptr = tmp_char;

  unsigned space_cnt = source_string.get_print_size_between(lb_ptr - source_string.data,begin);
  if (space_cnt != 0)
  {
    unsigned idx = 0;
    do
    {
      fputc(' ',stderr);
    }
    while(++idx < space_cnt);
  }

  fputc('^',stderr);
  fputc('\n',stderr);
}/*}}}*/

void print_error_line(string_s &source_string,unsigned char_pos)
{/*{{{*/
  debug_assert(char_pos < source_string.size);

  // - find begin of lines -
  char *lb_ptr = source_string.data + source_string.get_character_line_begin(char_pos);
  char *le_ptr = source_string.data + source_string.get_character_line_end(char_pos);

  char tmp_char = *le_ptr;
  *le_ptr = '\0';
  fprintf(stderr,"%s\n",lb_ptr);
  *le_ptr = tmp_char;
}/*}}}*/

