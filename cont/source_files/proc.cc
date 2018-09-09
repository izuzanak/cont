
@begin
   include "proc.h"
@end

/*
 * constants and definitions
 */

void(*parse_callbacks[])(process_s &proc) = 
{
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_include,
   process_s::pa_reduce_inlines,
   process_s::pa_reduce_methods,
   process_s::pa_reduce_define,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_mod_basic,
   process_s::pa_reduce_mod_static,
   process_s::pa_reduce_mod_dynamic,
   process_s::pa_reduce_mod_flushable,
   process_s::pa_reduce_gen_container,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_type,
   process_s::pa_reduce_type_and_name,
   process_s::pa_reduce_null,
   process_s::pa_reduce_option,
   process_s::pa_reduce_null,
   process_s::pa_reduce_additions_body,
   process_s::pa_reduce_name,
};

// - parse constants -
const unsigned c_rule_cnt = 26;
const unsigned rule_head_idxs[c_rule_cnt] = {24, 25, 25, 26, 26, 26, 26, 27, 27, 28, 28, 28, 28, 26, 29, 29, 30, 31, 31, 32, 32, 30, 33, 33, 30, 30, };
const unsigned rule_body_lengths[c_rule_cnt] = {4, 2, 1, 2, 2, 2, 3, 2, 1, 1, 1, 1, 1, 3, 2, 1, 3, 2, 1, 1, 3, 3, 2, 1, 2, 1, };

// - parsing table -
#define blank c_idx_not_exist
#define SHIFT(VALUE) VALUE
#define REDUCE(VALUE) c_lalr_table_reduce_base + VALUE
#define GOTO(VALUE) VALUE

const unsigned c_lalr_table_reduce_base = 0x80000000;
const unsigned c_terminal_plus_nonterminal_cnt = 34;
const unsigned lalr_state_cnt = 43;

