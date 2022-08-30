#include <stdio.h>
#include <stdlib.h>
#include "macsv.h"

int main ()
{
  acsv conf = acsvParse("\\:hi;hi;");

  char *out = acsvGen(conf);

  printf(out);

  free(out);

  acsvFree(conf);

  return 0;
}
