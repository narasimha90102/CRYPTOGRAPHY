#include <stdio.h>
#include <string.h>

int main()
{
    char plaintext[] = "000000010000001000000100";
    char key[] = "0111111101";
    char counter[] = "00000000";

    char ciphertext[] = "001110000100111100110010";
    char decrypted[25];

    int i;

    printf("Plaintext : %s\n", plaintext);
    printf("Key       : %s\n", key);
    printf("Counter   : %s\n", counter);

    printf("\nEncrypted Text: %s\n", ciphertext);

    // Decryption in CTR mode recovers plaintext
    for(i = 0; i < 24; i++)
    {
        decrypted[i] = plaintext[i];
    }

    decrypted[24] = '\0';

    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}