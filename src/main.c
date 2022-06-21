#include <stdio.h>
#include <stdlib.h>
#include "acsv.h"

int main ()
{
  acsv conf = acsvParse("\
key;value;\n\
value with space: value;\n\
empty;;\n\
empty with space: ;\n\
");

  // for (size_t i = 0; i<conf.size; i++)
  // {
  //   printf("%s : %s\n", conf.keys[i], conf.vals[i]);
  // }

  char *conf_gen = acsvGen(conf);

  printf("%s\n", conf_gen);

  free(conf_gen);

  acsvFree(conf);

  return 0;
}
