#include "helpers.h"

class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        stack<pair<int, int>> stk;
        stk.push({i, j});
        int totalFish = 0;

        while (!stk.empty())
        {
            auto [x, y] = stk.top();
            stk.pop();
            totalFish += grid[x][y];
            grid[x][y] = 0;

            for (auto [dx, dy] : directions)
            {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0)
                    stk.push({nx, ny});
            }
        }

        return totalFish;
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        // Iterate over each cell in the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > 0)
                    maxFish = max(maxFish, dfs(grid, i, j));
            }
        }

        return maxFish;
    }
};

int main()
{
    vector<vector<int>> grid1 = {{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}};
    vector<vector<int>> grid2 = {{10, 0, 0}};
    vector<vector<int>> grid3 = {{2, 0, 5}};

    Solution sol;
    cout << sol.findMaxFish(grid1) << endl;
    cout << sol.findMaxFish(grid2) << endl;
    cout << sol.findMaxFish(grid3) << endl;
    return 0;
}