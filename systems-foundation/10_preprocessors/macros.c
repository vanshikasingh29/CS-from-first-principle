/*
    ============================================================
    macros.c


    Purpose:

    Demonstrate preprocessor macros,
    constants, function-like macros,
    and conditional compilation.


    Concepts:

    - #define
    - Object-like macros
    - Function-like macros
    - Macro safety
    - Debug compilation


    Compile:

    gcc -Wall -Wextra -std=c17 macros.c -o macros


    Debug build:

    gcc -Wall -Wextra -std=c17 -DDEBUG macros.c -o macros


    ============================================================
*/


#include <stdio.h>





/*
    Object-like macro.

    Before compilation:

        BUFFER_SIZE


    becomes:


        100

*/


#define BUFFER_SIZE 100



/*
    Mathematical constant.

    Convention:
    Constants are often written in uppercase.

*/

#define PI 3.14159265359






/*
    Function-like macro.

    Important:

    Parentheses are required.

    Unsafe:

        #define SQUARE(x) x*x


    Example:

        SQUARE(2+3)


    becomes:

        2+3*2+3


    which is incorrect.


    Safe:

        ((x)*(x))

*/

#define SQUARE(x) ((x)*(x))






/*
    Debug macro.

    DEBUG only exists when compiled with:


    -DDEBUG


    Example:

    gcc program.c -DDEBUG


*/


#ifdef DEBUG

#define LOG(message) printf("DEBUG: %s\n", message)

#else

#define LOG(message)

#endif








int main(void)
{


    printf(
        "=== C Preprocessor Demonstration ===\n\n"
    );



    // Macro replacement.

    printf(
        "Buffer size: %d\n",
        BUFFER_SIZE
    );



    printf(
        "PI value: %.5f\n",
        PI
    );





    // Function-like macro.

    int number = 5;



    printf(
        "Square of %d = %d\n",
        number,
        SQUARE(number)
    );





    /*
        Demonstrating safe expansion:

        SQUARE(2+3)

        becomes:

        ((2+3)*(2+3))


        Result:

        25

    */


    printf(
        "Square of 2+3 = %d\n",
        SQUARE(2+3)
    );







    /*
        Conditional compilation.

        If compiled with:

        -DDEBUG


        this message appears.

    */


    LOG(
        "Program started successfully"
    );


    return 0;

}