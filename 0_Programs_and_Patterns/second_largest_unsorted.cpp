// Find the second largest element in an unsorted array

/*

Given an array of positive integers arr[] of size n, the task is to find second largest distinct element in the array.

Note: If the second largest element does not exist, return -1.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.

Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.

Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 there is no second largest element.

*/

// Better Solution
class Solution
{
public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr)
    {
        // Code Here
        int largest = arr[0];
        int secondL = -1;
        for (int x : arr)
        {
            if (x >= largest)
            {
                largest = x;
            }
        }

        for (int x : arr)
        {
            if (x > secondL && x < largest)
            {
                secondL = x;
            }
        }

        // cout << largest;

        return secondL;
    }
};

// Best or Expected Solution
class Solution
{
public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr)
    {
        // Code Here
        int largest = -1;
        int secondL = -1;
        for (int x : arr)
        {
            if (x > largest)
            {
                secondL = largest;
                largest = x;
            }
            else if (x > secondL && x < largest)
            {
                secondL = x;
            }
        }

        return secondL;
    }
};