#include "helpers.h"

vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
{
    if (nums.size() <= 1)
        return nums;

    vector<int> sortedNums(nums.size());
    partial_sort_copy(begin(nums), end(nums), begin(sortedNums), end(sortedNums));
    vector<queue<int>> groups;
    unordered_map<int, int> grpMap;

    for (int i = 0; i < sortedNums.size(); i++)
    {
        if (groups.size() == 0 || sortedNums[i] - sortedNums[i - 1] > limit)
        {
            queue<int> q;
            groups.push_back(q);
        }

        groups[groups.size() - 1].push(sortedNums[i]);
        grpMap[sortedNums[i]] = groups.size() - 1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int grp = grpMap[nums[i]];
        sortedNums[i] = groups[grp].front();
        groups[grp].pop();
    }

    return sortedNums;
}

int main()
{
    vector<int> nums = {1, 5, 3, 9, 8};
    int limit = 2;

    // vector<int> nums = {1, 7, 6, 18, 2, 1};
    // int limit = 3;

    // vector<int> nums = {1, 7, 28, 19, 10};
    // int limit = 3;

    vector<int> sorted = lexicographicallySmallestArray(nums, limit);
    printVector(sorted);
}