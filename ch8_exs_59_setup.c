#include <stdio.h>

/* Supposes that lowercase characters are contiguous . */
_Static_assert ('z'-'a' == 25, //OJO
 "alphabetic characters not contiguous");
 # include <ctype.h>
 /* Converts an alphanumeric digit to an unsigned */
 /* '0' ... '9' => 0 .. 9u */
 /* 'A' ... 'Z' => 10 .. 35u */
 /* 'a' ... 'z' => 10 .. 35u */
 /* Other values => Greater */
 unsigned hexatridecimal (int a) {
    if ( isdigit (a)) {
    /* This is guaranteed to work : decimal digits
    are consecutive , and isdigit is not
    locale dependent . */
        return a - '0'; // 0 represents 48 in ASCII. This returns the numeric value of the character
    } else {
    /* Leaves a unchanged if it is not lowercase */
    a = toupper (a);
 /* Returns value >= 36 if not Latin uppercase */
    return ( isupper (a)) ? 10 + (a - 'A') : -1; // This assumes that uppercase letters are consecutive?
    }
 }

 int main()
 {
   /* code */
   int result = hexatridecimal('Ñ');
   printf("%d\n", result);
   return 0;
 }
 