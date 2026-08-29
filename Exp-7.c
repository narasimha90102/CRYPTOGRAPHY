#include <stdio.h>
#include <string.h>
int main()
{
    char cipher[500];
    char plain[500];
    char key[256] = {0};
    int i;
    key['5'] = 'A';
    key['3'] = 'T';
    key['@'] = 'H';
    key['#'] = 'E';
    printf("Enter the Cipher Text:\n");
    scanf("%s", cipher);

    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(key[(unsigned char)cipher[i]] != 0)
            plain[i] = key[(unsigned char)cipher[i]];
        else
            plain[i] = cipher[i];
    }
    plain[i] = '\0';
    printf("\nDecrypted Text: %s\n", plain);
    return 0;
}