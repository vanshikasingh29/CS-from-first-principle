/*
    ===========================================================
    header_guards.c


    Purpose:

    Demonstrate the concept behind
    header guards.


    Concepts:

    - Header files
    - Multiple inclusion problem
    - #ifndef
    - #define
    - #endif


    ============================================================
*/


#include <stdio.h>





/*
    In a real project this would usually be placed in a separate file:

        math_utils.h

    Example:


    #ifndef MATH_UTILS_H
    #define MATH_UTILS_H

    int add(int a,int b);

    #endif


*/


#ifndef MATH_UTILS_H

#define MATH_UTILS_H



/*
    Function declaration.

    Headers normally contain declarations, not implementations.

*/

int add(int a, int b);



#endif







/*
    Function implementation.

    Normally this would be in:

        math_utils.c

*/

int add(int a, int b)
{

    return a + b;

}








int main(void)
{


    printf(
        "=== Header Guard Demonstration ===\n\n"
    );



    int result =
        add(10,20);



    printf(
        "Result: %d\n",
        result
    );





    /*
        Why header guards matter:

        Without guards:

        main.c

        includes:

            file1.h

                    |
                    |
                    v

            file2.h


                    |
                    |
                    v

            file1.h again

        Duplicate definitions occur.


        Guards ensure:

            First inclusion:
            
                Include contents


            Second inclusion:

                Ignore


    */



    return 0;

}