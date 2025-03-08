#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{

    int i = 5;
    int x = 2 * ++i;
    // i becomes 6 first
    // x = 2 * 6 = 12
    // final i = 6
    cout << "Value of x: " << x << endl;
    cout << "1st value of i: " << i << endl;

    i = 5;
    int y = 2 * i++;
    // y = 2 * (old i) = 2 * 5 = 10 (if i was already 5 from prior code)
    // then i becomes 6 afterward
    // final i = 6
    cout << "Value of y: " << y << endl;
    cout << "2nd value of i: " << i << endl;

    return 0;
}