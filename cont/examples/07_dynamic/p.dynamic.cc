
typedef bool bb;
typedef char bc;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef int bi;
typedef unsigned int ui;
typedef long int li;
typedef unsigned long uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef float bf;
typedef double bd;
typedef long double ld;



#ifndef __DYNAMIC_H
#define __DYNAMIC_H


#ifndef __STRUCT_H
#define __STRUCT_H


#ifndef __BASE_H
#define __BASE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "math.h"

// - functions used by generated code of containers -
#define debug_assert assert
#define cmalloc malloc
#define cfree free

// - constants used by generated code of containers -
const unsigned c_array_add = 64;
const unsigned c_idx_not_exist = 0xffffffff;

// - logarithm of two (needed by red-black tree container) -
const float c_log_of_2 = logf(2.0f);

/*
 * definition of generated structures
 */

/*
 * inline methods of generated structures
 */

/*
 * definition of global methods
 */

int main(int argc, char **argv);

#endif



/*
 * definition of generated structures
 */

// -- record_s --
// structure record_s definition

/*!
 * \brief __GEN structure
 */
struct record_s
{
   unsigned index; //!< member - 0
   unsigned value; //!< member - 1

   /*!
    * \brief __GEN initialize structure
    */
   inline void init();

   /*!
    * \brief __GEN release memory used by structure
    */
   inline void clear();

   /*!
    * \brief __GEN set structure members
    */
   inline void set(unsigned a_index,unsigned a_value);
   /*!
    * \brief __GEN flush structure memory usage, recursive on members
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap structure members with another structure
    */
   inline void swap(record_s &a_second);

   /*!
    * \brief __GEN copy structure from another structure
    * \param a_src - reference to another structure
    * \return reference to this structure
    */
   inline record_s &operator=(record_s &a_src);

   /*!
    * \brief __GEN compare structure with another structure
    * \param a_second - reference to another structure
    * \return result of comparison
    */
   inline bool operator==(record_s &a_second);

   
  inline unsigned get_index();
  inline unsigned get_value();

};



/*
 * inline methods of generated structures
 */

// -- record_s --
// --- struct record_s inline method definition ---

inline void record_s::init()
{/*{{{*/
}/*}}}*/

inline void record_s::clear()
{/*{{{*/

   init();
}/*}}}*/

inline void record_s::set(unsigned a_index,unsigned a_value)
{/*{{{*/
   index = a_index;
   value = a_value;
}/*}}}*/

inline void record_s::flush_all()
{/*{{{*/
}/*}}}*/

inline void record_s::swap(record_s &a_second)
{/*{{{*/
   unsigned tmp_index = index;
   index = a_second.index;
   a_second.index = tmp_index;

   unsigned tmp_value = value;
   value = a_second.value;
   a_second.value = tmp_value;
}/*}}}*/

inline record_s &record_s::operator=(record_s &a_src)
{/*{{{*/
   index = a_src.index;
   value = a_src.value;

   return *this;
}/*}}}*/

inline bool record_s::operator==(record_s &a_second)
{/*{{{*/
   return (index == a_second.index && value == a_second.value);
}/*}}}*/



inline unsigned record_s::get_index()
{
  return index;
}

inline unsigned record_s::get_value()
{
  return value;
}

/*
 * definition of global methods
 */

int main(int argc, char **argv);

#endif



#include <stdarg.h>

/*
 * constants and definitions
 */

// - string terminating character -
extern const char c_string_terminating_char;

// - tabulator size -
const unsigned c_tabulator_size = 8;

/*
 * definition of structure string_s
 */



struct string_s
{
  unsigned size;
  char *data;

  /*!
   * \brief initialization of string variables
   */
  inline void init();

  /*!
   * \brief release of string variables
   */
  inline void clear();

  /*!
   * \brief create new string
   * \param a_length - length of new string
   */
  inline void create(unsigned a_length);

  /*!
   * \brief set string to given data
   * \param a_length - length of new string
   * \param a_data - pointer to data of new string
   */
  inline void set(unsigned a_length,const char *a_data);

