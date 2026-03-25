#include <stdio.h>

void swap_endian(int *x) {
    int tmp = 0;
    unsigned char* addr_tmp = (unsigned char*)&tmp;
    unsigned char* addr_x = (unsigned char*)x;
    for (int i=0; i<sizeof(int); i++)
        *(addr_tmp + 3 - i) = *(addr_x + i);
    *x = tmp;
}

int main() {
    int x = 0x12345678;
    
    printf("%x\n", x);
    swap_endian(&x);
    printf("%x\n", x);

    return 0;
}


