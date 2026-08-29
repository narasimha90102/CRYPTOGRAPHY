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
    int n, m, g;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter plaintext block: ");
    scanf("%d", &m);

    g = gcd(m, n);

    printf("\nGCD(%d, %d) = %d\n", m, n, g);

    if(g > 1 && g < n)
    {
        printf("Common factor found!\n");
        printf("Factor of n = %d\n", g);
        printf("RSA modulus n can be factored.\n");
    }
    else
    {
        printf("No useful common factor found.\n");
    }

    return 0;
}