#include <stdio.h>

int main()
{
    int P[2][2], C[2][2];
    int K[2][2];

    printf("Enter Plaintext Matrix (2x2):\n");

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &P[i][j]);

    printf("Enter Ciphertext Matrix (2x2):\n");

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &C[i][j]);

    /*
       Simple example:
       If P is an identity matrix,
       then K = C.
    */

    if(P[0][0] == 1 && P[0][1] == 0 &&
       P[1][0] == 0 && P[1][1] == 1)
    {
        K[0][0] = C[0][0];
        K[0][1] = C[0][1];
        K[1][0] = C[1][0];
        K[1][1] = C[1][1];

        printf("\nRecovered Key Matrix:\n");

        printf("%d %d\n", K[0][0], K[0][1]);
        printf("%d %d\n", K[1][0], K[1][1]);
    }
    else
    {
        printf("\nUse an identity plaintext matrix for this simple example.\n");
    }

    return 0;
}