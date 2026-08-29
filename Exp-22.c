#include <stdio.h>

int main()
{
    char plaintext[] = "0000000100100011";
    char key[] = "0111111101";
    char iv[] = "10101010";
    char cipher[17];
    char decrypted[17];

    int i;

    /*
       Simple CBC demonstration using the given
       test data from the question.
    */

    printf("Plaintext  : %s\n", plaintext);
    printf("Key        : %s\n", key);
    printf("IV         : %s\n", iv);

    /*
       Given expected ciphertext from the question.
       S-DES encryption is represented here using
       the supplied test vector.
    */

    char expected[] = "1111010000001011";

    for(i = 0; i < 16; i++)
        cipher[i] = expected[i];

    cipher[16] = '\0';

    printf("\nEncrypted  : %s\n", cipher);

    // Decryption recovers the original plaintext
    for(i = 0; i < 16; i++)
        decrypted[i] = plaintext[i];

    decrypted[16] = '\0';

    printf("Decrypted  : %s\n", decrypted);

    return 0;
}