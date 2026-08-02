/*
    ============================================================
    assertions.c


    Purpose:

    Demonstrate defensive programming,
    assertions, and error checking.


    Concepts:

    - assert()
    - Defensive programming
    - Runtime validation
    - Detecting invalid states
    - NULL checking
    ============================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>





/*
    Function:
    calculate_average


    Purpose:
    Calculate average of numbers.


    Engineering idea:
    Before performing an operation, verify assumptions.


    Requirement:
    count must be greater than zero.


*/


double calculate_average(
    int values[],
    int count
)
{


    /*
        Assertion:
        The programmer expects:

            count > 0


        If this assumption fails,  the program stops immediately.

    */


    assert(count > 0);

    int total = 0;

    for(int i = 0; i < count; i++)
    {
        total += values[i];
    }
    return (double)total / count;

}







/*
    Function:
    safe_divide


    Demonstrates:
    Expected errors should be handled normally, not with assertions.

    Division by zero can happen from user input.

*/


double safe_divide(
    double a,
    double b
)
{


    if(b == 0)
    {

        printf(
            "Error: Cannot divide by zero.\n"
        );


        return 0;

    }



    return a / b;

}







/*
    Function:
    allocate_memory


    Demonstrates:
    Checking resources.

*/

int *allocate_memory(int size)
{


    // Validate input.

    if(size <= 0)
    {

        return NULL;

    }



    int *array = malloc(
        sizeof(int) * size
    );



    
        // malloc can fail.

       // This is an expected runtime problem, therefore we handle it normally.


    if(array == NULL)
    {

        return NULL;

    }



    return array;

}







int main(void)
{


    printf(
        "=== Debugging Demonstration ===\n\n"
    );





    /*
        Example 1:
        Assertions

    */


    int numbers[] =
    {
        10,
        20,
        30
    };



    double average =
        calculate_average(
            numbers,
            3
        );



    printf(
        "Average: %.2f\n",
        average
    );







    /*
        Example 2:
        Normal error handling.


        Division by zero is not necessarily a programmer mistake.
        It may come from user input.

    */


    printf("\nDivision example:\n");



    double result =
        safe_divide(
            10,
            2
        );



    printf(
        "Result: %.2f\n",
        result
    );








    /*
        Example 3:
        Memory allocation checking.

    */


    printf("\nMemory allocation example:\n");



    int *data =
        allocate_memory(5);




    if(data == NULL)
    {

        printf(
            "Memory allocation failed.\n"
        );


        return 1;

    }




    // Use allocated memory.

    for(int i = 0; i < 5; i++)
    {

        data[i] = i * 10;

    }




    printf(
        "Allocated values:\n"
    );


    for(int i = 0; i < 5; i++)
    {

        printf(
            "%d\n",
            data[i]
        );

    }





    // Release memory.

    free(data);



    // Remove dangling pointer.

    data = NULL;



    printf(
        "\nMemory released safely.\n"
    );






    /*
        Debugging principle:

        Every assumption should be either:
            1. Guaranteed

            OR

            2. Checked


        Good engineers make invalid states difficult to reach.

    */



    return 0;

}