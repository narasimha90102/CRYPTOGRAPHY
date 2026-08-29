#include <stdio.h>

int main()
{
    int rate = 1024;
    int state = 1600;
    int capacity = state - rate;

    int lanes = state / 64;
    int capacityLanes = capacity / 64;

    int blocks = 0;

    printf("SHA-3 State Size      : %d bits\n", state);
    printf("Block Size             : %d bits\n", rate);
    printf("Capacity               : %d bits\n", capacity);
    printf("Total Lanes            : %d\n", lanes);
    printf("Capacity Lanes         : %d\n", capacityLanes);

    /*
       Each message block has nonzero bits in
       all lanes belonging to the rate portion.

       Without permutation, the original capacity
       lanes remain zero.
    */

    printf("\nInitial capacity lanes are zero.\n");

    blocks = 1;

    printf("After %d message block: ", blocks);

    if(capacityLanes > 0)
        printf("Capacity lanes are still zero.\n");
    else
        printf("All lanes are nonzero.\n");

    printf("\nSince permutation is ignored, the original\n");
    printf("zero capacity lanes never receive nonzero bits.\n");

    printf("\nAnswer: They will never become nonzero\n");
    printf("under the conditions given in the question.\n");

    return 0;
}