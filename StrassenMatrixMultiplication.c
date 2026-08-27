#include <stdio.h>

int main() {
    // Define two 2x2 matrices A and B
    int A[2][2] = {{2, 1}, {3, 2}};
    int B[2][2] = {{1, 3}, {2, 1}};
    int C[2][2];
    int P1, P2, P3, P4, P5, P6, P7;

    // Strassen's algorithm for 2x2 matrix multiplication
    P1 = A[0][0] * (B[0][1] - B[1][1]);
    P2 = (A[0][0] + A[0][1]) * B[1][1];
    P3 = (A[1][0] + A[1][1]) * B[0][0];
    P4 = A[1][1] * (B[1][0] - B[0][0]);
    P5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    P6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    P7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);

    // Calculate the resulting matrix C using the Strassen's formula
    C[0][0] = P5 + P4 - P2 + P6;
    C[0][1] = P1 + P2;
    C[1][0] = P3 + P4;
    C[1][1] = P1 + P5 - P3 - P7;

    // Print the resulting matrix C
    printf("Result matrix:\n");
    for (int row = 0; row < 2; row++) {
        for (int column = 0; column < 2; column++) {
            printf("%d ", C[row][column]);
        }
        printf("\n");
    }

    return 0;
}