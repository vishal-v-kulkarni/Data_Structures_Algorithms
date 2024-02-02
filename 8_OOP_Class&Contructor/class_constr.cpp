#include <iostream>
using namespace std;

// We can use struct and can include functions inside struct/ By default Class members are private.
class Rectangle
{

private:
    int length;
    int breadth;

public:
    // Default constructor
    Rectangle()
    {
        length = breadth = 1;
    }

    // Parameterized contructor - Overloading
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    void changeLength(int l)
    {
        length = l;
    }
};

int main()
{

    Rectangle r(10, 5);

    int ar = r.area();
    r.changeLength(15);

    return 0;
}
