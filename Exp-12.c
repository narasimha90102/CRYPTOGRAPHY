#include <stdio.h>
#include <string.h>
#include <ctype.h>

int mod(int n)
{
    return (n % 26 + 26) % 26;
}

int main()
{
    char plain[200], text[200], cipher[200], decrypt[200];
    int i, j = 0;

    // Key matrix
    int key[2][2] = {
        {9, 4},
        {5, 7}
    };

    printf("Enter Plain Text: ");
    fgets(plain, sizeof(plain), stdin);

    // Remove spaces and convert to uppercase
    for(i = 0; plain[i] != '\0'; i++)
    {
        if(isalpha(plain[i]))
            text[j++] = toupper(plain[i]);
    }

    text[j] = '\0';

    // Add X if length is odd
    if(j % 2 != 0)
    {
        text[j++] = 'X';
        text[j] = '\0';
    }

    // Encryption
    for(i = 0; i < j; i += 2)
    {
        int x = text[i] - 'A';
        int y = text[i + 1] - 'A';

        cipher[i] =
            mod(key[0][0] * x + key[0][1] * y) + 'A';

        cipher[i + 1] =
            mod(key[1][0] * x + key[1][1] * y) + 'A';
    }

    cipher[j] = '\0';

    printf("\nEncrypted Text: %s\n", cipher);

    // Find inverse of determinant
    int det = key[0][0] * key[1][1] -
              key[0][1] * key[1][0];

    det = mod(det);

    int inverse = 0;

    for(i = 1; i < 26; i++)
    {
        if(mod(det * i) == 1)
        {
            inverse = i;
            break;
        }
    }

    // Inverse key matrix
    int inv[2][2];

    inv[0][0] = mod(inverse * key[1][1]);
    inv[0][1] = mod(-inverse * key[0][1]);
    inv[1][0] = mod(-inverse * key[1][0]);
    inv[1][1] = mod(inverse * key[0][0]);

    // Decryption
    for(i = 0; i < j; i += 2)
    {
        int x = cipher[i] - 'A';
        int y = cipher[i + 1] - 'A';

        decrypt[i] =
            mod(inv[0][0] * x + inv[0][1] * y) + 'A';

        decrypt[i + 1] =
            mod(inv[1][0] * x + inv[1][1] * y) + 'A';
    }

    decrypt[j] = '\0';

    printf("Decrypted Text: %s\n", decrypt);

    return 0;
}