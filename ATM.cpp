#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class atm
{
private:
    long int Acc_No;
    string name;
    string PIN;
    double balance;
    string Mob_No;

public:
    void setData(long int Acc_No_a, string name_a, string PIN_a, double balance_a, string Mob_No_a)
    {
        Acc_No = Acc_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        Mob_No = Mob_No_a;
    }
    long int getAccountNo()
    {
        return Acc_No;
    }

    string getName()
    {
        return name;
    }

    string getPIN()
    {
        return PIN;
    }

    double getBalance()
    {
        return balance;
    }

    string getMobileNo()
    {
        return Mob_No;
    }

    // update the mobile number
    void setMobile(string prev_no, string new_no)
    {
        if (prev_no == Mob_No)
        {
            Mob_No = new_no;

            cout << endl
                 << "Successfully changed the mobile number";
            _getch();
        }

        else
        {
            cout << endl
                 << "Incorrect!!! Old Mobile No.";
            _getch();
        }
    }

    void cashwithdrawl(int amount_a)
    {
        if (amount_a < balance && amount_a > 0)
        {
            balance -= amount_a;
            cout << endl
                 << "Please collect your cash";
            cout << endl
                 << "Available Balance : " << balance;
            _getch();
        }
        else
        {
            cout << endl
                 << "Invalid Input/Insufficient balance";
            _getch();
        }
    }
};

int main()
{
    int choice = 0;
    string Pin;
    long int AccountNo;

    atm user1;
    user1.setData(1234567, "Aabhas", "0401", 2305.45, "9457276420");

    do
    {
        cout << endl
             << " ***** WELCOME TO SBI ATM ***** " << endl;
        cout << endl
             << "Enter your Account Number : ";
        cin >> AccountNo;

        cout << endl
             << "Enter PIN: ";
        cin >> Pin;

        if ((AccountNo == user1.getAccountNo()) && (Pin == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                cout << endl
                     << " **** WELCOME TO SBI ATM ****" << endl;
                cout << endl
                     << "Select options " << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Cash Withdrawal" << endl;
                cout << "3. Show User Details" << endl;
                cout << "4. Update Mobile Number" << endl;
                cout << "5. Exit" << endl;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << endl
                         << "Your Available Balance is: " << user1.getBalance() << endl;
                    break;
                case 2:
                    cout << endl
                         << "Enter the amount: ";
                    cin >> amount;
                    user1.cashwithdrawl(amount);
                    break;
                case 3:
                    cout << endl
                         << " **** User Details are :- ****" << endl;
                    cout << " -> Account Number: " << user1.getAccountNo() << endl;
                    cout << " -> Name: " << user1.getName() << endl;
                    cout << " -> Balance: " << user1.getBalance() << endl;
                    cout << " -> Mobile Number: " << user1.getMobileNo() << endl;
                    break;
                case 4:
                    cout << endl
                         << "Enter old Mobile Number: ";
                    cin >> oldMobileNo;
                    cout << endl
                         << "Enter new Mobile Number: ";
                    cin >> newMobileNo;
                    user1.setMobile(oldMobileNo, newMobileNo);
                    break;
                case 5:
                    return 0;
                default:
                    cout << endl
                         << "Enter valid input" << endl;
                }

            } while (true);
        }
        else
        {
            cout << "wrong";
        }

    } while (true);

    return 0;
}
