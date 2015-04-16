
@begin
   include "main.h"
@end

int main(int argc,char **argv)
{
   mc_init();

   {
      if (argc <= 1) {
         fprintf(stderr,"ERROR: Expected at least one argument.\n");
         mc_clear();
         return 1;
      }

      string_array_s include_dirs;
      include_dirs.init();

      if (argc > 2)
      {
        char **ptr = argv + 2;
        char **ptr_end = argv + argc;
        do {
          include_dirs.push_blank();
          include_dirs.last().set(strlen(*ptr), *ptr);
        } while(++ptr < ptr_end);
      }

      processor_s processor;
      processor.init();

      processor.initialize_data_types();
      cassert(processor.run(argv[1],include_dirs,stdout));

      processor.clear();
      include_dirs.clear();
   }

   mc_clear();

   return 0;
}

