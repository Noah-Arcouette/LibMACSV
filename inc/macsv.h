#ifndef __LIBRARY_MIMIK_ACSV_H__
#define __LIBRARY_MIMIK_ACSV_H__

#include <stddef.h>

typedef struct MIMIK_ACSV acsv;

struct MIMIK_ACSV
{
  char **keys;
  char **vals;

  size_t size;
};

struct MIMIK_ACSV acsvParse  (char*);
char*             acsvGen    (struct MIMIK_ACSV);
void              acsvFree   (struct MIMIK_ACSV);
ssize_t           acsvSearch (struct MIMIK_ACSV, char*);
void              acsvAdd    (struct MIMIK_ACSV*, char*, char*);
void              acsvRemove (struct MIMIK_ACSV*, char*);

#endif
