#include <stdio.h>
#define true 1
#define false 0
#define size 8

int count = 0;

int check(int board[][8] , int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;
    
    for (i = row, j = col; j >= 0 && i < size; i++, j--)
        if(board[i][j])
            return false;
    
    return true;
}

int dp(int board[][8], int col)
{
    if (col == size)
    {
        count++;
        return 0;
    }

    for (int row = 0; row < size; row++)
    {
        if (check(board, row, col))
        {
            board[row][col] = 1;
            dp(board, col + 1);
            board[row][col] = 0;
        }
    }
    return 0;
}

int main(void)
{
    int board[size][size] = {0};
    dp(board, 0);
    printf("%d", count);
    return 0;
}