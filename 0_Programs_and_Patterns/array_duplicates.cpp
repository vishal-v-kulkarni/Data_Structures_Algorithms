/*
Given an array arr of integers, find all the elements that occur more than once in the array. If no element repeats, return an empty array.

Examples:

Input: arr[] = [2, 3, 1, 2, 3]
Output: [2, 3]
Explanation: 2 and 3 occur more than once in the given array.
Input: arr[] = [0, 3, 1, 2]
Output: []
Explanation: There is no repeating element in the array, so the output is empty.
Input: arr[] = [2]
Output: []
Explanation: There is single element in the array. Therefore output is empty.
*/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &arr)
    {
        // code here
        unordered_map<int, int> freq;
        vector<int> result;

        // Hashing for frequency
        for (int x : arr)
        {
            freq[x]++;
        }

        // Checking for duplicates into new vector
        for (auto f : freq)
        {
            if (f.second > 1)
                result.push_back(f.first);
        }

        return result;
    }
};