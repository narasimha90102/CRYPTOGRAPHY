#include <stdio.h>
#include <stdint.h>

uint64_t leftShift(uint64_t x)
{
    return x << 1;
}

int main()
{
    uint64_t L, K1, K2;
    int blockSize;

    printf("Enter block size (64 or 128): ");
    scanf("%d", &blockSize);

    printf("Enter hexadecimal value of L: ");
    scanf("%llx", &L);

    if(blockSize == 64)
    {
        // Rb = 0x1B for 64-bit block
        if(L & 0x8000000000000000ULL)
            K1 = (L << 1) ^ 0x1B;
        else
            K1 = L << 1;

        if(K1 & 0x8000000000000000ULL)
            K2 = (K1 << 1) ^ 0x1B;
        else
            K2 = K1 << 1;

        printf("\nK1 = %016llX\n", K1);
        printf("K2 = %016llX\n", K2);
    }
    else
    {
        printf("This simple program demonstrates the 64-bit case.\n");
        printf("For 128-bit CMAC, Rb = 0x87.\n");
    }

    return 0;
}