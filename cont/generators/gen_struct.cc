
#define STRUCT_GEN_PARAMS abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_cnt,data_type_s &data_type,data_type_s **types
#define STRUCT_GEN_VALUES abbreviations,abb_idx,type_cnt,data_type,types

void STRUCT_INIT(STRUCT_GEN_PARAMS)
{/*{{{*/
printf(
"static inline void %s_init(%s *this)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   unsigned t_idx = 0;
   do {
      if (TYPE_NUMBERS(t_idx) & c_type_dynamic) {
printf(
"   %s_init(&this->%s);\n"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
printf(
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_CLEAR(STRUCT_GEN_PARAMS)
{/*{{{*/
printf(
"static inline void %s_clear(%s *this)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   unsigned t_idx = 0;
   do {
      if (TYPE_NUMBERS(t_idx) & c_type_dynamic) {
printf(
"   %s_clear(&this->%s);\n"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
printf(
"\n"
"   %s_init(this);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void STRUCT_SET(STRUCT_GEN_PARAMS)
{/*{{{*/
printf(
"static inline void %s_set(%s *this,"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_basic) {
printf(
"%s a_%s"
,IM_TYPE_NAMES(0),VAR_NAMES(0));
   }
   else {
printf(
"%s *a_%s"
,IM_TYPE_NAMES(0),VAR_NAMES(0));
   }
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
         if (TYPE_NUMBERS(t_idx) & c_type_basic) {
printf(
",%s a_%s"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
         }
         else {
printf(
",%s *a_%s"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
         }
      } while(++t_idx < TYPE_CNT);
   }
printf(
")\n"
"{/*{{{*/\n"
);
   unsigned t_idx = 0;
   do {
       if (TYPE_NUMBERS(t_idx) & c_type_basic) {
printf(
"   this->%s = a_%s;\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
       }
       else {
printf(
"   %s_copy(&this->%s,a_%s);\n"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx));
       }
   } while(++t_idx < TYPE_CNT);
printf(
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_FLUSH_ALL(STRUCT_GEN_PARAMS)
{/*{{{*/
printf(
"static inline void %s_flush_all(%s *this)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   unsigned t_idx = 0;
   do {
      if (TYPE_NUMBERS(t_idx) & c_type_flushable) {
printf(
"   %s_flush_all(&this->%s);\n"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
printf(
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_SWAP(STRUCT_GEN_PARAMS)
{/*{{{*/
printf(
"static inline void %s_swap(%s *this,%s *a_second)\n"
"{/*{{{*/"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   unsigned t_idx = 0;
   do {
printf(
"\n"
);
      if (TYPE_NUMBERS(t_idx) & c_type_basic) {
printf(
"   %s tmp_%s = this->%s;\n"
"   this->%s = a_second->%s;\n"
"   a_second->%s = tmp_%s;\n"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      }
      else {
printf(
"   %s_swap(&this->%s,&a_second->%s);\n"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
printf(
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_OPERATOR_EQUAL(STRUCT_GEN_PARAMS)
{/*{{{*/
printf(
"static inline void %s_copy(%s *this,%s *a_src)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   unsigned t_idx = 0;
   do {
       if (TYPE_NUMBERS(t_idx) & c_type_basic) {
printf(
"   this->%s = a_src->%s;\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
       }
       else {
printf(
"   %s_copy(&this->%s,&a_src->%s);\n"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx));
       }
   } while(++t_idx < TYPE_CNT);
printf(
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_OPERATOR_DOUBLE_EQUAL(STRUCT_GEN_PARAMS)
{/*{{{*/
printf(
"static inline int %s_compare(%s *this,%s *a_second)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_basic) {
printf(
"   return (this->%s == a_second->%s"
,VAR_NAMES(0),VAR_NAMES(0));
   }
   else {
printf(
"   return (%s_compare(&this->%s,&a_second->%s)"
,IM_TYPE_NAMES(0),VAR_NAMES(0),VAR_NAMES(0));
   }
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
   if (TYPE_NUMBERS(t_idx) & c_type_basic) {
printf(
" && this->%s == a_second->%s"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
   }
   else {
printf(
" && %s_compare(&this->%s,&a_second->%s)"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx));
   }
      } while(++t_idx < TYPE_CNT);
   }
printf(
");\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_TO_STRING(STRUCT_GEN_PARAMS)
{/*{{{*/
printf(
"#if OPTION_TO_STRING == ENABLED\n"
"static inline void %s_to_string(%s *this,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
printf(
"   bc_array_s_push(a_trg,'{');\n"
"   %s_to_string(&this->%s,a_trg);\n"
,IM_TYPE_NAMES(0),VAR_NAMES(0));
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
printf(
"   bc_array_s_push(a_trg,',');\n"
"   %s_to_string(&this->%s,a_trg);\n"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
      } while(++t_idx < TYPE_CNT);
   }
printf(
"   bc_array_s_push(a_trg,'}');\n"
);
printf(
"}/*}}}*/\n"
"#endif\n"
"\n"
);
}/*}}}*/

void processor_s::generate_struct_type()
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
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];

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
            cassert(type.properties & c_type_dynamic);
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

      data_type_name_len += strlen(c_cont_postfixes[c_cont_struct]) - 1;
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

      memcpy(--dtn_ptr,c_cont_postfixes[c_cont_struct],strlen(c_cont_postfixes[c_cont_struct]));
   }

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   // - create abbreviation for new data type -
   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      if (d_idx != c_idx_not_exist) {
         fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      }

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_struct;
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

   // - definition of structure struct -

printf(
"// structure %s definition\n"
"\n"
,STRUCT_NAME);

    unsigned idx = 0;
    do {
printf(
"typedef struct %s %s;\n"
,abbs[0].data,abbs[idx].data);
    } while(++idx < abbs.used);
printf(
"\n"
);

printf(
"struct %s\n"
"{\n"
,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
printf(
"   %s %s; //!< member - %u\n"
,TYPE_NAMES(t_idx),VAR_NAMES(t_idx),t_idx);
   } while(++t_idx < TYPE_CNT);
printf(
"};\n"
"\n"
);
   if (!(data_type.properties & c_type_option_nogen_init)) {
printf(
"static inline void %s_init(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(data_type.properties & c_type_option_nogen_clear)) {
printf(
"static inline void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
printf(
"static inline void %s_set(%s *this,"
,STRUCT_NAME,STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_basic) {
printf(
"%s a_%s"
,TYPE_NAMES(0),VAR_NAMES(0));
   }
   else {
printf(
"%s *a_%s"
,TYPE_NAMES(0),VAR_NAMES(0));
   }
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
         if (TYPE_NUMBERS(t_idx) & c_type_basic) {
printf(
",%s a_%s"
,TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
         }
         else {
printf(
",%s *a_%s"
,TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
         }
      } while(++t_idx < TYPE_CNT);
   }
printf(
");\n"
"static inline void %s_flush_all(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(data_type.properties & c_type_option_nogen_swap)) {
printf(
"static inline void %s_swap(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(data_type.properties & c_type_option_nogen_copy)) {
printf(
"static inline void %s_copy(%s *this,%s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
printf(
"static inline int %s_compare(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
printf(
"#if OPTION_TO_STRING == ENABLED\n"
"static inline void %s_to_string(%s *this,bc_array_s *a_trg);\n"
"#endif\n"
,STRUCT_NAME,STRUCT_NAME);
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
printf(
"%s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
printf(
"\n"
);
}/*}}}*/

void processor_s::generate_struct_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];

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

   // - definition of inline methods -

printf(
"// --- struct %s inline method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - struct init method -
   if (!(data_type.properties & c_type_option_nogen_init)) {
STRUCT_INIT(STRUCT_GEN_VALUES);
   }

   // - struct clear method -
   if (!(data_type.properties & c_type_option_nogen_clear)) {
STRUCT_CLEAR(STRUCT_GEN_VALUES);
   }

   // - struct set method -
STRUCT_SET(STRUCT_GEN_VALUES);

   // - struct flush_all method  -
STRUCT_FLUSH_ALL(STRUCT_GEN_VALUES);

   // - struct swap method -
   if (!(data_type.properties & c_type_option_nogen_swap)) {
STRUCT_SWAP(STRUCT_GEN_VALUES);
   }

   // - struct operator= method -
   if (!(data_type.properties & c_type_option_nogen_copy)) {
STRUCT_OPERATOR_EQUAL(STRUCT_GEN_VALUES);
   }

   // - struct operator== method -
STRUCT_OPERATOR_DOUBLE_EQUAL(STRUCT_GEN_VALUES);

   // - struct to_string method -
STRUCT_TO_STRING(STRUCT_GEN_VALUES);

}/*}}}*/

void processor_s::generate_struct_methods(unsigned abb_idx,unsigned a_dt_idx)
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

   // - definition of methods -

printf(
"// --- struct %s method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - struct init method -

   // - struct clear method -

   // - struct set method -

   // - struct flush_all method  -

   // - struct swap method -

   // - struct operator= method -

   // - struct operator== method -

   // - struct to_string method -

}/*}}}*/

