#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int len, i;

    printf("Enter Plain Text: ");
    fgets(text, sizeof(text), stdin);

    len = strlen(text);

    if(text[len - 1] == '\n')
    {
        text[len - 1] = '\0';
        len--;
    }

    printf("\nOriginal Text: %s", text);
    printf("\nOriginal Length: %d", len);

    // Add padding
    text[len] = '1';
    len++;

    while(len % 8 != 0)
    {
        text[len] = '0';
        len++;
    }

    text[len] = '\0';

    printf("\nPadded Text: %s", text);
    printf("\nPadded Length: %d\n", len);

    return 0;
}