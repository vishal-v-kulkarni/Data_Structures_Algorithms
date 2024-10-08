#include <stdio.h>
#include <stdlib.h>
#include <iostream>
_LIBCPP_SUPPRESS_DEPRECATED_POP

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
    int i, j;
    char B[7];

    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i -= 1;

    for (j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';

    printf("Reversed String: %s\n", B);
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

// CASE-Sensitive
void compareStrings(char A[], char B[])
{
    int i, j;

    for (i = 0, j = 0; A[i] != '\0' && B[i] != '\0'; i++, j++)
    {
        if (A[i] != B[i])
            break;
    }

    if (A[i] == B[i])
        cout << "Equal Strings" << endl;
    else if (A[i] > B[i])
        cout << "String A1 comes first in the dictionary" << endl;
    else
        cout << "String A1 comes first in the dictionary" << endl;
}

// Using 2 pointers like reversing the array CASE-SENSITIVE
bool isPalindrome(char *P)
{
    int i, j;
    for (j = 0; P[j] != '\0'; j++)
    {
    }

    j -= 1;

    for (i = 0; i <= j; i++, j--)
    {
        if (P[i] != P[j])
            return false;
    }

    return true;
}

void checkingDuplicates(char A[])
{
    int H[26] = {0}, i;
    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++;
    }

    for (int j = 0; j < 26; j++)
    {
        if (H[j] > 1)
        {
            cout << "Letter " << static_cast<char>(j + 97) << " repeats " << H[j] << " times." << endl;
        }
    }
}

void duplicatesBitwise(char *A)
{
    int H = 0, x = 0;

    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 97);

        if ((x & H) > 0)
        {
            cout << A[i] << " is a duplicate." << endl;
        }
        else
        {
            H = x | H;
        }
    }
}

bool areAnagrams(char *A, char *B)
{
    int H[26] = {0};

    for (int i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++;
    }

    for (int i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 97]--;
        if (H[B[i] - 97] < 0)
            return false;
    }

    // OR
    // for (int i = 0; i < 26; i++)
    // {
    //     if (H[i] != 0)
    //     {
    //         return false;
    //     }
    // }

    return true;
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
    reverseSecondArray(string);
    // reverseTwoPointers(string);

    char A1[] = "Chair";
    char A2[] = "Chairs";
    compareStrings(A1, A2);

    char *P = "MOM";
    if (isPalindrome(P))
        cout << "String " << P << " is a Palindrome" << endl;
    else
        cout << "String " << P << " is NOT a Palindrome" << endl;

    char *D = "finding";
    checkingDuplicates(D);
    duplicatesBitwise(D);

    char *S1 = "medical";
    char *S2 = "decimal";
    if (areAnagrams(S1, S2))
    {
        cout << "Both the strings are anagrams." << endl;
    }
    else
    {
        cout << "Both the strings are NOT anagrams." << endl;
    }
    return 0;
}