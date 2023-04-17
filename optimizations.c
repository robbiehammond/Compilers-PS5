#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
const double EPS = 1E-9;

// Finds the rank of a matrix 
// Implementation created based on this C++ code: https://cp-algorithms.com/linear_algebra/rank-matrix.html
int rank(int rows, int cols, ll** matrix) {
    int rank = 0;
    int* row_selected = malloc(rows * sizeof(int));
    int i;
    for (i = 0; i < cols; i++) {
        int j;
        for (j = 0; j < rows; j++) {
            if (!row_selected[j] && llabs(matrix[j][i]) > EPS) 
                break;
        }
        if (j != rows) {
            rank++;
            row_selected[i] = 1;
            int p;
            for (p = i + 1; p < cols; p++) {
                matrix[j][p] /= matrix[j][i];
            }
            int k;
            for (int k = 0; k < rows; k++) {
                if (k != j && llabs(matrix[k][i]) > EPS) {
                    for (p = i + 1; p < cols; p++) {
                        matrix[k][p] -= matrix[j][p] * matrix[k][i];
                    }
                }
            }
        }
    }
    return rank;
}

int main() {
    int rows, cols;
    rows = 500;
    cols = 500;
    ll** matrix;
    matrix = malloc(rows * sizeof(ll*));
    int i;
    for (i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(ll));
    }
    int j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = random();
        }
    }
    printf("%d", rank(rows, cols, matrix));
}