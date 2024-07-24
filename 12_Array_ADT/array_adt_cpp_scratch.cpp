#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        A = new T[size];
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        A = new T[size];
        length = 0;
    }
    ~Array()
    {
        delete[] A;
    }

public:
    void Display();
    void Insert(int index, T element);
    T Delete(int index);
};

template <class T>
void Array<T>::Display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <class T>
void Array<T>::Insert(int index, T element)
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

template <class T>
T Array<T>::Delete(int index)
{
    T x = 0;
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

int main()
{
    Array<int> arr(10);
    arr.Insert(0, 1);
    arr.Insert(1, 4);
    arr.Insert(2, 5);
    arr.Insert(3, 3);

    arr.Display();

    Array<string> arr1(10);
    arr1.Insert(0, "hello");
    arr1.Insert(1, "Vishal");
    arr1.Insert(2, "How are you?");

    arr1.Display();

    return 0;
}