#include <iostream>
#include <cstdlib> // Needed for abs()
#include "FeetInches.h"
using namespace std;
int main()
{

    FeetInches length1(7, 9), length2(6, 5), length3(4, 6), length4(3, 7), length5(7, 8), length6(9, 10), length7(7 + 8), distance1, distance2;

    length3 = length1 + length2;
    // or write it as a function call
    length3 = length1.operator+(length2);
    length4 += length5;
    length5 = --length6;
    length6 = ++length7;

    cout << length3.getFeet() << " ft "
         << length3.getInches() << " in " << endl;
    cout << length4.getFeet() << " ft "
         << length4.getInches() << " in " << endl;
    cout << length5.getFeet() << " ft "
         << length5.getInches() << " in " << endl;
    cout << length6.getFeet() << " ft "
         << length6.getInches() << " in " << endl;
    cin >> distance2;
    cin >> distance1;

    cout << distance1 << "  " << distance2;

    cout << " Is distance1 == distance2 True or False ? " << endl;
    if (distance2 == distance1)
        cout << " True ";
    else
        cout << " False ";
    cout << endl;

    cout << " Is distance1 != distance2 True or False ? " << endl;
    if (distance2 != distance1)
        cout << " True ";
    else
        cout << " False ";
    cout << endl;
    cout << " Is distance1 >= distance2 True or False ? " << endl;
    if (distance2 >= distance1)
        cout << " True ";
    else
        cout << " False ";
    cout << endl;
    cout << " Is distance1 > distance2 True or False ? " << endl;
    if (distance2 > distance1)
        cout << " True ";
    else
        cout << " False ";
    cout << endl;
    cout << " Is distance1 < distance2 True or False ? " << endl;
    if (distance2 < distance1)
        cout << " True ";
    else
        cout << " False ";
    cout << endl;
    cout << " Is distance1 <= distance2 True or False ? " << endl;
    if (distance2 <= distance1)
        cout << " True ";
    else
        cout << " False ";
    cout << endl;
    cout << distance1 << " * " << distance2 << " = ";
    cout << distance1 * distance2;

    return 0;
}
