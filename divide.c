#include <limits.h>

int divide(int dividend, int divisor) {
    
    // Overflow case
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determine sign
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Convert to long to avoid overflow
    long dvd = labs((long)dividend);
    long dvs = labs((long)divisor);
    long result = 0;

    while (dvd >= dvs) {
        long temp = dvs;
        long multiple = 1;

        // Double divisor until it exceeds dividend
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        result += multiple;
    }

    result = (sign == -1) ? -result : result;

    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;

    return (int)result;
}