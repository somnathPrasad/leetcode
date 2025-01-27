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

vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
{
    int rows = isWater.size(), cols = isWater[0].size();
    vector<vector<int>> heights(rows, vector<int>(cols, -1)); // rows x cols all cells initailized to -1
    queue<pair<int, int>> bfsQueue;

    // initialize all water cells to 0 and add to queue
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (isWater[i][j] == 1)
            {
                bfsQueue.push({i, j});
                heights[i][j] = 0;
            }
        }
    }

    int adjCells[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!bfsQueue.empty())
    {
        auto [i, j] = bfsQueue.front();
        bfsQueue.pop();

        for (auto [dx, dy] : adjCells)
        {
            int x = i + dx, y = j + dy;
            if (isIndexWithinBounds(rows, cols, x, y) && heights[x][y] == -1)
            {
                heights[x][y] = heights[i][j] + 1;
                bfsQueue.push({x, y});
            }
        }
    }

    return heights;
}

int main()
{
    // vector<vector<int>> matrix = {{0, 1}, {0, 0}};
    vector<vector<int>> matrix = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
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
    vector<vector<int>> heights = highestPeak(matrix);

    print2DVector(heights);
    return 0;
}