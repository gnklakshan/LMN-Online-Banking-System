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
using namespace std;






class SavingAccount
{
   private:
   double balance;


   public:
};

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
    {cout << "Customer created" << endl;
    }


};

//add node to the link list
struct Node
{
    Customer Newcustomer;
    Node *next;
    Node *prev;
    
};

class Customerlist
{
    private:
    Node *start;

    public:
    void AddCustomer(Customer newCustomer)
    {
        Node* node = new Node;
        node->Newcustomer = newCustomer;
        if (start == nullptr)
        {
            node->prev = nullptr;
            node->next = nullptr;
            start = node;
        }
        else
        {
            node->prev = nullptr;
            node->next = start;
            start->prev = node;
            start = node;
        }
    }


};

class CustomerDatabase
{
    protected:
    Customerlist CustomerDatabaselist;

};

class Employee : public Profile,virtual public CustomerDatabase
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
            //customerlist[customer_count]=newcustomer;
            CustomerDatabaselist.AddCustomer(newcustomer);
        customer_count++;

    }

};

class Administatrator : public Profile
{
    private:
    int employee_count = 0;
    Employee *employeelist = new Employee[20];
    int Annualinterest=0;
    double OverdraftCharge=0;

    public:
    Administatrator() : Profile("Admin")
    {

    }
    void create_employee()
    {
        employee_count++;
        Employee newemployee("Employee1");
        if (employee_count < 20)
            employeelist[employee_count - 1] = newemployee;
    }
    void setAnnualSavingInterest(int annualInterest){
        Annualinterest=annualInterest;
    }
    void setOverdraft(double overdraftCharge){
        OverdraftCharge=overdraftCharge;
    }


    Employee return_employee()
    {
        return employeelist[0];
    }
};
//AddBank account class
class CurrentAccount : public Administatrator  {
private:
    double balance;
    int creditLimit;

public:
    CurrentAccount(double initialBalance, int initialCreditLimit) : balance(initialBalance), creditLimit(initialCreditLimit) {}

    void setCreditLimit(int adminLimit) {
        creditLimit = adminLimit;
    }
};

int main()
{
    Administatrator admin1;

    //create a new employee by administator
    admin1.create_employee();
    admin1.create_employee();
    admin1.create_employee();
    admin1.create_employee();

    //create customer by an employee
    admin1.return_employee().addCustomer();
    admin1.return_employee().addCustomer();
    admin1.return_employee().addCustomer();

    //Administrator admin();
   string username_in;
   string password_in;
   char ch;
   cout<<"Please enter your credentials and log in to the system"<<endl;
   cout<<"Please enter your username : ";
   cin>>username_in;
   cout<<"Please enter your password : ";
   while ((ch = _getch()) != '\r') {
        if (ch == '\b' && !password_in.empty()) {
            cout << "\b \b"; // Backspace handling
            password_in.pop_back();
        } else if (ch != '\b') {
            password_in.push_back(ch);
            cout << '*';
        }
    }
   cout<<password_in<<endl;
    cout << endl;
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
