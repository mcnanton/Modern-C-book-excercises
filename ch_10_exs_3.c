# include <stdlib.h>
# include <stdio.h>

#define sum(a, b) a+b

int main (int argc , char* argv[argc +1]) {

    printf("Output of sum macro: %d", sum(5,2) * 7 ); // 5 + 2 * 7
    return 0;
}