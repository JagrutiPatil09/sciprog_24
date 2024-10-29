#include <stdio.h>
#include <math.h> // Include math library for tan() and M_PI

#define N 12
float TanArr[N+1]; // Array to hold tan(x) values at each degree
float degtorad(float degarg);
float traprule();

int main()
{
    // Declare variables
    int i;
    float a=0.0, b_deg=60.0;
    float deg;

    // Calculate tan(x) at points 0, 5, 10, ..., 60 and store in TanArr
    for (i = 0; i < N; i=i+1)  // Change loop to go from 0 to N (inclusive)
    {
        deg = i * 5.0;
        TanArr[i] = tan(degtorad(deg));
        printf("TanArr[%d]: %f\n", i, TanArr[i]); // Print each value to verify
    }

    float area = traprule();

    // Approximated result
    printf("\nTrapezoidal result is: %f\n", area);
    // Actual result
    // Integral of tan(x) from 0 to ln(2)
    printf("Real result is: %f\n", log(2.0));

    return 0;
}

// Function to convert degrees to radians
float degtorad(float degarg) 
{
   float pi = 3.1415927;
   return (pi * degarg) / 180.0;
}

// Function to calculate area under tan(x) using the Trapezoidal Rule
float traprule() 
{
   float area;
   int i;

    // Initialize area with first and last values of TanArr
    area = TanArr[0] + TanArr[N];
    printf("\nInitial area (sum at x(0) and x(12)) = %f\n", area);

    // Add the rest of the tan(x) values with weight 2 in the Trapezoidal Rule
    for (i = 1; i < N; i++)
    {
        area += 2 * TanArr[i];
    }

    printf("The value of sum after the loop is: %f\n", area);

    // Calculate the width of each trapezoid
    float mult_rad = degtorad((60.0 - 0.0) / (2 * N)); // Step size in radians
    area = mult_rad * area;

    return area;
}
