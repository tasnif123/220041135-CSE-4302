#include <iostream>

using namespace std;

class Counter
{
private:
    int setdata;
    int count;
public:
    Counter()
    {
        count = 0;
        setdata = 1;
    }
    void setIncrementStep(int set)
    {
        setdata = set;
    }
    int getCount()
    {
        return count;
    }
    void increment()
    {
        count +=setdata;
    }
    void resetCount()
    {
        count = 0;
    }
};

int main()
{
    Counter count1;
    count1.setIncrementStep(5);
    count1.increment();
    int count_value = count1.getCount();
    cout << "Count = " << count_value << endl;
    count1.resetCount();
    cout << "Count after reset = " << count1.getCount() << endl;



    return 0;
}
