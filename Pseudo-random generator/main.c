#include <stdio.h>
#include <limits.h>
/*
Simple congruent pseudo-random generator
*/

// ix = seed
unsigned int ix = 0;

// Generate pseudo-random number in interval <0,1>
double Random(){
    ix = (ix * 69069L) + 1; // ix = (ix * A + B) mod M --> mod M is 2^32 thanks to unsigned int
    return ix / ((double)UINT_MAX); // interval 0 to 1, including 1
    //return ix / ((double)UINT_MAX + 1); // interval <0, 1)
}

int main()
{
    ix = (unsigned)time(NULL); // current timestamp as seed
    
    printf("Random %.53f\n", Random());
    return 0;
}
