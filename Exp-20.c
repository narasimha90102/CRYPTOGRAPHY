#include <stdio.h>
#include <string.h>

int main()
{
    char ecb[4][20];
    char cbc[4][20];
    int i;

    printf("Enter 4 ECB ciphertext blocks:\n");

    for(i = 0; i < 4; i++)
        scanf("%s", ecb[i]);

    printf("\nEnter 4 CBC ciphertext blocks:\n");

    for(i = 0; i < 4; i++)
        scanf("%s", cbc[i]);

    printf("\n--- ECB Error Effect ---\n");

    printf("If C2 has an error:\n");
    printf("P2 is corrupted.\n");
    printf("P1, P3 and P4 are not affected.\n");

    printf("\n--- CBC Error Effect ---\n");

    printf("If C2 has an error:\n");
    printf("P2 is completely corrupted.\n");
    printf("P3 has a corresponding bit error.\n");
    printf("P4 and later blocks are not affected.\n");

    printf("\nIf P1 has a bit error before encryption:\n");
    printf("The error affects only C1 in CBC mode.\n");

    return 0;
}