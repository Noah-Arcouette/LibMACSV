#include <stdio.h>
#include <stdlib.h>
#include "macsv.h"

int main ()
{
  acsv conf = acsvParse(NULL);

  for (size_t i = 0; i<conf.size; i++)
  {
    printf("%s : %s\n", conf.keys[i], conf.vals[i]);
  }

  acsvFree(conf);

  return 0;
}
