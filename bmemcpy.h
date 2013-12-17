#pragma once

#include <cstdlib>

void print_bits(const char* data, size_t s);
char setbits(unsigned char destination, unsigned char source,
             unsigned char at, unsigned char from, unsigned char to);
void bmemcpy(char *dest, const char *src, size_t offset, size_t size);

