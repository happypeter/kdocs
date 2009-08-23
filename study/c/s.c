#include <stdio.h>
   
   int main(void)
   {
      const char base[] = "filename";
      char filename [ FILENAME_MAX ];
      int number = 42;
      sprintf(filename, "%s%d", base, number);
      printf("filename = \"%s\"\n", filename);
      return 0;
   }

