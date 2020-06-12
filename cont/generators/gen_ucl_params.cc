
const unsigned c_ucl_max_param_types = 32;

// - ucl parameter types -
enum
{/*{{{*/
  c_test_class_ignore = 0,
  c_test_class_retrieve_integer,
  c_test_class_retrieve_float,
  c_test_class_retrieve_integer_init,
  c_test_class_retrieve_float_init,
  c_test_class_retrieve_data_buffer,
  c_test_class_type,
};/*}}}*/

// - ucl parameter options -
enum
{/*{{{*/
  c_option_method = 0,
  c_option_class,
  c_option_static_method,
  c_option_macro,
  c_option_ignore,
  c_option_retrieve_integer,
  c_option_retrieve_float,
  c_option_retrieve_integer_init,
  c_option_retrieve_float_init,
  c_option_retrieve_data_buffer,
};/*}}}*/

unsigned recognize_ucl_params_option(char *source_string)
{/*{{{*/
#define GET_NEXT_UCL_PARAMS_CHAR() \
{\
   in_char = (unsigned char)source_string[input_idx];\
}

#define CLOSE_UCL_PARAMS_CHAR(RET_TERM_IDX) \
{\
   if (in_char == '\0') {\
      return RET_TERM_IDX;\
   }\
\
   input_idx++;\
}

   unsigned input_idx = 0;
   unsigned char in_char;

// - STATE 0 -
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 99)
      goto state_1_label;

   if (in_char == 105)
      goto state_2_label;

   if (in_char == 109)
      goto state_3_label;

   if (in_char == 114)
      goto state_4_label;

   if (in_char == 115)
      goto state_5_label;

   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 108)
      goto state_6_label;

   return c_idx_not_exist;

// - STATE 2 -
state_2_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 103)
      goto state_7_label;

   return c_idx_not_exist;

// - STATE 3 -
state_3_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_8_label;

   if (in_char == 101)
      goto state_9_label;

   return c_idx_not_exist;

// - STATE 4 -
state_4_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_10_label;

   return c_idx_not_exist;

// - STATE 5 -
state_5_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_11_label;

   return c_idx_not_exist;

// - STATE 6 -
state_6_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_12_label;

   return c_idx_not_exist;

// - STATE 7 -
state_7_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 110)
      goto state_13_label;

   return c_idx_not_exist;

// - STATE 8 -
state_8_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 99)
      goto state_14_label;

   return c_idx_not_exist;

// - STATE 9 -
state_9_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_15_label;

   return c_idx_not_exist;

// - STATE 10 -
state_10_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_16_label;

   return c_idx_not_exist;

// - STATE 11 -
state_11_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_17_label;

   return c_idx_not_exist;

// - STATE 12 -
state_12_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 115)
      goto state_18_label;

   return c_idx_not_exist;

// - STATE 13 -
state_13_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 111)
      goto state_19_label;

   return c_idx_not_exist;

// - STATE 14 -
state_14_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 114)
      goto state_20_label;

   return c_idx_not_exist;

// - STATE 15 -
state_15_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 104)
      goto state_21_label;

   return c_idx_not_exist;

// - STATE 16 -
state_16_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 114)
      goto state_22_label;

   return c_idx_not_exist;

// - STATE 17 -
state_17_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_23_label;

   return c_idx_not_exist;

// - STATE 18 -
state_18_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 115)
      goto state_24_label;

   return c_idx_not_exist;

// - STATE 19 -
state_19_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 114)
      goto state_25_label;

   return c_idx_not_exist;

// - STATE 20 -
state_20_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 111)
      goto state_26_label;

   return c_idx_not_exist;

// - STATE 21 -
state_21_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 111)
      goto state_27_label;

   return c_idx_not_exist;

// - STATE 22 -
state_22_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_28_label;

   return c_idx_not_exist;

// - STATE 23 -
state_23_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_29_label;

   return c_idx_not_exist;

