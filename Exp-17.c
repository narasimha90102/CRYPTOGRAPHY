#include <stdio.h>

int main()
{
    int i;
    int key[16];

    printf("Enter 16 subkeys for encryption:\n");

    for(i = 0; i < 16; i++)
    {
        scanf("%d", &key[i]);
    }

    printf("\nDES Decryption Key Order:\n");

    for(i = 15; i >= 0; i--)
    {
        printf("K%d = %d\n", 16 - i, key[i]);
    }

    return 0;
}