#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;

#include "Time.hpp"
#include "ParkingRegister.hpp"
#include "EmployeeParkingCard.hpp"
#include "CustomerParkingCard.hpp"
#include "SupplierParkingCard.hpp"

void readFromFile(ParkingCard *listOfCards[], int &numOfCards)
{
    ifstream inFile;
    inFile.open("C:/Users/jesus/Documents/GitHub/POO/POOproject/ParkingCards.txt");
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    string type;
    int id;
    string name;
    string company;
    string store;

    while(inFile >> type >> id >> name >> store)
    {
        if (type == "E")
        {
            EmployeeParkingCard *epc = new EmployeeParkingCard(id, name, company);
            listOfCards[id] = epc;
            numOfCards++;
        }
        else if (type == "C")
        {
            CustomerParkingCard *cpc = new CustomerParkingCard(id, name);
            listOfCards[id] = cpc;
            numOfCards++;

        }
        else if (type == "S")
        {
            SupplierParkingCard *spc = new SupplierParkingCard(id, name, company);
            listOfCards[id] = spc;
            numOfCards++;

        }
    }
    inFile.close();

}


int main()
{
    //Read from file
    ParkingCard *listOfCards[50];
    int numOfCards = 0;
    readFromFile(listOfCards, numOfCards);
    for (int i = 0; i < numOfCards; i++)
    {
        listOfCards[i]->print();
    }



    int elapsed;
    // Test Time class
    Time t1(8, 46);
    Time t2(15, 11);
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
    hours = cpc.calculateHoursToPay(t2, t1);
    cout<<"Hours to pay: "<<hours<<endl;
    payment = cpc.calculatePayment(t2, t1, 20);
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