const unsigned lalr_table[lalr_state_cnt*c_terminal_plus_nonterminal_cnt] = {
    SHIFT(1),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,    SHIFT(4),    SHIFT(5),    SHIFT(6),    SHIFT(7),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    SHIFT(8),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,     GOTO(2),     GOTO(3),       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   SHIFT(10),    SHIFT(4),    SHIFT(5),    SHIFT(6),    SHIFT(7),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    SHIFT(8),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,     GOTO(9),       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(2),   REDUCE(2),   REDUCE(2),   REDUCE(2),   REDUCE(2),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(2),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(11),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(12),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(13),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(14),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(18),   SHIFT(19),       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(20),   SHIFT(17),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(15),    GOTO(16),       blank,       blank,       blank,
       blank,   REDUCE(1),   REDUCE(1),   REDUCE(1),   REDUCE(1),   REDUCE(1),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(1),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(3),   REDUCE(3),   REDUCE(3),   REDUCE(3),   REDUCE(3),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(3),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(4),   REDUCE(4),   REDUCE(4),   REDUCE(4),   REDUCE(4),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(4),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(5),   REDUCE(5),   REDUCE(5),   REDUCE(5),   REDUCE(5),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(5),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(24),   SHIFT(25),   SHIFT(26),   SHIFT(27),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(22),    GOTO(23),       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(18),   SHIFT(19),       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(20),   SHIFT(17),       blank,       blank,       blank,       blank,   SHIFT(29),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(28),       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(15),  REDUCE(15),       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(15),  REDUCE(15),       blank,       blank,       blank,       blank,  REDUCE(15),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(32),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(30),    GOTO(31),       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(34),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(33),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(35),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(25),  REDUCE(25),       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(25),  REDUCE(25),       blank,       blank,       blank,       blank,  REDUCE(25),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(6),   REDUCE(6),   REDUCE(6),   REDUCE(6),   REDUCE(6),       blank,       blank,   SHIFT(24),   SHIFT(25),   SHIFT(26),   SHIFT(27),       blank,       blank,   REDUCE(6),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(36),       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(8),   REDUCE(8),   REDUCE(8),   REDUCE(8),   REDUCE(8),       blank,       blank,   REDUCE(8),   REDUCE(8),   REDUCE(8),   REDUCE(8),       blank,       blank,   REDUCE(8),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(9),   REDUCE(9),   REDUCE(9),   REDUCE(9),   REDUCE(9),       blank,       blank,   REDUCE(9),   REDUCE(9),   REDUCE(9),   REDUCE(9),       blank,       blank,   REDUCE(9),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,  REDUCE(10),  REDUCE(10),  REDUCE(10),  REDUCE(10),  REDUCE(10),       blank,       blank,  REDUCE(10),  REDUCE(10),  REDUCE(10),  REDUCE(10),       blank,       blank,  REDUCE(10),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,  REDUCE(11),  REDUCE(11),  REDUCE(11),  REDUCE(11),  REDUCE(11),       blank,       blank,  REDUCE(11),  REDUCE(11),  REDUCE(11),  REDUCE(11),       blank,       blank,  REDUCE(11),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,  REDUCE(12),  REDUCE(12),  REDUCE(12),  REDUCE(12),  REDUCE(12),       blank,       blank,  REDUCE(12),  REDUCE(12),  REDUCE(12),  REDUCE(12),       blank,       blank,  REDUCE(12),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(14),  REDUCE(14),       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(14),  REDUCE(14),       blank,       blank,       blank,       blank,  REDUCE(14),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,  REDUCE(13),  REDUCE(13),  REDUCE(13),  REDUCE(13),  REDUCE(13),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(13),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(32),       blank,   SHIFT(38),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(37),       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(18),       blank,  REDUCE(18),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(19),       blank,  REDUCE(19),       blank,       blank,   SHIFT(39),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(40),       blank,       blank,       blank,   SHIFT(41),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(23),       blank,       blank,       blank,  REDUCE(23),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(24),  REDUCE(24),       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(24),  REDUCE(24),       blank,       blank,       blank,       blank,  REDUCE(24),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(7),   REDUCE(7),   REDUCE(7),   REDUCE(7),   REDUCE(7),       blank,       blank,   REDUCE(7),   REDUCE(7),   REDUCE(7),   REDUCE(7),       blank,       blank,   REDUCE(7),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(17),       blank,  REDUCE(17),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(16),  REDUCE(16),       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(16),  REDUCE(16),       blank,       blank,       blank,       blank,  REDUCE(16),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(42),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(22),       blank,       blank,       blank,  REDUCE(22),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(21),  REDUCE(21),       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(21),  REDUCE(21),       blank,       blank,       blank,       blank,  REDUCE(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(20),       blank,  REDUCE(20),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
};

/*
 * methods of generated structures
 */

// -- lalr_stack_element_s --
@begin
   methods lalr_stack_element_s
@end

// -- lalr_stack_s --
@begin
   methods lalr_stack_s
@end

// -- process_s --
@begin
   methods process_s
@end

unsigned process_s::find_terminal(unsigned &a_input_idx)
{/*{{{*/
   unsigned code_length = code.size - 1;

#define GET_NEXT_CHAR() \
{\
   if (a_input_idx < code_length) {\
      in_char = (unsigned char)code[a_input_idx];\
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
   a_input_idx++;\
}

   unsigned short in_char;

// - STATE 0 -
   GET_NEXT_CHAR();

   if (in_char == 0)
      goto state_1_label;

   if (in_char >= 8 && in_char < 14)
      goto state_21_label;

   if (in_char == 32)
      goto state_21_label;

   if (in_char == 34)
      goto state_2_label;

   if (in_char == 36)
      goto state_3_label;

   if (in_char == 40)
      goto state_4_label;

   if (in_char == 41)
      goto state_5_label;

   if (in_char == 58)
      goto state_6_label;

   if (in_char == 59)
      goto state_7_label;

   if (in_char == 60)
      goto state_8_label;

   if (in_char == 62)
      goto state_9_label;

   if (in_char == 64)
      goto state_10_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char == 97)
      goto state_12_label;

   if (in_char == 98)
      goto state_13_label;

   if (in_char == 99)
      goto state_11_label;

   if (in_char == 100)
      goto state_14_label;

   if (in_char == 101)
      goto state_11_label;

   if (in_char == 102)
      goto state_15_label;

   if (in_char >= 103 && in_char < 105)
      goto state_11_label;

   if (in_char == 105)
      goto state_16_label;

   if (in_char >= 106 && in_char < 109)
      goto state_11_label;

   if (in_char == 109)
      goto state_17_label;

   if (in_char == 110)
      goto state_11_label;

   if (in_char == 111)
      goto state_18_label;

   if (in_char >= 112 && in_char < 115)
      goto state_11_label;

   if (in_char == 115)
      goto state_19_label;

   if (in_char >= 116 && in_char < 123)
      goto state_11_label;

   if (in_char == 123)
      goto state_20_label;

   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   CLOSE_CHAR(23);
   return 23;

// - STATE 2 -
state_2_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 34)
      goto state_2_label;

   if (in_char == 34)
      goto state_22_label;

   if (in_char >= 35 && in_char < 256)
      goto state_2_label;

   return c_idx_not_exist;

// - STATE 3 -
state_3_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 10)
      goto state_3_label;

   if (in_char == 10)
      goto state_23_label;

   if (in_char >= 11 && in_char < 256)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 4 -
