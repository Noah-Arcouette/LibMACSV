#include <stdio.h>
#include "acsv.h"

int main ()
{
  acsv conf = acsvParse("\
key;value;\
");
/*
value with space: value;\n\
empty;;\n\
empty with space: ;\n\
solo key;\n\
*/
  for (size_t i = 0; i<conf.size; i++)
  {
    printf("%s : %s\n", conf.keys[i], conf.vals[i]);
  }

  acsvFree(conf);

  return 0;
}
