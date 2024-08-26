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

void vowelsConsonantsCount(char S[])
{
    int i, vcount = 0, ccount = 0;
    for (i = 0; S[i] != '\0'; i++)
    {
        if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' || S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U')
        {
            vcount++;
        }
        else if ((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122))
        {
            ccount++;
        }
    }
    cout << "Number of Vowels in the sentence are " << vcount << endl;
    cout << "Number of Consonants in the sentence are " << ccount << endl;
}

void wordsCount(char S[])
{
    int i, words = 0;

    for (i = 0; S[i] != '\0'; i++)
    {
        if (S[i] == ' ' && S[i - 1] != ' ')
            words++;
    }

    cout << "Number of words in the sentence are " << words + 1 << endl;
}

int main()
{

    char S[] = "WeLCOME";

    int length = stringLength(S);
    cout << "The length of the string is " << length << endl;

    toggleCase(S);

    char A[] = "How are    you"; // Big spaces are known as 'White Spaces'
    vowelsConsonantsCount(A);
    wordsCount(A);

    return 0;
}