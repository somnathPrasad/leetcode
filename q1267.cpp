#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

void print2DVector(vector<vector<int>> &matrix)
{
    if (matrix.empty())
    {
        cout << "Matrix is empty." << endl;
        return;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    // Print column indices
    cout << "    "; // Space for row index
    for (int j = 0; j < cols; ++j)
    {
        cout << j << "   ";
    }
    cout << endl;

    // Print top border
    cout << "   +";
    for (int j = 0; j < cols; ++j)
    {
        cout << "---+";
    }
    cout << endl;

    // Print matrix with row indices and lines
    for (int i = 0; i < rows; ++i)
    {
        cout << " " << i << " |"; // Row index
        for (int j = 0; j < cols; ++j)
        {
            cout << " " << matrix[i][j] << " |";
        }
        cout << endl;

        // Print horizontal line between rows
        cout << "   +";
        for (int j = 0; j < cols; ++j)
        {
            cout << "---+";
        }
        cout << endl;
    }
}

void printVector(vector<int> arr)
{
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]";
}

bool isIndexWithinBounds(int totalRows, int totalCols, int row, int col)
{
    return row >= 0 && row < totalRows && col >= 0 && col < totalCols;
}

int countServers(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    unordered_map<int, int> rowMap, colMap;
    vector<pair<int, int>> serverCells;
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                serverCells.push_back({i, j});
                if (rowMap.find(i) == rowMap.end())
                {
                    rowMap[i] = 1;
                }
                else
                {
                    rowMap[i] += 1;
                }
                if (colMap.find(j) == colMap.end())
                {
                    colMap[j] = 1;
                }
                else
                {
                    colMap[j] += 1;
                }
            }
        }
    }

    for (int i = 0; i < serverCells.size(); i++)
    {
        auto [row, col] = serverCells[i];
        if (rowMap[row] > 1)
        {
            count++;
            continue;
        }
        if (colMap[col] > 1)
        {
            count++;
            continue;
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1}, {0, 0}};
    // vector<vector<int>> matrix = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    // vector<vector<int>> matrix = {{1}};
    // vector<vector<int>> matrix = {
    //     {0, 0, 0, 0, 0, 0, 1, 0},
    //     {0, 1, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 1, 0},
    //     {0, 0, 1, 0, 0, 0, 0, 0}};
    int count = countServers(matrix);

    // print2DVector(heights);
    return 0;
}