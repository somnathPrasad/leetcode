#include "helpers.h"

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
{
    vector<bool> check(queries.size(), false);
    unordered_map<int, vector<int>> adjList;
    vector<vector<int>> cache(numCourses, vector<int>(numCourses, -1));

    // create adjacency list
    for (int i = 0; i < prerequisites.size(); i++)
        adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);

    function<bool(int, int)> dfs = [&](int course, int preq)
    {
        if (cache[course][preq] != -1)
            return cache[course][preq];

        for (int i = 0; i < adjList[course].size(); i++)
        {
            if (adjList[course][i] == preq || dfs(adjList[course][i], preq))
            {
                cache[course][preq] = true;
                return cache[course][preq];
            }
        }

        cache[course][preq] = false;
        return cache[course][preq];
    };

    for (int i = 0; i < queries.size(); i++)
        check[i] = dfs(queries[i][1], queries[i][0]);

    return check;
}

int main()
{
    // int numCourses = 3;
    // vector<vector<int>> prerequisites = {{1, 2}, {1, 0}, {2, 0}};
    // vector<vector<int>> queries = {{1, 0}, {1, 2}};

    int numCourses = 5;
    vector<vector<int>> prerequisites = {{4, 3}, {4, 1}, {4, 0}, {3, 2}, {3, 1}, {3, 0}, {2, 1}, {2, 0}, {1, 0}};
    vector<vector<int>> queries = {{1, 4}, {4, 2}, {0, 1}, {4, 0}, {0, 2}, {1, 3}, {0, 1}};

    vector<bool> check = checkIfPrerequisite(numCourses, prerequisites, queries);

    printBoolVector(check);

    return 0;
}