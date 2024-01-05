#include <iostream>
#include <string>
#include <limits> // for numeric_limits
#include <conio.h>
#include <fstream>
#include "Profile.h"
#include "Customer.h"
#include "linklist.h"
#include "Database.h"
#include "Employee.h"
#include "Employee.h"
#include "Administator.h"
using namespace std;

// AddBank account class
class CurrentAccount : public Administatrator
{
private:
    double Balance = 0;
    double Overdarft = 0;
    int AccNo;

public:
    void deposit(double depositValue)
    {
        Balance = Balance + depositValue;
    }
    void withdraw(double widthrawValue)
    {
        Balance = Balance - widthrawValue;
    }
};
class SavingAccount : public Administatrator
{
private:
    double SavingsBalance = 0;
    double DailyinterestAmount = 0;

public:
    void setSavingsBalance(double InitialSavingsAmount)
    {
        SavingsBalance = InitialSavingsAmount;
    }

    double getSavingsBalance()
    {
        return SavingsBalance;
    }

    void calculateInterest()
    {
        DailyinterestAmount = SavingsBalance * (getAnnualSavingsInterest() / 365);
        SavingsBalance = SavingsBalance - DailyinterestAmount;
    }
    double getDailyInterest()
    {
        return DailyinterestAmount;
    }
};
// Function definitions
bool user_authentication(string username)
{
    // clear variables values
    string username_in;
    string password_in;

    system("CLS");

    cout << "\tWelcome to the LMN Banking Management System.\n"
        << endl;
    cout << "________________________________________________________________" << endl;
    if (username == "admin")
        cout << "Admin Login" << endl;
    else if (username == "employee")
        cout << "Employee Login" << endl;
    cout << "----------------------------------------------------------------\n"
        << endl;

    char ch;
    cout << "Please enter your credentials and log in to the system" << endl;
   // cin.ignore(); // <-- Add this line to clear the input buffer
    cout << "\nEnter your username : ";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input

    getline(cin, username_in); // Use getline to read the entire line

    cin >> username_in;
    cout << "Enter your password : ";
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while ((ch = _getch()) != '\r')
    {
        if (ch == '\b' && !password_in.empty())
        {
            cout << "\b \b"; // Backspace handling
            password_in.pop_back();
        }
        else if (ch != '\b')
        {
            password_in.push_back(ch);
            cout << '*';
        }
    }

    bool condition = (username_in == username && password_in == "Password@1234");
    return condition;
}
void admin_attributes_in_main_fun(Administatrator admin1, Database* sharedDatabase)
{
    int selection;
    cout << "-------------------------------------------------------" << endl;
    cout << "Admin Operations" << endl;
    cout << "-------------------------------------------------------\n"
        << endl;
    cout << "[ 1 ] Add new Employee to the system" << endl;
    cout << "[ 2 ] Increase day count by 1 day" << endl;
    cout << "[ 3 ] Log out" << endl;
    cout << "[ 4 ] Set Annual Savings Interest" << endl;
    cout << "[ 5 ] Set Overdraft Charge" << endl;
    cout << "-------------------------------------------------------\n"
        << endl;
    cout << "Enter Operation Number to proceed : ";
    cin >> selection;

    switch (selection)
    {
    case 1: // add new employee
    {
        char Yes_or_No = 'y';
        cout << "Do you need to add a new employee (y/n):";
        cin >> Yes_or_No;
        while (Yes_or_No == 'y' || Yes_or_No == 'Y')
        {
            admin1.create_employee(sharedDatabase); // create a new employee by administator
            cout << "Do you need to add another new employee (y/n):";
            cin >> Yes_or_No;
        }
        bool isReturnToMenu = 1;
        do
        {
            cout << "\n-----------------------------\nEnter 0 to return the menu :";
            if (!(cin >> isReturnToMenu) || (isReturnToMenu != 0))
            {
                cout << "Invalid input. Please enter 0 to return to the menu." << endl;
                cin.clear(); // clear input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            }
        } while (isReturnToMenu);
        system("CLS");
        admin_attributes_in_main_fun(admin1, sharedDatabase);
        break;
    }
    case 2:
    {
        admin1.update_day_count();
        cout << "Update date by one day!" << endl;
        cout << "Day count : " << *((*sharedDatabase).return_day_count()) << endl;
        bool isReturnToMenu = 1;
        do
        {
            cout << "\n-----------------------------\nEnter 0 to return the menu :";
            if (!(cin >> isReturnToMenu) || (isReturnToMenu != 0))
            {
                cout << "Invalid input. Please enter 0 to return to the menu." << endl;
                cin.clear(); // clear input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            }
        } while (isReturnToMenu);
        system("CLS");
        admin_attributes_in_main_fun(admin1, sharedDatabase);
        break;
    }

    case 4:
    {   double AnnualInterest = 0;
    cout << "\n\t________________________" << endl;
    cout << "\tPlease enter the annual interest rate :" << endl;
    cin >> AnnualInterest;
    cout << "\t________________________" << endl;

    admin1.setAnnualSavingInterest(AnnualInterest);
    bool isReturnToMenu = 1;
    do
    {
        cout << "\n-----------------------------\nEnter 0 to return the menu :";
        if (!(cin >> isReturnToMenu) || (isReturnToMenu != 0))
        {
            cout << "Invalid input. Please enter 0 to return to the menu." << endl;
            cin.clear(); // clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }
    } while (isReturnToMenu);
    system("CLS");
    admin_attributes_in_main_fun(admin1, sharedDatabase);
    break;
    }
    case 5:
    {   double Overdraft = 0;
    cout << "\n\t________________________" << endl;
    cout << "\tPlease enter the overdraft charge :" << endl;
    cin >> Overdraft;
    cout << "\t________________________" << endl;

    admin1.setOverdraft(Overdraft);
    bool isReturnToMenu = 1;
    do
    {
        cout << "\n-----------------------------\nEnter 0 to return the menu :";
        if (!(cin >> isReturnToMenu) || (isReturnToMenu != 0))
        {
            cout << "Invalid input. Please enter 0 to return to the menu." << endl;
            cin.clear(); // clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }
    } while (isReturnToMenu);
    system("CLS");
    admin_attributes_in_main_fun(admin1, sharedDatabase);
    break;
    }
    default: {


        admin_attributes_in_main_fun(admin1, sharedDatabase);
        break;

    }
    case 3:
    {
        cout << "\n\t________________________" << endl;
        cout << "\tSuccessfully Logged out!" << endl;
        cout << "\t________________________" << endl;
    }
    }
}
void Employee_attributes_in_main_fun(Administatrator admin1, Database* sharedDatabase)
{
    int selection;
    cout << "-------------------------------------------------------" << endl;
    cout << "Employee Operations" << endl;
    cout << "-------------------------------------------------------\n"
        << endl;
    cout << "[ 1 ] Add new Customer" << endl;
    cout << "[ 2 ] Create Account" << endl;
    cout << "[ 3 ] Log out" << endl;
    cout << "-------------------------------------------------------\n"
        << endl;
    cout << "Enter Operation Number to proceed : ";
    cin >> selection;

    switch (selection)
    {
    case 1: // add new employee
    {
        char Yes_or_No = 'y';
        cout << "Do you need to add a new Customer (y/n):";
        cin >> Yes_or_No;
        do
        {
            admin1.return_employee().addCustomer(); // create a new employee by customer
            cout << "Do you need to add another new customer (y/n):";
            cin >> Yes_or_No;
        } while (Yes_or_No == 'y' || Yes_or_No == 'Y');
        break;
    }
    case 2:
    {

        break;
    }
    case 3:
    {
    }
    }
}

void select_user_login(Administatrator admin1, Database* sharedDatabase, bool isAdmin)
{
    bool condition_admin, condition_employee;
    if (isAdmin == true)
    {
        do
        {
            condition_admin = user_authentication("admin");

            if (!condition_admin)
                cout << "Incorrect username or password! Try again\n"
                << endl;
        } while (!condition_admin);

        // if admin credential is verified
        if (condition_admin == true)
        {
            cout << "\n\n\tSuccessfully Logged in! Logged in as Admin  \n"
                << endl;
            admin_attributes_in_main_fun(admin1, sharedDatabase);
        }
    }
    else
    {
        do
        {
            condition_employee = user_authentication("employee");

            if (!condition_employee)
                cout << "Incorrect username or password! Try again\n"
                << endl;
        } while (!condition_employee);

        // if employee credential is verified
        if (condition_employee == true)
        {
            cout << "\nSuccessfully Logged in! Logged in as Employee\n"
                << endl;
            Employee_attributes_in_main_fun(admin1, sharedDatabase);
        }
    }
}
int main()
{
    Database sharedDatabase;
    Administatrator admin1(&sharedDatabase);
    admin1.create_employee(&sharedDatabase); // initially there is an employee
    SavingAccount BankSavingsAccout;
    // bool condition_admin, condition_employee;
    BankSavingsAccout.setSavingsBalance(100000);
    bool choice;
    bool continueRunning = true;

    do
    {
        system("CLS");
        cout << "\tWelcome to the LMN Banking Management System." << endl;
        cout << "\t---------------------------------------------\n"
            << endl;
        cout << "Select Account Type\n--------------------------" << endl;
        cout << "\n\t[ 0 ] Administrator\n\t[ 1 ] Employee\n\nEnter the choice : ";

       // cin >> choice;
       
        
        while (!(cin >> choice) || (choice != 0 && choice != 1))
        {
            cout << "Invalid input. Please enter 0 or 1: ";
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore last input
        }
        // user authentication & log in
        select_user_login(admin1, &sharedDatabase, !choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        system("PAUSE");
    } while (true);

    /**
     *
     *
       //cin>>password_in;
      //validate password
      if(password_in == password){
        // check the username wording
         //check if the usernmae if for An admin
      if(username_in ==){
         //check if it is an employee
      }else if(){
         //check if it is an account holder/customer
      }else if(){

      }else{
         cout<<"Wrong credentials : Please check your username or password"<<endl;
         return main();
      }

      }else{
         cout<<"Wrong credentials : Please check your username or password"<<endl;
         return main();
      }

    */

    return 0;
}