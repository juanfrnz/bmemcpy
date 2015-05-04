#include "bmemcpy.hpp"

char data[] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };

int main(int argc, char** argv) {
    int value = 0xabcde;
    print_bits((char*)&value, sizeof(value));

    bmemcpy(data, (char*)&value, 4, 10);
    print_bits(data, sizeof(data));

    return 0;
}
