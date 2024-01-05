#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

class Profile
{
public:
    string username;
    string password = "Password@1234";

public:
    Profile(string name) : username(name) {}
};

class Customer
{
private:
    string name;
    string contract_no;

public:
    Customer() {}
    Customer(string Name) : name(Name), contract_no("0112782516")
    {
        cout << "Customer created" << endl;
    }
    void printname()
    {
        cout << name << endl;
    }
};

// add node to the link list
struct Node
{
    Customer customer;
    int customerCount = 0;
    Node *next;
};

class Customerlist
{
private:
    Node *start;

public:
    Customerlist() : start(nullptr) {}

    void AddCustomer(Customer newCustomer)
    {
        Node *node = new Node;
        node->customer = newCustomer;
        node->next = nullptr;
        node->customerCount++;
        cout << "Customer Username= Customer" << node->customerCount << endl;

        if (start == nullptr)
        {
            start = node;
        }
        else
        {
            Node *temp = start;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    void printfirstelement()
    {
        if (start == nullptr)
            cout << "-1" << endl;
        else
        {
            start->customer.printname();
            int count = 2;
            Node *temp = start;
            while (temp->next != nullptr)
            {
                temp = temp->next;
                count++;
            }
            cout << count << endl;
        }
    }
};

class CustomerDatabase
{
protected:
    Customerlist CustomerDatabaselist;
    int dayCount = 1;

public:
    Customerlist *GetCustomerDatabaselist()
    {
        return &CustomerDatabaselist;
    }

    int *return_day_count()
    {
        return &dayCount;
    }
};

class Employee : public Profile
{
private:
    int no;
    int customer_count = 0;
    CustomerDatabase *database1;

public:
    Employee() : Profile("Employee"), no(0) {}

    Employee(string employeeName, CustomerDatabase *db) : Profile(employeeName), database1(db)
    {
        cout << "Employee created" << endl;
    }
    void addCustomer()
    {
        customer_count++;
        if (customer_count <= 50)
        {
            Customer newcustomer("Customer01");
            database1->GetCustomerDatabaselist()->AddCustomer(newcustomer);
        }
    }
};
class Administatrator : public Profile
{
private:
    int employee_count = 0;
    Employee *employeelist = new Employee[20];
    CustomerDatabase *database;
    double AnnualIntrest = 0;
    double OverdarftCharge = 0;

public:
    Administatrator() : Profile("Admin") {}

    Administatrator(CustomerDatabase *db) : Profile("Admin"), database(db)
    {
        cout << "Administrator created" << endl;
    }
    void create_employee(CustomerDatabase *sharedDatabase)
    {
        employee_count++;
        Employee newemployee("Employee", sharedDatabase);
        if (employee_count < 20)
            employeelist[employee_count - 1] = newemployee;
    }
    void setAnnualSavingInterest(int annualInterest)
    {
        AnnualIntrest = annualInterest;
    }
    double getAnnualSavingsInterest()
    {
        return AnnualIntrest;
    }
    void setOverdraft(double overdraftCharge)
    {
        OverdarftCharge = overdraftCharge;
    }

    double getOverdraft()
    {
        return OverdarftCharge;
    }

    Employee return_employee()
    {
        return employeelist[0];
    }

    void update_day_count()
    {
        int *dayCount = (database->return_day_count());
        (*dayCount)++;
    }
};
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
    cout << "\nEnter your username : ";
    cin >> username_in;
    cout << "Enter your password : ";
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
void admin_attributes_in_main_fun(Administatrator admin1, CustomerDatabase *sharedDatabase)
{
    int selection;
    cout << "-------------------------------------------------------" << endl;
    cout << "Admin Operations" << endl;
    cout << "-------------------------------------------------------\n"
         << endl;
    cout << "[ 1 ] Add new Employee to the system" << endl;
    cout << "[ 2 ] Increase day count by 1 day" << endl;
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
            cin >> isReturnToMenu;
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
            cin >> isReturnToMenu;
        } while (isReturnToMenu);
        system("CLS");
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
void select_user_login(Administatrator admin1, CustomerDatabase *sharedDatabase, bool isAdmin)
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
            char Yes_or_No = 'y';
            cout << "Do you need to add a new Customer (y/n):";
            cin >> Yes_or_No;
            do
            {
                admin1.return_employee().addCustomer(); // create a new employee by customer
                cout << "Do you need to add another new customer (y/n):";
                cin >> Yes_or_No;
            }while (Yes_or_No == 'y' || Yes_or_No == 'Y');
        }
    }
}
int main()
{
    CustomerDatabase sharedDatabase;
    Administatrator admin1(&sharedDatabase);
    admin1.create_employee(&sharedDatabase);  //initially there is an employee
    SavingAccount BankSavingsAccout;
    // bool condition_admin, condition_employee;
    BankSavingsAccout.setSavingsBalance(100000);
    bool choice;
    bool continueRunning = true;

    do
    {
        system("CLS");
        cout << "\tWelcome to the LMN Banking Management System."<< endl;
        cout << "\t---------------------------------------------\n"<< endl;
        cout << "Select Account Type\n--------------------------" << endl;
        cout << "\n\t[ 0 ] Administrator\n\t[ 1 ] Employee\n\nEnter the choice : ";
        cin >> choice;
        // user authentication & log in
        select_user_login(admin1, &sharedDatabase, !choice);
        sharedDatabase.GetCustomerDatabaselist()->printfirstelement();
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