// - STATE 24 -
state_24_label:
   CLOSE_UCL_PARAMS_CHAR(1);
   return 1;

// - STATE 25 -
state_25_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_30_label;

   return c_idx_not_exist;

// - STATE 26 -
state_26_label:
   CLOSE_UCL_PARAMS_CHAR(3);
   return 3;

// - STATE 27 -
state_27_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 100)
      goto state_31_label;

   return c_idx_not_exist;

// - STATE 28 -
state_28_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_32_label;

   return c_idx_not_exist;

// - STATE 29 -
state_29_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 99)
      goto state_33_label;

   return c_idx_not_exist;

// - STATE 30 -
state_30_label:
   CLOSE_UCL_PARAMS_CHAR(4);
   return 4;

// - STATE 31 -
state_31_label:
   CLOSE_UCL_PARAMS_CHAR(0);
   return 0;

// - STATE 32 -
state_32_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 118)
      goto state_34_label;

   return c_idx_not_exist;

// - STATE 33 -
state_33_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 95)
      goto state_35_label;

   return c_idx_not_exist;

// - STATE 34 -
state_34_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_36_label;

   return c_idx_not_exist;

// - STATE 35 -
state_35_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 109)
      goto state_37_label;

   return c_idx_not_exist;

// - STATE 36 -
state_36_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 95)
      goto state_38_label;

   return c_idx_not_exist;

// - STATE 37 -
state_37_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_39_label;

   return c_idx_not_exist;

// - STATE 38 -
state_38_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 100)
      goto state_40_label;

   if (in_char == 102)
      goto state_41_label;

   if (in_char == 105)
      goto state_42_label;

   return c_idx_not_exist;

// - STATE 39 -
state_39_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_43_label;

   return c_idx_not_exist;

// - STATE 40 -
state_40_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_44_label;

   return c_idx_not_exist;

// - STATE 41 -
state_41_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 108)
      goto state_45_label;

   return c_idx_not_exist;

// - STATE 42 -
state_42_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 110)
      goto state_46_label;

   return c_idx_not_exist;

// - STATE 43 -
state_43_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 104)
      goto state_47_label;

   return c_idx_not_exist;

// - STATE 44 -
state_44_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_48_label;

   return c_idx_not_exist;

// - STATE 45 -
state_45_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 111)
      goto state_49_label;

   return c_idx_not_exist;

// - STATE 46 -
state_46_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_50_label;

   return c_idx_not_exist;

// - STATE 47 -
state_47_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 111)
      goto state_51_label;

   return c_idx_not_exist;

// - STATE 48 -
state_48_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_52_label;

   return c_idx_not_exist;

// - STATE 49 -
state_49_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_53_label;

   return c_idx_not_exist;

// - STATE 50 -
state_50_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_54_label;

   return c_idx_not_exist;

// - STATE 51 -
state_51_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 100)
      goto state_55_label;

   return c_idx_not_exist;

// - STATE 52 -
state_52_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 95)
      goto state_56_label;

   return c_idx_not_exist;

// - STATE 53 -
state_53_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_57_label;

   return c_idx_not_exist;

// - STATE 54 -
state_54_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 103)
      goto state_58_label;

   return c_idx_not_exist;

// - STATE 55 -
state_55_label:
   CLOSE_UCL_PARAMS_CHAR(2);
   return 2;

// - STATE 56 -
state_56_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 98)
      goto state_59_label;

   return c_idx_not_exist;

// - STATE 57 -
state_57_label:
   CLOSE_UCL_PARAMS_CHAR(6);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 95)
      goto state_60_label;

   return 6;

// - STATE 58 -
state_58_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_61_label;

   return c_idx_not_exist;

// - STATE 59 -
state_59_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 117)
      goto state_62_label;

   return c_idx_not_exist;

// - STATE 60 -
state_60_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_63_label;

   return c_idx_not_exist;

