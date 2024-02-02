#include <iostream>
using namespace std;

template <class T>
class Arithmetic
{
    private:
        T num1;
        T num2;

    public:
        Arithmetic(T num1, T num2);
        T add();
        T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T num1, T num2)
{
    this->num1 = num1; // this is a pointer, so we need -> to access the members.
    this->num2 = num2;
}

template <class T>
T Arithmetic<T>::add()
{
    return num1 + num2;
}

template <class T>
T Arithmetic<T>::sub()
{
    return num1 - num2;
}

int main()
{

    Arithmetic<int> ar1(10, 5);

    cout << "Add of ar1: " << ar1.add() << endl;
    cout << "Sub of ar1: " << ar1.sub() << endl;

    Arithmetic<float> ar2(10.56, 5.52);

    cout << "Add of ar1: " << ar2.add() << endl;
    cout << "Sub of ar1: " << ar2.sub() << endl;

    return 0;
}