  /*!
   * \brief create new string by concatenation of two strings described by length and pointer
   * \param a_flength - length of first string
   * \param a_fdata - pointer to data of first string
   * \param a_slength - length of second string
   * \param a_sdata - pointer to data of second string
   */
  inline void conc_set(unsigned a_flength,const char *a_fdata,unsigned a_slength,const char *a_sdata);

  /*!
   * \brief flush all variables of string
   */
  inline void flush_all() {}

  /*!
   * \brief swap string variables with another string
   * \param a_second - reference to another string
   */
  inline void swap(string_s &a_second);

  /*!
   * \brief select one character from string
   * \param a_idx - index of selected character
   * \return reference to character
   */
  inline char &operator[](unsigned a_idx);

  /*!
   * \brief set string to value of another string
   * \param a_src - reference to another string
   * \return reference to this string
   */
  inline string_s &operator=(string_s &a_src);

  /*!
   * \brief compare value with another string
   * \param a_second - reference to another string
   * \return result of comparison
   */
  inline bool operator==(string_s &a_second);

  /*!
   * \brief compare string with string described by its length and its data
   * \param a_length - length of second string
   * \param a_data - data of second string
   * \return result of comparison
   */
  inline bool compare_char_ptr(unsigned a_length,const char *a_data);

  /*!
   * \brief multiply character string a_mult times
   *
   * \param a_length - length of string to be multiplied
   * \param a_data - pointer to string data
   * \param a_mult - multiplier of string
   */
  void mult_char_ptr(unsigned a_length,const char *a_data,unsigned a_mult);

  /*!
   * \brief convert utf8 string to utf32 unsigned int string
   * \param a_src - pointer to source utf8 characters
   * \param a_trg - pointer to target utf32 unsigned integers
   * \param a_size - count of characters to be converted
   * \return count of converted integers
   */
  static int utf8_to_utf32(char *a_src,unsigned *a_trg,unsigned a_size);

  /*!
   * \brief convert utf32 unsigned int string to utf8 string
   * \param a_src - pointer to source utf32 unsigned integeres
   * \param a_trg - pointer to target utf8 characters
   * \param a_size - count of integers to be converted
   * \return count of converted characters
   */
  static unsigned utf32_to_utf8(unsigned *a_src,char *a_trg,unsigned a_size);

  /*!
   * \brief print string to standard output
   * \return count of writed characters
   */
  inline unsigned print();

  /*!
   * \brief load string from given stream
   * \param stream - stream from which is string loaded
   */
  bool read_line_from_stream(FILE *stream);

  /*!
   * \brief load string from text file
   * \param a_file - name of file containing string text
   * \return true if string is successfully loaded
   */
  inline bool load_text_file(const char *a_file);

  /*!
   * \brief save string to text file
   * \param a_file - name of target file
   * \return true if string is successfully saved
   */
  inline bool save_text_file(const char *a_file);

  /*!
   * \brief create string of desired format
   * \param format - format as in printf functions family
   * \param ... - list of parameters desired in format
   */
  void setf(const char *format,...);

  /*!
   * \brief conctenate string of desired format
   * \param format - format as in printf functions family
   * \param ... - list of parameters demanded in format
   */
  void concf(const char *format,...);

  /*!
   * \brief find position of given string in string from given index
   * \param a_idx - position from which is substring searched
   * \param a_length - length of searched string
   * \param a_data - data of searched string
   */
  unsigned get_idx(unsigned a_idx,unsigned a_length,const char *a_data);

  /*!
   * \brief return print size between two character indexes in string
   * \param f_idx - index of first character
   * \param s_idx - index of second character
   * \return print size
   */
  unsigned get_print_size_between(unsigned f_idx,unsigned s_idx);

  /*!
   * \brief return number of line of character index
   * \param c_idx - character index
   * \return line number
   */
  unsigned get_character_line(unsigned c_idx);

  /*!
   * \brief return index of character at beginning of line on which is located given character
   * \param c_idx - index of given character
   * \return index of begin of line
   */
  unsigned get_character_line_begin(unsigned c_idx);

