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

// Revision
class Square
{

private:
    int side;

public:
    Square()
    {
        side = 10;
    }

    Square(int s)
    {
        side = s;
    }

    int area()
    {
        return side * side;
    }

    void setSide(int s)
    {
        side = s;
    }

    int getSide()
    {
        return side;
    }
};

int main()
{

    Rectangle r(10, 5);

    int ar = r.area();
    r.changeLength(15);

    // Revision
    Square s(5);
    int area = s.area();
    cout << area << endl;
    s.setSide(10);
    cout << s.getSide() << endl;

    return 0;
}
