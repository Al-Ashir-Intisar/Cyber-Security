#include <stdio.h>
#include <string.h>

int main() {
    char string[10];
    int A = -73;
    unsigned int B = 31337;

    strcpy(string, "sample");
    printf("[A] Dec: %d, Hex: %x, Unsigned: %u\n", A, A, A);
    printf("[B] Dec: %d, Hex: %x, Unsigned: %u\n", B, B, B);
    printf("[field width on B] 3: '%3u', 10: '%10u', 8: '%08u'\n", B, B, B);
    printf("[string] %s address %08x\n", string, string);

    printf("variable A is at address: %08x\n", &A);
}