  /*!
   * \brief return index of character at end of line on which is located given character
   * \param c_idx - index of given character
   * \return index of end of line
   */
  unsigned get_character_line_end(unsigned c_idx);
};

/*
 * definition of generated structures
 */

// -- string_array_s --
// --- struct string_array_s definition --- 

/*!
 * \brief __GEN array of type string_s
 */
struct string_array_s
{
   unsigned size; //!< actual size of allocated space in array
   unsigned used; //!< count of used space in array
   string_s *data; //!< pointer to array elements

   /*!
    * \brief __GEN initialize array
    */
   inline void init();

   /*!
    * \brief __GEN initialize array of requested size
    * \param a_size - requested size of array
    */
   inline void init_size(unsigned a_size);

   /*!
    * \brief __GEN release memory used by array
    */
   void clear();

   /*!
    * \brief __GEN set array content from element pointer
    * \param a_used - number of elements stored at pointed location
    * \param a_data - pointer to elements
    */
   void set(unsigned a_used,string_s *a_data);

   /*!
    * \brief __GEN flush array memory usage
    */
   inline void flush();

   /*!
    * \brief __GEN flush array memory usage, recursive on elemenets
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap array members with another array
    * \param a_second - reference to another array
    */
   inline void swap(string_array_s &a_second);

   /*!
    * \brief __GEN select element of array
    * \param a_idx - index of element in array
    * \return reference to element of array
    */
   inline string_s &operator[](unsigned a_idx);

   /*!
    * \brief __GEN insert element to end of array
    * \param a_value - reference to inserted value
    */
   inline void push(string_s &a_value);

   /*!
    * \brief __GEN insert blank element to end of array
    */
   inline void push_blank();

   /*!
    * \brief __GEN reserve requested count of elements at end of array
    * \param a_cnt - count of elements to be reserved
    */
   void reserve(unsigned a_cnt);

   /*!
    * \brief __GEN insert blank elements to end of array
    * \param a_cnt - count of elements inserted to array
    */
   void push_blanks(unsigned a_cnt);

   /*!
    * \brief __GEN insert and clear element to end of array
    */
   inline void push_clear();

   /*!
    * \brief __GEN return value of last element in array, and remove it
    * \return reference to last element
    */
   inline string_s &pop();

   /*!
    * \brief __GEN return value of last element in array
    * \return reference to last element
    */
   inline string_s &last();

   /*!
    * \brief __GEN change array capacity
    * \param a_size - requested array capacity
    */
   void copy_resize(unsigned a_size);

   /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
   void fill(string_s &a_value);

   /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
   unsigned get_idx(string_s &a_value);

   /*!
    * \brief __GEN copy array from another array
    * \param a_src - reference to another array
    */
   string_array_s &operator=(string_array_s &a_src);

   /*!
    * \brief __GEN comparison of array with another array
    * \param a_second - reference to another array
    */
   bool operator==(string_array_s &a_second);

};



/*
 * inline methods of structure string_s
 */

inline void string_s::init()
{/*{{{*/
  size = 1;
  data = (char *)&c_string_terminating_char;
}/*}}}*/

inline void string_s::clear()
{/*{{{*/
  if (data != &c_string_terminating_char)
  {
    cfree(data);
  }

  init();
}/*}}}*/

inline void string_s::create(unsigned a_length)
{/*{{{*/
  clear();
  data = (char *)cmalloc((a_length + 1)*sizeof(char));

  data[a_length] = '\0';
  size = a_length + 1;
}/*}}}*/

inline void string_s::set(unsigned a_length,const char *a_data)
{/*{{{*/
  clear();
  data = (char *)cmalloc((a_length + 1)*sizeof(char));

  if (a_length != 0)
  {
    memcpy(data,a_data,a_length*sizeof(char));
  }

  data[a_length] = '\0';
  size = a_length + 1;
}/*}}}*/

