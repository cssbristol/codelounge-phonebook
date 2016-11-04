# Phonebook

A simple phonebook in C. Written for CodeLounge 2016.

## Build + Run

### Simple

```
gcc phonebook.c -o phonebook
./phonebook
```

(On Windows, run `phonebook.exe`)

### With CMake

If you have CMake and GNU Make installed, you can compile with:

```
cmake -G"Unix Makefiles" .
make
```

## Use

```
Welcome to the phone book. You can add or lookup contacts. (A/L).
> A
Name    Number:
Police  01189998819991197253
Input another command.
> L
Name desired: > Police
Name:Police     Num:011899988199911
Input another command.
(Ctrl-C)
```
