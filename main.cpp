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

void readFromFile(ParkingCard *listOfCards[], int &numOfCards){
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

    while(inFile >> type)
    {
        if (type == "E")
        {
            inFile >> id >> name >> store;
            listOfCards[numOfCards] = new EmployeeParkingCard(id, name, store);
            numOfCards++;
        }
        else if (type == "C")
        {
            inFile >> id >> name;
            listOfCards[numOfCards] = new CustomerParkingCard(id, name);
            numOfCards++;

        }
        else if (type == "S")
        {
            inFile >> id >> name >> store;
            listOfCards[numOfCards] = new SupplierParkingCard(id, name, store);
            numOfCards++;

        }
    }
    inFile.close();
}

int findCard(ParkingCard *listOfCards[], int numOfCards, int id)
{
    for (int i = 0; i < numOfCards; i++)
    {
        if (listOfCards[i]->getCardID() == id)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    ParkingRegister *listRegister[20];
    int numOfRegisters = 0;

    //Welcome and initializing today's rate
    float todaysRate = 0.0;
    cout<<"-----------------------------------"<<endl;
    cout<<"Welcome to the Parking Lot"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"Please enter today's rate: ";
    cin>>todaysRate;

    //Read from file
    ParkingCard *listOfCards[50];
    int numOfCards = 0;
    readFromFile(listOfCards, numOfCards);

    //Menu
    char option;

    do
    {
        cout<<"*****************************************"<<endl;
        cout << "Options " << endl;
        cout << endl;
        cout <<"a) Register entrance to Parking Lot " << endl;
        cout <<"b) Exit from the Parking Lot " << endl;
        cout <<"c) Display Parking Lot information " << endl;
        cout <<"d) Display Parking Cards information " << endl;
        cout <<"e) Exit " << endl;
        cout<<"*****************************************"<<endl;
        cout << "option ->";
        cin >> option;
        switch (option) {
            case 'a':
            {
                int checkID;
                bool foundID=false;
                bool checkHour=false;
                bool checkMinutes=false;
                do{
                    cout<<"Enter ID: ";
                    cin>>checkID;
                    for (int i=0; i < numOfCards; i++)
                    {
                        if (listOfCards[i]->getCardID() == checkID)
                        {
                            foundID = true;
                            break;
                        }
                    }
                    if (foundID==false)
                    {
                        cout<<"Invalid ID, please enter a valid one"<<endl;
                    }

                }while (foundID==false);
                
                cout<<"Introduce time of entrance: "<<endl;
                Time tEntrance;
                int hour, minute;
                do{
                    cout<<"Enter Hour: ";
                    cin>>hour;
                    if (hour>=8 && hour<=22)
                    {
                        checkHour=true;
                        tEntrance.setHour(hour);
                    }
                    else
                    {
                        cout<<"Invalid hour, please enter an hour\n between 8 and 22"<<endl;
                    }

                }while (checkHour==false);

                do{
                    cout<<"Enter Minutes: ";
                    cin>>minute;
                    if (minute>=0 && minute<=59)
                    {
                        checkMinutes=true;
                        tEntrance.setMinute(minute);
                    }
                    else
                    {
                        cout<<"Invalid minutes, please enter a minute\n between 0 and 59"<<endl;
                    }
                }while (checkMinutes==false);
                listRegister[numOfRegisters] = new ParkingRegister(checkID, tEntrance);
                numOfRegisters++;
                break;
            }
            case 'b':
            {
                int checkID;
                bool foundID=false;
                Time exitTime;
                Time entryTime;
                int index;
                do{
                    cout<<"Enter ID: ";
                    cin>>checkID;
                    for (int i=0; i < numOfRegisters; i++)
                    {
                        if (listRegister[i]->getCardID() == checkID)
                        {
                            foundID = true;
                            entryTime = listRegister[i]->getEntryTime();
                            index = i;
                            break;
                        }
                    }
                    if (foundID==false)
                    {
                        cout<<"Invalid ID, please enter a valid one"<<endl;
                    }

                }while (foundID==false);

                cout<<"Introduce time of exit: "<<endl;
                int hour, minute;
                bool checkTime=false;
                bool checkHour=false;
                bool checkMinutes=false;
                do{
                    do{
                        cout<<"Enter Hour: ";
                        cin>>hour;
                        if (hour>=8 && hour<=22)
                        {
                            checkHour=true;
                        }
                        else
                        {
                            cout<<"Invalid hour, please enter an hour\n between 8 and 22"<<endl;
                        }

                    }while (checkHour==false);
                    do{
                        cout<<"Enter Minutes: ";
                        cin>>minute;
                        if (minute>=0 && minute<=59)
                        {
                            checkMinutes=true;
                        }
                        else
                        {
                            cout<<"Invalid minutes, please enter a minute\n between 0 and 59"<<endl;
                        }
                    }while (checkMinutes==false);
                    exitTime.setHour(hour);
                    exitTime.setMinute(minute);
                    if (exitTime>entryTime)
                    {
                        checkTime=true;
                        exitTime.setHour(hour);
                    }
                    else
                    {
                        cout<<"Invalid time, please enter a time\n greater than the entry time"<<endl;
                    }
                }while (checkTime==false);
                int cardID = findCard(listOfCards, numOfCards, checkID);
                int hrsToPay = listOfCards[cardID]->calculateHoursToPay(entryTime, exitTime);
                double amToPay = listOfCards[cardID]->calculatePayment(entryTime, exitTime, todaysRate);
                cout<<"*****************************************"<<endl;
                cout<<"Exit Ticket"<<endl;
                listRegister[index]->print();
                cout<<"Exit time: ";
                exitTime.print();
                cout<<"Hours to pay: "<<hrsToPay<<endl;
                cout<<"Amount to pay: "<<amToPay<<endl;
                cout<<"Have a nice day!"<<endl;
                cout<<"*****************************************"<<endl;
                break;
            }
            case 'c':
            {
                for (int i=0; i<numOfRegisters; i++)
                {
                    int cardID = listRegister[i]->getCardID();
                    int index = findCard(listOfCards, numOfCards, cardID);
                    cout<<"*****************************************"<<endl;
                    cout<<"Lot: "<<i+1<<endl;
                    listOfCards[index]->print();
                    listRegister[i]->print();
                }
                break;
            }
            case 'd':
            {
                for (int i=0; i<numOfCards; i++)
                {
                    cout<<"*****************************************"<<endl;
                    cout<<"Card: "<<i+1<<endl;
                    listOfCards[i]->print();
                }
                break;
            }

        }
    } while (option != 'e');

    return 0;

}