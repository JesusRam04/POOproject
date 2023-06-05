#include <iostream>
#include <math.h>
using namespace std;
#include "Time.hpp"

#ifndef PARKINGREGISTER_HPP
#define PARKINGREGISTER_HPP

class ParkingRegister
{
public:
    ParkingRegister();
    ParkingRegister(int, Time);
    int getCardID();
    void setCardID(int);
    Time getEntryTime();
    void setEntryTime(Time);
    void print();
private:
    int cardID;
    Time entryTime;
};

ParkingRegister::ParkingRegister()
{
    cardID = 0;
    entryTime = Time();
}

ParkingRegister::ParkingRegister(int id, Time t)
{
    cardID = id;
    entryTime = t;
}

int ParkingRegister::getCardID()
{
    return cardID;
}

void ParkingRegister::setCardID(int id)
{
    cardID = id;
}

Time ParkingRegister::getEntryTime()
{
    return entryTime;
}

void ParkingRegister::setEntryTime(Time t)
{
    entryTime = t;
}

void ParkingRegister::print()
{
    cout << "Card ID: " << cardID << endl;
    cout << "Entry time: ";
    entryTime.print();
}

#endif // PARKINGREGISTER_HPP
