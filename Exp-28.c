#include <stdio.h>

long long powerMod(long long base, long long exp, long long mod)
{
    long long result = 1;

    while(exp > 0)
    {
        result = (result * base) % mod;
        exp--;
    }

    return result;
}

int main()
{
    long long q, a;
    long long xa, xb;
    long long ya, yb;
    long long keyA, keyB;

    printf("Enter public prime q: ");
    scanf("%lld", &q);

    printf("Enter public number a: ");
    scanf("%lld", &a);

    printf("Enter Alice secret key: ");
    scanf("%lld", &xa);

    printf("Enter Bob secret key: ");
    scanf("%lld", &xb);

    // Alice sends a^xa mod q
    ya = powerMod(a, xa, q);

    // Bob sends a^xb mod q
    yb = powerMod(a, xb, q);

    // Calculate shared keys
    keyA = powerMod(yb, xa, q);
    keyB = powerMod(ya, xb, q);

    printf("\nAlice public value: %lld\n", ya);
    printf("Bob public value  : %lld\n", yb);

    printf("Alice shared key  : %lld\n", keyA);
    printf("Bob shared key    : %lld\n", keyB);

    if(keyA == keyB)
        printf("\nKey Exchange Successful!\n");
    else
        printf("\nKey Exchange Failed!\n");

    return 0;
}