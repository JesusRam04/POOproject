#include <iostream>
#include <math.h>
using namespace std;

#include "Time.hpp"
#include "ParkingRegister.hpp"

int main()
{
    // testing the Time class
    Time t1(5, 00);
    Time t2(9, 30);
    int elapsed = t1.elapsedTime(t2);
    t2.print();
    cout << "Elapsed time: " << elapsed << endl;
    if (t2 > t1)
        cout << "t1 is greater than t2" << endl;
    else
        cout << "t1 is not greater than t2" << endl;

    // testing the ParkingRegister class
    ParkingRegister p1(1234, t1);
    p1.print();
    return 0;
}