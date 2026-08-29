#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], cipher[100];
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    int i, j = 0;

    printf("Enter Plain Text: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            text[i] = toupper(text[i]);

            cipher[j] = ((text[i] - 'A') + key[j]) % 26 + 'A';
            j++;
        }
    }

    cipher[j] = '\0';

    printf("Encrypted Text: %s\n", cipher);

    return 0;
}