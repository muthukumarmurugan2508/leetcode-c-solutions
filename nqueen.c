#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(int n, int row, char*** result, int* returnSize,
           char** board, int* col, int* diag1, int* diag2) {

    if (row == n) {
        result[*returnSize] = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            result[*returnSize][i] = strdup(board[i]);
        }
        (*returnSize)++;
        return;
    }

    for (int c = 0; c < n; c++) {

        if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
            continue;

        board[row][c] = 'Q';
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = 1;

        solve(n, row + 1, result, returnSize,
              board, col, diag1, diag2);

        board[row][c] = '.';
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = 0;
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {

    char*** result = (char***)malloc(10000 * sizeof(char**));
    *returnSize = 0;

    char** board = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc((n + 1) * sizeof(char));
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }

    int* col = (int*)calloc(n, sizeof(int));
    int* diag1 = (int*)calloc(2 * n, sizeof(int));
    int* diag2 = (int*)calloc(2 * n, sizeof(int));

    solve(n, 0, result, returnSize,
          board, col, diag1, diag2);

    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = n;

    return result;
}