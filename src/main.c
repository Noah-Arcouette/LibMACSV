#include <stdio.h>
#include <stdlib.h>
#include "macsv.h"

int main ()
{
  acsv conf = acsvParse("\
key;value;\n\
");

  acsvAdd(&conf, "kely", "vlauew");

  for (size_t i = 0; i<conf.size; i++)
  {
    printf("%s : %s\n", conf.keys[i], conf.vals[i]);
  }

  printf("%ld\n", acsvSearch(conf, "kely"));

  acsvFree(conf);

  return 0;
}
