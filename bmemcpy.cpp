#include <iostream>
#include <bitset>
#include <climits>

void print_bits(const char* data, size_t s) {
    for (int i = 0; i < s; i++) {
        std::bitset<8> u(data[i]);
        std::cout << u;
    }
    std::cout << std::endl;
}

char set_bits(unsigned char destination, 
             unsigned char source,
             unsigned char at,
             unsigned char from,
             unsigned char to)
{
    char numbits = to - from;
    char mask = numbits == CHAR_BIT ? UCHAR_MAX : ((1 << numbits) - 1) << (CHAR_BIT - numbits) - at;
    return (mask | destination ) ^ ((~(source << from) >> at ) & mask );
}

void bmemcpy(char *dest, const char *src, size_t offset, size_t size)
{
    char byte = offset / CHAR_BIT;

    char r_offset = offset - byte * CHAR_BIT;
    size_t r_size = CHAR_BIT - r_offset > size ? size : CHAR_BIT - r_offset;

    dest[byte] = set_bits(dest[byte], src[0], r_offset, 0, r_size);

    size_t remaining_size = size - r_size;
    if (remaining_size > 0) {
        dest[byte + 1] = set_bits(dest[byte + 1], 
                                 src[0], 
                                 0, 
                                 r_size, 
                                 remaining_size > CHAR_BIT ? CHAR_BIT : r_size + remaining_size);
        remaining_size = size > CHAR_BIT ? size - CHAR_BIT : 0;
    }

    if (remaining_size > 0) {
        bmemcpy(dest, src + 1, CHAR_BIT + offset, remaining_size);
    }
}
