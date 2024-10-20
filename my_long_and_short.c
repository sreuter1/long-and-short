#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    
    // declaring variables
    unsigned int toFile1 = 0;
    unsigned int toFile2 = 0;
    char str[255];
    int len;
    
    // checking the input arguements
    if (argc != 4)
    {
        printf("There is not an appropriate amount of command-line arguements");
    }

    // open the files
    // file 1: file to read from 
    FILE * file1 = fopen(argv[1], "r");

    // file 2: file to write to
    FILE * file2 = fopen(argv[2], "w");

    // file 3: file to write to
    FILE * file3 = fopen(argv[3], "w");

    // iterating through the read only file
    while (fgets(str, 255, file1))
    {
        
        len = strlen(str);
        // if length is less than 20 character
        if ( len < 20 )
        {
            // converting the string to upper
            for(int i = 0; i < len ; i++)
            {
                str[i] = toupper(str[i]);
            }

            // send to the first file
            fputs(str, file2);

            // incrementing
            toFile1++;
        }

        // if length is 20 characters or more than 20 characters
        else
        {
            // converting to lower
            for(int i = 0; i < len ; i++)
            {
                str[i] = tolower(str[i]);
            }

            // send to the second file
            fputs(str, file3);

            // incrementing
            toFile2++;
        }

    }
    
    // close all of the files
    fclose(file1);
    fclose(file2);
    fclose(file3);

    // printing the details
    printf("%d lines written to %s\n", toFile1, argv[2]);
    printf("%d lines written to %s\n", toFile2, argv[3]);

}