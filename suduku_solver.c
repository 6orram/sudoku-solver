#include<stdio.h>
#include<stdbool.h>

void print_table(int table[9][9]){
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("---------------------\n");
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                printf("| ");
            }
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

bool row_is_valid(int table[9][9], int r, int k){
    for (int i = 0; i < 9; i++) {
        if (table[r][i] == k) {
            return false; 
        }
    }
    return true;
}

bool col_is_valid(int table[9][9], int c, int k){
    for (int i = 0; i < 9; i++) {
        if (table[i][c] == k) {
            return false; 
        }
    }
    return true;
}

bool box_is_valid(int table[9][9], int r, int c, int k){
    int startRow = (r / 3) * 3;
    int startCol = (c / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (table[i][j] == k) {
                return false;
            }
        }
    }
    return true;
}

bool is_valid(int table[9][9], int r, int c, int k){
    return row_is_valid(table,r,k) * col_is_valid(table,c,k) * box_is_valid(table,r,c,k);
}

bool solve(int table[9][9], int r, int c) {
    if (r == 9) {
        return true;
    } else if (c == 9) {
        return solve(table, r + 1, 0);
    } else if (table[r][c] != 0) {
        return solve(table, r, c + 1);
    } else {
        for (int k = 1; k <= 9; k++) {
            if (is_valid(table, r, c, k)) {
                table[r][c] = k;
                if (solve(table, r, c + 1)) {
                    return true;
                }
                table[r][c] = 0;
            }
        }
        return false;
    }
}

int main(){
    int table[9][9] = {
        { 0, 5, 0, 4, 0, 3, 9, 7, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 6 },
        { 0, 0, 0, 8, 6, 0, 0, 0, 2 },
        { 0, 2, 0, 0, 0, 0, 0, 1, 3 },
        { 0, 0, 0, 9, 0, 0, 0, 0, 0 },
        { 0, 0, 4, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 9, 0, 3, 0 },
        { 0, 0, 6, 0, 7, 0, 2, 0, 1 },
        { 9, 0, 5, 0, 0, 8, 0, 0, 0 }
    };

    // solving function
    solve(table, 0, 0);

    // print the table
    print_table(table);
    
    

    return 0;
}