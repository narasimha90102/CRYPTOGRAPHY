#include <stdio.h>

long long mod(long long a, long long m)
{
    return (a % m + m) % m;
}

long long power(long long a, long long b, long long m)
{
    long long result = 1;

    while(b > 0)
    {
        result = (result * a) % m;
        b--;
    }

    return result;
}

int main()
{
    long long p = 23;
    long long q = 11;
    long long g = 4;

    long long x = 3;       // Private key
    long long y;
    long long H = 5;       // Message hash

    long long k1 = 2;
    long long k2 = 7;

    long long r1, s1;
    long long r2, s2;

    y = power(g, x, p);

    // Signature 1
    r1 = power(g, k1, p) % q;
    s1 = mod((H + x * r1) * 6, q);

    // Signature 2
    r2 = power(g, k2, p) % q;
    s2 = mod((H + x * r2) * 8, q);

    printf("Message Hash = %lld\n", H);
    printf("Public Key   = %lld\n", y);

    printf("\nSignature 1:\n");
    printf("k = %lld\n", k1);
    printf("r = %lld\n", r1);
    printf("s = %lld\n", s1);

    printf("\nSignature 2:\n");
    printf("k = %lld\n", k2);
    printf("r = %lld\n", r2);
    printf("s = %lld\n", s2);

    printf("\nConclusion:\n");

    if(r1 != r2 || s1 != s2)
        printf("Same message produced different signatures.\n");
    else
        printf("Signatures are the same.\n");

    return 0;
}