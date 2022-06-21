# NAME

**acsvFree** - Free ACSV structure

# SYNOPSIS

```C
void acsvFree (struct MIMIK_ACSV conf);
```

# DESCRIPTION

Free an ACSV structure ***This is always need for ACSV structures***

# USAGE

**conf** The ACSV structure to be freed

# EXAMPLES

```C
acsv conf = acsvParse("key: value;");

...

acsvFree(conf);
```

# OTHER

**acsvParse** Parse raw ACSV into a ACSV structure

**acsvGen** Generate raw ACSV from a ACSV structure
