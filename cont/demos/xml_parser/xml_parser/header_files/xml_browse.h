
#ifndef __XML_BROWSE_H
#define __XML_BROWSE_H

@begin
include "xml_parser.h"
@end

#define NODE_IDX_TEST

// - forward declaration of br_element_s -
typedef class br_element_s br_element_s;

/*
 * definition of generated structures
 */

// -- br_attribute_s --
@begin
   struct
   <
   pointer:xml_parser
   unsigned:attribute_idx
   >

   not_generate: operator=
   additions
{
  inline const char *name();
  inline const char *value();
  inline bool valid();

  inline br_attribute_s &operator=(br_attribute_s src);

  inline br_element_s parent();
  inline br_attribute_s prev();
  inline br_attribute_s next();
}

   br_attribute_s;
@end

// -- br_element_s --
@begin
   struct
   <
   pointer:xml_parser
   unsigned:element_idx
   >

   not_generate: operator=
   additions
{
  inline const char *name();
  inline bool valid();

  inline br_element_s &operator=(br_element_s src);

  inline static br_element_s root(xml_parser_s &xml);

  inline unsigned elm_cnt();
  inline br_element_s elm(unsigned a_idx);

  inline br_element_s elm_first();
  inline br_element_s elm_last();

  unsigned __attr_by_name(unsigned a_name_idx);

  inline unsigned attr_cnt();
  inline br_attribute_s attr(unsigned a_idx);
  inline br_attribute_s attr_by_name(unsigned a_name_idx);
  inline br_attribute_s attr_by_name(unsigned a_length,const char *a_data);
  inline br_attribute_s attr_by_name(const char *a_data);

  inline br_attribute_s attr_first();
  inline br_attribute_s attr_last();

  inline unsigned data_cnt();
  inline const char *data();
  inline const char *data(unsigned a_idx);

  inline br_element_s parent();
  inline br_element_s prev();
  inline br_element_s next();
}

br_element_s;
@end

/*
 * inline methods of generated structures
 */

// -- br_attribute_s --
@begin
   inlines br_attribute_s
@end

#ifndef NODE_IDX_TEST
#define ATTRIBUTE_IDX_TEST_RET_ATTRIBUTE()
#else
#define ATTRIBUTE_IDX_TEST_RET_ATTRIBUTE() \
{/*{{{*/\
\
  /* - if attribute is not valid - */\
  if (attribute_idx >= xml.attributes.used)\
  {\
    ret.attribute_idx = c_idx_not_exist;\
\
    return ret;\
  }\
}/*}}}*/
#endif

#ifndef NODE_IDX_TEST
#define ATTRIBUTE_IDX_TEST_RET_ELEMENT()
#else
#define ATTRIBUTE_IDX_TEST_RET_ELEMENT() \
{/*{{{*/\
\
  /* - if attribute is not valid - */\
  if (attribute_idx >= xml.attributes.used)\
  {\
    ret.element_idx = c_idx_not_exist;\
\
    return ret;\
  }\
}/*}}}*/
#endif

inline const char *br_attribute_s::name()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  if (attribute_idx >= xml.attributes.used)
  {
    return NULL;
  }

  return xml.name_tree[xml.attributes[attribute_idx].name_idx].data;
}/*}}}*/

inline const char *br_attribute_s::value()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  if (attribute_idx >= xml.attributes.used)
  {
    return NULL;
  }

  return xml.data_array[xml.attributes[attribute_idx].value_idx].data;
}/*}}}*/

inline bool br_attribute_s::valid()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  return attribute_idx < xml.attributes.used;
}/*}}}*/

inline br_attribute_s &br_attribute_s::operator=(br_attribute_s src)
{/*{{{*/
   xml_parser = src.xml_parser;
   attribute_idx = src.attribute_idx;

   return *this;
}/*}}}*/

inline br_element_s br_attribute_s::parent()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_element_s ret;
  ret.xml_parser = xml_parser;

  ATTRIBUTE_IDX_TEST_RET_ELEMENT();

  ret.element_idx = xml.attributes[attribute_idx].parent_idx;

  return ret;
}/*}}}*/

inline br_attribute_s br_attribute_s::prev()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_attribute_s ret;
  ret.xml_parser = xml_parser;

  ATTRIBUTE_IDX_TEST_RET_ATTRIBUTE();

  ret.attribute_idx = xml.attributes[attribute_idx].prev_idx;

  return ret;
}/*}}}*/

