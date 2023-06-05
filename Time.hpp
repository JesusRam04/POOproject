#include <iostream>
#include <math.h>
using namespace std;

#ifndef TIME_HPP
#define TIME_HPP

class Time
{
public:
    Time();
    Time(int, int);
    int getHour();
    void setHour(int);
    int getMinute();
    void setMinute(int);
    int elapsedTime(Time);
    bool operator>(Time);
    void print();
private:
    int hour;
    int minute;
};

Time::Time()
{
    hour = 0;
    minute = 0;
}

Time::Time(int h, int m)
{
    hour = h;
    minute = m;
}

int Time::getHour()
{
    return hour;
}

void Time::setHour(int h)
{
    hour = h;
}

int Time::getMinute()
{
    return minute;
}

void Time::setMinute(int m)
{
    minute = m;
}

int Time::elapsedTime(Time t)
{
    int h = t.getHour();
    int m = t.getMinute();
    float elapsed = 0;
    int timeElapsed = 0;
    if (hour > h)
    {
        elapsed = (hour - h) * 60;
        if (minute > m)
        {
            elapsed += minute - m;
        }
        else
        {
            elapsed += m - minute;
        }
    }
    else
    {
        elapsed = (h - hour) * 60;
        if (minute > m)
        {
            elapsed += minute - m;
        }
        else
        {
            elapsed += m - minute;
        }
    }
    return elapsed;
}

bool Time::operator>(Time t)
{
    int h = t.getHour();
    int m = t.getMinute();
    if (hour > h)
    {
        return true;
    }
    else if (hour == h)
    {
        if (minute > m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void Time::print()
{
    if (minute==0){
        cout << hour << ":" << minute << "0" << endl;
    }
    else if (minute<10){
        cout << hour << ":" << "0" << minute << endl;
    }
    else{
        cout << hour << ":" << minute << endl;
    }
}

#endif // TIME_HPP