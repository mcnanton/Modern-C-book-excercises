#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

enum { buf_max = 32 };
const char *dir = "../text_exs_54.txt";


int main(int argc, char* argv[argc + 1]) {
    int ret = EXIT_FAILURE;
    char buffer[buf_max + 1] = {0}; // Increased buffer size to accommodate one extra character
    for (int i = 1; i < argc; ++i) {
        FILE* instream = fopen( dir, "r");
        if (instream) {
            int line_number = 1; // Variable to store the line number
            while (fgets(buffer, buf_max + 1, instream)) {
                int len = strlen(buffer);
                int remaining_chars = len;
                int offset = 0;
                while (remaining_chars > 0) {
                    int chunk_size = remaining_chars > buf_max ? buf_max : remaining_chars;
                    printf("Line %d: %.*s", line_number, chunk_size, buffer + offset);
                    remaining_chars -= chunk_size;
                    offset += chunk_size;
                    if (remaining_chars > 0) {
                        line_number++;
                    }
                }
            }
            fclose(instream);
            ret = EXIT_SUCCESS;
        } else {
            fprintf(stderr, "Could not open %s: ", argv[i]);
            perror(0);
            errno = 0;
        }
    }
    return ret;
}