inline void string_s::conc_set(unsigned a_flength,const char *a_fdata,unsigned a_slength,const char *a_sdata)
{/*{{{*/
  clear();
  data = (char *)cmalloc((a_flength + a_slength + 1)*sizeof(char));

  if (a_flength != 0)
  {
    memcpy(data,a_fdata,a_flength*sizeof(char));
  }

  if (a_slength != 0)
  {
    memcpy(data + a_flength,a_sdata,a_slength*sizeof(char));
  }

  data[a_flength + a_slength] = '\0';
  size = a_flength + a_slength + 1;
}/*}}}*/

inline void string_s::swap(string_s &a_second)
{/*{{{*/
  unsigned tmp_size = size;
  size = a_second.size;
  a_second.size = tmp_size;

  char *tmp_data = data;
  data = a_second.data;
  a_second.data = tmp_data;
}/*}}}*/

inline char &string_s::operator[](unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < size - 1);
  return data[a_idx];
}/*}}}*/

inline string_s &string_s::operator=(string_s &a_src)
{/*{{{*/
  clear();

  if (a_src.data == &c_string_terminating_char) return *this;
  data = (char *)cmalloc(a_src.size*sizeof(char));
  memcpy(data,a_src.data,(a_src.size - 1)*sizeof(char));
  data[a_src.size - 1] = '\0';
  size = a_src.size;

  return *this;
}/*}}}*/

inline bool string_s::operator==(string_s &a_second)
{/*{{{*/
  if (size != a_second.size) return false;
  if (data == &c_string_terminating_char) return true;
  return (memcmp(data,a_second.data,(size - 1)*sizeof(char)) == 0);
}/*}}}*/

inline bool string_s::compare_char_ptr(unsigned a_length,const char *a_data)
{/*{{{*/
  if (size != a_length + 1) return false;
  if (a_length == 0) return true;
  return (memcmp(data,a_data,a_length*sizeof(char)) == 0);
}/*}}}*/

inline unsigned string_s::print()
{/*{{{*/
  return fwrite(data,size - 1,1,stdout);
}/*}}}*/

inline bool string_s::load_text_file(const char *a_file)
{/*{{{*/
  if (a_file == NULL) return false;
  FILE *f = fopen(a_file,"r");
  if (f == NULL) return false;

  fseek(f,0,SEEK_END);
  unsigned file_size = ftell(f);
  fseek(f,0,SEEK_SET);

  clear();
  data = (char *)cmalloc((file_size + 1)*sizeof(char));
  if (fread(data,file_size,1,f) != 1)
  {
    fclose(f);
    return false;
  }
  fclose(f);

  data[file_size] = '\0';
  size = file_size + 1;

  return true;
}/*}}}*/

inline bool string_s::save_text_file(const char *a_file)
{/*{{{*/
  if (a_file == NULL) return false;
  FILE *f = fopen(a_file,"w");
  if (f == NULL) return false;

  if (size > 1)
  {
    if (fwrite(data,size - 1,1,f) != 1)
    {
      fclose(f);
      return false;
    }
  }

  fclose(f);
  return true;
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- string_array_s --
// --- struct string_array_s inline method definition ---

inline void string_array_s::init()
{/*{{{*/
   size = 0;
   used = 0;
   data = NULL;
}/*}}}*/

inline void string_array_s::init_size(unsigned a_size)
{/*{{{*/
   init();
   copy_resize(a_size);
}/*}}}*/

inline void string_array_s::flush()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void string_array_s::flush_all()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void string_array_s::swap(string_array_s &a_second)
{/*{{{*/
   unsigned tmp_unsigned = size;
   size = a_second.size;
   a_second.size = tmp_unsigned;

   tmp_unsigned = used;
   used = a_second.used;
   a_second.used = tmp_unsigned;

   string_s *tmp_data = data;
   data = a_second.data;
   a_second.data = tmp_data;
}/*}}}*/

inline string_s &string_array_s::operator[](unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used);
   return data[a_idx];
}/*}}}*/

inline void string_array_s::push(string_s &a_value)
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   data[used++] = a_value;
}/*}}}*/

inline void string_array_s::push_blank()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   used++;
}/*}}}*/

inline void string_array_s::push_clear()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   data[used++].clear();
}/*}}}*/

