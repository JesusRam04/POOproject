#include <iostream>
#include <math.h>
#include <string>

using namespace std;

#include "Time.hpp"
#include "ParkingCard.hpp"

#ifndef CUSTOMERPARKINGCARD_HPP
#define CUSTOMERPARKINGCARD_HPP

class CustomerParkingCard : public ParkingCard
{
public:
    CustomerParkingCard();
    CustomerParkingCard(int, string);
    int calculateHoursToPay(Time, Time);
    void print();
};

CustomerParkingCard::CustomerParkingCard() : ParkingCard()
{
}

CustomerParkingCard::CustomerParkingCard(int id, string name) : ParkingCard(id, name)
{
}

int CustomerParkingCard::calculateHoursToPay(Time t1, Time t2)
{
    int elapsed = ceil(t1.elapsedTime(t2)/60.0);
    return elapsed;
}

void CustomerParkingCard::print()
{
    cout <<"-----------------------------------" << endl; 
    cout << "Customer Parking Card" << endl;
    cout << "Card ID: " << cardID << endl;
    cout << "Person Name: " << personName << endl;
    cout <<"-----------------------------------" << endl;
}

#endif // CUSTOMERPARKINGCARD_HPP
