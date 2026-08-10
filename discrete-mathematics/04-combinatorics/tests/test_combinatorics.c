#include <stdio.h>
#include "combinatorics.h"


int passed = 0;
int failed = 0;


void assert_test(
    int condition,
    const char* name
)
{
    if(condition)
    {
        printf("[PASS] %s\n", name);
        passed++;
    }
    else
    {
        printf("[FAIL] %s\n", name);
        failed++;
    }
}


int main(void)
{
    printf(
        "Combinatorics Test Suite\n"
    );

    printf(
        "========================\n\n"
    );


    assert_test(
        factorial(0) == 1,
        "Factorial zero"
    );


    assert_test(
        factorial(5) == 120,
        "Factorial"
    );


    assert_test(
        permutation(5, 2) == 20,
        "Permutation"
    );


    assert_test(
        permutation(5, 5) == 120,
        "Full permutation"
    );


    assert_test(
        combination(5, 2) == 10,
        "Combination"
    );


    assert_test(
        combination(6, 3) == 20,
        "Combination C(6,3)"
    );


    assert_test(
        combination(10, 0) == 1,
        "Combination boundary"
    );


    assert_test(
        binomial_recursive(6, 3) == 20,
        "Recursive binomial coefficient"
    );


    assert_test(
        combination(7, 2) == combination(7, 5),
        "Combination symmetry"
    );


    printf(
        "\nPassed: %d\n",
        passed
    );

    printf(
        "Failed: %d\n",
        failed
    );


    return failed == 0 ? 0 : 1;
}