inline string_s &string_array_s::pop()
{/*{{{*/
   debug_assert(used > 0);
   return data[--used];
}/*}}}*/

inline string_s &string_array_s::last()
{/*{{{*/
   debug_assert(used > 0);
   return data[used - 1];
}/*}}}*/



/*
 * definition of global methods
 */

void print_array(string_array_s &str_array,const char *name);

#endif



/*
 * constants and definitions
 */

// - string terminating character -
const char c_string_terminating_char = '\0';

/*
 * methods of structure string_s
 */

void string_s::mult_char_ptr(unsigned a_length,const char *a_data,unsigned a_mult)
{/*{{{*/
  if (a_length == 0 || a_mult == 0)
  {
    clear();
    return;
  }

  create(a_length*a_mult);

  char *s_ptr = data;
  do
  {
    memcpy(s_ptr,a_data,a_length*sizeof(char));
  }
  while(s_ptr += a_length, --a_mult > 0);

}/*}}}*/

int string_s::utf8_to_utf32(char *a_src,unsigned *a_trg,unsigned a_size)
{/*{{{*/
  if (a_size == 0)
  {
    return 0;
  }

  unsigned char *s_ptr = (unsigned char *)a_src;
  unsigned char *s_ptr_end = s_ptr + a_size;
  unsigned *t_ptr = a_trg;
  do {

    if (*s_ptr <= 127)
    {
      *t_ptr = (unsigned)*s_ptr++;
    }
    else
    {
      unsigned char value = *s_ptr++ << 2;
      unsigned count = 2;
      unsigned code = *s_ptr++ & 0x3f;

      while (value & 0x80)
      {
        if ((*s_ptr & 0xc0) != 0x80)
        {
          return -1;
        }

        code |= (code << 6) | (*s_ptr++ & 0x3f);
        value <<= 1;
        count++;
      }

      *t_ptr = code | (value << (5*count - 6));
    }

  } while(++t_ptr,s_ptr < s_ptr_end);

  return t_ptr - a_trg;
}/*}}}*/

unsigned string_s::utf32_to_utf8(unsigned *a_src,char *a_trg,unsigned a_size)
{/*{{{*/
  if (a_size == 0)
  {
    return 0;
  }

  unsigned *s_ptr = a_src;
  unsigned *s_ptr_end = s_ptr + a_size;
  unsigned char *t_ptr = (unsigned char *)a_trg;
  do {
    register unsigned value = *s_ptr;

    if (value <= 0x7f)
    {
      *t_ptr++ = value;
      continue;
    }

    if (value <= 0x7ff)
    {
      t_ptr[0] = 0xc0 | value >> 6;
      t_ptr[1] = 0x80 | (value & 0x3f);
      t_ptr += 2;
      continue;
    }
    
    if (value <= 0xffff)
    {
      t_ptr[0] = 0xe0 |   value >> 12;
      t_ptr[1] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[2] = 0x80 |  (value        & 0x3f);
      t_ptr += 3;
      continue;
    }
    
    if (value <= 0x1fffff)
    {
      t_ptr[0] = 0xf0 |   value >> 18;
      t_ptr[1] = 0x80 | ((value >> 12) & 0x3f);
      t_ptr[2] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[3] = 0x80 |  (value        & 0x3f);
      t_ptr += 4;
      continue;
    }
    
    if (value <= 0x3ffffff)
    {
      t_ptr[0] = 0xf8 |   value >> 24;
      t_ptr[1] = 0x80 | ((value >> 18) & 0x3f);
      t_ptr[2] = 0x80 | ((value >> 12) & 0x3f);
      t_ptr[3] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[4] = 0x80 |  (value        & 0x3f);
      t_ptr += 5;
      continue;
    }
    
    if (value <= 0x7fffffff)
    {
      t_ptr[0] = 0xfc |   value >> 30;
      t_ptr[1] = 0x80 | ((value >> 24) & 0x3f);
      t_ptr[2] = 0x80 | ((value >> 18) & 0x3f);
      t_ptr[3] = 0x80 | ((value >> 12) & 0x3f);
      t_ptr[4] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[5] = 0x80 |  (value        & 0x3f);
      t_ptr += 6;
      continue;
    }
    
  } while(++s_ptr < s_ptr_end);

  return t_ptr - (unsigned char *)a_trg;
}/*}}}*/

