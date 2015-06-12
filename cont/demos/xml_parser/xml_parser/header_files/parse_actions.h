
#ifndef __PARSE_ACTIONS_H
#define __PARSE_ACTIONS_H

/*
 * declaration of function describing parse actions
 */

bool pa_null(xml_parser_s &_this);
bool pa_close(xml_parser_s &_this);
bool pa_data(xml_parser_s &_this);
bool pa_open(xml_parser_s &_this);
bool pa_self_close(xml_parser_s &_this);
bool pa_attribute(xml_parser_s &_this);
bool pa_identifier(xml_parser_s &_this);
bool pa_string(xml_parser_s &_this);

bool pa_decl_version(xml_parser_s &_this);
bool pa_decl_encoding(xml_parser_s &_this);
bool pa_decl_standalone(xml_parser_s &_this);

/*
 * access to function callers
 */

extern bool(*xml_pa_decl_callers[])(xml_parser_s &_this);
extern bool(*xml_pa_callers[])(xml_parser_s &_this);

#endif

