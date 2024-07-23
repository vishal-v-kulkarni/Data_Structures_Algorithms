#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

    void Swap(int *elementOne, int *elementTwo);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Append(int element);
    void Insert(int index, int element);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int RecBinarySearch(int l, int h, int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    int SumRec(int n);
    float Avg();
    void Reverse();
    void ReverseSwap();
    void LeftShift();
    void LeftRotate();
    void RightShift();
    void RightRotate();
    void InsertSorted(int x);
    bool isSorted(Array arr);
    void NegativeArrange();
    Array *MergeArrays(Array arr2);
    Array *UnionArrays(Array arr1, Array arr2);
    Array *IntersectionArrays(Array arr1, Array arr2);
    Array *DifferenceArrays(Array arr1, Array arr2);
};

// Scope resolution for the class Array
void Array::Display()
{
    cout << "Elements are: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << endl;
    }
}

/* struct Array Append(struct Array arr, int element){
    if(arr.length < arr.size){
        arr.A[arr.length] = element;
        arr.length++;
    }
    return arr;
}
*/

// Instead of returning the struct(above), we can pass struct as an address and make changes.
void Array::Append(int element)
{
    if (length < size)
    {
        A[length] = element; // Can also be written as  arr->A[arr->length++] = element;. Read post and pre-increments.
        length++;
    }
}

/* struct Array Insert(struct Array arr, int index, int element){
    if(arr.length < arr.size && index + 1 < arr.length){
        for(int i = arr.length; i > index; i--){
            arr.A[i] = arr.A[i-1];
        }
        arr.A[index] = element;
        arr.length++;
    }
    return arr;
} */

// Instead of returning the struct(above), we can pass struct as an address and make changes.
void Array::Insert(int index, int element)
{
    if (index >= 0 && length < size && index <= length)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = element;
        length++;
    }
}

int Array::Delete(int index)
{
    int x = 0;
    if (index >= 0 && index < length)
    {
        x = A[length - 1];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }

        A[length - 1] = 0;
        length--;
    }
    return x;
}

void Array::Swap(int *elementOne, int *elementTwo)
{

    int Temp;
    Temp = *elementOne;
    *elementOne = *elementTwo;
    *elementTwo = Temp;
}

int Array::LinearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            // Method 1: Transposition
            // Swap(&arr->A[i], &arr->A[i-1]);
            // return i-1;

            // Method 2: Move to Head
            Swap(&A[i], &A[0]);
            return 0;
        }
    }
    return -1;
}

int Array::BinarySearch(int key)
{
    int l = 0;
    int h = length - 1;
    int mid;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

int Array::RecBinarySearch(int l, int h, int key)
{
    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return RecBinarySearch(l, mid - 1, key);
        else
            return RecBinarySearch(mid + 1, h, key);
    }
    return -1;
}

int Array::Get(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    return -1;
}

void Array::Set(int index, int x)
{
    if (index >= 0 && index < length)
        A[index] = x;
}

int Array::Max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    return max;
}

int Array::Min()
{
    int min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }

    return min;
}

int Array::Sum()
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total = total + A[i];
    }
    return total;
}

int Array::SumRec(int n)
{
    if (n < 0)
        return 0;
    else
        return A[n] + SumRec(n - 1);
}

float Array::Avg()
{
    return (float)SumRec(length) / length;
}

void Array::Reverse()
{
    // int B[arr->length];
    int *B;
    B = (int *)malloc(sizeof(int) * length);

    for (int i = length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }

    for (int i = 0; i < length; i++)
    {
        A[i] = B[i];
    }
}

void Array::ReverseSwap()
{
    int temp;
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        Swap(&A[i], &A[j]);
    }
}

void Array::LeftShift()
{
    for (int i = 1; i < length; i++)
    {
        A[i - 1] = A[i];
    }
    A[length - 1] = 0;
}

void Array::LeftRotate()
{
    int temp = A[0];
    for (int i = 1; i < length; i++)
    {
        A[i - 1] = A[i];
    }
    A[length - 1] = temp;
}

void Array::RightShift()
{
    for (int i = length - 1; i > 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = 0;
}

void Array::RightRotate()
{
    int temp = A[length - 1];
    for (int i = length - 1; i > 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = temp;
}

void Array::InsertSorted(int x)
{
    int i = length - 1;

    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }

    A[i + 1] = x; // Because 'i' will be 1 behind the empty space.
    length++;
}

bool Array::isSorted(Array arr)
{

    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return false;
    }

    return true;
}

void Array::NegativeArrange()
{
    int i = 0;
    int j = length - 1;

    while (i < j)
    {
        while (A[i] < 0)
        {
            i++;
        }
        while (A[j] >= 0)
        {
            j--;
        }

        if (i < j)
        {
            Swap(&A[i], &A[j]);
        }
    }
}

Array *Array::MergeArrays(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] <= arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = A[j];

    arr3->length = length + arr2.length;
    arr3->size = 10;

    return arr3;
}

