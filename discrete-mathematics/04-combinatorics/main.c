#include <stdio.h>
#include "combinatorics.h"


int main(void)
{
    printf(
        "Combinatorics Lab\n"
    );

    printf(
        "=================\n\n"
    );


    printf(
        "5! = %llu\n",
        factorial(5)
    );


    printf(
        "P(5,2) = %llu\n",
        permutation(5, 2)
    );


    printf(
        "C(5,2) = %llu\n",
        combination(5, 2)
    );


    printf(
        "C(6,3) = %llu\n",
        combination(6, 3)
    );


    printf(
        "Recursive C(6,3) = %llu\n",
        binomial_recursive(6, 3)
    );


    return 0;
}