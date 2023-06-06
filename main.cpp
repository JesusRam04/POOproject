#include <iostream>
#include <math.h>
using namespace std;

#include "Time.hpp"
#include "ParkingRegister.hpp"
#include "EmployeeParkingCard.hpp"
#include "CustomerParkingCard.hpp"
#include "SupplierParkingCard.hpp"

int main()
{
    int elapsed;
    // Test Time class
    Time t1(10, 40);
    Time t2(15, 1);
    elapsed = t1.elapsedTime(t2);
    cout<<"Elapsed time: "<<elapsed<<endl;  
    // Test ParkingRegister class
    ParkingRegister pr(1234, t1);
    pr.print();

    // Test Employee class
    int hours;
    double payment;
    EmployeeParkingCard epc(1234, "John", "Walmart");
    epc.print();
    hours = epc.calculateHoursToPay(t1, t2);
    cout<<"Hours to pay: "<<hours<<endl;
    payment = epc.calculatePayment(t1, t2, 20);
    cout<<"Payment: "<<payment<<endl;   

    // Test Customer class
    CustomerParkingCard cpc(1234, "Mary");
    cpc.print();
    hours = cpc.calculateHoursToPay(t1, t2);
    cout<<"Hours to pay: "<<hours<<endl;
    payment = cpc.calculatePayment(t1, t2, 20);
    cout<<"Payment: "<<payment<<endl;

    // Test Supplier class
    SupplierParkingCard spc(1234, "John", "Walmart");
    spc.print();
    hours = spc.calculateHoursToPay(t1, t2);
    cout<<"Hours to pay: "<<hours<<endl;
    payment = spc.calculatePayment(t1, t2, 20);
    cout<<"Payment: "<<payment<<endl;

    return 0;

}