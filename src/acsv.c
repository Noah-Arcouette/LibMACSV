#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macsv.h"

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

  if (data != NULL)
  {
    for (register size_t i = 0; data[i]!=0; i++)
    {
      // printf("%c ; %d ; %ld ; %ld\n", data[i], val, size, conf.size);

      if (data[i] == '\n' || data[i] == '\r' || data[i] == '\t' || (data[i] == '\\' && data[i-1] != '\\'))
      {
        continue;
      }

      if ((data[i] == ';' || data[i] == ':') && (data[i-1] != '\\' || i<1))
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

          continue;
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
  }

  return conf;
}

char *acsv_addExp (char *in)
{
	size_t size = strlen(in)+1; 
	char *out   = (char*)malloc(size * sizeof(char));

  char c[3] = { '\\', 0, 0 };

	for (register size_t i = 0; in[i]!=0; i++)
	{
    if (in[i] == ':' || in[i] == ';')
    {
      out = (char*)realloc(out, ++size * sizeof(char));
      c[1] = in[i];
      strcat(out, c);

      continue;
    }

		strncat(out, &in[i], 1);
	}

	return out;
}

char* acsvGen (struct MIMIK_ACSV conf)
{
  register char *gen   = (char*)malloc(1 * sizeof(char));
  *gen                 = 0;
  register size_t size = 1;

  char *out;

  for (register size_t i = 0; i<conf.size && conf.keys[i][0]; i++)
  {
    if (conf.keys[i])
    {
      size += strlen(conf.keys[i]) + strlen(conf.vals[i]) + 2;
      gen   = (char*)realloc(gen, size * sizeof(char));

      out = acsv_addExp(conf.keys[i]);
      strcat(gen, out);
      free(out);
      strcat(gen, ";");

      out = acsv_addExp(conf.vals[i]);
      strcat(gen, out);
      free(out);
      strcat(gen, ";");
    }
  }

  return gen;
}

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

ssize_t acsvSearch (struct MIMIK_ACSV conf, char *find)
{
  for (register size_t i = 0; i<conf.size; i++)
  {
    if (conf.keys[i] && !strcmp(conf.keys[i], find))
    {
      return i;
    }
  }

  return -1;
}

void acsvAdd (struct MIMIK_ACSV *conf, char *key, char *value)
{
  conf->size++;
  conf->keys = (char**)realloc(conf->keys, conf->size * sizeof(char*));
  conf->vals = (char**)realloc(conf->vals, conf->size * sizeof(char*));

  conf->keys[conf->size-1]  = (char*)malloc((1 + strlen(key)) * sizeof(char));
  strcpy(conf->keys[conf->size-1], key);
  conf->vals[conf->size-1]  = (char*)malloc((1 + strlen(value)) * sizeof(char));
  strcpy(conf->vals[conf->size-1], value);
}

void acsvRemove (struct MIMIK_ACSV *conf, char *key)
{
  for (register size_t i = 0; i<conf->size; i++)
  {
    if (conf->keys[i] && !strcmp(conf->keys[i], key))
    {
      free(conf->keys[i]);
      conf->keys[i] = NULL;
    }
  }
}
