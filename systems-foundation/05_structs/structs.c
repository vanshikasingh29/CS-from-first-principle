/*
    ===========================================================
    structs.c


    Purpose:

    Demonstrate custom data structures,
    memory layout, struct pointers,
    and alignment.


    Concepts:

    - Creating structures
    - Accessing members
    - Struct pointers
    - Arrow operator
    - sizeof()
    - Memory addresses
    - Padding and alignment

    ============================================================
*/


#include <stdio.h>
#include <string.h>



/*
    Memory representation:

    Student


    +----------------+
    | id             |
    +----------------+
    | grade          |
    +----------------+
    | name           |
    +----------------+


*/

// Groups multiple data types into a unified custom blueprint
struct Student
{

    int id;  // 4 bytes

    char grade; // 1 byte

    char name[50];  // 50 bytes

};





/*
    Another structure to demonstrate padding and alignment.
    Notice:

        char

        followed by:

        int

    The compiler may insert padding between them.

*/

// Simple test struct to expose how hardware shifts memory addresses
struct AlignmentExample
{

     char letter;     // 1 byte
    int number;      // 4 bytes (Requires an address divisible by 4)

};



// Receives a pointer to a struct. 
//Passing the address avoids copying the entire structure.
// Takes a memory address rather than duplicating the entire structure
void print_student(struct Student *student)
{

    printf("\n=== Student Information ===\n");


    /*
        Arrow operator:
            pointer->field

        is equivalent to:
            (*pointer).field

    */

// The -> symbol dereferences the struct address and grabs the specified member
    printf("ID: %d\n",
           student->id);



    printf("Grade: %c\n",
           student->grade);



    printf("Name: %s\n",
           student->name);


}





int main(void)
{


    printf("=== Struct Demonstration ===\n\n");



    // Reserves a single, continuous chunk of stack memory using our blueprint.  Memory is allocated on the stack.
    struct Student student;



    // Use direct dot notation to write data straight into the allocated space
    student.id = 101;
    student.grade = 'A';



   // Must use strcpy because Strings cannot be assigned directly after declaration. Therefore we copy the characters.
    strcpy(student.name, "Computer Science");


// Passes the physical address of the struct block down to the function
    print_student(&student);



    printf("\n=== Memory Information ===\n");



    // sizeof returns the amount of memory occupied by the structure.
    // Shows total footprints (Includes extra space added silently by the compiler)
    printf("Size of Student struct: %zu bytes\n", sizeof(student));



   // Printing the address of the entire struct.
    // The starting boundary of our complete data block
    printf("Struct address: %p\n", (void *)&student);



    // Printing addresses of individual fields.
    //These demonstrate that struct members exist at different offsets.
    printf("\nField addresses:\n");


    // Demonstrates that members stack sequentially, one after another, in RAM
    printf( "id address: %p\n", (void *)&student.id);
    printf("grade address: %p\n", (void *)&student.grade);
    printf("name address: %p\n", (void *)&student.name);





    printf("\n=== Pointer To Struct ===\n");



   //  Creating a pointer to the struct.
   // Binds a specialized pointer directly to the struct's base address
    struct Student *pointer = &student;



    /*
        Accessing through pointer.

        These two are identical:


            student.id


            pointer->id


    */

    // Modifying through a pointer immediately alters the underlying memory stack
    printf("Access using pointer: %d\n", pointer->id);





    printf("\n=== Alignment Demonstration ===\n");



    struct AlignmentExample example;


    // Notice: 1 byte (char) + 4 bytes (int) will likely yield 8 bytes, not 5 bytes!
    printf("Size of AlignmentExample: %zu bytes\n", sizeof(example));


    // The CPU inserts 3 hidden padding bytes after 'letter' so 'number' aligns with 4
    printf("Address of char: %p\n", (void *)&example.letter);
    printf("Address of int: %p\n", (void *)&example.number);





    /*
        Why might the size be larger than:

            char + int

            1 + 4 = 5 bytes


        Because the compiler may insert:

            padding bytes


        Example:


        Without padding:

        +----+----+----+----+----+
        | c  | i  | i  | i  | i  |
        +----+----+----+----+----+


        With alignment:

        +----+----+----+----+----+
        | c  |pad |pad |pad | int|
        +----+----+----+----+----+


        This allows faster CPU access.

    */



    return 0;
}