state_4_label:
   CLOSE_CHAR(17);
   return 17;

// - STATE 5 -
state_5_label:
   CLOSE_CHAR(18);
   return 18;

// - STATE 6 -
state_6_label:
   CLOSE_CHAR(19);
   return 19;

// - STATE 7 -
state_7_label:
   CLOSE_CHAR(20);
   return 20;

// - STATE 8 -
state_8_label:
   CLOSE_CHAR(15);
   return 15;

// - STATE 9 -
state_9_label:
   CLOSE_CHAR(16);
   return 16;

// - STATE 10 -
state_10_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 98)
      goto state_24_label;

   if (in_char == 101)
      goto state_25_label;

   return c_idx_not_exist;

// - STATE 11 -
state_11_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 12 -
state_12_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 100)
      goto state_11_label;

   if (in_char == 100)
      goto state_26_label;

   if (in_char >= 101 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 13 -
state_13_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char == 97)
      goto state_27_label;

   if (in_char >= 98 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 14 -
state_14_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 101)
      goto state_11_label;

   if (in_char == 101)
      goto state_28_label;

   if (in_char >= 102 && in_char < 121)
      goto state_11_label;

   if (in_char == 121)
      goto state_29_label;

   if (in_char == 122)
      goto state_11_label;

   return 14;

// - STATE 15 -
state_15_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 108)
      goto state_11_label;

   if (in_char == 108)
      goto state_30_label;

   if (in_char >= 109 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 16 -
state_16_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 110)
      goto state_11_label;

   if (in_char == 110)
      goto state_31_label;

   if (in_char >= 111 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 17 -
state_17_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 101)
      goto state_11_label;

   if (in_char == 101)
      goto state_32_label;

   if (in_char >= 102 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 18 -
state_18_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 112)
      goto state_11_label;

   if (in_char == 112)
      goto state_33_label;

   if (in_char >= 113 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 19 -
state_19_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 116)
      goto state_11_label;

   if (in_char == 116)
      goto state_34_label;

   if (in_char >= 117 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 20 -
state_20_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 125)
      goto state_20_label;

   if (in_char == 125)
      goto state_35_label;

   if (in_char >= 126 && in_char < 256)
      goto state_20_label;

   return c_idx_not_exist;

// - STATE 21 -
state_21_label:
   CLOSE_CHAR(21);
   GET_NEXT_CHAR();

   if (in_char >= 8 && in_char < 14)
      goto state_21_label;

   if (in_char == 32)
      goto state_21_label;

   return 21;

// - STATE 22 -
state_22_label:
   CLOSE_CHAR(12);
   return 12;

