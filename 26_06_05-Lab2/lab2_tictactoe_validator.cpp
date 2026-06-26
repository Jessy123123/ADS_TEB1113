#include <iostream>

using namespace std;

int win[8][3] = {
    {0, 1, 2}, // check 1st row
    {3, 4, 5}, // check 2nd row
    {6, 7, 8}, // check 3rd row
    {0, 3, 6}, // check 1st col
    {1, 4, 7}, // check 2nd col
    {2, 5, 8}, // check 3rd col
    {0, 4, 8}, // check 1st diagonal
    {2, 4, 6}, // check 2nd diagonal
};

bool isCWin(char *board, char c)
{
    for (int i = 0; i < 8; i++)
    {
        if (board[win[i][0]] == c &&
            board[win[i][1]] == c &&
            board[win[i][2]] == c)
            return true;
    }
    return false;
};

bool isValid(char board[9])
{
    int xCount = 0, oCount = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 'X')
        {
            xCount++;
        }
        if (board[i] == 'O')
        {
            oCount++;
        }
    }

    if (xCount == oCount || xCount == oCount + 1)
    {
        if (isCWin(board, 'O'))
        {
            if (isCWin(board, 'X')) // both can't win simultaneously
            {
                return false;
            }

            return (xCount == oCount); // O wins only if O played last
        }

        if (isCWin(board, 'X') && xCount != oCount + 1) // X must have oCount + 1 moves when winning
        {
            return false;
        }

        return true; // valid if nobody won & the counts are balanced
    }
    return false;
}

int main()
{

    // game starts with X
    char board[] = {
        'X', 'X', 'O',
        'O', 'O', 'X',
        'X', 'O', 'X'};

    // condition ? expression_if_true : expression_if_false;
    (isValid(board)) ? cout << "Given board is valid" : cout << "Given board is not valid";

    return 0;
}