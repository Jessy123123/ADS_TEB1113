#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateMatrix(vector<vector<int>> &mat)
{

    int m = mat.size();    // counts how many rows
    int n = mat[0].size(); // counts how many columns

    int row = 0, col = 0;
    int prev, curr;

    // Rotate the matrix in layers
    while (row < m && col < n) // Keep going while a layer exists
    {
        if (row + 1 == m || col + 1 == n) // when the remaining layer is only 1 row tall or 1 column wide
        {
            break;
        }

        // Store the first element of the next row
        prev = mat[row + 1][col];

        // Move elements of the first row
        for (int i = col; i < m; i++)
        {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        // Move elements of the last column
        for (int i = row; i < m; i++)
        {
            curr = mat[i][n - 1];
            mat[i][n - 1] = prev;
            prev = curr;
        }
        n--; // Moves the right boundary left

        // Move elements of the last row
        if (row < m)
        {
            for (int i = n - 1; i >= col; i--)
            {
                curr = mat[m - 1][i];
                mat[m - 1][i] = prev;
                prev = curr;
            }
        }
        m--; // Moves the bottom boundary up

        // Move elements of the first column
        if (col < n)
        {
            for (int i = m - 1; i >= row; i--)
            {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    rotateMatrix(mat);

    // Print the rotated matrix
    for (auto &r : mat) // range-based for loop (goes through every row in the matrix one by one)
    {
        for (int val : r) // walking through each element inside the current row
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
