#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

// This program reads files and prints it to stdout.

enum { buf_max = 32, }; //

int main ( int argc , char * argv [ argc +1]) { 
    int ret = EXIT_FAILURE ; // same as ret = 1 
    char buffer [ buf_max ] = { 0 }; // Declares 32 chars array initialized to 0
    for ( int i = 1; i < argc ; ++i) { // Goes over all the arguments, each one is a file path
        FILE * instream = fopen ( argv [i], "r"); // We assume argv containts paths of files
        if ( instream ) { // Check that the pointer is different from NULL
            while ( fgets ( buffer , buf_max , instream )) { // Name of the array is a poiner to its first element 
                fputs ( buffer , stdout ); // Prints each line until reaching EOF
            }
            fclose ( instream );
            ret = EXIT_SUCCESS ; // If we reach this point, the file was succesfully read. 
        } else {
            /* Provides some error diagnostic . */
            fprintf ( stderr , " Could   not  open  %s: ", argv [i]);
            perror (0) ; // Prints corresponding error code
            errno = 0; // Resets the error code
        }
        }
 return ret ; // Returns the last value of ret 
 }