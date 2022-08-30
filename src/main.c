#include <stdio.h>
#include <stdlib.h>
#include "macsv.h"

int main ()
{
  acsv conf = acsvParse("imd: https\\://raw.githubusercontent.com/Noah-Arcouette/imd/master/net;imd: https\\://raw.githubusercontent.com/Noah-Arcouette/imd/master/net;imd: https\\://raw.githubusercontent.com/Noah-Arcouette/imd/master/net;");

  char *out = acsvGen(conf);

  printf(out);

  free(out);

  acsvFree(conf);

  return 0;
}
