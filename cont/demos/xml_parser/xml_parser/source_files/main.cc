
@begin
   include "main.h"
@end

void DEMO_elements(xml_parser_s &xml)
{/*{{{*/
  br_element_s element = br_element_s::root(xml);

  while (element.valid())
  {
    const char *name = element.name();

    // - print element name -
    printf("<%s></%s>\n",name,name);

    // - get first contained element -
    br_element_s next_elm = element.elm_first();
    if (!next_elm.valid())
    {
      do {

        // - get next element on same level -
        next_elm = element.next();
        if (next_elm.valid())
        {
          break;
        }

        // - get parent -
        element = element.parent();
      } while(element.valid());
    }

    element = next_elm;
  }
}/*}}}*/

void DEMO_attributes(xml_parser_s &xml)
{/*{{{*/
  br_element_s element = br_element_s::root(xml);

  while (element.valid())
  {
    // - print element attributes -
    br_attribute_s attribute = element.attr_first();
    if (attribute.valid())
    {
      const char *name = element.name();

      printf("<%s",name);
      do {
        printf(" %s=\"%s\"",attribute.name(),attribute.value());

        attribute = attribute.next();
      } while(attribute.valid());
      printf("></%s>\n",name);
    }

    // - get first contained element -
    br_element_s next_elm = element.elm_first();
    if (!next_elm.valid())
    {
      do {

        // - get next element on same level -
        next_elm = element.next();
        if (next_elm.valid())
        {
          break;
        }

        // - get parent -
        element = element.parent();
      } while(element.valid());
    }

    element = next_elm;
  }
}/*}}}*/

void DEMO_data(xml_parser_s &xml)
{/*{{{*/
  br_element_s element = br_element_s::root(xml);

  while (element.valid())
  {
    // - get first contained element -
    br_element_s next_elm = element.elm_first();
    if (!next_elm.valid())
    {
      const char *data = element.data();

      // - print element name -
      if (data != NULL)
      {
        const char *name = element.name();
        printf("<%s>%s</%s>\n",name,data,name);
      }

      do {

        // - get next element on same level -
        next_elm = element.next();
        if (next_elm.valid())
        {
          break;
        }

        // - get parent -
        element = element.parent();
      } while(element.valid());
    }

    element = next_elm;
  }
}/*}}}*/

void DEMO_mixed(xml_parser_s &xml,unsigned a_idx)
{/*{{{*/
  element_s &elm = xml.elements[a_idx];
  string_s &name = xml.name_tree[elm.name_idx];

  printf("<%s>",name.data);

  if (elm.cont_types.used != 0)
  {
    unsigned e_idx = 0;
    unsigned d_idx = 0;
    unsigned c_idx = 0;

    do {
      if (elm.cont_types[c_idx] == c_cont_type_element)
      {
        DEMO_mixed(xml,elm.element_idxs[e_idx++]);
      }
      else
      {
        printf("%s",xml.data_array[elm.data_idxs[d_idx++]].data);
      }
    } while(++c_idx < elm.cont_types.used);
  }

  printf("</%s>",name.data);
}/*}}}*/

void DEMO_attr_by_name(xml_parser_s &xml)
{/*{{{*/
  br_element_s element = br_element_s::root(xml);

  while (element.valid())
  {
    br_attribute_s attr = element.attr_by_name("test");
    if (attr.valid())
    {
      printf("attr: %s=%s\n",attr.name(),attr.value());
    }

    // - get first contained element -
    br_element_s next_elm = element.elm_first();
    if (!next_elm.valid())
    {
      do {

        // - get next element on same level -
        next_elm = element.next();
        if (next_elm.valid())
        {
          break;
        }

        // - get parent -
        element = element.parent();
      } while(element.valid());
    }

    element = next_elm;
  }
}/*}}}*/

int main(int argc,char **argv)
{/*{{{*/
  xml_parser_s parser;
  parser.init();

  if (argc > 1)
  {
    string_s source;
    source.init();
    source.load_text_file(argv[1]);

    // - parse xml in memory -
    if (!parser.parse_memory(source.size - 1,source.data))
    {
      parser.process_errors();
    }
    else
    {
    }

    //DEMO_elements(parser);
    //DEMO_attributes(parser);
    unsigned idx = 0;
    do {
      DEMO_data(parser);
    } while(++idx < 1);
    //DEMO_mixed(parser,0);
    //DEMO_attr_by_name(parser);

    source.clear();
  }

  parser.clear();

  return 0;
}/*}}}*/

