/*
    ============================================================
    recursion.c


    Purpose:

    Demonstrate recursion and observe how each
    recursive call creates a new stack frame.


    Concepts:

    - Base cases
    - Recursive calls
    - Stack growth
    - Function lifetime
    - Return order
    ============================================================
*/


#include <stdio.h>



/*
    Function: factorial

    Mathematical definition:

        n! = n × (n-1) × (n-2) ...

    Example:

        5!

        = 5 × 4 × 3 × 2 × 1

        = 120


    Recursive idea:

        factorial(n)

        depends on:

        factorial(n-1)


    Every recursive call creates
    a new stack frame.

*/

/*
    Calculates n! (e.g., 5! = 5 * 4 * 3 * 2 * 1 = 120)
    Each call pauses mid-calculation until the next call returns its result.
*/
int factorial(int n)
{


     // BASE CASE: Prevents infinite loops. Stops stack growth and returns 1.
    if(n == 1)
    {
        return 1;
    }



    //Recursive call: The current function pauses, until the smaller problem returns.
   
    // RECURSIVE STEP: Pauses current frame, creates a new one with (n - 1)
    // Example for n=3: returns 3 * factorial(2) -> which waits for 2 * factorial(1)
    return n * factorial(n - 1);

}





/*
    Function: trace_recursion

    Purpose:

    Makes the stack behaviour visible.

    Each function call prints before
    creating another stack frame.

*/


   // Visualises stack growth (going down) and stack unwinding (coming back up).
void trace_recursion(int depth)
{

    // EXECUTES ON THE WAY DOWN: Runs as each new stack frame is created
    printf("Entering function with depth: %d\n",
           depth);



    
   // BASE CASE: The absolute bottom of the recursion. Starts the chain reaction of returns. stops creating new stack frames
    if(depth == 0)
    {

        printf("Base case reached.\n");

        return; // Exits the deepest frame

    }



    //Recursive call: Another stack frame is created.
    trace_recursion(depth - 1);



    // This line executes while the stack is being removed.
    // The calls return in reverse order.
   // EXECUTES ON THE WAY UP: Runs in reverse order as stack frames are destroyed/popped
    printf("Returning from depth: %d\n",
           depth);

}





int main(void)
{


    printf("=== Recursive Function Demonstration ===\n\n");



    int number = 5;



    printf("Factorial of %d = %d\n\n",
           number,
           factorial(number));



    printf("=== Stack Trace Example ===\n\n");

// Traces 5 -> 4 -> 3 -> 2 -> 1 -> 0 (down), then prints returns from 1 -> 2 -> 3 -> 4 -> 5 (up)
    trace_recursion(5);



    return 0;
}