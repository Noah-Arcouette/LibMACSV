# NAME

**LibMACSV** - Mimik Advanced Colon Separated Values Library

# SYNOPSIS

**LibMACSV** Include file is **macsv.h** and library is **libmacsv.a**

# DESCRIPTION

**LibMACSV** A simple configuration language based on Colon Separated Values

# USAGE

Basic key value pares

```ACSV
key;value;
```

More useful pares

```ACSV
key: value;
```

Tabs and newlines are ignored,
and there are no comments

# EXAMPLES

```ACSV
key;simple value;
key: space value;
```

# OTHER

**acsvAdd** Add key value pare to ACSV structure

**acsvFree** Free ACSV structure

**ascvGen** Generate raw ACSV from ACSV structure

**acsvParse** Parse raw ACSV into a ACSV structure

**acsvRemove** Remove key value pare from ACSV structure

**acsvSearch** Search for key in ACSV structure

**MIMIK_ACSV** The ACSV structure documentation
