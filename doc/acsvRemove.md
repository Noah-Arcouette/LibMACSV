# NAME

**acsvRemove** - Remove key value pare from ACSV structure

# SYNOPSIS

```
void acsvRemove (struct MIMIK_ACSV *conf, char *key);
```

# DESCRIPTION

Remove `key` from ACSV sturcture `conf`

# USAGE

`char *key` The key to remove
`sturct MIMIK_ACSV *conf` A pointer to the ACSV structure

# EXAMPLES

```C
# conf is an initialized ACSV structure
acsvRemove(&conf, "key");
```

# OTHER

**MIMIK_ACSV** The ACSV structure

**acsvAdd** Add key value pare to an ACSV structure