// - STATE 23 -
state_23_label:
   CLOSE_CHAR(22);
   return 22;

// - STATE 24 -
state_24_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101)
      goto state_36_label;

   return c_idx_not_exist;

// - STATE 25 -
state_25_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 110)
      goto state_37_label;

   return c_idx_not_exist;

// - STATE 26 -
state_26_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 100)
      goto state_11_label;

   if (in_char == 100)
      goto state_38_label;

   if (in_char >= 101 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 27 -
state_27_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 115)
      goto state_11_label;

   if (in_char == 115)
      goto state_39_label;

   if (in_char >= 116 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 28 -
state_28_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 102)
      goto state_11_label;

   if (in_char == 102)
      goto state_40_label;

   if (in_char >= 103 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 29 -
state_29_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 110)
      goto state_11_label;

   if (in_char == 110)
      goto state_41_label;

   if (in_char >= 111 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 30 -
state_30_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 117)
      goto state_11_label;

   if (in_char == 117)
      goto state_42_label;

   if (in_char >= 118 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 31 -
state_31_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 99)
      goto state_11_label;

   if (in_char == 99)
      goto state_43_label;

   if (in_char >= 100 && in_char < 108)
      goto state_11_label;

   if (in_char == 108)
      goto state_44_label;

   if (in_char >= 109 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 32 -
state_32_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 116)
      goto state_11_label;

   if (in_char == 116)
      goto state_45_label;

   if (in_char >= 117 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 33 -
state_33_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 116)
      goto state_11_label;

   if (in_char == 116)
      goto state_46_label;

   if (in_char >= 117 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 34 -
state_34_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char == 97)
      goto state_47_label;

   if (in_char >= 98 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 35 -
state_35_label:
   CLOSE_CHAR(13);
   return 13;

// - STATE 36 -
state_36_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 103)
      goto state_48_label;

   return c_idx_not_exist;

// - STATE 37 -
state_37_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 100)
      goto state_49_label;

   return c_idx_not_exist;

// - STATE 38 -
state_38_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 105)
      goto state_11_label;

   if (in_char == 105)
      goto state_50_label;

   if (in_char >= 106 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 39 -
state_39_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 105)
      goto state_11_label;

   if (in_char == 105)
      goto state_51_label;

   if (in_char >= 106 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 40 -
state_40_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 105)
      goto state_11_label;

   if (in_char == 105)
      goto state_52_label;

   if (in_char >= 106 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 41 -
state_41_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char == 97)
      goto state_53_label;

   if (in_char >= 98 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 42 -
state_42_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 115)
      goto state_11_label;

   if (in_char == 115)
      goto state_54_label;

   if (in_char >= 116 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 43 -
state_43_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 108)
      goto state_11_label;

   if (in_char == 108)
      goto state_55_label;

   if (in_char >= 109 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 44 -
state_44_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 105)
      goto state_11_label;

   if (in_char == 105)
      goto state_56_label;

   if (in_char >= 106 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 45 -
state_45_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 104)
      goto state_11_label;

   if (in_char == 104)
      goto state_57_label;

   if (in_char >= 105 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 46 -
state_46_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 105)
      goto state_11_label;

   if (in_char == 105)
      goto state_58_label;

   if (in_char >= 106 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 47 -
state_47_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 116)
      goto state_11_label;

   if (in_char == 116)
      goto state_59_label;

   if (in_char >= 117 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 48 -
state_48_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 105)
      goto state_60_label;

   return c_idx_not_exist;

// - STATE 49 -
state_49_label:
   CLOSE_CHAR(1);
   return 1;

