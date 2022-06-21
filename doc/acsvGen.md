# NAME

**acsvGen** - Generate raw ACSV from ACSV structure

# SYNOPSIS

```
char* acsvGen (struct MIMIK_ACSV conf);
```

# DESCRIPTION

Generate raw ACSV from an ACSV structure

# USAGE

`struct MIMIK_ACSV conf` The ACSV structure used for generation

**RETURN** The return value of the function is dynamically allocated so it must be freed

# EXAMPLES

```
# conf is an initialized ACSV sturcture
char *raw = acsvGen(conf);

printf("%s\n", raw);

free(raw);
```

# OTHER

**acsvAdd** Add key value pare to ACSV structure

**acsvRemove** Remove key value pare from ACSV structure
