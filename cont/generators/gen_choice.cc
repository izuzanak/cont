
#define CHOICE_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_cnt,data_type_s &data_type,data_type_s **types
#define CHOICE_GEN_VALUES out_file,abbreviations,abb_idx,type_cnt,data_type,types

void CHOICE_INIT(CHOICE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_init(%s *this)\n"
"{/*{{{*/\n"
"  this->type = c_%s_type_%s;\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,VAR_NAMES(0));
    if (TYPE_NUMBERS(0) & (c_type_dynamic | c_type_option_force_init)) {
fprintf(out_file,
"  %s_init(&this->data.%s);\n"
,TYPE_NAMES(0),VAR_NAMES(0));
    }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void CHOICE_CLEAR(CHOICE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_clear(%s *this)\n"
"{/*{{{*/\n"
,STRUCT_NAME,STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_dynamic) {
fprintf(out_file,
"  switch(this->type)\n"
"  {\n"
);
      unsigned t_idx = 0;
      do {
         if (TYPE_NUMBERS(t_idx) & c_type_dynamic) {
fprintf(out_file,
"    case c_%s_type_%s:\n"
"      %s_clear(&this->data.%s);\n"
"      break;\n"
,STRUCT_NAME,VAR_NAMES(t_idx),TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
         }
      } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"    default:\n"
"      break;\n"
"  }\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void CHOICE_SET(CHOICE_GEN_PARAMS)
{/*{{{*/
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"static inline %s *%s_%s(%s *this)\n"
"{/*{{{*/\n"
"  if (this->type != c_%s_type_%s)\n"
"  {\n"
"    %s_clear(this);\n"
"    this->type = c_%s_type_%s;\n"
,TYPE_NAMES(t_idx),STRUCT_NAME,VAR_NAMES(t_idx),STRUCT_NAME
,STRUCT_NAME,VAR_NAMES(t_idx),STRUCT_NAME
,STRUCT_NAME,VAR_NAMES(t_idx));
      if (TYPE_NUMBERS(t_idx) & (c_type_dynamic | c_type_option_force_init)) {
fprintf(out_file,
"    %s_init(&this->data.%s);\n"
,TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
      }
fprintf(out_file,
"  }\n"
"\n"
"  return &this->data.%s;\n"
"}/*}}}*/\n"
"\n"
,VAR_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
}/*}}}*/

void CHOICE_FLUSH_ALL(CHOICE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_flush_all(%s *this)\n"
"{/*{{{*/\n"
,STRUCT_NAME,STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_flushable) {
fprintf(out_file,
"  switch(this->type)\n"
"  {\n"
);
      unsigned t_idx = 0;
      do {
         if (TYPE_NUMBERS(t_idx) & c_type_flushable) {
fprintf(out_file,
"    case c_%s_type_%s:\n"
"      %s_flush_all(&this->data.%s);\n"
"      break;\n"
,STRUCT_NAME,VAR_NAMES(t_idx),TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
         }
      } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"    default:\n"
"      break;\n"
"  }\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void CHOICE_SWAP(CHOICE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_swap(%s *this,%s *a_second)\n"
"{/*{{{*/\n"
"  %s tmp = *this;\n"
"  *this = *a_second;\n"
"  *a_second = tmp;\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
}/*}}}*/

void CHOICE_OPERATOR_EQUAL(CHOICE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_copy(%s *this,const %s *a_src)\n"
"{/*{{{*/\n"
"  switch (a_src->type)\n"
"  {\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"    case c_%s_type_%s:\n"
,STRUCT_NAME,VAR_NAMES(t_idx));

      if (TYPE_NUMBERS(t_idx) & c_type_basic) {
fprintf(out_file,
"      *%s_%s(this) = a_src->data.%s;\n"
,STRUCT_NAME,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      }
      else {
fprintf(out_file,
"      %s_copy(%s_%s(this),&a_src->data.%s);\n"
,TYPE_NAMES(t_idx),STRUCT_NAME,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      }

fprintf(out_file,
"      break;\n"
);
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"  }\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void CHOICE_OPERATOR_DOUBLE_EQUAL(CHOICE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline int %s_compare(const %s *this,const %s *a_second)\n"
"{/*{{{*/\n"
"  if (this->type != a_second->type)\n"
"  {\n"
"    return 0;\n"
"  }\n"
"\n"
"  switch (this->type)\n"
"  {\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"    case c_%s_type_%s:\n"
,STRUCT_NAME,VAR_NAMES(t_idx));
      if (TYPE_NUMBERS(t_idx) & c_type_basic)
      {
fprintf(out_file,
"      return this->data.%s == a_second->data.%s;\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      }
      else
      {
fprintf(out_file,
"      return %s_compare(&this->data.%s,&a_second->data.%s);\n"
,TYPE_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"    default:\n"
"      return 0;\n"
"  }\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void CHOICE_TO_STRING(CHOICE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_STRING == ENABLED\n"
"static inline void %s___to_string(const %s *this,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"  switch (this->type)\n"
"  {\n"
,STRUCT_NAME,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"    case c_%s_type_%s:\n"
"      bc_array_s_append_ptr(a_trg,\"{%s:\");\n"
"      %s_to_string(&this->data.%s,a_trg);\n"
"      break;\n"
,STRUCT_NAME,VAR_NAMES(t_idx),VAR_NAMES(t_idx),TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"  }\n"
"\n"
"  bc_array_s_push(a_trg,'}');\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
);
}/*}}}*/

void CHOICE_TO_STRING_SEPARATOR(CHOICE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_STRING == ENABLED\n"
"static inline void %s_to_string_separator(const %s *this,bc_array_s *a_trg,unsigned a_count,const char *a_data)\n"
"{/*{{{*/\n"
"  (void)a_count;\n"
"  (void)a_data;\n"
"\n"
"  switch (this->type)\n"
"  {\n"
,STRUCT_NAME,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"    case c_%s_type_%s:\n"
"      bc_array_s_append_ptr(a_trg,\"{%s:\");\n"
"      %s_to_string(&this->data.%s,a_trg);\n"
"      break;\n"
,STRUCT_NAME,VAR_NAMES(t_idx),VAR_NAMES(t_idx),TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"  }\n"
"\n"
"  bc_array_s_push(a_trg,'}');\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
);
}/*}}}*/

void CHOICE_TO_JSON(CHOICE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_JSON == ENABLED\n"
"static inline void %s_to_json(const %s *this,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"  switch (this->type)\n"
"  {\n"
,STRUCT_NAME,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"    case c_%s_type_%s:\n"
"      bc_array_s_append_ptr(a_trg,\"{\\\"%s\\\":\");\n"
"      %s_to_json(&this->data.%s,a_trg);\n"
"      break;\n"
,STRUCT_NAME,VAR_NAMES(t_idx),VAR_NAMES(t_idx),TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"  }\n"
"\n"
"  bc_array_s_push(a_trg,'}');\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
);
}/*}}}*/

void CHOICE_TO_JSON_NICE(CHOICE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_JSON == ENABLED\n"
"static inline void %s_to_json_nice(const %s *this,json_nice_s *a_json_nice,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"  bc_array_s_push(a_trg,'{');\n"
"  json_nice_s_push_indent(a_json_nice,a_trg);\n"
"\n"
"  switch (this->type)\n"
"  {\n"
,STRUCT_NAME,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"    case c_%s_type_%s:\n"
"      bc_array_s_append_ptr(a_trg,\"\\\"%s\\\": \");\n"
"      %s_to_json_nice(&this->data.%s,a_json_nice,a_trg);\n"
"      break;\n"
,STRUCT_NAME,VAR_NAMES(t_idx),VAR_NAMES(t_idx),TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"  }\n"
"\n"
"  json_nice_s_pop_indent(a_json_nice,a_trg);\n"
"  bc_array_s_push(a_trg,'}');\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
);
}/*}}}*/

void CHOICE_FROM_VAR(CHOICE_GEN_PARAMS)
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
"  if (%s_var != NULL)\n"
"  {\n"
"    if (%s_from_var(%s_%s(this),%s_var))\n"
"    {\n"
"      throw_error(FROM_VAR_ERROR);\n"
"    }\n"
"\n"
"    return 0;\n"
"  }\n"
"\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx)
,TYPE_NAMES(t_idx),STRUCT_NAME,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"  throw_error(FROM_VAR_ERROR);\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
);
}/*}}}*/

//void CHOICE_FROM_JSON(CHOICE_GEN_PARAMS)
//{/*{{{*/
//fprintf(out_file,
//"#if OPTION_FROM_JSON == ENABLED\n"
//"static inline int %s_from_json(%s *this,const bc_array_s *a_src,from_json_s *a_from_json)\n"
//"{/*{{{*/\n"
//"  if (from_json_s_get_terminal(a_from_json,a_src,c_json_terminal_lc_br) ||\n"
//,STRUCT_NAME,STRUCT_NAME);
//   unsigned t_idx = 0;
//   do {
//fprintf(out_file,
//"      from_json_s_get_string(a_from_json,a_src) ||\n"
//"      strcmp(a_from_json->buffer.data,\"%s\") ||\n"
//"      from_json_s_get_terminal(a_from_json,a_src,c_json_terminal_colon) ||\n"
//"      %s_from_json(&this->%s,a_src,a_from_json) ||\n"
//"      from_json_s_get_terminal(a_from_json,a_src,%s"
//,VAR_NAMES(t_idx),TYPE_NAMES(t_idx),VAR_NAMES(t_idx)
//,t_idx == TYPE_CNT - 1 ? "c_json_terminal_rc_br))\n" : "c_json_terminal_comma) ||\n"
//);
//   } while(++t_idx < TYPE_CNT);
//fprintf(out_file,
//"  {\n"
//"    throw_error(FROM_JSON_ERROR);\n"
//"  }\n"
//"\n"
//"  return 0;\n"
//"}/*}}}*/\n"
//"#endif\n"
//"\n"
//);
//}/*}}}*/

void processor_s::generate_choice_type()
{/*{{{*/
   string_array_s &type_names = cont_params.types;
   string_array_s &variables = cont_params.variables;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used < 1 || type_names.used != variables.used) {
      fprintf(stderr,"choice: not given name of contained type, or not same count of types and variables\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"choice: not given name of generated structure\n");
      cassert(0);
   }

   unsigned type_cnt = type_names.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"choice: too many contained types, max 256 supported\n");
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
            fprintf(stderr,"choice: contained type \"%s\" does not exist\n",type_names[tn_idx].data);
            cassert(0);
         }

         unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
         type_idxs[tn_idx] = type_idx;

         // - test type options -
         data_type_s &type = data_types[type_idx];
         if (type.properties & c_type_option_strict_dynamic) {
            fprintf(stderr,"choice: option strict_dynamic not supported\n");
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

      data_type_name_len += strlen(c_cont_postfixes[c_cont_choice]) - 1;
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

      memcpy(--dtn_ptr,c_cont_postfixes[c_cont_choice],strlen(c_cont_postfixes[c_cont_choice]));
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

      data_type.cont_idx = c_cont_choice;
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
        (flushable ? c_type_flushable : 0) |
        c_type_option_force_init;

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
      fprintf(stderr,"choice: name of generated structure \"%s\" is already used\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"choice: abreviated name \"%s\" for generated structure is already used\n",abb.data);
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
   // - definition of structure choice -

fprintf(out_file,
"// structure %s definition\n"
"\n"
,STRUCT_NAME);

fprintf(out_file,
"enum\n"
"{\n"
);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"  c_%s_type_%s = %u,\n"
,STRUCT_NAME,VAR_NAMES(t_idx),t_idx);
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"};\n"
"\n"
);

   unsigned idx = 0;
   do {
fprintf(out_file,
"typedef struct %s %s;\n"
,abbs[0].data,abbs[idx].data);
   } while(++idx < abbs.used);
fprintf(out_file,
"\n"
);

fprintf(out_file,
"struct %s\n"
"{\n"
"  unsigned type;\n"
"  union {\n"
,STRUCT_NAME);
   t_idx = 0;
   do {
fprintf(out_file,
"    %s %s;\n"
,TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"  } data;\n"
"};\n"
"\n"
);
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
fprintf(out_file,
"static inline void %s_init(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
fprintf(out_file,
"static inline void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   t_idx = 0;
   do {
fprintf(out_file,
"static inline %s *%s_%s(%s *this);\n"
,TYPE_NAMES(t_idx),STRUCT_NAME,VAR_NAMES(t_idx),STRUCT_NAME);
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"static inline void %s_flush_all(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
fprintf(out_file,
"static inline void %s_swap(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
fprintf(out_file,
"static inline void %s_copy(%s *this,const %s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
fprintf(out_file,
"static inline int %s_compare(const %s *this,const %s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
fprintf(out_file,
"#if OPTION_TO_STRING == ENABLED\n"
"static inline void %s___to_string(const %s *this,bc_array_s *a_trg);\n"
"#define %s_to_string %s___to_string\n"
"static inline void %s_to_string_separator(const %s *this,bc_array_s *a_trg,unsigned a_count,const char *a_data);\n"
"#endif\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (STRUCT_NUMBER & (c_type_option_to_json | c_type_option_to_json_nice)) {
fprintf(out_file,
"#if OPTION_TO_JSON == ENABLED\n"
);
      if (STRUCT_NUMBER & c_type_option_to_json) {
fprintf(out_file,
"static inline void %s_to_json(const %s *this,bc_array_s *a_trg);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
      if (STRUCT_NUMBER & c_type_option_to_json_nice) {
fprintf(out_file,
"static inline void %s_to_json_nice(const %s *this,json_nice_s *a_json_nice,bc_array_s *a_trg);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
fprintf(out_file,
"#endif\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_from_var) {
fprintf(out_file,
"#if OPTION_FROM_VAR == ENABLED\n"
"WUR static inline int %s_from_var(%s *this,var_s a_var);\n"
"#endif\n"
,STRUCT_NAME,STRUCT_NAME);
   }
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

void processor_s::generate_choice_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"choice: inlines: too many contained types, max 256 supported\n");
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
            fprintf(stderr,"choice: inlines: abbreviated type name \"%s\" does not exist\n",type_abb_string.data);
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
"// LCOV_EXCL_START\n"
"\n"
,STRUCT_NAME);

   // - choice init method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
CHOICE_INIT(CHOICE_GEN_VALUES);
   }

   // - choice clear method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
CHOICE_CLEAR(CHOICE_GEN_VALUES);
   }

   // - choice set methods -
CHOICE_SET(CHOICE_GEN_VALUES);

   // - choice flush_all method  -
CHOICE_FLUSH_ALL(CHOICE_GEN_VALUES);

   // - choice swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
CHOICE_SWAP(CHOICE_GEN_VALUES);
   }

   // - choice operator= method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
CHOICE_OPERATOR_EQUAL(CHOICE_GEN_VALUES);
   }

   // - choice operator== method -
CHOICE_OPERATOR_DOUBLE_EQUAL(CHOICE_GEN_VALUES);

   // - choice to_string method -
CHOICE_TO_STRING(CHOICE_GEN_VALUES);

   // - choice to_string_separator method -
CHOICE_TO_STRING_SEPARATOR(CHOICE_GEN_VALUES);

   // - choice to_json method -
   if (STRUCT_NUMBER & c_type_option_to_json) {
CHOICE_TO_JSON(CHOICE_GEN_VALUES);
   }

   // - choice to_json_nice method -
   if (STRUCT_NUMBER & c_type_option_to_json_nice) {
CHOICE_TO_JSON_NICE(CHOICE_GEN_VALUES);
   }

   // - choice from_var method -
   if (STRUCT_NUMBER & c_type_option_from_var) {
CHOICE_FROM_VAR(CHOICE_GEN_VALUES);
   }

//   // - choice from_json method -
//   if (STRUCT_NUMBER & c_type_option_from_json) {
//CHOICE_FROM_JSON(CHOICE_GEN_VALUES);
//   }

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/

void processor_s::generate_choice_methods(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;

   {
      unsigned tn_idx = 0;
      do {
         string_s &type_abb_string = data_type.types[tn_idx];
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"choice: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
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
"// LCOV_EXCL_START\n"
"\n"
,STRUCT_NAME);

   // - choice init method -

   // - choice clear method -

   // - choice set methods -

   // - choice flush_all method  -

   // - choice swap method -

   // - choice operator= method -

   // - choice operator== method -

   // - choice to_string method -

   // - choice to_string_separator method -

   // - choice to_json method -

   // - choice to_json_nice method -

   // - choice from_var method -

   // - choice from_json method -

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/

