#include <stdio.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int p = 61;
    int q = 53;
    int n, phi;
    int e, d;

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("n = %d\n", n);
    printf("Phi(n) = %d\n", phi);

    // Choose public key
    e = 17;

    // Find private key
    for(d = 1; d < phi; d++)
    {
        if((d * e) % phi == 1)
            break;
    }

    printf("\nOriginal Public Key : (%d, %d)\n", e, n);
    printf("Original Private Key: (%d, %d)\n", d, n);

    // Generate another valid public key
    for(e = 3; e < phi; e++)
    {
        if(gcd(e, phi) == 1)
            break;
    }

    for(d = 1; d < phi; d++)
    {
        if((d * e) % phi == 1)
            break;
    }

    printf("\nNew Public Key      : (%d, %d)\n", e, n);
    printf("New Private Key     : (%d, %d)\n", d, n);

    printf("\nConclusion:\n");
    printf("Changing only the keys while keeping the same n is NOT safe.\n");
    printf("A new RSA modulus should be generated.\n");

    return 0;
}