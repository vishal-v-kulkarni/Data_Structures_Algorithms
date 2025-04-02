#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ThreeSum(vector<int> &nums)
{
    // Replace this placeholder return statement with your code

    // Sorting in the ascending order
    sort(nums.begin(), nums.end());

    int pivot = 0;
    int low = 1;
    int high = nums.size() - 1;

    while (nums[pivot] > 0 || (pivot > nums.size() - 3))
    {
    }

    return {{}};
}

int main()
{
    return 0;
}
