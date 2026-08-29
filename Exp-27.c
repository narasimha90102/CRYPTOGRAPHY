#include <stdio.h>

long long powerMod(long long base, long long exp, long long n)
{
    long long result = 1;

    while(exp > 0)
    {
        result = (result * base) % n;
        exp--;
    }

    return result;
}

int main()
{
    int e;
    long long n;
    char text[100];
    int i;

    printf("Enter public key e: ");
    scanf("%d", &e);

    printf("Enter modulus n: ");
    scanf("%lld", &n);

    printf("Enter message (capital letters): ");
    scanf("%s", text);

    printf("\nEncrypted values:\n");

    for(i = 0; text[i] != '\0'; i++)
    {
        int m = text[i] - 'A';

        long long c = powerMod(m, e, n);

        printf("%lld ", c);
    }

    printf("\n");

    printf("\nAttack idea:\n");
    printf("Only 26 possible plaintext values exist (0 to 25).\n");
    printf("An attacker can encrypt all 26 values and compare them.\n");

    return 0;
}