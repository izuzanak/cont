
#define QUEUE_INIT() \
{\
printf(\
"inline void %s_init(%s *this)\n"\
"{/*{{{*/\n"\
"   this->size = 0;\n"\
"   this->used = 0;\n"\
"   this->begin = 0;\n"\
"   this->data = NULL;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define QUEUE_INIT_SIZE() \
{\
printf(\
"inline void %s_init_size(%s *this,unsigned a_size)\n"\
"{/*{{{*/\n"\
"   %s_init(this);\n"\
"   %s_copy_resize(this,a_size);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define QUEUE_CLEAR() \
{\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"inline void %s_clear(%s *this)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"void %s_clear(%s *this)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   if (this->data != NULL) {\n"\
);\
   if (TYPE_NUMBER & c_type_dynamic) {\
printf(\
"      %s *ptr = this->data;\n"\
"      %s *ptr_end = ptr + this->size;\n"\
"\n"\
"      do {\n"\
"         %s_clear(ptr);\n"\
"      } while(++ptr < ptr_end);\n"\
"\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"      cfree(this->data);\n"\
"   }\n"\
"\n"\
"   %s_init(this);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define QUEUE_FLUSH() \
{\
printf(\
"inline void %s_flush(%s *this)\n"\
"{/*{{{*/\n"\
"   %s_copy_resize(this,this->used);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define QUEUE_FLUSH_ALL() \
{\
   if (!(TYPE_NUMBER & c_type_flushable)) {\
printf(\
"inline void %s_flush_all(%s *this)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"void %s_flush_all(%s *this)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   %s_copy_resize(this,this->used);\n"\
,IM_STRUCT_NAME);\
   if (TYPE_NUMBER & c_type_flushable) {\
printf(\
"\n"\
"   if (this->used == 0) return;\n"\
"\n"\
"   %s *ptr = this->data;\n"\
"   %s *ptr_end = ptr + this->used;\n"\
"\n"\
"   do {\n"\
"      %s_flush_all(ptr);\n"\
"   } while(++ptr < ptr_end);\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"}/*}}}*/\n"\
"\n"\
);\
}

#define QUEUE_SWAP() \
{\
printf(\
"inline void %s_swap(%s *this,%s *a_second)\n"\
"{/*{{{*/\n"\
"   unsigned tmp_unsigned = this->size;\n"\
"   this->size = a_second->size;\n"\
"   a_second->size = tmp_unsigned;\n"\
"\n"\
"   tmp_unsigned = this->used;\n"\
"   this->used = a_second->used;\n"\
"   a_second->used = tmp_unsigned;\n"\
"\n"\
"   tmp_unsigned = this->begin;\n"\
"   this->begin = a_second->begin;\n"\
"   a_second->begin = tmp_unsigned;\n"\
"\n"\
"   %s *tmp_data = this->data;\n"\
"   this->data = a_second->data;\n"\
"   a_second->data = tmp_data;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
}

#define QUEUE_INSERT() \
{\
   if (TYPE_NUMBER & c_type_basic) {\
printf(\
"inline unsigned %s_insert(%s *this,%s a_value)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
   }\
   else {\
printf(\
"inline unsigned %s_insert(%s *this,%s *a_value)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   if (this->used >= this->size) {\n"\
"      %s_copy_resize(this,(this->size << 1) + c_array_add);\n"\
"   }\n"\
"\n"\
,IM_STRUCT_NAME);\
printf(\
"   if (this->begin + this->used >= this->size) {\n"\
);\
   if (TYPE_NUMBER & c_type_basic) {\
printf(\
"      this->data[this->begin + this->used - this->size] = a_value;\n"\
);\
   }\
   else {\
printf(\
"      %s_copy(this->data + this->begin + this->used - this->size,a_value);\n"\
,TYPE_NAME);\
   }\
printf(\
"   }\n"\
"   else {\n"\
);\
   if (TYPE_NUMBER & c_type_basic) {\
printf(\
"      this->data[this->begin + this->used] = a_value;\n"\
);\
   }\
   else {\
printf(\
"      %s_copy(this->data + this->begin + this->used,a_value);\n"\
,TYPE_NAME);\
   }\
printf(\
"   }\n"\
"\n"\
"   return this->used++;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define QUEUE_INSERT_BLANK() \
{\
printf(\
"inline unsigned %s_insert_blank(%s *this)\n"\
"{/*{{{*/\n"\
"   if (this->used >= this->size) {\n"\
"      %s_copy_resize(this,(this->size << 1) + c_array_add);\n"\
"   }\n"\
"\n"\
"   return this->used++;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define QUEUE_NEXT() \
{\
   if (TYPE_NUMBER & c_type_basic) {\
printf(\
"inline %s %s_next(%s *this)\n"\
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"inline %s *%s_next(%s *this)\n"\
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   debug_assert(this->used > 0);\n"\
"\n"\
"   unsigned ret_idx = this->begin;\n"\
"\n"\
"   if (++this->begin >= this->size) {\n"\
"      this->begin = 0;\n"\
"   }\n"\
"\n"\
"   this->used--;\n"\
"\n"\
);\
   if (TYPE_NUMBER & c_type_basic) {\
printf(\
"   return this->data[ret_idx];\n"\
);\
   }\
   else {\
printf(\
"   return this->data + ret_idx;\n"\
);\
   }\
printf(\
"}/*}}}*/\n"\
"\n"\
);\
}

#define QUEUE_LAST() \
{\
printf(\
"inline %s *%s_last(%s *this)\n"\
"{/*{{{*/\n"\
"   debug_assert(this->used > 0);\n"\
"\n"\
"   unsigned last_idx = this->begin + (this->used - 1);\n"\
"   if (last_idx >= this->size) {\n"\
"      return this->data + last_idx - this->size;\n"\
"   }\n"\
"   else {\n"\
"      return this->data + last_idx;\n"\
"   }\n"\
"}/*}}}*/\n"\
"\n"\
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define QUEUE_COPY_RESIZE() \
{\
printf(\
"void %s_copy_resize(%s *this,unsigned a_size)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_size >= this->used);\n"\
"\n"\
"   %s *n_data;\n"\
"\n"\
"   if (a_size == 0) {\n"\
"      n_data = NULL;\n"\
"   }\n"\
"   else {\n"\
"      n_data = (%s *)cmalloc(a_size*sizeof(%s));\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   if (TYPE_NUMBER & c_type_dynamic) {\
printf(\
"\n"\
"      if (a_size > this->used) {\n"\
"         %s *ptr = n_data + this->used;\n"\
"         %s *ptr_end = n_data + a_size;\n"\
"\n"\
"         do {\n"\
"            %s_init(ptr);\n"\
"         } while(++ptr < ptr_end);\n"\
"      }\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"   }\n"\
"\n"\
"   if (this->used != 0) {\n"\
"      unsigned fir_cnt;\n"\
"      unsigned sec_cnt;\n"\
"\n"\
"      if (this->begin + this->used > this->size) {\n"\
"         sec_cnt = this->begin + this->used - this->size;\n"\
"         fir_cnt = this->used - sec_cnt;\n"\
"      }\n"\
"      else {\n"\
"         fir_cnt = this->used;\n"\
"         sec_cnt = 0;\n"\
"      }\n"\
"\n"\
"      memcpy(n_data,this->data + this->begin,fir_cnt*sizeof(%s));\n"\
"\n"\
"      if (sec_cnt != 0) {\n"\
"         memcpy(n_data + fir_cnt,this->data,sec_cnt*sizeof(%s));\n"\
"      }\n"\
"   }\n"\
"\n"\
,TYPE_NAME,TYPE_NAME);\
   if (TYPE_NUMBER & c_type_dynamic) {\
printf(\
"   if (this->size > this->used) {\n"\
"      %s *ptr;\n"\
"      %s *ptr_end;\n"\
"      %s *s_ptr;\n"\
"\n"\
"      if (this->begin + this->used >= this->size) {\n"\
"         ptr = this->data + (this->begin + this->used - this->size);\n"\
"         ptr_end = this->data + this->begin;\n"\
"         s_ptr = NULL;\n"\
"      }\n"\
"      else {\n"\
"         ptr = this->data;\n"\
"         ptr_end = this->data + this->begin;\n"\
"         s_ptr = ptr_end + this->used;\n"\
"      }\n"\
"\n"\
"      if (ptr < ptr_end) {\n"\
"         do {\n"\
"            %s_clear(ptr);\n"\
"         } while(++ptr < ptr_end);\n"\
"      }\n"\
"\n"\
"      if (s_ptr != NULL) {\n"\
"         %s *s_ptr_end = this->data + this->size;\n"\
"         do {\n"\
"            %s_clear(s_ptr);\n"\
"         } while(++s_ptr < s_ptr_end);\n"\
"      }\n"\
"   }\n"\
"\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"   if (this->size != 0) {\n"\
"      cfree(this->data);\n"\
"   }\n"\
"\n"\
"   this->data = n_data;\n"\
"   this->size = a_size;\n"\
"   this->begin = 0;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define QUEUE_OPERATOR_EQUAL() \
{\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"inline void %s_copy(%s *this,%s *a_src)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"void %s_copy(%s *this,%s *a_src)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   %s_clear(this);\n"\
"\n"\
"   if (a_src->used == 0) return;\n"\
"\n"\
"   %s_copy_resize(this,a_src->used);\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"   unsigned fir_cnt;\n"\
"   unsigned sec_cnt;\n"\
"\n"\
"   if (a_src->begin + a_src->used > a_src->size) {\n"\
"      sec_cnt = a_src->begin + a_src->used - a_src->size;\n"\
"      fir_cnt = a_src->used - sec_cnt;\n"\
"   }\n"\
"   else {\n"\
"      fir_cnt = a_src->used;\n"\
"      sec_cnt = 0;\n"\
"   }\n"\
"\n"\
"   memcpy(this->data,a_src->data + a_src->begin,fir_cnt*sizeof(%s));\n"\
"\n"\
"   if (sec_cnt != 0) {\n"\
"      memcpy(this->data + fir_cnt,a_src->data,sec_cnt*sizeof(%s));\n"\
"   }\n"\
"\n"\
,TYPE_NAME,TYPE_NAME);\
   }\
   else {\
printf(\
"   unsigned sec_cnt;\n"\
"   %s *ptr = this->data;\n"\
"   %s *s_ptr = a_src->data + a_src->begin;\n"\
"   %s *s_ptr_end;\n"\
"\n"\
"   if (a_src->begin + a_src->used > a_src->size) {\n"\
"      s_ptr_end = a_src->data + a_src->size;\n"\
"      sec_cnt = a_src->begin + a_src->used - a_src->size;\n"\
"   }\n"\
"   else {\n"\
"      s_ptr_end = s_ptr + a_src->used;\n"\
"      sec_cnt = 0;\n"\
"   }\n"\
"\n"\
"   do {\n"\
"      %s_copy(ptr,s_ptr); \n"\
"   } while(++ptr,++s_ptr < s_ptr_end);\n"\
"\n"\
"   if (sec_cnt != 0) {\n"\
"      s_ptr = a_src->data;\n"\
"      s_ptr_end = s_ptr + sec_cnt;\n"\
"\n"\
"      do {\n"\
"         %s_copy(ptr,s_ptr);\n"\
"      } while(++ptr,++s_ptr < s_ptr_end);\n"\
"   }\n"\
"\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"   this->used = a_src->used;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define QUEUE_OPERATOR_DOUBLE_EQUAL() \
{\
printf(\
"int %s_compare(%s *this,%s *a_second)\n"\
"{/*{{{*/\n"\
"   if (this->used != a_second->used) return 0;\n"\
"   if (this->used == 0) return 1;\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"   int _break;\n"\
"   int s_break;\n"\
"   unsigned pos;\n"\
"   unsigned pos_end;\n"\
"   unsigned s_pos;\n"\
"\n"\
"   _break = (this->begin + this->used > this->size);\n"\
"   s_break = (a_second->begin + a_second->used > a_second->size);\n"\
"   pos = this->begin;\n"\
"   s_pos = a_second->begin;\n"\
"\n"\
"   if (_break) {\n"\
"      pos_end = this->begin + this->used - this->size;\n"\
"   }\n"\
"   else {\n"\
"      pos_end = this->begin + this->used;\n"\
"   }\n"\
"\n"\
"   do {\n"\
"      if (_break) {\n"\
"         unsigned offset = this->size - pos;\n"\
"\n"\
"         if (s_break) {\n"\
"            unsigned s_offset = a_second->size = s_pos;\n"\
"\n"\
"            if (offset < s_offset) {\n"\
"               if (memcmp(this->data + pos,a_second->data + s_pos,offset*sizeof(%s)) != 0) {\n"\
"                  return 0;\n"\
"               }\n"\
"\n"\
"               s_pos += offset;\n"\
"               pos = 0;\n"\
"               _break = 0;\n"\
"            }\n"\
"            else {\n"\
"               if (memcmp(this->data + pos,a_second->data + s_pos,s_offset*sizeof(%s)) != 0) {\n"\
"                  return 0;\n"\
"               }\n"\
"\n"\
"               if (pos += s_offset >= this->size) {\n"\
"                  pos = 0;\n"\
"                  _break = 0;\n"\
"               }\n"\
"               s_pos = 0;\n"\
"               s_break = 0;\n"\
"            }\n"\
"         }\n"\
"         else {\n"\
"            if (memcmp(this->data + pos,a_second->data + s_pos,offset*sizeof(%s)) != 0) {\n"\
"               return 0;\n"\
"            }\n"\
"            s_pos += offset;\n"\
"            pos = 0;\n"\
"            _break = 0;\n"\
"         }\n"\
"      }\n"\
"      else {\n"\
"         if (s_break) {\n"\
"            unsigned s_offset = a_second->size - s_pos;\n"\
"\n"\
"            if (memcmp(this->data + pos,a_second->data + s_pos,s_offset*sizeof(%s)) != 0) {\n"\
"               return 0;\n"\
"            }\n"\
"            pos += s_offset;\n"\
"            s_pos = 0;\n"\
"            s_break = 0;\n"\
"         }\n"\
"         else {\n"\
"            if (memcmp(this->data + pos,a_second->data + s_pos,(pos_end - pos)*sizeof(%s)) != 0) {\n"\
"               return 0;\n"\
"            }\n"\
"            else {\n"\
"               return 1;\n"\
"            }\n"\
"         }\n"\
"      }\n"\
"   } while(1);\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
   else {\
printf(\
"   %s *ptr = this->data + this->begin;\n"\
"   %s *ptr_break = this->data + this->size;\n"\
"   %s *ptr_end;\n"\
"   %s *s_ptr = a_second->data + a_second->begin;\n"\
"   %s *s_ptr_break = a_second->data + a_second->size;\n"\
"\n"\
"   if (this->begin + this->used > this->size) {\n"\
"      ptr_end = this->data + (this->begin + this->used - this->size);\n"\
"   }\n"\
"   else {\n"\
"      ptr_end = ptr + this->used;\n"\
"   }\n"\
"\n"\
"   do {\n"\
"      if (!%s_compare(ptr,s_ptr)) {\n"\
"         return 0;\n"\
"      }\n"\
"\n"\
"      if (++ptr >= ptr_break) {\n"\
"         ptr = this->data;\n"\
"      }\n"\
"\n"\
"      if (++s_ptr >= s_ptr_break) {\n"\
"         s_ptr = a_second->data;\n"\
"      }\n"\
"\n"\
"   } while(ptr != ptr_end);\n"\
"\n"\
"   return 1;\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"}/*}}}*/\n"\
"\n"\
);\
}

void processor_s::generate_queue_type()
{
   string_array_s &type_names = cont_params.types;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used != 1) {
      fprintf(stderr,"queue: not given name (or too many names) of contained type\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"queue: not given name of generated structures\n");
      cassert(0);
   }

   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_names[0].size - 1,type_names[0].data);
   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"queue: contained type \"%s\" does not exist\n",type_names[0].data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   // - test type options -
   if (type.properties & c_type_setting_strict_dynamic) {
      fprintf(stderr,"queue: container have not implemented processing of types with option strict_dynamic\n");
      cassert(0);
   }

   string_s real_name;
   real_name.init();
   real_name.conc_set(type.name.size - 1,type.name.data,strlen(c_cont_postfixes[c_cont_queue]),(char *)c_cont_postfixes[c_cont_queue]);

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      if (d_idx != c_idx_not_exist) {
         fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      }

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_queue;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      data_type.properties = c_type_dynamic | c_type_flushable  | (type_settings & c_type_setting_mask);
      data_type.types.push(abbreviations[type_abb_idx].name);

      data_type_idx = data_types.used - 1;
   }
   else {
      fprintf(stderr,"queue: name of generated structure \"%s\" already exist\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"queue: abreaviated name \"%s\" for generated structure is already used\n",abb.data);
            cassert(0);
         }

         abbreviations.push_blank();
         abbreviations.last().set(abb,data_type_idx);
      } while(++idx < abbs.used);
   }

   data_type_s &data_type = data_types[data_type_idx];

   // - definition of structure queue -

printf(
"// struct %s definition\n"
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
"   unsigned size; //!< actual size of allocated space (element count)\n"
"   unsigned used; //!< count of stored elements\n"
"   unsigned begin; //!< position of first element\n"
"   %s *data; //!< pointer to queue elements\n"
"};\n"
"\n"
,STRUCT_NAME,TYPE_NAME);
   if (!(data_type.properties & c_type_setting_not_generate_init)) {
printf(
"inline void %s_init(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
printf(
"inline void %s_init_size(%s *this,unsigned a_size);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
printf(
"inline void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
   else {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
printf(
"void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
printf(
"inline void %s_flush(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(TYPE_NUMBER & c_type_flushable)) {
printf(
"inline void %s_flush_all(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   else {
printf(
"void %s_flush_all(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(data_type.properties & c_type_setting_not_generate_swap)) {
printf(
"inline void %s_swap(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
   if (TYPE_NUMBER & c_type_basic) {
printf(
"inline unsigned %s_insert(%s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"inline unsigned %s_insert(%s *this,%s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
printf(
"inline unsigned %s_insert_blank(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"inline %s %s_next(%s *this);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   }
   else {
printf(
"inline %s *%s_next(%s *this);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   }
printf(
"inline %s *%s_last(%s *this);\n"
"void %s_copy_resize(%s *this,unsigned a_size);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(data_type.properties & c_type_setting_not_generate_operator_equal)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"inline void %s_copy(%s *this,%s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
      else {
printf(
"void %s_copy(%s *this,%s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
   }
printf(
"int %s_compare(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
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
};

void processor_s::generate_queue_inlines(unsigned abb_idx,unsigned a_dt_idx)
{
   data_type_s &data_type = data_types[a_dt_idx];
   
   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"queue: inlines: abbeviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   // - definition of inline methods -

printf(
"// --- struct %s inline method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - queue init method -
   if (!(data_type.properties & c_type_setting_not_generate_init)) {
QUEUE_INIT();
   }

   // - queue init_size method -
QUEUE_INIT_SIZE();

   // - queue clear method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
QUEUE_CLEAR();
      }
   }

   // - queue flush method -
QUEUE_FLUSH();

   // - queue flush_all method -
   if (!(TYPE_NUMBER & c_type_flushable)) {
QUEUE_FLUSH_ALL();
   }

   // - queue swap method -
   if (!(data_type.properties & c_type_setting_not_generate_swap)) {
QUEUE_SWAP();
   }

   // - queue insert method -
QUEUE_INSERT();

   // - queue insert_blank method -
QUEUE_INSERT_BLANK();

   // - queue next method -
QUEUE_NEXT();

   // - queue last method -
QUEUE_LAST();

   // - queue copy_resize method -

   // - queue operator= method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_setting_not_generate_operator_equal)) {
QUEUE_OPERATOR_EQUAL();
      }
   }

   // - queue operator== method -
}

void processor_s::generate_queue_methods(unsigned abb_idx,unsigned a_dt_idx)
{
   data_type_s &data_type = data_types[a_dt_idx];
   
   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"queue: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   // - definition of methods -

printf(
"// --- struct %s method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - queue init method -

   // - queue init_size method -

   // - queue clear method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
QUEUE_CLEAR();
      }
   }

   // - queue flush method -

   // - queue flush_all method -
   if (TYPE_NUMBER & c_type_flushable) {
QUEUE_FLUSH_ALL();
   }

   // - queue swap method -

   // - queue insert method -

   // - queue insert_blank method -

   // - queue next method -

   // - queue last method -

   // - queue copy_resize method -
QUEUE_COPY_RESIZE();

   // - queue operator= method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(data_type.properties & c_type_setting_not_generate_operator_equal)) {
QUEUE_OPERATOR_EQUAL();
      }
   }

   // - queue operator== method -
QUEUE_OPERATOR_DOUBLE_EQUAL();
}