// - STATE 61 -
state_61_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 114)
      goto state_64_label;

   return c_idx_not_exist;

// - STATE 62 -
state_62_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 102)
      goto state_65_label;

   return c_idx_not_exist;

// - STATE 63 -
state_63_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 110)
      goto state_66_label;

   return c_idx_not_exist;

// - STATE 64 -
state_64_label:
   CLOSE_UCL_PARAMS_CHAR(5);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 95)
      goto state_67_label;

   return 5;

// - STATE 65 -
state_65_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 102)
      goto state_68_label;

   return c_idx_not_exist;

// - STATE 66 -
state_66_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_69_label;

   return c_idx_not_exist;

// - STATE 67 -
state_67_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_70_label;

   return c_idx_not_exist;

// - STATE 68 -
state_68_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_71_label;

   return c_idx_not_exist;

// - STATE 69 -
state_69_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_72_label;

   return c_idx_not_exist;

// - STATE 70 -
state_70_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 110)
      goto state_73_label;

   return c_idx_not_exist;

// - STATE 71 -
state_71_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 114)
      goto state_74_label;

   return c_idx_not_exist;

// - STATE 72 -
state_72_label:
   CLOSE_UCL_PARAMS_CHAR(8);
   return 8;

// - STATE 73 -
state_73_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_75_label;

   return c_idx_not_exist;

// - STATE 74 -
state_74_label:
   CLOSE_UCL_PARAMS_CHAR(9);
   return 9;

// - STATE 75 -
state_75_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_76_label;

   return c_idx_not_exist;

// - STATE 76 -
state_76_label:
   CLOSE_UCL_PARAMS_CHAR(7);
   return 7;

}/*}}}*/

