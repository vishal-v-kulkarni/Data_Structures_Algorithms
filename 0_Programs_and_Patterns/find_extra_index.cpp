// Finding the index of the extra element - BETTER way BINARY SEARCH (TODO)

/*
You have given two sorted arrays arr1[] & arr2[] of distinct elements. The first array has one element extra added in between. Return the index of the extra element.

Note: 0-based indexing is followed.

Examples

Input: a[] = [2,4,6,8,9,10,12], b[] = [2,4,6,8,10,12]
Output: 4
Explanation: In the first array, 9 is extra added and it's index is 4.

Constraints:
2<=arr1.size()<=105
1<=arr1[i],arr2[i]<=106

*/

class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        // code here
        int n = arr.size() + 1;
        int sum = (n * (n + 1)) / 2;

        int sumArray = 0;

        for (int x : arr)
        {
            sumArray += x;
        }

        return sum - sumArray;
    }
};