#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* Plan: Create a supervisor module that monitors a specific file. When first run, it will load the file into a buffer. It will then continuously monitor the file location to see if the file is present */
/* I would like to expand this to be able to port one executable inside another. Also, to be able to add paramters if necessary. */

// return true if the file specified by the filename exists
bool file_exists(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    bool is_exist = false;
    if (fp != NULL)
    {
        // It does indeed exist
        is_exist = true;

        // char *secretString="ROCKS";

        // char buf[100]; // Either char* buf or char buf[<your_buffer_size>]
        // int myNumber = -1;
        // while((fgets(buf, 100, fp)!=NULL)) 
        // {  //good to handle error as well
        //     if(strstr(buf, secretString)!=NULL) 
        //     {
        //         sscanf(buf + strlen(secretString), "%d", &myNumber);
        //         break;
        //     }
        // }
        // printf("After the loop, myNumber is %d\n", myNumber);


        // Define and allocate source file variable
        char *source = NULL;

        FILE *fp = fopen("foo.txt", "r");
        if (fp != NULL) {

            /* Go to the end of the file. */
            if (fseek(fp, 0L, SEEK_END) == 0) {

                /* Get the size of the file. */
                long bufsize = ftell(fp);
                if (bufsize == -1) { /* Error */ }

                /* Allocate our buffer to that size. */
                source = malloc(sizeof(char) * (bufsize + 1));

                /* Go back to the start of the file. */
                if (fseek(fp, 0L, SEEK_SET) != 0) { /* Error */ }

                /* Read the entire file into memory. */
                size_t newLen = fread(source, sizeof(char), bufsize, fp);
                if ( ferror( fp ) != 0 ) {
                    fputs("Error reading file", stderr);
                } else {
                    source[newLen++] = '\0'; /* Just to be safe. */
                }
            }
            fclose(fp);
        }

        free(source); /* Don't forget to call free() later! */


        

        fclose(fp); // close the file
    }
    return is_exist;
}

int main()
{
    char *filename = "C:\\Users\\joshr\\Documents\\Jex\\KheePittDuhp\\main.c";

    // Check if file exists
    if (file_exists(filename))
        printf("File %s exists", filename);
    else
        printf("File %s doesn't exist.", filename);

    return 0;
}