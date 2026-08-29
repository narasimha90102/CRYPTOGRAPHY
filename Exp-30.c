#include <stdio.h>

int main()
{
    int X, T, secondBlock, finalMAC;

    printf("Enter message block X: ");
    scanf("%d", &X);

    printf("Enter CBC-MAC T: ");
    scanf("%d", &T);

    // Calculate X XOR T
    secondBlock = X ^ T;

    printf("\nOriginal Message Block X = %d", X);
    printf("\nOriginal MAC T = %d", T);

    printf("\n\nConstructed Second Block (X XOR T) = %d", secondBlock);

    // CBC-MAC of X || (X XOR T) becomes T
    finalMAC = T;

    printf("\nMAC of X || (X XOR T) = %d\n", finalMAC);

    return 0;
}