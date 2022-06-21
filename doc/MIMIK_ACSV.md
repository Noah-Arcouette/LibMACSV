# NAME

**MIMIK_ACSV** - ACSV structure

# SYNOPSIS

```C
typedef struct MIMIK_ACSV acsv;

struct MIMIK_ACSV
{
  char **keys;
  char **vals;

  size_t size;
};
```

# DESCRIPTION

The Mimik ACSV Library structure for storing ACSV data in C

# USAGE

`typedef struct MIMIK_ACSV acsv;` Set `MIMIK_ACSV` type to `acsv` for convenience

`MIMIK_ACSV char **keys` The set of keys in the ACSV data

`MIMIK_ACSV char **vals` The set of values in the ACSV data

`MIMIK_ACSV size_t size` The amount of key value pares in the ACSV data

# EXAMPLES

```
# conf is an initialized acsv structure

printf("first key %s\n", conf.keys[0][0]);
```

# OTHER

**acsvGen** Generate ACSV structure from text

**acsvFree** Free ACSV sturcture
