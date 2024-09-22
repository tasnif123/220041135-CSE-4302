#include <iostream>

using namespace std;

class Temperature
{
private:
    float temp_value;
    char cl_unit;
    char target_unit;
public:
    Temperature()
    {
        temp_value = 0;
        cl_unit = NULL;
        target_unit = NULL;
    }
    int Assign(int temp_ini, int unit)
    {
        if((unit=='C' && temp_ini >=-273.15) || (unit=='F' && temp_ini >=-459.67) || (unit=='K' && temp_ini >=0))
        {
            temp_value  = temp_ini;
            cl_unit = unit;
        }
        else
        {
            cout << "Wrong Input" << endl;
            return 0;
        }
        return temp_value;

    }
    int converter()
    {
        cout << "Enter the unit you want to convert the temperature: " << endl;
        cin >> target_unit;
        if(cl_unit == 'C' && target_unit == 'F')
        {
            temp_value = (temp_value*9/5)+32;
        }
        else if(cl_unit == 'C' && target_unit == 'K')
            temp_value = temp_value +273;
        else if(cl_unit == 'F' && target_unit == 'C')
            temp_value = ((temp_value-32)/9)*5;
        else if(cl_unit == 'F' && target_unit == 'K')
            temp_value = (((temp_value-32)/9)*5)+273;
        else if(cl_unit == 'K' && target_unit == 'C')
            temp_value = temp_value-273;
        else if(cl_unit == 'K' && target_unit == 'F')
            temp_value = (((temp_value-273)/5)*9)+32;
        else
        {
            cout << "Wrong input" << endl;
            return 0;

        }

    }
    void print()
    {
        cout << "The temperature is: " << temp_value;
    }


};

int main()
{
    Temperature T;
    int temp_ini;
    char unit;
    cout << "Enter Temperature Value: " << endl;

    cin >> temp_ini;
    cout << "Enter Unit: " << endl;
    cin >> unit;

    T.Assign(temp_ini, unit);
    T.converter();
    T.print();




    return 0;
}
