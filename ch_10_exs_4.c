# include <stdlib.h>
# include <stdio.h>

#define max(a,b) ((a) < (b) ? (b) : (a))

int main (int argc , char* argv[argc +1]) {
    int i = 6;
    printf("Output of max macro: %d", max(i++,5) );
    return 0;
}