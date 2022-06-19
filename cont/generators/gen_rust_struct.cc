
#define RUST_STRUCT_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_cnt,data_type_s &data_type,data_type_s **types
#define RUST_STRUCT_GEN_VALUES out_file,abbreviations,abb_idx,type_cnt,data_type,types

void RUST_STRUCT_INIT(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn init(&mut self)\n"
"{/*{{{*/\n"
);
   unsigned t_idx = 0;
   do {
      if (TYPE_NUMBERS(t_idx) & (c_type_dynamic | c_type_option_force_init)) {
fprintf(out_file,
"  self.%s.init();\n"
,VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_CLEAR(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn clear(&mut self)\n"
"{/*{{{*/\n"
);
   unsigned t_idx = 0;
   do {
      if (TYPE_NUMBERS(t_idx) & c_type_dynamic) {
fprintf(out_file,
"  self.%s.clear();\n"
,VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_SET(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn set(&mut self,"
);
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"a_%s:%s"
,VAR_NAMES(0),TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"a_%s:&%s"
,VAR_NAMES(0),TYPE_NAMES(0));
   }
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
         if (TYPE_NUMBERS(t_idx) & c_type_basic) {
fprintf(out_file,
",a_%s:%s"
,VAR_NAMES(t_idx),TYPE_NAMES(t_idx));
         }
         else {
fprintf(out_file,
",a_%s:&%s"
,VAR_NAMES(t_idx),TYPE_NAMES(t_idx));
         }
      } while(++t_idx < TYPE_CNT);
   }
fprintf(out_file,
")\n"
"{/*{{{*/\n"
);
   unsigned t_idx = 0;
   do {
       if (TYPE_NUMBERS(t_idx) & c_type_basic) {
fprintf(out_file,
"  self.%s = a_%s;\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
       }
       else if (TYPE_NUMBERS(t_idx) & c_type_static) {
fprintf(out_file,
"  self.%s = a_%s;\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
       }
       else {
fprintf(out_file,
"  self.%s.copy(a_%s);\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
       }
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_FLUSH_ALL(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn flush_all(&mut self)\n"
"{/*{{{*/\n"
);
   unsigned t_idx = 0;
   do {
      if (TYPE_NUMBERS(t_idx) & c_type_flushable) {
fprintf(out_file,
"  self.%s.flush_all();\n"
,VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_SWAP(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn swap(&mut self,a_second:&mut Self)\n"
"{/*{{{*/\n"
"  std::mem::swap(self,a_second);\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_OPERATOR_EQUAL(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn copy(&mut self,a_src:&Self)\n"
"{/*{{{*/\n"
);
   unsigned t_idx = 0;
   do {
       if (!(TYPE_NUMBERS(t_idx) & c_type_dynamic)) {
fprintf(out_file,
"  self.%s = a_src.%s;\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
       }
       else {
fprintf(out_file,
"  self.%s.copy(&a_src.%s);\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
       }
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_OPERATOR_DOUBLE_EQUAL(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn compare(&self,a_second:&Self) -> bool\n"
"{/*{{{*/\n"
);
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"  (self.%s == a_second.%s"
,VAR_NAMES(0),VAR_NAMES(0));
   }
   else {
fprintf(out_file,
"  (self.%s.compare(&a_second.%s)"
,VAR_NAMES(0),VAR_NAMES(0));
   }
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
fprintf(out_file,
" &&\n"
);
         if (TYPE_NUMBERS(t_idx) & c_type_basic) {
fprintf(out_file,
"          self.%s == a_second.%s"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
         }
         else {
fprintf(out_file,
"          self.%s.compare(&a_second.%s)"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
         }
      } while(++t_idx < TYPE_CNT);
   }
fprintf(out_file,
")\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_TO_STRING(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_STRING = \"ENABLED\")]\n"
"fn to_string(&self,a_trg:&mut bc_array_s)\n"
"{/*{{{*/\n"
);
fprintf(out_file,
"  a_trg.append(b\"{%s:\");\n"
"  Cont::to_string(&self.%s,a_trg);\n"
,VAR_NAMES(0),VAR_NAMES(0));
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
fprintf(out_file,
"  a_trg.append(b\",%s:\");\n"
"  Cont::to_string(&self.%s,a_trg);\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      } while(++t_idx < TYPE_CNT);
   }
fprintf(out_file,
"  a_trg.push(b'}' as bc);\n"
);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_TO_STRING_SEPARATOR(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_STRING = \"ENABLED\")]\n"
"fn to_string_separator(&self,a_trg:&mut bc_array_s,a_data:&[u8])\n"
"{/*{{{*/\n"
);
fprintf(out_file,
"  a_trg.append(b\"%s:\");\n"
"  Cont::to_string(&self.%s,a_trg);\n"
,VAR_NAMES(0),VAR_NAMES(0));
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
fprintf(out_file,
"  a_trg.append(a_data);\n"
"  a_trg.append(b\"%s:\");\n"
"  Cont::to_string(&self.%s,a_trg);\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      } while(++t_idx < TYPE_CNT);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_TO_JSON(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_JSON = \"ENABLED\")]\n"
"fn to_json(&self,a_trg:&mut bc_array_s)\n"
"{/*{{{*/\n"
);
fprintf(out_file,
"  a_trg.append(b\"{\\\"%s\\\":\");\n"
"  Cont::to_json(&self.%s,a_trg);\n"
,VAR_NAMES(0),VAR_NAMES(0));
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
fprintf(out_file,
"  a_trg.append(b\",\\\"%s\\\":\");\n"
"  Cont::to_json(&self.%s,a_trg);\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      } while(++t_idx < TYPE_CNT);
   }
fprintf(out_file,
"  a_trg.push('}' as bc);\n"
);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_TO_JSON_NICE(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_JSON = \"ENABLED\")]\n"
"fn to_json_nice(&self,a_json_nice:&mut json_nice_s,a_trg:&mut bc_array_s)\n"
"{/*{{{*/\n"
);
fprintf(out_file,
"  a_trg.push(b'{' as bc);\n"
"  a_json_nice.push_indent(a_trg);\n"
"  a_trg.append(b\"\\\"%s\\\": \");\n"
"  Cont::to_json_nice(&self.%s,a_json_nice,a_trg);\n"
,VAR_NAMES(0),VAR_NAMES(0));
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
fprintf(out_file,
"  a_trg.push(b',' as bc);\n"
"  a_json_nice.indent(a_trg);\n"
"  a_trg.append(b\"\\\"%s\\\": \");\n"
"  Cont::to_json_nice(&self.%s,a_json_nice,a_trg);\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      } while(++t_idx < TYPE_CNT);
   }
fprintf(out_file,
"  a_json_nice.pop_indent(a_trg);\n"
"  a_trg.push(b'}' as bc);\n"
);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_FROM_VAR(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_FROM_VAR == ENABLED\n"
"static inline int %s_from_var(%s *this,var_s a_var)\n"
"{/*{{{*/\n"
"  if (a_var == NULL || a_var->v_type != c_bi_type_dict)\n"
"  {\n"
"    throw_error(FROM_VAR_ERROR);\n"
"  }\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"  var_s %s_var = loc_s_dict_str_get(a_var,\"%s\");\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"\n"
"  if (%s_from_var(&this->%s,%s_var)"
,TYPE_NAMES(0),VAR_NAMES(0),VAR_NAMES(0));
   if (TYPE_CNT > 1) {
     unsigned t_idx = 1;
     do {
fprintf(out_file,
" ||\n"
"      %s_from_var(&this->%s,%s_var)"
,TYPE_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx));
     } while(++t_idx < TYPE_CNT);
   }
fprintf(out_file,
")\n"
"  {\n"
"    throw_error(FROM_VAR_ERROR);\n"
"  }\n"
"\n"
"  return 0;\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
);
}/*}}}*/

void RUST_STRUCT_FROM_JSON(RUST_STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_FROM_JSON == ENABLED\n"
"static inline int %s_from_json(%s *this,const bc_array_s *a_src,from_json_s *a_from_json)\n"
"{/*{{{*/\n"
"  if (from_json_s_get_terminal(a_from_json,a_src,c_json_terminal_lc_br) ||\n"
,STRUCT_NAME,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"      from_json_s_get_string(a_from_json,a_src) ||\n"
"      strcmp(a_from_json->buffer.data,\"%s\") ||\n"
"      from_json_s_get_terminal(a_from_json,a_src,c_json_terminal_colon) ||\n"
"      %s_from_json(&this->%s,a_src,a_from_json) ||\n"
"      from_json_s_get_terminal(a_from_json,a_src,%s"
,VAR_NAMES(t_idx),TYPE_NAMES(t_idx),VAR_NAMES(t_idx)
,t_idx == TYPE_CNT - 1 ? "c_json_terminal_rc_br))\n" : "c_json_terminal_comma) ||\n"
);
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"  {\n"
"    throw_error(FROM_JSON_ERROR);\n"
"  }\n"
"\n"
"  return 0;\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
);
}/*}}}*/

void processor_s::generate_rust_struct_type()
{/*{{{*/
   string_array_s &type_names = cont_params.types;
   string_array_s &variables = cont_params.variables;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used < 1 || type_names.used != variables.used) {
      fprintf(stderr,"struct: not given name of contained type, or not same count of types and variables\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"struct: not given name of generated structure\n");
      cassert(0);
   }

   unsigned type_cnt = type_names.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"struct: too many contained types, max 256 supported\n");
      cassert(0);
   }
#else
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];
#endif

   {
      unsigned tn_idx = 0;
      do {
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_names[tn_idx].size - 1,type_names[tn_idx].data);
         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"struct: contained type \"%s\" does not exist\n",type_names[tn_idx].data);
            cassert(0);
         }

         unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
         type_idxs[tn_idx] = type_idx;

         // - test type options -
         data_type_s &type = data_types[type_idx];
         if (type.properties & c_type_option_strict_dynamic) {
            fprintf(stderr,"struct: option strict_dynamic not supported\n");
            cassert(0);
         }

      } while(++tn_idx < type_cnt);
   }

   // - compute length of type name -
   unsigned data_type_name_len = 0;
   {
      unsigned t_idx = 0;
      do {
         data_type_name_len += data_types[type_idxs[t_idx]].name.size;
      } while(++t_idx < type_cnt);

      data_type_name_len += strlen(c_cont_postfixes[c_cont_rust_struct]) - 1;
   }

   // - compose name of type -
   string_s real_name;
   real_name.init();
   real_name.create(data_type_name_len);

   {
      unsigned t_idx = 0;
      char *dtn_ptr = real_name.data;
      do {
         data_type_s &type = data_types[type_idxs[t_idx]];
         memcpy(dtn_ptr,type.name.data,type.name.size - 1);
         dtn_ptr += type.name.size - 1;
         *dtn_ptr++ = '_';
      } while(++t_idx < type_cnt);

      memcpy(--dtn_ptr,c_cont_postfixes[c_cont_rust_struct],strlen(c_cont_postfixes[c_cont_rust_struct]));
   }

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   // - create abbreviation for new data type -
   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      // - do not report duplicate structures -
      //unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      //if (d_idx != c_idx_not_exist) {
      //   fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      //}

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_rust_struct;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      // - retrieve of types pointers -
      {
         unsigned tn_idx = 0;
         do {
            types[tn_idx] = &data_types[type_idxs[tn_idx]];
         } while(++tn_idx < type_cnt);
      }

      bool dynamic = false;
      bool flushable = false;

      data_type_s **t_pptr = types;
      data_type_s **t_pptr_end = types + type_cnt;
      do {
         if ((*t_pptr)->properties & c_type_dynamic) {
            dynamic = true;
            break;
         }
      } while(++t_pptr < t_pptr_end);

      t_pptr = types;
      do {
         if ((*t_pptr)->properties & c_type_flushable) {
            flushable = true;
            break;
         }
      } while(++t_pptr < t_pptr_end);

      data_type.properties =
        (dynamic ? c_type_dynamic : c_type_static) |
        (flushable ? c_type_flushable : 0);

      data_type.properties |= type_settings & c_type_option_mask;

      {
         string_array_s &dt_type_names = data_type.types;
         string_s *tn_ptr = type_names.data;
         string_s *tn_ptr_end = type_names.data + type_cnt;

         do {
            dt_type_names.push(*tn_ptr);
         } while(++tn_ptr < tn_ptr_end);
      }

      data_type.variables.swap(variables);

      data_type_idx = data_types.used - 1;
   }
   else {
      fprintf(stderr,"struct: name of generated structure \"%s\" is already used\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"struct: abreviated name \"%s\" for generated structure is already used\n",abb.data);
            cassert(0);
         }

         abbreviations.push_blank();
         abbreviations.last().set(abb,data_type_idx);
      } while(++idx < abbs.used);
   }

   data_type_s &data_type = data_types[data_type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of structure struct -

fprintf(out_file,
"// --- struct %s definition --- \n"
"\n"
,STRUCT_NAME);

    unsigned idx = 0;
    while(++idx < abbs.used) {
fprintf(out_file,
"type %s = %s;\n"
,abbs[idx].data,abbs[0].data);
    }
fprintf(out_file,
"\n"
);

fprintf(out_file,
"#[repr(C)] pub struct %s\n"
"{\n"
,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"  %s:%s,\n"
,VAR_NAMES(t_idx),TYPE_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"}\n"
"\n"
);
//   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
//fprintf(out_file,
//"static inline void %s_init(%s *this);\n"
//,STRUCT_NAME,STRUCT_NAME);
//   }
//   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
//fprintf(out_file,
//"static inline void %s_clear(%s *this);\n"
//,STRUCT_NAME,STRUCT_NAME);
//   }
//fprintf(out_file,
//"static inline void %s_set(%s *this,"
//,STRUCT_NAME,STRUCT_NAME);
//   if (TYPE_NUMBERS(0) & c_type_basic) {
//fprintf(out_file,
//"%s a_%s"
//,TYPE_NAMES(0),VAR_NAMES(0));
//   }
//   else {
//fprintf(out_file,
//"const %s *a_%s"
//,TYPE_NAMES(0),VAR_NAMES(0));
//   }
//   if (TYPE_CNT > 1) {
//      unsigned t_idx = 1;
//      do {
//         if (TYPE_NUMBERS(t_idx) & c_type_basic) {
//fprintf(out_file,
//",%s a_%s"
//,TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
//         }
//         else {
//fprintf(out_file,
//",const %s *a_%s"
//,TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
//         }
//      } while(++t_idx < TYPE_CNT);
//   }
//fprintf(out_file,
//");\n"
//"static inline void %s_flush_all(%s *this);\n"
//,STRUCT_NAME,STRUCT_NAME);
//   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
//fprintf(out_file,
//"static inline void %s_swap(%s *this,%s *a_second);\n"
//,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
//   }
//   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
//fprintf(out_file,
//"static inline void %s_copy(%s *this,const %s *a_src);\n"
//,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
//   }
//fprintf(out_file,
//"static inline int %s_compare(const %s *this,const %s *a_second);\n"
//,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
//fprintf(out_file,
//"#if OPTION_TO_STRING == ENABLED\n"
//"static inline void %s___to_string(const %s *this,bc_array_s *a_trg);\n"
//"#define %s_to_string %s___to_string\n"
//"static inline void %s_to_string_separator(const %s *this,bc_array_s *a_trg,unsigned a_count,const char *a_data);\n"
//"#endif\n"
//,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
//   if (STRUCT_NUMBER & (c_type_option_to_json | c_type_option_to_json_nice)) {
//fprintf(out_file,
//"#if OPTION_TO_JSON == ENABLED\n"
//);
//      if (STRUCT_NUMBER & c_type_option_to_json) {
//fprintf(out_file,
//"static inline void %s_to_json(const %s *this,bc_array_s *a_trg);\n"
//,STRUCT_NAME,STRUCT_NAME);
//      }
//      if (STRUCT_NUMBER & c_type_option_to_json_nice) {
//fprintf(out_file,
//"static inline void %s_to_json_nice(const %s *this,json_nice_s *a_json_nice,bc_array_s *a_trg);\n"
//,STRUCT_NAME,STRUCT_NAME);
//      }
//fprintf(out_file,
//"#endif\n"
//);
//   }
//   if (STRUCT_NUMBER & c_type_option_from_var) {
//fprintf(out_file,
//"#if OPTION_FROM_VAR == ENABLED\n"
//"WUR static inline int %s_from_var(%s *this,var_s a_var);\n"
//"#endif\n"
//,STRUCT_NAME,STRUCT_NAME);
//   }
//   if (STRUCT_NUMBER & c_type_option_from_json) {
//fprintf(out_file,
//"#if OPTION_FROM_JSON == ENABLED\n"
//"WUR static inline int %s_from_json(%s *this,const bc_array_s *a_src,from_json_s *a_from_json);\n"
//"#endif\n"
//,STRUCT_NAME,STRUCT_NAME);
//   }
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
fprintf(out_file,
"%s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
fprintf(out_file,
"\n"
);
   }
}/*}}}*/

