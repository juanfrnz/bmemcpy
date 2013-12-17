#include "bmemcpy.h"

char signal_data[] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };

int main(int argc, char** argv) {
    int value = 0xabcde;
    print_bits((char*)&value, 4);

    bmemcpy(signal_data, (char*)&value, 4, 10);
    print_bits(signal_data, sizeof(signal_data));

    return 0;
}
