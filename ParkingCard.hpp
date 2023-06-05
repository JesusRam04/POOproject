#include <iostream>
#include <math.h>
#include <string>
using namespace std;

#include "Time.hpp"

#ifndef PARKINGCARD_HPP
#define PARKINGCARD_HPP

class ParkingCard
{
public:
    ParkingCard();
    ParkingCard(int, string);
    int getCardID();
    void setCardID(int);
    string getPersonName();
    void setPersonName(string);
    double calculatePayment(Time, Time, double);
    virtual int calculateHoursToPay(Time, Time) = 0;
    virtual void print() = 0;
protected:
    int cardID;
    string personName;
};

ParkingCard::ParkingCard()
{
    cardID = 0;
    personName = "";
}

ParkingCard::ParkingCard(int id, string name)
{
    cardID = id;
    personName = name;
}

int ParkingCard::getCardID()
{
    return cardID;
}

void ParkingCard::setCardID(int id)
{
    cardID = id;
}   

string ParkingCard::getPersonName()
{
    return personName;
}

void ParkingCard::setPersonName(string name)
{
    personName = name;
}

double ParkingCard::calculatePayment(Time t1, Time t2, double rate)
{
    int hours = calculateHoursToPay(t1, t2);
    return hours * rate;
}

#endif // PARKINGCARD_HPP