bool string_s::read_line_from_stream(FILE *stream)
{/*{{{*/
  clear();

  const unsigned c_buffer_size = 256;
  char buffer[c_buffer_size];

  if (fgets(buffer,c_buffer_size,stream) == NULL)
  {
    return false;
  }

  unsigned b_str_size = strlen(buffer) + 1;
  set(b_str_size - 1,buffer);

  if (buffer[b_str_size - 2] == '\n')
  {
    return true;
  }

  string_s tmp_str;
  tmp_str.init();

  do
  {
    if (fgets(buffer,c_buffer_size,stream) == NULL)
    {
      break;
    }

    unsigned b_str_size = strlen(buffer) + 1;
    tmp_str.conc_set(size - 1,data,b_str_size - 1,buffer);
    swap(tmp_str);

    if (buffer[b_str_size - 2] == '\n')
    {
      break;
    }
  }
  while(1);

  tmp_str.clear();

  return true;
}/*}}}*/

void string_s::setf(const char *format,...)
{/*{{{*/
  clear();

  const int init_size = 256;
  int alloc_size = init_size;

  va_list ap;

  do
  {
    data = (char *)cmalloc(alloc_size*sizeof(char));

    va_start(ap,format);

#if SYSTEM_TYPE == SYSTEM_TYPE_DSP
    // DSP FIXME
    int cnt = vsprintf(data,format,ap);
#else
    int cnt = vsnprintf(data,alloc_size,format,ap);
#endif
    va_end(ap);

    if (cnt < alloc_size)
    {
      size = cnt + 1;
      break;
    }

    cfree(data);
    alloc_size <<= 1;

  }
  while(1);
}/*}}}*/

void string_s::concf(const char *format,...)
{/*{{{*/
  const int init_size = 256;
  int alloc_size = init_size;

  // - creation of formated string -
  string_s fmt_str;
  fmt_str.init();

  va_list ap;

  do
  {
    fmt_str.data = (char *)cmalloc(alloc_size*sizeof(char));

    va_start(ap,format);

#if SYSTEM_TYPE == SYSTEM_TYPE_DSP
    // DSP FIXME
    int cnt = vsprintf(fmt_str.data,format,ap);
#else
    int cnt = vsnprintf(fmt_str.data,alloc_size,format,ap);
#endif
    va_end(ap);

    if (cnt < alloc_size)
    {
      fmt_str.size = cnt + 1;
      break;
    }

    cfree(fmt_str.data);
    alloc_size <<= 1;

  }
  while(1);

  // - concatenation to result string -
  string_s res_str;
  res_str.init();
  res_str.conc_set(size - 1,data,fmt_str.size - 1,fmt_str.data);

  // - swap this string with result string -
  swap(res_str);

  // - clear temporary strings -
  res_str.clear();
  fmt_str.clear();
}/*}}}*/

unsigned string_s::get_idx(unsigned a_idx,unsigned a_length,const char *a_data)
{/*{{{*/
  if (a_idx >= (size - 1) || a_length >= (size - a_idx))
  {
    return c_idx_not_exist;
  }

  char *s_ptr = data + a_idx;
  char *s_ptr_end = data + (size - a_length);
  do
  {
    char *ss_ptr = s_ptr;
    char *ss_ptr_end = ss_ptr + a_length;
    const char *a_ptr = a_data;
    do
    {
      if (*ss_ptr != *a_ptr)
      {
        break;
      }

      if (++a_ptr,++ss_ptr >= ss_ptr_end)
      {
        return s_ptr - data;
      }
    }
    while(1);

  }
  while(++s_ptr < s_ptr_end);

  return c_idx_not_exist;
}/*}}}*/

