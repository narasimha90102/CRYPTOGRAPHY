#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char plain[100], cipher[100];
    char map[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    int i;
    printf("Enter Plain Text (Lowercase): ");
    scanf("%s", plain);
    for(i = 0; plain[i] != '\0'; i++)
    {
        if(plain[i] >= 'a' && plain[i] <= 'z')
        {
            cipher[i] = map[plain[i] - 'a'];
        }
        else
        {
            cipher[i] = plain[i];
        }
    }
    cipher[i] = '\0';
    printf("\nPlain Text  : %s\n", plain);
    printf("Cipher Text : %s\n", cipher);
    return 0;
}