inline br_attribute_s br_attribute_s::next()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_attribute_s ret;
  ret.xml_parser = xml_parser;

  ATTRIBUTE_IDX_TEST_RET_ATTRIBUTE();

  ret.attribute_idx = xml.attributes[attribute_idx].next_idx;

  return ret;
}/*}}}*/

// -- br_element_s --
@begin
   inlines br_element_s
@end

#ifndef NODE_IDX_TEST
#define ELEMENT_IDX_TEST_RET_ELEMENT()
#else
#define ELEMENT_IDX_TEST_RET_ELEMENT() \
{/*{{{*/\
\
  /* - if element is not valid - */\
  if (element_idx >= xml.elements.used)\
  {\
    ret.element_idx = c_idx_not_exist;\
  \
    return ret;\
  }\
}/*}}}*/
#endif

#ifndef NODE_IDX_TEST
#define ELEMENT_IDX_TEST_RET_ATTRIBUTE()
#else
#define ELEMENT_IDX_TEST_RET_ATTRIBUTE() \
{/*{{{*/\
\
  /* - if element is not valid - */\
  if (element_idx >= xml.elements.used)\
  {\
    ret.attribute_idx = c_idx_not_exist;\
\
    return ret;\
  }\
}/*}}}*/
#endif

inline const char *br_element_s::name()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  if (element_idx >= xml.elements.used)
  {
    return NULL;
  }

  return xml.name_tree[xml.elements[element_idx].name_idx].data;
}/*}}}*/

inline bool br_element_s::valid()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  return element_idx < xml.elements.used;
}/*}}}*/

inline br_element_s &br_element_s::operator=(br_element_s src)
{/*{{{*/
   xml_parser = src.xml_parser;
   element_idx = src.element_idx;

   return *this;
}/*}}}*/

inline br_element_s br_element_s::root(xml_parser_s &xml)
{/*{{{*/
  br_element_s ret;
  ret.xml_parser = &xml;

  if (xml.elements.used == 0)
  {
    ret.element_idx = c_idx_not_exist;

    return ret;
  }

  ret.element_idx = 0;

  return ret;
}/*}}}*/

inline unsigned br_element_s::elm_cnt()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);
  
  // - if element is not valid -
  if (element_idx >= xml.elements.used)
  {
    return 0;
  }

  return xml.elements[element_idx].element_idxs.used;
}/*}}}*/

inline br_element_s br_element_s::elm(unsigned a_idx)
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_element_s ret;
  ret.xml_parser = xml_parser;

  ELEMENT_IDX_TEST_RET_ELEMENT();

  // - if there is no requested element -
  ui_array_s &element_idxs = xml.elements[element_idx].element_idxs;
  if (a_idx >= element_idxs.used)
  {
    ret.element_idx = c_idx_not_exist;

    return ret;
  }

  ret.element_idx = element_idxs[a_idx];

  return ret;
}/*}}}*/

inline br_element_s br_element_s::elm_first()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_element_s ret;
  ret.xml_parser = xml_parser;

  ELEMENT_IDX_TEST_RET_ELEMENT();

  element_s &element = xml.elements[element_idx];
  if (element.element_idxs.used == 0)
  {
    ret.element_idx = c_idx_not_exist;

    return ret;
  }

  ret.element_idx = element.element_idxs[0];

  return ret;
}/*}}}*/

inline br_element_s br_element_s::elm_last()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_element_s ret;
  ret.xml_parser = xml_parser;

  ELEMENT_IDX_TEST_RET_ELEMENT();

  element_s &element = xml.elements[element_idx];
  if (element.element_idxs.used == 0)
  {
    ret.element_idx = c_idx_not_exist;

    return ret;
  }

  ret.element_idx = element.element_idxs.last();

  return ret;
}/*}}}*/

inline unsigned br_element_s::attr_cnt()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);
  
  // - if element is not valid -
  if (element_idx >= xml.elements.used)
  {
    return 0;
  }

  return xml.elements[element_idx].attribute_idxs.used;
}/*}}}*/

inline br_attribute_s br_element_s::attr(unsigned a_idx)
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_attribute_s ret;
  ret.xml_parser = xml_parser;

  ELEMENT_IDX_TEST_RET_ATTRIBUTE();

  // - if there is no requested attribute -
  ui_array_s &attribute_idxs = xml.elements[element_idx].attribute_idxs;
  if (a_idx >= attribute_idxs.used)
  {
    ret.attribute_idx = c_idx_not_exist;

    return ret;
  }

  ret.attribute_idx = attribute_idxs[a_idx];

  return ret;
}/*}}}*/

