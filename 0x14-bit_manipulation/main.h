#ifndef MAIN_HH
#define MAIN_HH

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int _putchar(char c);
unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int n);
int set_bit(unsigned long int *n, unsigned int index);
int get_bit(unsigned long int n, unsigned int index);

#endif