void processor_s::generate_ucl_params()
{/*{{{*/
  string_array_s &names = cont_params.types;
  string_array_s &types = cont_params.variables;
  string_array_s &additions = cont_params.functions;
  string_array_s &props = cont_params.names;

  if (names.used != types.used)
  {
    fprintf(stderr,"ucl_params: different count of variable names and types\n");
    cassert(0);
  }

  if (types.used > c_ucl_max_param_types)
  {
    fprintf(stderr,"ucl_params: maximal count of parameter types (%u) exceeded\n",c_ucl_max_param_types);
    cassert(0);
  }

  string_s *method_name = nullptr;
  string_s *class_name = nullptr;
  bool static_method = false;
  bool macro = false;
  const char *line_end = "\n";

  // - process parameters properties -
  if (props.used != 0)
  {
    string_s *p_ptr = props.data;
    string_s *p_ptr_end = p_ptr + props.used;
    do {
      unsigned option_idx = recognize_ucl_params_option(p_ptr->data);
      switch (option_idx)
      {
        case c_option_method:
        case c_option_class:
          if (++p_ptr >= p_ptr_end)
          {
            fprintf(stderr,"ucl_params: missing value of property %s\n",(p_ptr - 1)->data);
            cassert(0);
          }

          switch (option_idx)
          {
          case c_option_method:
            method_name = p_ptr;
            break;
          case c_option_class:
            class_name = p_ptr;
            break;
          }
          break;
        case c_option_static_method:
          static_method = true;
          break;
        case c_option_macro:
          macro = true;
          line_end = "\\\n";
          break;
        default:
          fprintf(stderr,"ucl_params: unrecognized propery: \"%s\"\n",p_ptr->data);
          cassert(0);
      }
    } while(++p_ptr < p_ptr_end);
  }

  unsigned param_count = 0;
  unsigned test_count = 0;
  bool retrieve_params = false;

  unsigned type_test_classes[c_ucl_max_param_types];
  unsigned map_type_param[c_ucl_max_param_types];
  unsigned param_test_counts[c_ucl_max_param_types];
  unsigned map_test_type[c_ucl_max_param_types];

  // - process parameters -
  if (types.used != 0)
  {
    unsigned type_idx = 0;
    unsigned param_idx = 0;
    do {
      string_s &type = types[type_idx];
      string_s &name = names[type_idx];
      unsigned &type_test_class = type_test_classes[type_idx];

      // - recognize type test class -
      switch (recognize_ucl_params_option(type.data))
      {
        case c_option_ignore:
          type_test_class = c_test_class_ignore;
          break;
        case c_option_retrieve_integer:
          type_test_class = c_test_class_retrieve_integer;
          retrieve_params = true;
          break;
        case c_option_retrieve_float:
          type_test_class = c_test_class_retrieve_float;
          retrieve_params = true;
          break;
        case c_option_retrieve_integer_init:
          type_test_class = c_test_class_retrieve_integer_init;
          retrieve_params = true;
          break;
        case c_option_retrieve_float_init:
          type_test_class = c_test_class_retrieve_float_init;
          retrieve_params = true;
          break;
        case c_option_retrieve_data_buffer:
          type_test_class = c_test_class_retrieve_data_buffer;
          retrieve_params = true;
          break;
        default:
          type_test_class = c_test_class_type;
      }

      // - process new parameter -
      unsigned name_idx = names.get_idx(name);
      if (name_idx == type_idx)
      {
        param_idx = param_count++;
        param_test_counts[param_idx] = 0;
      }
      else
      {
        if (map_type_param[name_idx] != param_idx)
        {
          fprintf(stderr,"ucl_params: parameter name \"%s\" out of order\n",name.data);
          cassert(0);
        }
      }

      // - update type to parameter map -
      map_type_param[type_idx] = param_idx;

      // - process new test -
      if (type_test_class != c_test_class_ignore)
      {
        // - update test to type map -
        map_test_type[test_count++] = type_idx;

        ++param_test_counts[param_idx];
      }
    } while(++type_idx < types.used);
  }

  if (gen_options & c_option_gen_code &&
     (include_level == 0 || gen_options & c_option_gen_includes))
  {
  // - generate uclang parameters code -

  // - retrieve destination for non static methods -
  if (!static_method)
  {
fprintf(out_file,
"  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);"
);
  }

  // - retrieve source locations -
  if (param_count != 0)
  {
    unsigned p_idx = 0;
    do {
fprintf(out_file,
"%s  location_s *src_%d_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_%d_op_idx]);"
,(static_method && p_idx == 0) ? "" : line_end,p_idx,p_idx);
    } while(++p_idx < param_count);
  }

  if (test_count > 0)
  {
    fprintf(out_file,"%s",line_end);

    // - declare retrieve variables -
    if (retrieve_params)
    {
      unsigned t_idx = 0;
      do {
        switch (type_test_classes[t_idx])
        {
        case c_test_class_retrieve_integer:
          fprintf(out_file,"%s  long long int %s;",line_end,names[t_idx].data);
          break;
        case c_test_class_retrieve_float:
          fprintf(out_file,"%s  double %s;",line_end,names[t_idx].data);
          break;
        case c_test_class_retrieve_integer_init:
          fprintf(out_file,"%s  long long int %s = 0;",line_end,names[t_idx].data);
          break;
        case c_test_class_retrieve_float_init:
          fprintf(out_file,"%s  double %s = 0.0;",line_end,names[t_idx].data);
          break;
        case c_test_class_retrieve_data_buffer:
          fprintf(out_file,
            "%s  const void *%s_ptr;"
            "%s  unsigned %s_size;",
          line_end,names[t_idx].data,line_end,names[t_idx].data);
          break;
        }
      } while(++t_idx < types.used);

      fprintf(out_file,"%s",line_end);
    }

   if (additions.used != 0)
   {
      unsigned f_idx = 0;
      do {
fprintf(out_file,
"%s  %s"
,line_end,additions[f_idx].data);
      } while(++f_idx < additions.used);

      fprintf(out_file,"%s",line_end);
   }

fprintf(out_file,
"%s  %s"
,line_end,macro ? "/* - ERROR - */" : "// - ERROR -");

    fprintf(out_file,"%s  if (",line_end);

    unsigned test_idx = 0;
    unsigned param_test_idx = 0;
    do {
      unsigned type_idx = map_test_type[test_idx];
      unsigned param_idx = map_type_param[type_idx];
      unsigned param_test_count = param_test_counts[param_idx];

      // - more than one test for parameter -
      if (param_test_count > 1)
      {
        fprintf(out_file,"%c",param_test_idx == 0 ? '(' : ' ');
      }

      switch (type_test_classes[type_idx])
      {
      case c_test_class_retrieve_integer:
      case c_test_class_retrieve_integer_init:
        fprintf(out_file,"!it.retrieve_integer(src_%u_location,%s)",param_idx,names[type_idx].data);
        break;
      case c_test_class_retrieve_float:
      case c_test_class_retrieve_float_init:
        fprintf(out_file,"!it.retrieve_float(src_%u_location,%s)",param_idx,names[type_idx].data);
        break;
      case c_test_class_retrieve_data_buffer:
        fprintf(out_file,"!it.retrieve_data_buffer(src_%u_location,%s_ptr,%s_size)",
            param_idx,names[type_idx].data,names[type_idx].data);
        break;
      case c_test_class_type:
        fprintf(out_file,"src_%u_location->v_type != %s",param_idx,types[type_idx].data);
        break;
      default:
        fprintf(stderr,"ucl_params: unrecognized test class %s\n",types[type_idx].data);
        cassert(0);
      }

      // - all parameter tests processed -
      if (++param_test_idx >= param_test_count)
      {
        // - more than one test of parameter -
        if (param_test_count > 1)
        {
          fprintf(out_file,")");
        }

        // - some remaining tests exist -
        if (++test_idx < test_count)
        {
          fprintf(out_file," ||");
        }
        else
        {
          break;
        }

        // - reset parameter test index -
        param_test_idx = 0;
      }
      else
      {
        // - next parameter test index -
        ++test_idx;
        fprintf(out_file," &&");
      }

      fprintf(out_file,"%s      ",line_end);
    } while(true);

fprintf(out_file,
")"
"%s  {"
,line_end);

fprintf(out_file,
"%s    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);"
,line_end);

    // - ERROR -
    if (method_name == nullptr)
    {
      fprintf(stderr,"ucl_params: missing method name value\n");
      cassert(0);
    }

    if (static_method)
    {
      // - ERROR -
      if (class_name == nullptr)
      {
        fprintf(stderr,"ucl_params: missing class name value\n");
        cassert(0);
      }

      if (macro)
      {
fprintf(out_file,
"%s    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,%s,%s);"
,line_end,class_name->data,method_name->data);
      }
      else
      {
fprintf(out_file,
"%s    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,%s,\"%s#%u\");"
,line_end,class_name->data,method_name->data,param_count);
      }
    }
    else
    {
      if (macro)
      {
fprintf(out_file,
"%s    BIC_EXCEPTION_PUSH_METHOD_RI(%s);"
,line_end,method_name->data);
      }
      else
      {
fprintf(out_file,
"%s    BIC_EXCEPTION_PUSH_METHOD_RI(\"%s#%u\");"
,line_end,method_name->data,param_count);
      }
    }

fprintf(out_file,
"%s    new_exception->params.push(%u);"
,line_end,param_count);

    unsigned param_idx = 0;
    do {
fprintf(out_file,
"%s    new_exception->params.push(src_%u_location->v_type);"
,line_end,param_idx);
    } while(++param_idx < param_count);

fprintf(out_file,
"%s"
"%s    return false;"
,line_end,line_end);

fprintf(out_file,
"%s  }"
,line_end);
  }
  }
}/*}}}*/

