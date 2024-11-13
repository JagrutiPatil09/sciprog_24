#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function declarations
double arctanh1(double x, double delta);
double arctanh2(double x);

int main(void) {
    double delta;
    
    // Get user input for delta
    printf("Please enter a positive real number delta:\n");
    if (scanf("%lf", &delta) != 1) {  
        printf("Invalid input.\n");
        return 1;
    }

    // Check if delta is negative
    if (delta < 0) {
        printf("Delta was negative\n");
        exit(1);
    }

    // Variables for calculating arctanh
    double x;
    int length = 19; // Updated length to match step size
    double step = 0.1;

    // Loop through values of x from -0.9 to 0.9
    for (int i = 0; i < length; i++) {
        x = -0.9 + i * step;
        double tan1 = arctanh1(x, delta);
        double tan2 = arctanh2(x);
        printf("The difference at x = %.2lf is %.10lf\n", x, fabs(tan1 - tan2));
    }

    return 0;
}

// Function to compute arctanh using the series expansion
double arctanh1(double x, double delta) {
    double sum = 0;
    double elem, val;
    int n = 0;

    // Use a series expansion until the term is smaller than delta
    do {
        val = 2 * n + 1;
        elem = pow(x, val) / val;
        sum += elem;
        n++;
    } while (fabs(elem) >= delta);

    return sum;
}

// Function to compute arctanh using the built-in formula
double arctanh2(double x) {
    return (log(1 + x) - log(1 - x)) / 2;
}
