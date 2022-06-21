# NAME

**acsvAdd** - Add key value pare to ACSV structure

# SYNOPSIS

```C
void acsvAdd (struct MIMIK_ACSV *conf, char *key, char *value);
```

# DESCRIPTION

Add a key value pare to an ACSV structure

# USAGE

`struct MIMIK_ACSV *conf` ACSV structure to add the key value pare to

`char *key` Key to add

`char *value` Value to add

# EXAMPLES

```
# conf is an initialized ACSV structure
acsvAdd(&conf, "key", "value");
```

# OTHER

**acsvRemove** Remove key value pare from ACSV structure
