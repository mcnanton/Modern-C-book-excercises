/*Correct listing 1.2 step by step. Start from the first diagnostic line, fix the code that is mentioned there,
recompile, and so on, until you have a flawless program. */

/*void main () {
    // Declarations
    int i;
    double A [5] = {
        9.0 ,
        2.9 ,
        3.E+25 ,
        .00007 ,
    };

    // Doing some work
    for (i = 0; i < 5; ++i) {
        printf (" element  %d is %g, \ tits   square  is %g\n",
            i,
            A[i],
            A[i]*A[i]);
    }

return 0;
}*/

/*Run with gcc -Wall -std=c99 -g exs_6.c*/
/*Use -Werror to not create an executable even when there are just warnings*/

/* Fixed listing */

/* Include files*/
#include <stdio.h>

/* The main thing that this program does . */

int main () {
    // Declarations
    int i;
    double A [5] = {
        [0] = 9.0 ,
        [1] = 2.9 ,
        [4] = 3.E+25 ,
        [3] = .00007 ,
    };

// Doing some work
    for (i = 0; i < 5; ++i) {
        printf (" element  %d is %g, \tits   square  is %g\n",
                i,
                A[i],
                A[i]*A[i]);
    }

    return 0;
}