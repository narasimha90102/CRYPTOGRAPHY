#include <stdio.h>
#include <string.h>

int main()
{
    char plain[65];
    char key[65];
    char cipher[65];
    int i;

    printf("Enter 64-bit Plaintext: ");
    scanf("%64s", plain);

    printf("Enter 56-bit Key: ");
    scanf("%56s", key);

    /*
       Simple DES demonstration.
       XOR plaintext bits with repeated key bits.
    */

    for(i = 0; i < 64; i++)
    {
        if(plain[i] == key[i % 56])
            cipher[i] = '0';
        else
            cipher[i] = '1';
    }

    cipher[64] = '\0';

    printf("\nPlaintext : %s", plain);
    printf("\nKey       : %s", key);
    printf("\nCiphertext: %s\n", cipher);

    return 0;
}