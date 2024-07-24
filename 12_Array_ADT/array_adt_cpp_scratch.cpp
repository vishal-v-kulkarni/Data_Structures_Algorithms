#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>

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
    // cout << typeid(T).name() << endl;
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
        x = A[index];
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

    cout << "Deleted " << arr.Delete(2) << endl;

    arr.Display();

    // Array<string> arr1(10);
    // arr1.Insert(0, "hello");
    // arr1.Insert(1, "Vishal");
    // arr1.Insert(2, "How are you?");
    // cout << "Deleted " << arr1.Delete(2) << endl;

    // arr1.Display();

    Array<float> arr2(10);
    arr2.Insert(0, 1.2);
    arr2.Insert(1, 2.2);
    arr2.Insert(2, 3.2);
    arr2.Insert(3, 4.2);

    arr2.Display();

    cout << "Deleted " << arr2.Delete(2) << endl;

    arr2.Display();

    Array<char> arr3(10);
    arr3.Insert(0, 'a');
    arr3.Insert(1, 'b');
    arr3.Insert(2, 'c');
    arr3.Insert(3, 'd');

    arr3.Display();

    cout << "Deleted " << arr3.Delete(2) << endl;

    arr3.Display();

    char x = 0;
    cout << x << endl;

    return 0;
}