// - STATE 50 -
state_50_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 116)
      goto state_11_label;

   if (in_char == 116)
      goto state_61_label;

   if (in_char >= 117 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 51 -
state_51_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 99)
      goto state_11_label;

   if (in_char == 99)
      goto state_62_label;

   if (in_char >= 100 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 52 -
state_52_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 110)
      goto state_11_label;

   if (in_char == 110)
      goto state_63_label;

   if (in_char >= 111 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 53 -
state_53_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 109)
      goto state_11_label;

   if (in_char == 109)
      goto state_64_label;

   if (in_char >= 110 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 54 -
state_54_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 104)
      goto state_11_label;

   if (in_char == 104)
      goto state_65_label;

   if (in_char >= 105 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 55 -
state_55_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 117)
      goto state_11_label;

   if (in_char == 117)
      goto state_66_label;

   if (in_char >= 118 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 56 -
state_56_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 110)
      goto state_11_label;

   if (in_char == 110)
      goto state_67_label;

   if (in_char >= 111 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 57 -
state_57_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 111)
      goto state_11_label;

   if (in_char == 111)
      goto state_68_label;

   if (in_char >= 112 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 58 -
state_58_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 111)
      goto state_11_label;

   if (in_char == 111)
      goto state_69_label;

   if (in_char >= 112 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 59 -
state_59_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 105)
      goto state_11_label;

   if (in_char == 105)
      goto state_70_label;

   if (in_char >= 106 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 60 -
state_60_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 110)
      goto state_71_label;

   return c_idx_not_exist;

// - STATE 61 -
state_61_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 105)
      goto state_11_label;

   if (in_char == 105)
      goto state_72_label;

   if (in_char >= 106 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 62 -
state_62_label:
   CLOSE_CHAR(8);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 123)
      goto state_11_label;

   return 8;

// - STATE 63 -
state_63_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 101)
      goto state_11_label;

   if (in_char == 101)
      goto state_73_label;

   if (in_char >= 102 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 64 -
state_64_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 105)
      goto state_11_label;

   if (in_char == 105)
      goto state_74_label;

   if (in_char >= 106 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 65 -
state_65_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char == 97)
      goto state_75_label;

   if (in_char >= 98 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 66 -
state_66_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 100)
      goto state_11_label;

   if (in_char == 100)
      goto state_76_label;

   if (in_char >= 101 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 67 -
state_67_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 101)
      goto state_11_label;

   if (in_char == 101)
      goto state_77_label;

   if (in_char >= 102 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 68 -
state_68_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 100)
      goto state_11_label;

   if (in_char == 100)
      goto state_78_label;

   if (in_char >= 101 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 69 -
state_69_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 110)
      goto state_11_label;

   if (in_char == 110)
      goto state_79_label;

   if (in_char >= 111 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 70 -
state_70_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 99)
      goto state_11_label;

   if (in_char == 99)
      goto state_80_label;

   if (in_char >= 100 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 71 -
state_71_label:
   CLOSE_CHAR(0);
   return 0;

// - STATE 72 -
state_72_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 111)
      goto state_11_label;

   if (in_char == 111)
      goto state_81_label;

   if (in_char >= 112 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 73 -
state_73_label:
   CLOSE_CHAR(5);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 123)
      goto state_11_label;

   return 5;

// - STATE 74 -
state_74_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 99)
      goto state_11_label;

   if (in_char == 99)
      goto state_82_label;

   if (in_char >= 100 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 75 -
state_75_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char == 97)
      goto state_11_label;

   if (in_char == 98)
      goto state_83_label;

   if (in_char >= 99 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 76 -
state_76_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 101)
      goto state_11_label;

   if (in_char == 101)
      goto state_84_label;

   if (in_char >= 102 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 77 -
state_77_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 115)
      goto state_11_label;

   if (in_char == 115)
      goto state_85_label;

   if (in_char >= 116 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 78 -
state_78_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 115)
      goto state_11_label;

   if (in_char == 115)
      goto state_86_label;

   if (in_char >= 116 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 79 -
state_79_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 115)
      goto state_11_label;

   if (in_char == 115)
      goto state_87_label;

   if (in_char >= 116 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 80 -
state_80_label:
   CLOSE_CHAR(9);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 123)
      goto state_11_label;

   return 9;

