#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], cipher[100];
    int key[100];
    int n, i;

    printf("Enter Plain Text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter number of key values: ");
    scanf("%d", &n);

    printf("Enter key values:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &key[i]);

    int j = 0;

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