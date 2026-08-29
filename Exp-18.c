#include <stdio.h>
#include <string.h>

void leftShift(char half[], int shift)
{
    char temp[29];
    int i;

    for(i = 0; i < 28; i++)
        temp[i] = half[(i + shift) % 28];

    temp[28] = '\0';

    strcpy(half, temp);
}

int main()
{
    char key[57];
    char left[29], right[29];
    int i, round;
    int shift[16] = {
        1, 1, 2, 2, 2, 2, 2, 2,
        1, 2, 2, 2, 2, 2, 2, 1
    };

    printf("Enter 56-bit key: ");
    scanf("%56s", key);

    // Divide key into two 28-bit halves
    for(i = 0; i < 28; i++)
        left[i] = key[i];

    left[28] = '\0';

    for(i = 0; i < 28; i++)
        right[i] = key[i + 28];

    right[28] = '\0';

    printf("\nDES Subkeys:\n");

    for(round = 0; round < 16; round++)
    {
        leftShift(left, shift[round]);
        leftShift(right, shift[round]);

        printf("K%d = ", round + 1);

        // Print first 24 bits from left half
        for(i = 0; i < 24; i++)
            printf("%c", left[i]);

        // Print second 24 bits from right half
        for(i = 0; i < 24; i++)
            printf("%c", right[i]);

        printf("\n");
    }

    return 0;
}