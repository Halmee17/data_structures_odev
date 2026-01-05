#include <stdio.h>

typedef struct {
    int row, col, val;
} Sparse;

int main() {
    int mat[3][3] = {
        {0, 0, 3},
        {4, 0, 0},
        {0, 5, 0}
    };

    Sparse sp[10];
    int k = 1;

    sp[0].row = 3;
    sp[0].col = 3;
    sp[0].val = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(mat[i][j] != 0) {
                sp[k].row = i;
                sp[k].col = j;
                sp[k].val = mat[i][j];
                k++;
                sp[0].val++;
            }
        }
    }

    for(int i = 0; i < k; i++)
        printf("%d %d %d\n", sp[i].row, sp[i].col, sp[i].val);

    return 0;
}
