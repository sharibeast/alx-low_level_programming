#!/bin/bash
gcc -Wall -fPIC -c *.c
gcc -shared -o 100-operations.so *.o
