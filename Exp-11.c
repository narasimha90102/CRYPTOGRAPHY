#include <stdio.h>
#include <math.h>

int main()
{
    double keys, power;

    keys = 1;

    for(int i = 1; i <= 25; i++)
    {
        keys = keys * i;
    }

    power = log(keys) / log(2);

    printf("Number of possible Playfair keys = 25!\n");
    printf("Approximate value = %.0e\n", keys);
    printf("Approximately = 2^%.0f\n", power);

    return 0;
}