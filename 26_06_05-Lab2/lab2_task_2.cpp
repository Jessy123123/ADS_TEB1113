#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> diagonalOrder(const vector<vector<int>> &mat) // Function Signature
{
    vector<int> res;

    int n = mat.size();    // number of rows = 5
    int m = mat[0].size(); // number of cols = 4

    for (int line = 1; line <= (n + m - 1); line++) // A matrix of size n rows × m cols always has exactly n + m − 1 anti-diagonals
    {
        int startCol = max(0, line - n);            // finding the starting column
        int count = min({line, (m - startCol), n}); // counting elements in this diagonal

        for (int j = 0; j < count; j++)
        {
            int row = min(n, line) - j - 1;
            int col = startCol + j;
            res.push_back(mat[row][col]); // appending the value
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}};

    vector<int> res = diagonalOrder(mat);

    for (auto val : res)
    {
        cout << val << " ";
    }
    cout << endl;
}