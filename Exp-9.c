#include <stdio.h>
#include <string.h>
char matrix[5][5] = {
    {'P','L','A','Y','F'},
    {'I','R','E','X','M'},
    {'B','C','D','G','H'},
    {'K','N','O','Q','S'},
    {'T','U','V','W','Z'}
};
void findPosition(char ch, int *row, int *col)
{
    int i, j;
    if(ch == 'J')
        ch = 'I';
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
            }
        }
    }
}
int main()
{
    char text[100];
    int i, r1, c1, r2, c2;
    printf("Enter Plain Text (Uppercase): ");
    scanf("%s", text);
    printf("\nCipher Text: ");
    for(i = 0; text[i] != '\0'; i += 2)
    {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);
        if(r1 == r2)
        {
            printf("%c", matrix[r1][(c1 + 1) % 5]);
            printf("%c", matrix[r2][(c2 + 1) % 5]);
        }
        else if(c1 == c2)
        {
            printf("%c", matrix[(r1 + 1) % 5][c1]);
            printf("%c", matrix[(r2 + 1) % 5][c2]);
        }
        else
        {
            printf("%c", matrix[r1][c2]);
            printf("%c", matrix[r2][c1]);
        }
    }
    printf("\n");
    return 0;
}