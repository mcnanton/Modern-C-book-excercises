# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

enum { buf_max = 32, }; //
const char *dir = "../text_exs_54.txt";

int main ( int argc , char * argv [ argc +1]) { 
    int ret = EXIT_FAILURE ; 
    char buffer [ buf_max ] = { 0 }; 
    for ( int i = 1; i < argc ; ++i) { 
        FILE * instream = fopen ( dir, "r"); 
        int line_number = 1; // Variable to store the line number
        if ( instream ) { 
            while ( fgets ( buffer , buf_max , instream )) {
                int len = strlen(buffer); // Stores the length of the string
                int remaining_chars = len; // Stores the remaining characters to be printed
                int offset = 0; // Stores the offset to be used in the next iteration???
                while (remaining_chars > 0) { // While there are remaining characters to be printed
                    int chars_to_print = remaining_chars > buf_max ? buf_max : remaining_chars; // If there are more than 32 characters to be printed, print 32, else print the remaining characters
                    printf("%d: %.*s", line_number, chars_to_print, buffer + offset); // Prints the line number, the number of characters to be printed and the offset
                    remaining_chars -= chars_to_print; // Decreases the remaining characters to be printed
                    offset += chars_to_print; // Increases the offset
                    if (remaining_chars > 0) {
                        line_number++;
                    }
                } 
            }
            fclose ( instream );
            ret = EXIT_SUCCESS ; 
        } else {
            fprintf ( stderr , " Could   not  open  %s: ", argv [i]);
            perror (0) ; 
            errno = 0; 
        }
        }
 return ret ; 
 }