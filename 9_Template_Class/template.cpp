#include <iostream>
using namespace std;

template <class T>
class Arithmetic // OR Calculator
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

// Revision
template <class T>
class Square
{
private:
    T side;

public:
    // Constructor
    Square(T s);

    // Setters - Mutators
    T getSide();

    void setSide(T s);
};

template <class T>
Square<T>::Square(T s)
{
    side = s;
}

template <class T>
T Square<T>::getSide()
{
    return side;
}

template <class T>
void Square<T>::setSide(T s)
{
    side = s;
}

int main()
{

    Arithmetic<int> ar1(10, 5);

    cout << "Add of ar1: " << ar1.add() << endl;
    cout << "Sub of ar1: " << ar1.sub() << endl;

    Arithmetic<float> ar2(10.56, 5.52);

    cout << "Add of ar1: " << ar2.add() << endl;
    cout << "Sub of ar1: " << ar2.sub() << endl;

    // Revision
    // Int
    Square<int> s(10);
    cout << "Side of the Square: " << s.getSide() << endl;

    // Float
    Square<float> s1(10.2);
    cout << "Side of the Square: " << s1.getSide() << endl;

    return 0;
}