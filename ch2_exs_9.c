/*Find the different uses of these {} and [] brackets*/

#include <stdlib.h>
#include <stdio.h>

int main(void) { /* Delimit the main function*/
  double A[5] = { /* Specifies array content */
    [0] = 9.0, /* 'Assigns' values to indexes */
    [1] = 2.9,
    [4] = 3.E+25,
    [3] = .00007,
  };

  for (size_t i = 0; i < 5; ++i) { /* Contains for loop */
     printf("element %zu is %g, \tits square is %g\n", 
            i,
            A[i], /* Specifies index for A array*/
            A[i]*A[i]); 
  } 

  return EXIT_SUCCESS;
}

