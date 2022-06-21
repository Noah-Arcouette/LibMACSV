#include <stdio.h>
#include <stdlib.h>
#include "acsv.h"

int main ()
{
  acsv conf = acsvParse("\
key;value;\n\
");

  for (size_t i = 0; i<conf.size; i++)
  {
    printf("%s : %s\n", conf.keys[i], conf.vals[i]);
  }

  printf("%ld\n", acsvSearch(conf, "key"));

  acsvFree(conf);

  return 0;
}
