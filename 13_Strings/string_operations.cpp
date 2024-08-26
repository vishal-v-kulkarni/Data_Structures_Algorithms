#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int stringLength(char S[])
{
    int i;
    for (i = 0; S[i] != '\0'; i++)
    {
    }

    return i;
}

void toggleCase(char S[])
{
    int i;
    for (i = 0; S[i] != '\0'; i++)
    {
        if (S[i] >= 67 && S[i] <= 90)
            S[i] += 32;
        else if (S[i] >= 'a' && S[i] <= 122)
            S[i] -= 32;
    }
    cout << S << endl;
}

int main()
{

    char S[] = "WeLCOME";

    int length = stringLength(S);
    cout << "The length of the string is " << length << endl;

    toggleCase(S);

    return 0;
}