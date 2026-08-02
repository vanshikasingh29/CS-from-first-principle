/*
    ============================================================
    call_stack.c


    Purpose:

    Demonstrate nested function calls
    and how stack frames are created
    and destroyed.


    Concepts:

    - Function calling order
    - Stack growth
    - Local variable lifetime
    - Return sequence
    ============================================================
*/


#include <stdio.h>



/*
    Third function.

    This is the deepest point
    in our call chain.

*/
void function_three(void)
{

    /*
        Local variable.

        Stored inside this function's
        stack frame.

    */
    int value_three = 300;



    printf("\nInside function_three\n");

    printf("Local value: %d\n",
           value_three);


}



/*
    Second function.

    Calls function_three.

*/
void function_two(void)
{


    int value_two = 200;



    printf("\nInside function_two\n");

    printf("Local value: %d\n",
           value_two);



    /*
        Stack before call:

        +----------------+
        | function_two  |
        +----------------+


        After call:

        +----------------+
        | function_three|
        +----------------+
        | function_two  |
        +----------------+

    */

    function_three();



    /*
        function_three has now returned.

        Its stack frame disappears.

        Execution continues here.

    */

    printf("Returned to function_two\n");

}



/*
    First function after main.

*/
void function_one(void)
{


    int value_one = 100;



    printf("\nInside function_one\n");

    printf("Local value: %d\n",
           value_one);



    function_two();



    printf("Returned to function_one\n");

}





int main(void)
{


    printf("=== Call Stack Demonstration ===\n");



    /*
        Program execution begins in main.

        Current stack:


        +-------------+
        | main        |
        +-------------+

    */


    function_one();



    // After function_one returns: Its stack frame is removed.
    printf("\nBack inside main\n");



    return 0;
}