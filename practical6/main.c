#include <stdio.h>

// Function prototype for matmult
void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]);

int main() {
    int n = 5, p = 3, q = 4;
    double A[n][p], B[p][q], C[n][q];
    int i, j; // Loop indices

    // Initialize matrices A, B, and C
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            A[i][j] = i + j;
        }
    }
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            B[i][j] = i - j;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < q; j++) {
            C[i][j] = 0.0;
        }
    }

    // Perform matrix multiplication
    matmult(n, p, q, A, B, C);

    // Print out matrices
    printf("\nThis is matrix A:\n\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            printf("%6.1f ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nThis is matrix B:\n\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            printf("%6.1f ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nThis is matrix C (Result of A x B):\n\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < q; j++) {
            printf("%6.1f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

