#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acsv.h"

struct MIMIK_ACSV acsvParse (char *data)
{
  struct MIMIK_ACSV conf;
  conf.size        = 1;
  conf.keys        = (char**)malloc(1 * sizeof(char*));
  *conf.keys       = (char*) malloc(1 * sizeof(char));
  **conf.keys      = 0;
  conf.vals        = (char**)malloc(1 * sizeof(char*));
  *conf.vals       = (char*) malloc(1 * sizeof(char));
  **conf.vals      = 0;

  register size_t size = 1;
  register int    val  = 0;

  for (register size_t i = 0; data[i]!=0; i++)
  {
    // printf("%c ; %d ; %ld ; %ld\n", data[i], val, size, conf.size);

    if (data[i] == '\n' || data[i] == '\r' || data[i] == '\t')
    {
      continue;
    }

    if (data[i] == ';' || data[i] == ':')
    {
      val  = !val;
      size = 1;

      if (!val)
      {
        conf.size++;
        conf.keys               = (char**)realloc(conf.keys, conf.size * sizeof(char*));
        conf.keys[conf.size-1]  = (char*) malloc(1 * sizeof(char));
        *conf.keys[conf.size-1] = 0;
        conf.vals               = (char**)realloc(conf.vals, conf.size * sizeof(char*));
        conf.vals[conf.size-1]  = (char*) malloc(1 * sizeof(char));
        *conf.vals[conf.size-1] = 0;
      }

      if (data[i] == ':' && data[i+1] != 0)
      {
        i++;
      }

      continue;
    }

    if (val)
    {
      conf.vals[conf.size-1] = (char*)realloc(conf.vals[conf.size-1], ++size * sizeof(char));
      strncat(conf.vals[conf.size-1], &data[i], 1);

      continue;
    }

    conf.keys[conf.size-1] = (char*)realloc(conf.keys[conf.size-1], ++size * sizeof(char));
    strncat(conf.keys[conf.size-1], &data[i], 1);
  }

  return conf;
}

// char* acsvGen (struct MIMIK_ACSV conf)
// {
//
// }

void acsvFree (struct MIMIK_ACSV conf)
{
  for (conf.size--; conf.size; conf.size--)
  {
    free(conf.keys[conf.size]);
    free(conf.vals[conf.size]);
  }
  free(conf.keys[0]);
  free(conf.keys);

  free(conf.vals[0]);
  free(conf.vals);
}

// ssize_t acsvSearch (struct MIMIK_ACSV conf, char *find)
// {
//
// }
//
// void acsvAdd (struct MIMIK_ACSV *conf, char *key, char *value)
// {
//
// }
//
// void acsvRemove (struct MIMIK_ACSV *conf, char *key)
// {
//
// }