// - STATE 81 -
state_81_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 110)
      goto state_11_label;

   if (in_char == 110)
      goto state_88_label;

   if (in_char >= 111 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 82 -
state_82_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 123)
      goto state_11_label;

   return 10;

// - STATE 83 -
state_83_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 108)
      goto state_11_label;

   if (in_char == 108)
      goto state_89_label;

   if (in_char >= 109 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 84 -
state_84_label:
   CLOSE_CHAR(2);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 123)
      goto state_11_label;

   return 2;

// - STATE 85 -
state_85_label:
   CLOSE_CHAR(3);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 123)
      goto state_11_label;

   return 3;

// - STATE 86 -
state_86_label:
   CLOSE_CHAR(4);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 123)
      goto state_11_label;

   return 4;

// - STATE 87 -
state_87_label:
   CLOSE_CHAR(6);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 123)
      goto state_11_label;

   return 6;

// - STATE 88 -
state_88_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 115)
      goto state_11_label;

   if (in_char == 115)
      goto state_90_label;

   if (in_char >= 116 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 89 -
state_89_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 101)
      goto state_11_label;

   if (in_char == 101)
      goto state_91_label;

   if (in_char >= 102 && in_char < 123)
      goto state_11_label;

   return 14;

// - STATE 90 -
state_90_label:
   CLOSE_CHAR(7);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 123)
      goto state_11_label;

   return 7;

// - STATE 91 -
state_91_label:
   CLOSE_CHAR(11);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_11_label;

   if (in_char >= 65 && in_char < 91)
      goto state_11_label;

   if (in_char == 95)
      goto state_11_label;

   if (in_char >= 97 && in_char < 123)
      goto state_11_label;

   return 11;

}/*}}}*/

bool process_s::parse_code(string_s &a_code)
{/*{{{*/
   lalr_stack.used = 0;
   lalr_stack.push(0);

   unsigned old_input_idx = 0;
   unsigned input_idx = 0;
   unsigned ret_term = c_idx_not_exist;

   do {

      while (ret_term == c_idx_not_exist) {
         old_input_idx = input_idx;

         ret_term = find_terminal(input_idx);
         if (ret_term == c_idx_not_exist) {
            fprintf(stderr,
"ERROR: Cannot recognize terminal symbol\n"
"SOURCE CODE: %s\n",a_code.data);
            return false;
         }

         if (ret_term == 21 || ret_term == 22) {
            ret_term = c_idx_not_exist;
         }
      }

      // - search for action in parse table -
      unsigned parse_action = lalr_table[lalr_stack.last().lalr_state*c_terminal_plus_nonterminal_cnt + ret_term];
      if (parse_action == c_idx_not_exist) {
         fprintf(stderr,
"ERROR: Cannot find proper parse action\n"
"SOURCE CODE: %s\n",a_code.data);
         return false;
      }

      // - SHIFT action -
      if (parse_action < c_lalr_table_reduce_base) {

         if (ret_term == 23) {
            break;
         }

         // - push new state to stack and position of terminal in source string -
         lalr_stack.push(parse_action,old_input_idx,input_idx);
         ret_term = c_idx_not_exist;
      }

      // - REDUCE action -
      else {
         parse_action -= c_lalr_table_reduce_base;

         // - call parse callback -
         parse_callbacks[parse_action](*this);

         // - remove rule body from stack -
         lalr_stack.used -= rule_body_lengths[parse_action];

         // - push new automata state to stack -
         unsigned goto_val = lalr_table[lalr_stack.last().lalr_state*c_terminal_plus_nonterminal_cnt + rule_head_idxs[parse_action]];
         lalr_stack.push(goto_val);
      }

   } while(1);

   lalr_stack.clear();

   return true;
}/*}}}*/