inline br_attribute_s br_element_s::attr_by_name(unsigned a_name_idx)
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_attribute_s ret;
  ret.xml_parser = xml_parser;

  ELEMENT_IDX_TEST_RET_ATTRIBUTE();

  // - if attribute name exist -
  if (a_name_idx >= xml.name_tree.used)
  {
    ret.attribute_idx = c_idx_not_exist;

    return ret;
  }

  ret.attribute_idx = __attr_by_name(a_name_idx);

  return ret;
}/*}}}*/

inline br_attribute_s br_element_s::attr_by_name(unsigned a_length,const char *a_data)
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_attribute_s ret;
  ret.xml_parser = xml_parser;

  ELEMENT_IDX_TEST_RET_ATTRIBUTE();

  unsigned name_idx = xml.name_tree.get_idx_char_ptr(a_length,a_data);
  if (name_idx == c_idx_not_exist)
  {
    ret.attribute_idx = c_idx_not_exist;

    return ret;
  }

  ret.attribute_idx = __attr_by_name(name_idx);

  return ret;
}/*}}}*/

inline br_attribute_s br_element_s::attr_by_name(const char *a_data)
{/*{{{*/
  return attr_by_name(strlen(a_data),a_data);  
}/*}}}*/

inline br_attribute_s br_element_s::attr_first()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_attribute_s ret;
  ret.xml_parser = xml_parser;

  ELEMENT_IDX_TEST_RET_ATTRIBUTE();

  element_s &element = xml.elements[element_idx];
  if (element.attribute_idxs.used == 0)
  {
    ret.attribute_idx = c_idx_not_exist;

    return ret;
  }

  ret.attribute_idx = element.attribute_idxs[0];

  return ret;
}/*}}}*/

inline br_attribute_s br_element_s::attr_last()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_attribute_s ret;
  ret.xml_parser = xml_parser;

  ELEMENT_IDX_TEST_RET_ATTRIBUTE();

  element_s &element = xml.elements[element_idx];
  if (element.attribute_idxs.used == 0)
  {
    ret.attribute_idx = c_idx_not_exist;

    return ret;
  }

  ret.attribute_idx = element.attribute_idxs.last();

  return ret;
}/*}}}*/

inline unsigned br_element_s::data_cnt()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);
  
  // - if element is not valid -
  if (element_idx >= xml.elements.used)
  {
    return 0;
  }

  return xml.elements[element_idx].data_idxs.used;
}/*}}}*/

inline const char *br_element_s::data()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);
  
  // - if element is not valid -
  if (element_idx >= xml.elements.used)
  {
    return NULL;
  }

  // - if there are no any data -
  ui_array_s &data_idxs = xml.elements[element_idx].data_idxs;
  if (data_idxs.used == 0)
  {
    return NULL;
  }

  return xml.data_array[data_idxs[0]].data;
}/*}}}*/

inline const char *br_element_s::data(unsigned a_idx)
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);
  
  // - if element is not valid -
  if (element_idx >= xml.elements.used)
  {
    return NULL;
  }

  // - if there are no requested data -
  ui_array_s &data_idxs = xml.elements[element_idx].data_idxs;
  if (a_idx >= data_idxs.used)
  {
    return NULL;
  }

  return xml.data_array[data_idxs[a_idx]].data;
}/*}}}*/

inline br_element_s br_element_s::parent()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_element_s ret;
  ret.xml_parser = xml_parser;

  ELEMENT_IDX_TEST_RET_ELEMENT();

  ret.element_idx = xml.elements[element_idx].parent_idx;

  return ret;
}/*}}}*/

inline br_element_s br_element_s::prev()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_element_s ret;
  ret.xml_parser = xml_parser;

  ELEMENT_IDX_TEST_RET_ELEMENT();

  ret.element_idx = xml.elements[element_idx].prev_idx;

  return ret;
}/*}}}*/

inline br_element_s br_element_s::next()
{/*{{{*/
  xml_parser_s &xml = *((xml_parser_s *)xml_parser);

  br_element_s ret;
  ret.xml_parser = xml_parser;

  ELEMENT_IDX_TEST_RET_ELEMENT();

  ret.element_idx = xml.elements[element_idx].next_idx;

  return ret;
}/*}}}*/

#endif