void processor_s::generate_rust_struct_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"struct: inlines: too many contained types, max 256 supported\n");
      cassert(0);
   }
#else
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];
#endif

   {
      unsigned tn_idx = 0;
      do {
         string_s &type_abb_string = data_type.types[tn_idx];
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"struct: inlines: abbreviated type name \"%s\" does not exist\n",type_abb_string.data);
            cassert(0);
         }

         type_idxs[tn_idx] = abbreviations[type_abb_idx].data_type_idx;
         types[tn_idx] = &data_types[type_idxs[tn_idx]];

      } while(++tn_idx < type_cnt);
   }

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of inline methods -

fprintf(out_file,
"// --- struct %s inline method definition ---\n"
"\n"
"impl %s {\n"
"\n"
"fn new() -> Self\n"
"{/*{{{*/\n"
"  <Self as Cont>::default()\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);

   // - struct init method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
RUST_STRUCT_INIT(RUST_STRUCT_GEN_VALUES);
   }

   // - struct clear method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
RUST_STRUCT_CLEAR(RUST_STRUCT_GEN_VALUES);
   }

   // - struct set method -
RUST_STRUCT_SET(RUST_STRUCT_GEN_VALUES);

   // - struct flush_all method  -
RUST_STRUCT_FLUSH_ALL(RUST_STRUCT_GEN_VALUES);

   // - struct swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
