#include <stdio.h>
#include <ctype.h>

int main()
{
    char cipher[200];
    int shift, i;

    printf("Enter Cipher Text: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("\nPossible Plaintexts:\n");

    for(shift = 0; shift < 26; shift++)
    {
        printf("Shift %d: ", shift);

        for(i = 0; cipher[i] != '\0'; i++)
        {
            if(isalpha(cipher[i]))
            {
                char ch = toupper(cipher[i]);
                ch = (ch - 'A' - shift + 26) % 26 + 'A';
                printf("%c", ch);
            }
            else
            {
                printf("%c", cipher[i]);
            }
        }

        printf("\n");
    }

    return 0;
}