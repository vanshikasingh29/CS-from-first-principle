/*
    ============================================================
    binary_files.c


    Purpose:

    Demonstrate storing and reading
    raw binary data.


    Concepts:

    - Binary files
    - Struct serialization
    - fwrite()
    - fread()
    - Memory representation
    - Persistent structures
    ============================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
    A structure represents a block of organised memory.

    We can store this exact memory representation inside a file.

*/


struct Employee
{

    int id;

    char name[50];

    double salary;

};






int main(void)
{


    struct Employee employee;



    // Creating data.

    employee.id = 1001;


    strcpy(
        employee.name,
        "Software Engineer"
    );


    employee.salary = 65000.00;





    /*
        Opening binary file.

        wb:

            write binary

    */

    FILE *file = fopen(
        "employee.dat",
        "wb"
    );



    if(file == NULL)
    {

        printf("Unable to create file.\n");

        return 1;

    }





    /*
        fwrite()

        Writes raw bytes.

        Memory:

        Struct

        +-------------+
        | id          |
        +-------------+
        | name        |
        +-------------+
        | salary      |
        +-------------+


        becomes:
        Binary File
        010101010101

    */


    fwrite(
        &employee,
        sizeof(struct Employee),
        1,
        file
    );



    fclose(file);



    printf("Binary data saved.\n\n");






    /*
        Clear the structure.

        Demonstrates that we are loading from disk.

    */

    memset(
        &employee,
        0,
        sizeof(employee)
    );






    /*
        Open binary file again.

        rb:

            read binary

    */

    file = fopen(
        "employee.dat",
        "rb"
    );



    if(file == NULL)
    {

        printf("Unable to open binary file.\n");

        return 1;

    }





    /*
        fread()

        Copies bytes from the file back into memory.

    */

    fread(
        &employee,
        sizeof(struct Employee),
        1,
        file
    );



    fclose(file);





    printf("=== Loaded Employee ===\n\n");


    printf(
        "ID: %d\n",
        employee.id
    );


    printf(
        "Role: %s\n",
        employee.name
    );


    printf(
        "Salary: %.2f\n",
        employee.salary
    );





    /*
        Important:

        Binary files are efficient, but they are not always portable.


        Problems can occur because of:

        - Different CPU architectures
        - Different integer sizes
        - Different compiler padding

    */



    return 0;
}