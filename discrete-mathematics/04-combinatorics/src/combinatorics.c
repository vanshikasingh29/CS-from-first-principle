#include "combinatorics.h"


unsigned long long factorial(
    unsigned int n
)
{
    unsigned long long result = 1;

    for(unsigned int i = 2;
        i <= n;
        i++)
    {
        result *= i;
    }

    return result;
}


unsigned long long permutation(
    unsigned int n,
    unsigned int r
)
{
    if(r > n)
    {
        return 0;
    }

    return factorial(n) /
           factorial(n - r);
}


unsigned long long combination(
    unsigned int n,
    unsigned int r
)
{
    if(r > n)
    {
        return 0;
    }

    /*
     * C(n,r) = n! / (r!(n-r)!)
     */

    return factorial(n) /
           (
               factorial(r) *
               factorial(n - r)
           );
}


unsigned long long binomial_recursive(
    unsigned int n,
    unsigned int k
)
{
    if(k > n)
    {
        return 0;
    }

    if(k == 0 || k == n)
    {
        return 1;
    }

    /*
     * Pascal's identity:
     *
     * C(n,k) =
     * C(n-1,k-1) + C(n-1,k)
     */

    return
        binomial_recursive(n - 1, k - 1)
        +
        binomial_recursive(n - 1, k);
}