unsigned string_s::get_print_size_between(unsigned f_idx,unsigned s_idx)
{/*{{{*/
  debug_assert(f_idx < size && s_idx < size);

  if (f_idx >= s_idx) return 0;

  unsigned char_cnt = s_idx - f_idx;
  unsigned utf32_data[char_cnt];

  int utf32_cnt = utf8_to_utf32(data + f_idx,utf32_data,char_cnt);

  unsigned *c_ptr = utf32_data;
  unsigned *c_ptr_end = c_ptr + utf32_cnt;
  unsigned print_size = 0;

  do
  {
    if (*c_ptr == '\t')
    {
      print_size += c_tabulator_size;
    }
    else
    {
      print_size++;
    }
  }
  while(++c_ptr < c_ptr_end);

  return print_size;
}/*}}}*/

unsigned string_s::get_character_line(unsigned c_idx)
{/*{{{*/
  if (size <= c_idx) return 0;

  char *c_ptr = data;
  char *c_ptr_end = c_ptr + c_idx;
  unsigned line_cnt = 1;

  do
  {
    if (*c_ptr == '\n')
    {
      line_cnt++;
    }
  }
  while(++c_ptr < c_ptr_end);

  return line_cnt;
}/*}}}*/

unsigned string_s::get_character_line_begin(unsigned c_idx)
{/*{{{*/
  char *s_ptr = data + c_idx;

  do
  {
    if (*s_ptr == '\n')
    {
      break;
    }
  }
  while(--s_ptr >= data);

  return (s_ptr - data) + 1;
}/*}}}*/

unsigned string_s::get_character_line_end(unsigned c_idx)
{/*{{{*/
  char *e_ptr = data + c_idx;
  char *e_ptr_end = data + size - 1;

  do
  {
    if (*e_ptr == '\n')
    {
      break;
    }
  }
  while(++e_ptr < e_ptr_end);

  return e_ptr - data;
}/*}}}*/

/*
 * methods of generated structures
 */

// -- string_array_s --
// --- struct string_array_s method definition ---

void string_array_s::clear()
{/*{{{*/
   if (data != NULL) {
      string_s *ptr = data;
      string_s *ptr_end = ptr + size;

      do {
         ptr->clear();
      } while(++ptr < ptr_end);

      cfree(data);
   }

   init();
}/*}}}*/

void string_array_s::set(unsigned a_used,string_s *a_data)
{/*{{{*/
   clear();
   if (a_used == 0) return;
   
   debug_assert(a_data != NULL);
   copy_resize(a_used);

   string_s *ptr = data;
   string_s *ptr_end = ptr + a_used;
   string_s *a_ptr = a_data;

   do {
      *ptr = *a_ptr;
   } while(++a_ptr,++ptr < ptr_end);

   used = a_used;
}/*}}}*/

void string_array_s::reserve(unsigned a_cnt)
{/*{{{*/
   unsigned required_cnt = used + a_cnt;
   if (required_cnt > size) {
      unsigned r_size = size;
      do {
         r_size = (r_size << 1) + c_array_add;
      } while(r_size < required_cnt);

      copy_resize(r_size);
   }
}/*}}}*/

void string_array_s::push_blanks(unsigned a_cnt)
{/*{{{*/
   unsigned required_cnt = used + a_cnt;
   if (required_cnt > size) {
      unsigned r_size = size;
      do {
         r_size = (r_size << 1) + c_array_add;
      } while(r_size < required_cnt);

      copy_resize(r_size);
   }

   used += a_cnt;
}/*}}}*/

void string_array_s::copy_resize(unsigned a_size)
{/*{{{*/
   debug_assert(a_size >= used);

   string_s *n_data;

   if (a_size == 0) {
      n_data = NULL;
   }
   else {
      n_data = (string_s *)cmalloc(a_size*sizeof(string_s));

      if (a_size > used) {
         string_s *ptr = n_data + used;
         string_s *ptr_end = n_data + a_size;

         do {
            ptr->init();
         } while(++ptr < ptr_end);
      }
   }

   if (used != 0) {
      memcpy(n_data,data,used*sizeof(string_s));
   }

   if (size > used) {
      string_s *ptr = data + used;
      string_s *ptr_end = data + size;

      do {
         ptr->clear();
      } while(++ptr < ptr_end);
   }

   if (size != 0) {
      cfree(data);
   }

   data = n_data;
   size = a_size;
}/*}}}*/