Array *Array::UnionArrays(Array arr1, Array arr2)
{

    struct Array *arr3 = new Array(arr1.length + arr2.length);

    if (isSorted(arr1) && isSorted(arr2))
    {
        int i = 0, j = 0, k = 0;
        while (i < arr1.length && j < arr2.length)
        {
            if (arr1.A[i] < arr2.A[j])
                arr3->A[k++] = arr1.A[i++];
            else if (arr1.A[i] > arr2.A[j])
                arr3->A[k++] = arr2.A[j++];
            else
            {
                arr3->A[k++] = arr1.A[i++];
                j++;
            }
        }

        for (; i < arr1.length; i++)
            arr3->A[k++] = arr1.A[i];
        for (; j < arr2.length; j++)
            arr3->A[k++] = arr1.A[j];

        arr3->length = k;
        arr3->size = 10;
    }
    else
    {
        int l = 0;
        bool elementPresent = false;
        // Copy the Array A to Array C
        for (int i = 0; i < arr1.length; i++, l++)
        {
            arr3->A[l] = arr1.A[i];
        }
        arr3->length = arr1.length;
        arr3->size = 15;

        // Check the Elements of Array B to Array C and add if they are not there in Array C. If not, copy the element to C.
        for (int j = 0; j < arr2.length; j++)
        {
            for (int k = 0; k < arr3->length; k++)
            {
                if (arr2.A[j] == arr3->A[k])
                {
                    elementPresent = true;
                    break;
                }
                else
                {
                    elementPresent = false;
                    continue;
                }
            }
            if (elementPresent)
                continue;
            else
            {
                arr3->A[l] = arr2.A[j];
                l++;
            }
        }
        arr3->length = l;
    }
    return arr3;
}

Array *Array::IntersectionArrays(Array arr1, Array arr2)
{
    Array *arr3 = new Array(arr1.length + arr2.length);

    if (isSorted(arr1) && isSorted(arr2))
    {
        int i = 0, j = 0, k = 0;
        while (i < arr1.length && j < arr2.length)
        {
            if (arr1.A[i] < arr2.A[j])
                i++;
            else if (arr1.A[i] > arr2.A[j])
                j++;
            else
            {
                arr3->A[k++] = arr1.A[i++];
                j++;
            }
        }

        arr3->length = k;
        arr3->size = 10;
    }
    else
    {

        int k = 0;
        bool sameElement = false;
        arr3->size = 15;

        // Check the Elements of Array A to Array B and add them to Array C if they are equal. If not, skip the element.
        for (int i = 0; i < arr1.length; i++)
        {
            for (int j = 0; j < arr2.length; j++)
            {
                if (arr1.A[i] == arr2.A[j])
                {
                    sameElement = true;
                    break;
                }
                else
                {
                    sameElement = false;
                    continue;
                }
            }
            if (sameElement)
            {
                arr3->A[k] = arr1.A[i];
                k++;
            }
            else
            {
                continue;
            }
        }
        arr3->length = k;
    }

    return arr3;
}

Array *Array::DifferenceArrays(Array arr1, Array arr2)
{
    Array *arr3 = new Array(arr1.length + arr2.length);

    if (isSorted(arr1) && isSorted(arr2))
    {
        int i = 0, j = 0, k = 0;
        while (i < arr1.length && j < arr2.length)
        {
            if (arr1.A[i] < arr2.A[j])
                arr3->A[k++] = arr1.A[i++];
            else if (arr1.A[i] > arr2.A[j])
                j++;
            else
            {
                i++;
                j++;
            }
        }
        for (; i < arr1.length; i++)
            arr3->A[k++] = arr1.A[i];

        arr3->length = k;
        arr3->size = 10;
    }
    else
    {

        int k = 0;
        bool sameElement = false;
        arr3->size = 15;

        // Check the Elements of Array A to Array B and add them to Array C if they are equal. If not, skip the element.
        for (int i = 0; i < arr1.length; i++)
        {
            for (int j = 0; j < arr2.length; j++)
            {
                if (arr1.A[i] == arr2.A[j])
                {
                    sameElement = true;
                    break;
                }
                else
                {
                    sameElement = false;
                    continue;
                }
            }
            if (sameElement)
            {
                continue;
            }
            else
            {
                arr3->A[k] = arr1.A[i];
                k++;
            }
        }
        arr3->length = k;
    }

    return arr3;
}

int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;

    cout << "Enter Size of Array";
    cin >> sz;
    arr1 = new Array(sz);

    do
    {
        cout << "\n\nMenu" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Sum" << endl;
        cout << "5. Display" << endl;
        cout << "6.Exit" << endl;

        cout << "Enter you choice ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter an element and index";
            cin >> x >> index;
            arr1->Insert(index, x);
            break;
        case 2:
            cout << "Enter index ";
            cin >> index;
            x = arr1->Delete(index);
            cout << "Deleted Element is " << x << endl;
            break;
        case 3:
            cout << "Enter element to search ";
            cin >> x;
            index = arr1->BinarySearch(x);
            cout << "Element index " << index;
            break;
        case 4:
            cout << "Sum is " << arr1->Sum() << endl;
            break;
        case 5:
            arr1->Display();
        }
    } while (ch < 6);
    return 0;
}