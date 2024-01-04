// //LMN-Online-Banking-System
// //
// #include<iostream>
// #include<string>
 
//  using namespace std;

//  class User{
//    protected:
//    string username;
//    string password = "Password@1234";

//    public:
//    User(string AdminName) 
//    {
//       this->username = AdminName;
//       cout<<username<<endl;
//    }
//  };

//  //Administrator class
// class Administrator  : private User
// {
//    public:
   

// };

// //Customer class
// class Customer : private User
// {
//    private:


//    public:

// };

// //Employee class
// class Employee : private User 
// {
//    private:
//     Customer customer;

//    public:
//    void addCustomer(string username){
        
//    }

// };


// //Main class
//  int main(){

//    Administrator admin();

//     return 0;
//  }

//----------------------------------------------------------------
#include <iostream>
#include <string>
#include <conio.h> 
#include<fstream>
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
    Customer(){ }
    Customer(string Name) : name(Name),contract_no("0112782516")
    {cout << "Customer created" << endl;}


};

class Employee : public Profile
{
private:
    int no;
    int customer_count=0;
    Customer *customerlist = new Customer[20];



public:
    Employee() : Profile("Employee"), no(0) {}

    Employee(string employeeName) : Profile(employeeName)
    {
        cout << "Employee created" << endl;
    }
    void addCustomer()
    {
        Customer newcustomer("Customer01");
        if (customer_count<50)
            customerlist[customer_count]=newcustomer;
        customer_count++;

    }
};

class Administatrator : public Profile
{
    private:
    int employee_count = 0;
    Employee *employeelist = new Employee[20];
    int AnnualIntrest=0;
    double OverdarftCharge=0;

    public:
    Administatrator() : Profile("Admin")
    {
        cout << "Administrator created" << endl;
    }
    void create_employee()
    {
        employee_count++;
        Employee newemployee("Employee1");
        if (employee_count < 20)
            employeelist[employee_count - 1] = newemployee;
    }
    void setAnnualSavingInterest(int annualInterest){
        AnnualIntrest=annualInterest;
    }
    void setOverdraft(double overdraftCharge){
        OverdarftCharge=overdraftCharge;
    }


    Employee return_employee()
    {
        return employeelist[0];
    }
};

//AddBank account class
class CurrentAccount: public Administatrator
{
   private:
   double Balance=0;
   double Overdarft=0;


   public:
   void deposit(double depositValue){
    Balance=Balance+depositValue;
   }
   void withdraw(double widthrawValue){
    Balance=Balance-widthrawValue;
   }
   
};
class SavingAccount
{
   private:
   double SavingsBalance = 0 ;
   double DailyinterrestAmount = 0;


   public:
   void setSavingsBalance(double InitialSavingsAmount){
    SavingsBalance = InitialSavingsAmount;
   }
  /*
   double calculateInterest(double Amount){
     DailyinterrestAmount = SavingsBalance;//* rtae
   }

  */
};

int main()
{
    Administatrator admin1;
    SavingAccount BankSavingsAccout;
    string username_in;
    string password_in;
    bool condition;

    do
    {
        // clear variables values
        username_in.clear();
        password_in.clear();
        system("CLS");

        cout << "\tWelcome to the LMN Banking Management System.\n"
             << endl;
        cout << "________________________________________________________________" << endl;
        cout << "Admin Login" << endl;
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
        condition = (username_in == "admin" && password_in == "Password@1234");
        if (!condition)
            cout << "Incorrect username or password! Try again\n"
                 << endl;

    } while (!condition);

    // if admin credential is verified
    if (condition == true)
    {
        cout<<"condition verified\n"<< endl;
        char Yes_or_No = 'y';
        cout << "Do you need to add a new employee (y/n):";
        cin >> Yes_or_No;
        while (Yes_or_No == 'y' || Yes_or_No == 'Y')
        {
            admin1.create_employee();       // create a new employee by administator
            cout << "Do you need to add another new employee (y/n):";
            cin >> Yes_or_No;
        }
    }

    // create customer by an employee
    admin1.return_employee().addCustomer();
    admin1.return_employee().addCustomer();
    admin1.return_employee().addCustomer();

    // Administrator admin();

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