void string_array_s::fill(string_s &a_value)
{/*{{{*/
   if (size == 0) return;

   string_s *ptr = data;
   string_s *ptr_end = data + size;

   do {
      *ptr = a_value;
   } while(++ptr < ptr_end);

   used = size;
}/*}}}*/

unsigned string_array_s::get_idx(string_s &a_value)
{/*{{{*/
   if (used == 0) return c_idx_not_exist;

   string_s *ptr = data;
   string_s *ptr_end = data + used;

   do {
      if (*ptr == a_value) {
         return ptr - data;
      }
   } while(++ptr < ptr_end);

   return c_idx_not_exist;
}/*}}}*/

string_array_s &string_array_s::operator=(string_array_s &a_src)
{/*{{{*/
   clear();

   if (a_src.used == 0) return *this;

   copy_resize(a_src.used);

   string_s *ptr = data;
   string_s *s_ptr = a_src.data;
   string_s *s_ptr_end = s_ptr + a_src.used;

   do {
      *ptr = *s_ptr;
   } while(++ptr,++s_ptr < s_ptr_end);

   used = a_src.used;
   return *this;
}/*}}}*/

bool string_array_s::operator==(string_array_s &a_second)
{/*{{{*/
   if (used != a_second.used) return false;
   if (used == 0) return true;

   string_s *ptr = data;
   string_s *ptr_end = ptr + used;
   string_s *s_ptr = a_second.data;

   do {
      if (!(*ptr == *s_ptr)) {
         return false;
      }
   } while(++s_ptr,++ptr < ptr_end);

   return true;
}/*}}}*/



/*
 * global methods
 */

void print_array(string_array_s &str_array,const char *name)
{
  printf("%s.size: %u\n",name,str_array.size);
  printf("%s.used: %u\n",name,str_array.used);
  printf("%s: ",name);

  string_s *s_ptr = str_array.data;
  string_s *s_ptr_end = s_ptr + str_array.used;
  while (s_ptr < s_ptr_end)
  {
    printf("%s ",s_ptr->data);
    ++s_ptr;
  }
  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  string_s string;
  string.init();
  string.set(strlen("String"),"String");

  string_array_s array0;
  array0.init();

  printf("--- CREATE EMPTY ARRAY ---\n");
  print_array(array0,"array0");

  printf("--- FILL STRINGS TO ARRAY ---\n");
  unsigned idx = 0;
  do {
    array0.push(string);
  } while(++idx < 8);

  print_array(array0,"array0");

  printf("--- POP STRINGS FROM ARRAY ---\n");
  while (array0.used > 3)
  {
    array0.pop();
  }

  print_array(array0,"array0");

  printf("--- PUSH STRINGS TO ARRAY ---\n");
  string.set(strlen("Pushed"),"Pushed");
  array0.push(string);
  array0.push(string);
  array0.push(string);

  print_array(array0,"array0");

  printf("--- MODIFY ARRAY ELEMENT ---\n");
  string.set(strlen("Modified"),"Modified");
  array0[2] = string;

  print_array(array0,"array0");

  printf("--- CREATE NEW EMPTY ARRAY ---\n");
  string_array_s array1;
  array1.init();

  print_array(array0,"array0");
  print_array(array1,"array1");

  printf("--- SWAP CONTENT OF ARRAYS ---\n");
  array0.swap(array1);

  print_array(array0,"array0");
  print_array(array1,"array1");

  printf("--- COMPARE ARRAY CONTENT ---\n");
  printf("array0 == array1: %s\n",array0 == array1 ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN ARRAY CONTENT ---\n");
  array0 = array1;

  printf("array0 == array1: %s\n",array0 == array1 ? "TRUE" : "FALSE");
  printf("\n");

  array1.clear();
  array0.clear();
  string.clear();

  return 0;
}