RUST_STRUCT_SWAP(RUST_STRUCT_GEN_VALUES);
   }

   // - struct operator= method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
RUST_STRUCT_OPERATOR_EQUAL(RUST_STRUCT_GEN_VALUES);
   }

   // - struct operator== method -
RUST_STRUCT_OPERATOR_DOUBLE_EQUAL(RUST_STRUCT_GEN_VALUES);

   // - struct to_string_separator method -
RUST_STRUCT_TO_STRING_SEPARATOR(RUST_STRUCT_GEN_VALUES);

//   // - struct from_var method -
//   if (STRUCT_NUMBER & c_type_option_from_var) {
//RUST_STRUCT_FROM_VAR(RUST_STRUCT_GEN_VALUES);
//   }
//
//   // - struct from_json method -
//   if (STRUCT_NUMBER & c_type_option_from_json) {
//RUST_STRUCT_FROM_JSON(RUST_STRUCT_GEN_VALUES);
//   }

fprintf(out_file,
"}\n"
"\n"
"impl Cont for %s\n"
"{\n"
"\n"
"fn default() -> Self\n"
"{/*{{{*/\n"
"  %s{\n"
,STRUCT_NAME,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"    %s:<%s as Cont>::default(),\n"
,VAR_NAMES(t_idx),TYPE_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"  }\n"
"}/*}}}*/\n"
"\n"
);

   // - struct to_string method -
