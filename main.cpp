#include <iostream>
#include <math.h>
using namespace std;

#include "Time.hpp"
#include "ParkingRegister.hpp"

int main()
{
    int elapsed;
    // Test Time class
    Time t1(10, 30);
    Time t2(11, 30);
    elapsed = t1.elapsedTime(t2);
    cout<<"Elapsed time: "<<elapsed<<endl;  
    // Test ParkingRegister class
    ParkingRegister pr(1234, t1);
    pr.print();
}