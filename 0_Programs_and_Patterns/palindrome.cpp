#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool IsPalindrome(string inputString)
{
    // Replace this placeholder return statement with your coded
    int i = 0;
    int l = inputString.length() - 1;

    while (i <= l)
    {
        if (inputString[i] != inputString[l])
            return false;

        i++;
        l--;
    }

    return true;
}

int main()
{
    cout << "Result: " << IsPalindrome("hello") << endl;

    return 0;
}