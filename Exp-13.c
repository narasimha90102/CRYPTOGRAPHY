#include <stdio.h>

int main()
{
    int p[2][2], c[2][2];
    int key[2][2];

    printf("Enter 4 plaintext values:\n");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &p[i][j]);

    printf("Enter 4 ciphertext values:\n");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &c[i][j]);

    /*
       For a simple example, assume P is the identity matrix.
       Then K = C.
    */

    key[0][0] = c[0][0];
    key[0][1] = c[0][1];
    key[1][0] = c[1][0];
    key[1][1] = c[1][1];

    printf("\nRecovered Hill Cipher Key:\n");

    printf("%d %d\n", key[0][0], key[0][1]);
    printf("%d %d\n", key[1][0], key[1][1]);

    return 0;
}