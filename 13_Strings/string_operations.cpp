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

// String should not contain any symbols
bool validateString(char *A)
{
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (!((A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122) || (A[i] >= 48 && A[i] <= 57)))
        {
            return false;
        }
    }
    return true;
}

void reverseSecondArray(char A[])
{
    int i;
    char B[7];

    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i -= 1;

    for (int j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }

    printf("Reversed String: %s", B);
}

void reverseTwoPointers(char A[])
{
    int i, j;
    char temp;

    for (j = 0; A[j] != '\0'; j++)
    {
    }
    j -= 1;

    for (i = 0; i < j; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    cout << A << endl;
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

    char *B = "Wel?come";
    if (validateString(B))
    {
        cout << "Valid String" << endl;
    }
    else
    {
        cout << "Invalid String" << endl;
    }

    char string[] = "Python";
    // reverseSecondArray(string);
    reverseTwoPointers(string);

    return 0;
}