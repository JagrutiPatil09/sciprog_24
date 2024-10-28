#include <stdio.h>
#include <math.h>

int main() {
    // Define variables
    double a = 0.0;
    double b = M_PI / 3.0;  // Upper limit is pi/3
    int N = 12;  // Number of intervals
    double h = (b - a) / N;  // Width of each interval

    // Initialize sum with the end points
    double sum = tan(a) + tan(b);

    // Loop through interior points and add 2*tan(x_i) to the sum
    for (int i = 1; i < N; i++) {
        double x_i = a + i * h;
        sum += 2 * tan(x_i);
    }

    // Final calculation of the area under the curve
    double area = (h / 2) * sum;

    // Calculate the exact result and the error
    double exact_result = log(2);
    double error = fabs(area - exact_result);

    // Print the results
    printf("Approximate area under curve using trapezoidal rule: %.6f\n", area);
    printf("Exact area (log(2)): %.6f\n", exact_result);
    printf("Error: %.6f\n", error);

    return 0;
}
