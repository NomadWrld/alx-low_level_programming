#!/bin/bash

# Compile the shared library
gcc -Wall -fPIC -shared -o /tmp/libinject.so /tmp/inject.c

# Run the Giga Millions program with LD_PRELOAD
LD_PRELOAD=/tmp/libinject.so ./gm 9 8 10 24 75 9
