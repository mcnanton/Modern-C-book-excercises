#include <stdlib.h>
#include <stdio.h>

int main() {
    const char *str = "12.345 is my number";
    char *endptr;
    float number;

    number = strtod(str, &endptr);

    printf("Full string: %s\n", str);
    printf("Number: %.3f\n", number);
    printf("Remaining string: %s\n", endptr);

    return 0;
}
