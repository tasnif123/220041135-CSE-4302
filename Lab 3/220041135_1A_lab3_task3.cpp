#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;


    void adjustTime()
    {
        if (second >= 60)
        {
            minute += second / 60;
            second = second % 60;
        }


        if (minute >= 60)
        {
            hour += minute / 60;
            minute = minute % 60;
        }

        if (hour >= 24)
        {
            hour = hour % 24;
        }
    }

public:

    Time()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }


    int hours() const
    {
        return hour;
    }


    int minutes() const
    {
        return minute;
    }


    int seconds() const
    {
        return second;
    }


    void reset(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
        adjustTime();
    }


    void advance(int h, int m, int s)
    {
        hour += h;
        minute += m;
        second += s;
        adjustTime();
    }


    void print()
    {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }
};

int main()
{
    Time t;


    t.reset(14, 30, 45);
    t.print();

    t.advance(2, 45, 30);
    t.print();


    t.advance(10, 50, 70);
    t.print();

    return 0;
}
