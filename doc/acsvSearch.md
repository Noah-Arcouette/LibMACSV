# NAME

**acsvSearch** - Search for key in ACSV sturcture

# SYNOPSIS

```C
ssize_t acsvSearch (struct MIMIK_ACSV conf, char *key);
```

# DESCRIPTION

Search for key in ACSV structure and return the index or -1 if not found

# USAGE

`struct MIMIK_ACSV conf` The ACSV sturcture to search through

`char *key` The key to search for

# EXAMPLES

```C
# conf is an initialized ACSV structure
size_t index = acsvSearch(conf, "key");

```

# OTHER

**MIMIK_ACSV** The ACSV Structure

**acsvAdd** Add ACSV key value pare

**acsvRemove** Remove ACSV key value pare
