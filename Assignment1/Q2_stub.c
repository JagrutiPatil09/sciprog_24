#include <stdio.h>

/*
TODO: Write function declaration 
      for the calculation of the determinant of 3x3 matrix
*/
float getdet(float minor[3][3]);

int main(void) {

//TODO: Complete variable declarations
   float hmat[4][4], minor[3][3];
   float det = 0.0;

//TODO: Initialise Hilbert matrix and print
    printf("Hilbert Matrix:\n");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                hmat[i][j] = 1.0 / (i + j + 1);  // Populate Hilbert matrix
                printf("%.4f ", hmat[i][j]);     // Print each element with 4 decimal precision
            }
            printf("\n");
        }

//TODO: Find determinant of 4x4 Hilbert matrix using Cramer rule
    for (int col = 0; col < 4; col++) {
        // Fill 3x3 minor matrix by excluding the 1st row and the 'col'-th column
        for (int i = 1; i < 4; i++) {
            int minor_col = 0;
            for (int j = 0; j < 4; j++) {
                if (j == col) continue;  // Skip the 'col'-th column
                minor[i - 1][minor_col] = hmat[i][j];
                minor_col++;
            }
        }

        // Calculate cofactor and add to determinant
        float cofactor = (col % 2 == 0 ? 1 : -1) * hmat[0][col] * getdet(minor);
        det += cofactor;
    }

//TODO: Print calculated determinant
    printf("Determinant of the 4x4 Hilbert matrix: %.4f\n", det);

    return 0;
}

//TODO: Complete function definition to get determinant  
float getdet(float minor[3][3]) {
    // Calculate the determinant of a 3x3 matrix using cofactor expansion
    float a = minor[0][0], b = minor[0][1], c = minor[0][2];
    float d = minor[1][0], e = minor[1][1], f = minor[1][2];
    float g = minor[2][0], h = minor[2][1], i = minor[2][2];
    return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}


