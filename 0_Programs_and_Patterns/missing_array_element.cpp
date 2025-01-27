// This will NOT work for long integers, hence add "long long" instead of int for larger inputs.

/*
You are given an array arr of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

Examples:

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.

1 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ arr.size() + 1
*/

class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        // code here
        long long n = arr.size() + 1;
        long long sum = (n * (n + 1)) / 2;

        long long sumArray = 0;

        for (int x : arr)
        {
            sumArray += x;
        }

        return sum - sumArray;
    }
};