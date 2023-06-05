#include <iostream>
#include <math.h>
#include <string>

using namespace std;

#include "Time.hpp"
#include "ParkingCard.hpp"

#ifndef EMPLOYEEPARKINGCARD_HPP
#define EMPLOYEEPARKINGCARD_HPP

class EmployeeParkingCard : public ParkingCard
{
public:
    EmployeeParkingCard();
    EmployeeParkingCard(int, string, string);
    void setStoreName(string);
    string getStoreName();
    int calculateHoursToPay(Time, Time);
    void print();
private:
    string storeName;
};

EmployeeParkingCard::EmployeeParkingCard() : ParkingCard()
{
    storeName = "";
}

EmployeeParkingCard::EmployeeParkingCard(int id, string name, string store) : ParkingCard(id, name)
{
    storeName = store;
}

void EmployeeParkingCard::setStoreName(string store)
{
    storeName = store;
}

string EmployeeParkingCard::getStoreName()
{
    return storeName;
}

int EmployeeParkingCard::calculateHoursToPay(Time t1, Time t2)
{
    return 0;
}

void EmployeeParkingCard::print()
{
    cout <<"-----------------------------------" << endl; 
    cout << "Employee Parking Card" << endl;
    cout << "Card ID: " << cardID << endl;
    cout << "Person Name: " << personName << endl;
    cout << "Store Name: " << storeName << endl;
    cout <<"-----------------------------------" << endl;
}

#endif // EMPLOYEEPARKINGCARD_HPP