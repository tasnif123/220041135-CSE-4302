#include <iostream>
using namespace std;

class Calculator
{
private:
    int currentStatus;

    int getStatus() const
    {
        return currentStatus;
    }

    void setStatus(int value)
    {
        currentStatus = value;
    }

public:

    Calculator()
    {
        currentStatus = 0;
    }


    Calculator(int initialStatus)
    {
        currentStatus = initialStatus;
    }


    ~Calculator() //'~' is used when destructor is called. Remember!!!
    {
        cout << "Calculator display: " << currentStatus << endl;
        cout << "Destructor of the Calculator object is called." << endl;
    }


    void add(int value)
    {
        setStatus(getStatus() + value);
    }


    void subtract(int value)
    {
        setStatus(getStatus() - value);
    }


    void multiply(int value)
    {
        setStatus(getStatus() * value);
    }


    int divideBy(int value)
    {
        if (value == 0)
        {
            cout << "Invalid arithmetic operation." << endl;
            return getStatus();
        }
        else
        {
            int remainder = getStatus() % value;
            setStatus(getStatus() / value);
            return remainder;
        }
    }


    void clear()
    {
        setStatus(0);
    }


    void display() const
    {
        cout << "Calculator display: " << getStatus() << endl;
    }
};

int main()
{

    Calculator calc;

    calc.add(10);
    calc.display();

    calc.add(7);
    calc.display();

    calc.multiply(31);
    calc.display();

    calc.subtract(42);
    calc.display();

    calc.divideBy(7);
    calc.display();

    calc.divideBy(0);
    calc.display();
    calc.add(3);
    calc.display();

    calc.clear();
    calc.display();

    return 0;
}
