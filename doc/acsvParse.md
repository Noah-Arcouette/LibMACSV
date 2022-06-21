# NAME

**acsvParse** - Parse text into a ACSV structure

# SYNOPSIS

```C
struct MIMIK_ACSV acsvParse (char* raw);
```

# DESCRIPTION

Create a ACSV structure from raw ACSV data

# USAGE

`raw` The raw ACSV data

# EXAMPLES

```C
acsv conf = acsvParse("key: value;");

acsvFree(conf);
```

# OTHER

**acsvFree** Free ACSV structure 
