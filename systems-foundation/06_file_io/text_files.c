/*
    ============================================================
    text_files.c


    Purpose:

    Demonstrate reading and writing
    human-readable text files.


    Concepts:

    - FILE pointers
    - fopen()
    - fprintf()
    - fgets()
    - fclose()
    - File error handling
    - Streams
    ============================================================
*/


#include <stdio.h>
#include <stdlib.h>



int main(void)
{


    /*
        FILE pointer.

        This does not store the file contents.

        It represents a connection between:

            Program

                ↓

            Operating System

                ↓

            File

    */

    FILE *file;



    /*
        Opening a file.

        Mode:

            w

        means:

            write

        If the file does not exist, it will be created.

        If it exists,contents are replaced.

    */

    file = fopen("student.txt", "w");



    /*
        Always check if opening succeeded.

        fopen returns NULL on failure.

    */

    if(file == NULL)
    {

        printf("Error opening file.\n");

        return 1;

    }




    /*
        Writing formatted text.

        Similar to printf(), but output goes to a file.

    */

    fprintf(file, "Name: Alice\nAge: 21\nCourse: Computer Science\n");



    /*
        Closing the file.

        This:

        - releases resources
        - flushes buffers
        - ensures data is written

    */

    fclose(file);




    printf("File written successfully.\n\n");





    /*
        Reopening the file.

        Mode:

            r

        means:

            read

    */

    file = fopen("student.txt", "r");



    if(file == NULL)
    {

        printf("Unable to read file.\n");

        return 1;

    }





    printf("Reading file contents:\n\n");



  
    //Buffer for storing each line.
    char buffer[100];



    /*
        fgets()

        Reads one line at a time.

        Stops when:

        - newline found
        - buffer full
        - end of file reached

    */

    while(fgets(buffer, sizeof(buffer), file))
    {

        printf("%s", buffer);

    }




    fclose(file);



    return 0;
}