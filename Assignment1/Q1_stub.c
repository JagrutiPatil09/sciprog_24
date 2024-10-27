// TODO: Complete the inclusion of necessary libraries
#include <stdio.h>
#include <math.h> // Needed for the pow() function


int main() {

//TODO: Complete variable declarations
    int n,i;
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    float alpha, beta, denominator;

// TODO: Enter the number of data points
    printf("Enter the number of data points (n): ");
    scanf("%d", &n);

    float x[n], y[n];

// TODO: Enter (xi, yi) values i=1, 2, ..., n
//       Note that C array indices start from 0
    printf("Enter the x and y values for each data point:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

/*
TODO: Calculate alpha and beta formulas
      Use the pow() function for the calculation of power of 2 in the formula.
      Check and exit the code if the denominator for a is equal to zero.
*/
    for (i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += pow(x[i], 2); // Using pow() to calculate x[i]^2
    }

    denominator = n * sum_x2 - pow(sum_x, 2);
    if (denominator == 0) {
        printf("Error: Division by zero in the calculation of alpha.\n");
        return 1;
    }

    alpha = (n * sum_xy - sum_x * sum_y) / denominator;
    beta = (sum_y - alpha * sum_x) / n;

//TODO: Print the equation of the line 

    printf("The equation of the best-fitting line is: y = %.2fx + %.2f\n", alpha, beta);

    return 0;
}