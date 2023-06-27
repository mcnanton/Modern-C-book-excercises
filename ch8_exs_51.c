#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

float my_strtod(const char *str, char **ptr){
    int sign = 1; 

// 1- Remove spaces.
    while(isspace(*str)){
        str++;
    }

// 2- Check for negative sign that we want to keep
    if(*str == '-'){
        sign = -1;
    }

// 3- Search for integer part
    float result = 0;
    while(isdigit(*str)){
        result = (result * 10) + (float)(*str - '0');
        str++;
    }

// 4- Search for fractional part
    float fraction = 0.1f; // Initialize fraction value
    if (*str == '.' || *str == ',') //Check for commas or dots
    {
        str++; // Skip comma

        while(isdigit(*str)){
        result = result + (*str - '0') * fraction;
        fraction = fraction * 0.1f; // Update the fraction value by dividing it by 10
        str++; 
        }
    } else { // Even if it's not a point / comma, we still need to skip the position
        str++; 
    }
    
// 5- Search for exponent if any

    if (*str == 'e' || *str == 'E') {
        str++; // Skip 'e' or 'E'

        int exponentSign = 1; // We initialize the exponent sign to positive
        if (*str == '-') {
            exponentSign = -1;
            str++; // Skip negative sign
        } else if (*str == '+') {
            str++; // Skip positive sign
        }

        int exponent = 0;
        while (isdigit(*str)) {
            exponent = (exponent * 10) + (*str - '0');
            str++;
        }

        result *= powf(10, exponentSign * exponent); 
    }

// 6 - Update pointer to the remaining text
    *ptr = (char *)str; 

// 7- Return the result
    return result * sign;
}

int main() {
    const char *str = "5,45 is my number";
    char *endptr;
    float number;
    number = my_strtod(str, &endptr);

    printf("Full string: %s\n", str);
    printf("Number: %.3f\n", number);
    printf("Remaining string: %s\n", endptr);

    return 0;
}