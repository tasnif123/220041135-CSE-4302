#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolder;
    string accountType;
    float currentBalance;
    const float minimumBalance;
    static int totalAccounts;
    static float totalSourceTax;

public:

    BankAccount(int accNo, string accHolder, string accType, float balance, float minBalance) //set the value of the variables with the value of the parameters being passed
        : accountNumber(accNo), accountHolder(accHolder), accountType(accType),
          currentBalance(balance), minimumBalance(minBalance)
    {
        totalAccounts++;
    }


    ~BankAccount()
    {
        cout << "Account of " << accountHolder << " with account no " << accountNumber
             << " is destroyed with a balance BDT " << currentBalance << endl;
    }


    string getAccountHolder() const
    {
        return accountHolder;
    }


    void showInfo()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: " << currentBalance << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
    }


    void showBalance() const
    {
        cout << "Current Balance: " << currentBalance << endl;
    }


    void deposit(float amount)
    {
        if (amount > 0)
        {
            currentBalance += amount;
            cout << "Deposited: " << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }


    void withdraw(float amount)
    {
        if (amount > 0 && (currentBalance - amount) >= minimumBalance)
        {
            currentBalance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }


    void giveInterest(float interestRate = 0.03)
    {
        float interest = currentBalance * interestRate;
        float sourceTax = interest * 0.10;
        totalSourceTax += sourceTax; // Accumulate total source tax
        currentBalance += (interest - sourceTax);
        cout << "Interest credited after tax: " << (interest - sourceTax) << endl;
    }


    static void display_stat()
    {
        cout << "Total Bank Accounts created: " << totalAccounts << endl;
        cout << "Total Source Tax collected: " << totalSourceTax << endl;
    }


    friend BankAccount Larger(const BankAccount& A, const BankAccount& B);
};


int BankAccount::totalAccounts = 0;
float BankAccount::totalSourceTax = 0.0;


BankAccount Larger(const BankAccount& A, const BankAccount& B)
{
    return (A.currentBalance >= B.currentBalance) ? A : B;
}

int main()
{

    BankAccount account1(1234, "John Doe", "Savings", 10000.0, 500.0);
    BankAccount account2(5678, "Jane Smith", "Current", 15000.0, 1000.0);


    account1.showInfo();
    account2.showInfo();


    account1.deposit(2000);
    account1.withdraw(3000);
    account1.giveInterest();

    cout << endl;
    BankAccount::display_stat(); //'::' scope resolution operator. It is used to define or refer to members of a class, namespace, or enumeration
    cout << endl;

    BankAccount largerAccount = Larger(account1, account2);
    cout << "Account with larger balance: " << largerAccount.getAccountHolder() << endl;

    return 0;
}
