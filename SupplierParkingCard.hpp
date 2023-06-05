#include <iostream>
#include <math.h>
#include <string>
using namespace std;

#include "Time.hpp"
#include "ParkingCard.hpp"

#ifndef SUPPLIERPARKINGCARD_HPP
#define SUPPLIERPARKINGCARD_HPP

class SupplierParkingCard : public ParkingCard
{
public:
    SupplierParkingCard();
    SupplierParkingCard(int, string, string);
    string getCompany();
    void setCompany(string);
    int calculateHoursToPay(Time, Time);
    void print();
private:
    string company;
};

SupplierParkingCard::SupplierParkingCard() : ParkingCard()
{
    company = "";
}

SupplierParkingCard::SupplierParkingCard(int id, string name, string c) : ParkingCard(id, name)
{
    company = c;
}

string SupplierParkingCard::getCompany()
{
    return company;
}

void SupplierParkingCard::setCompany(string c)
{
    company = c;
}

int SupplierParkingCard::calculateHoursToPay(Time t1, Time t2)
{
    int elapsed = ceil(t1.elapsedTime(t2)/60.0);
    return elapsed-1;
}

void SupplierParkingCard::print()
{
    cout <<"-----------------------------------" << endl; // added "-----------------------------------
    cout << "Supplier Parking Card" << endl;
    cout << "Card ID: " << cardID << endl;
    cout << "Person Name: " << personName << endl;
    cout << "Company: " << company << endl;
    cout <<"-----------------------------------" << endl; // added "-----------------------------------
}

#endif // SUPPLIERPARKINGCARD_HPP