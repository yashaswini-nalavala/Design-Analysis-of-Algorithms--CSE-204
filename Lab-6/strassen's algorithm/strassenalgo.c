#include <stdio.h>

#define MAX 8

void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int C[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n) {
    int i, j;
    int half;

    int A11[MAX][MAX], A12[MAX][MAX];
    int A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX];
    int B21[MAX][MAX], B22[MAX][MAX];

    int M1[MAX][MAX], M2[MAX][MAX];
    int M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX];
    int M7[MAX][MAX];

    int T1[MAX][MAX], T2[MAX][MAX];

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    half = n / 2;

    for (i = 0; i < half; i++) {
        for (j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    addMatrix(A11, A22, T1, half);
    addMatrix(B11, B22, T2, half);
    strassen(T1, T2, M1, half);

    addMatrix(A21, A22, T1, half);
    strassen(T1, B11, M2, half);

    subtractMatrix(B12, B22, T2, half);
    strassen(A11, T2, M3, half);

    subtractMatrix(B21, B11, T2, half);
    strassen(A22, T2, M4, half);

    addMatrix(A11, A12, T1, half);
    strassen(T1, B22, M5, half);

    subtractMatrix(A21, A11, T1, half);
    addMatrix(B11, B12, T2, half);
    strassen(T1, T2, M6, half);

    subtractMatrix(A12, A22, T1, half);
    addMatrix(B21, B22, T2, half);
    strassen(T1, T2, M7, half);

    for (i = 0; i < half; i++) {
        for (j = 0; j < half; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];

            C[i][j + half] = M3[i][j] + M5[i][j];

            C[i + half][j] = M2[i][j] + M4[i][j];

            C[i + half][j + half] =
                M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n, i, j;

    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);

    printf("\nEnter elements of Matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(A, B, C, n);

    printf("\nResultant Matrix using Strassen's Algorithm:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}