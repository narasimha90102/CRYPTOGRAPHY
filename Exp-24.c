#include <stdio.h>

int main()
{
    int n = 3599;
    int e = 31;
    int p, q, phi;
    int d;

    // Find p and q
    for(p = 2; p < n; p++)
    {
        if(n % p == 0)
        {
            q = n / p;
            break;
        }
    }

    printf("p = %d\n", p);
    printf("q = %d\n", q);

    // Calculate phi(n)
    phi = (p - 1) * (q - 1);

    printf("Phi(n) = %d\n", phi);

    // Find d such that (d * e) mod phi = 1
    for(d = 1; d < phi; d++)
    {
        if((d * e) % phi == 1)
            break;
    }

    printf("Public Key  = (%d, %d)\n", e, n);
    printf("Private Key = (%d, %d)\n", d, n);

    return 0;
}