RUST_STRUCT_TO_STRING(RUST_STRUCT_GEN_VALUES);

   // - struct to_json method -
   if (STRUCT_NUMBER & c_type_option_to_json) {
RUST_STRUCT_TO_JSON(RUST_STRUCT_GEN_VALUES);
   }

   // - struct to_json_nice method -
   if (STRUCT_NUMBER & c_type_option_to_json_nice) {
RUST_STRUCT_TO_JSON_NICE(RUST_STRUCT_GEN_VALUES);
   }

fprintf(out_file,
"}\n"
"\n");
   }
}/*}}}*/

void processor_s::generate_rust_struct_methods(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;

   {
      unsigned tn_idx = 0;
      do {
         string_s &type_abb_string = data_type.types[tn_idx];
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"struct: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
            cassert(0);
         }

      } while(++tn_idx < type_cnt);
   }

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of methods -

fprintf(out_file,
"// --- struct %s method definition ---\n"
"\n"
"impl %s {\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);

   // - struct init method -

   // - struct clear method -

   // - struct set method -

   // - struct flush_all method  -

   // - struct swap method -

   // - struct operator= method -

   // - struct operator== method -

   // - struct to_string method -

   // - struct to_string_separator method -

   // - struct to_json method -

   // - struct to_json_nice method -

   // - struct from_var method -

   // - struct from_json method -

fprintf(out_file,
"}\n"
"\n"
"impl Drop for %s\n"
"{\n"
"  fn drop(&mut self) {\n"
"    self.clear();\n"
"  }\n"
"}\n"
"\n"
,STRUCT_NAME);
   }
}/*}}}*/