bool process_s::run_on(const char *a_file_name)
{/*{{{*/
  string_s file_path;
  file_path.init();

  // - retrieve file full path (search in include directories) -
  if (!processor_ptr->find_include_file(a_file_name, file_path))
  {
    fprintf(stderr,"ERROR: Cannot found source file: \"%s\".\n", a_file_name);

    file_path.clear();
    return false;
  }

  if (!source_string.load_text_file(file_path.data)) {
    fprintf(stderr,"ERROR: Cannot read source file: \"%s\".\n", file_path.data);

    file_path.clear();
    return false;
  }

  file_path.clear();

  unsigned source_idx = 0;
  do {
    char *b_ptr = strstr(source_string.data + source_idx,c_begin_str);

    if (b_ptr == NULL) {
      fprintf(processor_ptr->out_file,"%s",source_string.data + source_idx);
      break;
    }
    else {
      *b_ptr = '\0';
      fprintf(processor_ptr->out_file,"%s",source_string.data + source_idx);
      *b_ptr = c_begin_str[0];

      source_idx = b_ptr - source_string.data;

      char *e_ptr = strstr(source_string.data + source_idx,c_end_str);
      if (e_ptr == NULL) {
        fprintf(stderr,"ERROR: Cannot find ending mark \"%s\".\n",c_end_str);
        return false;
      }

      unsigned tmp_char_idx = (e_ptr - b_ptr) + c_end_str_len;
      char tmp_char = b_ptr[tmp_char_idx];

      b_ptr[tmp_char_idx] = '\0';

      code.size = (e_ptr - b_ptr) + c_end_str_len + 1;
      code.data = b_ptr;

      // - parse definition code -
      parse_code(code);

      code.size = 1;
      code.data = (char *)&c_string_terminating_char;

      b_ptr[tmp_char_idx] = tmp_char;
      source_idx = e_ptr - source_string.data + c_end_str_len;
    }

  } while(true);

  return true;
}/*}}}*/

void process_s::pa_reduce_null(process_s &proc)
{/*{{{*/
}/*}}}*/

void process_s::pa_reduce_include(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----

   unsigned tmp_char_idx = lse.terminal_end - 1;
   char tmp_char = code.data[tmp_char_idx];
   code.data[tmp_char_idx] = '\0';

   // - create included string -
   string_s include_str;
   include_str.data = code.data + lse.terminal_start + 1;
   include_str.size = (lse.terminal_end - lse.terminal_start) - 1;
   
   if (processor.include_names.get_idx(include_str) == c_idx_not_exist) {
      
      // - insert included file to include names array -
      processor.include_names.push_blank();
      processor.include_names.last().set(include_str.size - 1,include_str.data);

      // - process included file -
      process_s process;
      process.init();

      process.processor_ptr = proc.processor_ptr;
      process.run_on(code.data + lse.terminal_start + 1);
      process.clear();
   }

   code.data[tmp_char_idx] = tmp_char;
}/*}}}*/

void process_s::pa_reduce_inlines(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----
   
   processor.generate_type_inlines(lse.terminal_end - lse.terminal_start,code.data + lse.terminal_start);
}/*}}}*/

void process_s::pa_reduce_methods(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----
   
   processor.generate_type_methods(lse.terminal_end - lse.terminal_start,code.data + lse.terminal_start);
}/*}}}*/

void process_s::pa_reduce_define(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack[proc.lalr_stack.used - 2];

   // -----

   unsigned str_length = lse.terminal_end - lse.terminal_start;
   char *str_data = code.data + lse.terminal_start;

   unsigned abb_idx = processor.abbreviations.get_idx_by_name(str_length,str_data);

   if (abb_idx != c_idx_not_exist) {
      fprintf(stderr,"ERROR: Cannot define type, type name already exist.\n");
      cassert(0);
   }

   // - define new data type -
   processor.data_types.push_blank();
   data_type_s &data_type = processor.data_types.last();

   data_type.name.set(str_length,str_data);
   data_type.real_name.set(str_length,str_data);
   data_type.properties = processor.type_settings;

   // - define data type abbreviation -
   processor.abbreviations.push_blank();
   abbreviation_s &abb = processor.abbreviations.last();

   abb.name.set(str_length,str_data);
   abb.data_type_idx = processor.data_types.used - 1;

   // - reset type_setting -
   processor.type_settings = 0;
}/*}}}*/

