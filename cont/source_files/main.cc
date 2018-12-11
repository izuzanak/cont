
@begin
   include "main.h"
@end

int main(int argc,char **argv)
{
   mc_init();

   {
      // - skip program name -
      ++argv;
      --argc;

      // - output file -
      FILE *out_file = stdout;
      unsigned gen_options = c_option_gen_code;

      // - process options -
      if (argc > 0)
      {/*{{{*/
        char **ptr = argv;
        char **ptr_end = argv + argc;
        do {
          if (strcmp(*ptr,"--output") == 0)
          {
            // - error -
            if (++ptr >= ptr_end || (out_file = fopen(*ptr,"w")) == NULL)
            {
              fprintf(stderr,"ERROR: Cannot open output file.\n");
              mc_clear();
              return 1;
            }

            argv += 2;
            argc -= 2;
          }
          else if (strcmp(*ptr,"--nogen") == 0)
          {
            gen_options &= ~c_option_gen_code;

            ++argv;
            --argc;
          }
          else if (strcmp(*ptr,"--deps") == 0)
          {
            gen_options &= ~c_option_gen_code;
            gen_options |= c_option_gen_dependencies;

            ++argv;
            --argc;
          }
          else
          {
            break;
          }
        } while(++ptr < ptr_end);
      }/*}}}*/

      if (argc <= 0)
      {
        fprintf(stderr,"ERROR: Missing name of file to process.\n");
        mc_clear();
        return 1;
      }

      // - process include directories -
      string_array_s include_dirs;
      include_dirs.init();

      if (argc > 1)
      {
        char **ptr = argv + 1;
        char **ptr_end = argv + argc;
        do {
          include_dirs.push_blank();
          include_dirs.last().set(strlen(*ptr), *ptr);
        } while(++ptr < ptr_end);
      }

      processor_s processor;
      processor.init();

      processor.initialize_data_types();
      cassert(processor.run(argv[0],include_dirs,out_file,gen_options));

      processor.clear();
      include_dirs.clear();

      // - close output file -
      if (out_file != stdout)
      {
        fclose(out_file);
      }
   }

   mc_clear();

   return 0;
}

