#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int len, i;

    printf("Enter Plain Text: ");
    scanf("%s", text);

    len = strlen(text);

    printf("\nOriginal Text: %s", text);
    printf("\nOriginal Length: %d", len);

    // Add 1 bit
    text[len] = '1';
    len++;

    // Add 0 bits until block size becomes 8
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