#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[100], cipher[100];
    int a, b, i;

    printf("Enter Plain Text: ");
    scanf("%s", text);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    // Check valid value of a
    if (a != 1 && a != 3 && a != 5 && a != 7 &&
        a != 9 && a != 11 && a != 15 && a != 17 &&
        a != 19 && a != 21 && a != 23 && a != 25)
    {
        printf("Invalid value of a\n");
        return 0;
    }

    for(i = 0; text[i] != '\0'; i++)
    {
        char ch = toupper(text[i]);

        cipher[i] = ((a * (ch - 'A') + b) % 26) + 'A';
    }

    cipher[i] = '\0';

    printf("Encrypted Text: %s\n", cipher);

    return 0;
}