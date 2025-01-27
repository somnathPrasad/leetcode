#include "helpers.h"

int searchInsert(vector<int> &nums, int target)
{
    function<int(int, int)> bs = [&](int start, int end)
    {
        if (start > end)
            return start;

        int mid = start + (end - start) / 2;
        if (target == nums[mid])
            return mid;

        if (target > nums[mid])
            return bs(mid + 1, end);

        return bs(start, mid - 1);
    };

    return bs(0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    cout << searchInsert(nums, 7);
}