#include "helpers.h"

class Solution
{
private:
    int findParent(vector<int> &parent, int i)
    {
        if (parent[i] == -1)
            return i;
        return findParent(parent, parent[i]);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1, -1);

        for (auto edge : edges)
        {
            int x = findParent(parent, edge[0]);
            int y = findParent(parent, edge[1]);

            if (x == y)
                return edge;

            parent[x] = y;
        }

        return parent;
    }
};

int main()
{
    vector<vector<int>> v1 = {{1, 2}, {1, 3}, {2, 3}};
    vector<vector<int>> v2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};

    Solution sol;
    printVector(sol.findRedundantConnection(v1));
    printVector(sol.findRedundantConnection(v2));

    return 0;
}