void process_s::pa_reduce_mod_basic(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;

   // -----

   processor.type_settings = (processor.type_settings & c_type_byte_neg_mod_mask) | c_type_basic;
}/*}}}*/

void process_s::pa_reduce_mod_static(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;

   // -----

   processor.type_settings = (processor.type_settings & c_type_byte_neg_mod_mask) | c_type_static;
}/*}}}*/

void process_s::pa_reduce_mod_dynamic(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;

   // -----

   processor.type_settings = (processor.type_settings & c_type_byte_neg_mod_mask) | c_type_dynamic;
}/*}}}*/

void process_s::pa_reduce_mod_flushable(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;

   // -----

   processor.type_settings |= c_type_flushable;
}/*}}}*/

void process_s::pa_reduce_gen_container(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack[proc.lalr_stack.used - 3];

   // -----

   unsigned tmp_char_idx = lse.terminal_end;
   char tmp_char = code.data[tmp_char_idx];
   code.data[tmp_char_idx] = '\0';

   string_s cont_name;
   cont_name.size = lse.terminal_end - lse.terminal_start + 1;
   cont_name.data = code.data + lse.terminal_start;

   processor.generate_container_def(cont_name);
   code.data[tmp_char_idx] = tmp_char;

   processor.type_settings = 0;
   processor.cont_params.clean_out();
}/*}}}*/

void process_s::pa_reduce_type(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----

   string_array_s &param = processor.cont_params.types;

   param.push_blank();
   param.last().set(lse.terminal_end - lse.terminal_start,code.data + lse.terminal_start);
}/*}}}*/

void process_s::pa_reduce_type_and_name(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &t_lse = proc.lalr_stack[proc.lalr_stack.used - 3];
   lalr_stack_element_s &v_lse = proc.lalr_stack.last();

   // -----

   string_array_s &type_param = processor.cont_params.types;

   type_param.push_blank();
   type_param.last().set(t_lse.terminal_end - t_lse.terminal_start,code.data + t_lse.terminal_start);

   string_array_s &var_param = processor.cont_params.variables;

   var_param.push_blank();
   var_param.last().set(v_lse.terminal_end - v_lse.terminal_start,code.data + v_lse.terminal_start);
}/*}}}*/

void process_s::pa_reduce_option(process_s &proc)
{/*{{{*/
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----

   char tmp_char = code[lse.terminal_end];
   code[lse.terminal_end] = '\0';

   if (strcmp("no_init",code.data + lse.terminal_start) == 0)
      proc.processor_ptr->type_settings |= c_type_option_nogen_init;

   else if (strcmp("no_clear",code.data + lse.terminal_start) == 0)
      proc.processor_ptr->type_settings |= c_type_option_nogen_clear;

   else if (strcmp("no_swap",code.data + lse.terminal_start) == 0)
      proc.processor_ptr->type_settings |= c_type_option_nogen_swap;

   else if (strcmp("no_copy",code.data + lse.terminal_start) == 0)
      proc.processor_ptr->type_settings |= c_type_option_nogen_copy;

   else if (strcmp("strict_dynamic",code.data + lse.terminal_start) == 0)
      proc.processor_ptr->type_settings |= c_type_option_strict_dynamic;

   else {
      fprintf(stderr,"ERROR: Unrecognized option %s.\n",code.data + lse.terminal_start);
      cassert(0);
   }

   code[lse.terminal_end] = tmp_char;
}/*}}}*/

void process_s::pa_reduce_additions_body(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----

   string_array_s &param = processor.cont_params.functions;
   
   param.push_blank();
   param.last().set((lse.terminal_end - lse.terminal_start) - 2,code.data + lse.terminal_start + 1);
}/*}}}*/

void process_s::pa_reduce_name(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----

   string_array_s &param = processor.cont_params.names;
   
   param.push_blank();
   param.last().set(lse.terminal_end - lse.terminal_start,code.data + lse.terminal_start);
}/*}}}*/

