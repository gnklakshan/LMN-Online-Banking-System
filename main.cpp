#include <iostream>
#include <string>
#include <limits> // for numeric_limits
#include <conio.h>
#include <fstream>
using namespace std;

class SavingAccount;
class CurrentAccount;
class BankAccount{
    protected:
    double balance;
    int accountNo;
    double AnnualIntrest;
    string transactionFileName;


    public:
    BankAccount():balance(0),accountNo(0),AnnualIntrest(15){}
    void setTransactionFileName(const string& username) {
        transactionFileName = username + "_transactions.txt";
    }

    void saveTransaction(const string& transactionType, double amount) {
        ofstream outFile(transactionFileName, ios::app);

        if (outFile.is_open()) {
            outFile << "Account No: " << accountNo << endl;
            outFile << "Transaction Type: " << transactionType << endl;
            outFile << "Amount: " << amount << endl;
            //outFile << "Date: " << _DATE_ << " " << _TIME_ << endl;
            outFile << "------------------------" << endl;

            outFile.close();
        } else {
            cout << "Error opening the file for saving transactions." << endl;
        }
    }

    double getBalance(){
        return balance;
    }
    double getAnnualSavingsInterest(){
        return AnnualIntrest;
    }

    void deposit(double depositValue){
        balance += depositValue;
    }

    void withdraw(double withdrawValue){
        if(balance>= withdrawValue){
            balance -= withdrawValue;
        }
        else cout<<" Insufficient funds"<<endl;
    }

    int getAccountNo(){
        return accountNo;
    }
};
class CurrentAccount : public BankAccount
{
private:
    double Overdarft = 0;

public:
    CurrentAccount(int accountNo):BankAccount(){
        this->accountNo=accountNo;
    }
    void setOverdraft(int chargeOverdraft){
        Overdarft=chargeOverdraft;
    }

    double getOverDraft(){
        return Overdarft;
    }

    void addOverdraftchage(){
        this->balance += Overdarft;
    }
};
class SavingAccount : public BankAccount
{
private:
    double DailyinterestAmount = 0;



public:
    SavingAccount(){};
    SavingAccount(int accountNo):BankAccount(){
        this->accountNo=accountNo;
    }
    void calculateInterest()
    {
        DailyinterestAmount = this->balance * (getAnnualSavingsInterest() / 365);
        this->balance = this->balance - DailyinterestAmount;
    }
    double getDailyInterest()
    {
        return DailyinterestAmount;
    }
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
    string username;
    string Name;
    string contract_no;
    SavingAccount *savingAccount;
    CurrentAccount *currentAccount;
    bool isSaving;
    bool isCurrent;


public:
    Customer() {}
    Customer(string UserName,string name, string Phone_no) : username(UserName), contract_no(Phone_no),Name(name),savingAccount(nullptr),currentAccount(nullptr),isSaving(false),isCurrent(false)
    {
        cout << "\n\tCustomer created : [Username : " << UserName << " ]\n" << endl;
    }
    void printname()
    {
        cout << username << endl;
    }
    string getUsername(){
        return username;
    }
    void createSavingAccount(int accountNo);
    void createCurrentAccount(int accountNo);

    SavingAccount *getSavingAccount(){
        return savingAccount;
    }

    CurrentAccount *getCurrentACcount(){
        return currentAccount;
    }
    bool is_Saving(){
        return isSaving;
    }
    bool is_Current(){
        return isCurrent;
    }
    void  Set_is_Saving(bool b){
        isSaving =b;
    }

        void  Set_is_Current(bool b){
        isCurrent =b;
    }

    
};


// add node to the link list
struct Node
{
    Customer customer;
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
    Customer GetCustomer(const string username){
        Node *temp = start;
        while (temp != nullptr){
            if (temp->customer.getUsername() == username){
                return temp->customer; 
            }
            temp = temp->next;
        }
    return Customer(); 
}

    int getcustomerCount()
    {
        int count = 0;
        if (start == nullptr)
            count = 0;
        else
        {
            Node *temp = start;
            while (temp->next != nullptr)
            {
                temp = temp->next;
                count++;
            }
            if (count == 0 && temp == start)
                count = 1;
        }
        return count;
    }
    void UpdateCustomer(const string username, Customer updatedCustomer) {
        Node *temp = start;
        while (temp != nullptr) {
            if (temp->customer.getUsername() == username) {
                temp->customer = updatedCustomer;
                break;
            }
            temp = temp->next;
        }
    }
};

class Database
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
    int customer_count;
    Database *database1;

public:
    Employee() : Profile("Employee"), no(0) {}

    Employee(string employeeName, Database *db) : Profile(employeeName), database1(db)
    {
        cout << "\n\tEmployee created : [Username : " << employeeName << " ]\n"
             << endl;
    }
    void addCustomer()
    {
        customer_count = database1->GetCustomerDatabaselist()->getcustomerCount();
        if (customer_count < 50)
        {
            string customer_name,contract_no;
            cout<<"\nEnter Customer Name : ";cin>>customer_name;
            cout<<"Enter Customer Contract No : ";cin>>contract_no;
            string Username = "Customer0" + to_string(customer_count + 1);
            Customer newcustomer(Username,customer_name,contract_no);

            //manavi
            int accchoice;
            cout<<"Saving [0] Account or Current [1] Account: ";
            cin>>accchoice;
            if(accchoice==0){
                newcustomer.createSavingAccount(customer_count*2-1);
                SavingAccount *SavingAccount=newcustomer.getSavingAccount();
                SavingAccount->deposit(0);
                SavingAccount->withdraw(0);
                cout<<"Created Saving Account: "<<SavingAccount->getAccountNo()<<endl;
                //database1->GetCustomerDatabaselist()->GetCustomer(Username).
            }
            else if(accchoice==1){
                newcustomer.createCurrentAccount(customer_count*2);
                CurrentAccount *CurrentAccount =newcustomer.getCurrentACcount();
                CurrentAccount->deposit(0);
                CurrentAccount->withdraw(0);
                cout<<"Created Current Account: "<<CurrentAccount->getAccountNo()<<endl;
            }

            database1->GetCustomerDatabaselist()->AddCustomer(newcustomer);

        }
    }
};
class Administatrator : public Profile
{
private:
    int employee_count = 0;
    Employee *employeelist = new Employee[20];
    Database *database;
    double AnnualIntrest = 0;
    double OverdarftCharge = 0;

public:
    Administatrator() : Profile("Admin") {}

    Administatrator(Database *db) : Profile("Admin"), database(db)
    {
        cout << "Administrator created" << endl;
    }
    void create_employee(Database *sharedDatabase)
    {
        employee_count++;
        string name = "Employee0" + to_string(employee_count);
        Employee newemployee(name, sharedDatabase);
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

// Function definitions

void Customer::createSavingAccount(int accountNo){
    savingAccount= new SavingAccount(accountNo);
    isSaving=true;
}
void Customer::createCurrentAccount(int accountNo){
    currentAccount=new CurrentAccount(accountNo);
    isCurrent=true;
}
string search_customer_username(Database *sharedDatabase) {
    string username_in;
    bool isInDatabase = false;
    
    do {
        cout << "Enter your username : ";
        cin >> username_in;

        Customer foundCustomer = sharedDatabase->GetCustomerDatabaselist()->GetCustomer(username_in);
        if (foundCustomer.getUsername() != "") {
            isInDatabase = true;
        } else {
            cout << "\nUsername: " << username_in << " not found. Please try again." << endl;
        }

    } while (!isInDatabase);

    return username_in;
}
bool user_authentication(string username,Database *sharedDatabase)
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
    else if (username == "customer")
        cout<<"Customer Login"<<endl;
    cout << "----------------------------------------------------------------\n"
        << endl;

    char ch;
    cout << "Please enter your credentials and log in to the system" << endl;
   // cin.ignore(); // <-- Add this line to clear the input buffer
    cout << "\nEnter your username : ";

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
    if(username_in!="admin" || username_in!="employee"){
        bool isInDatabase=false;
        Customer foundCustomer=sharedDatabase->GetCustomerDatabaselist()->GetCustomer(username_in);
        if(foundCustomer.getUsername()!=""){
            isInDatabase=true;
            condition = ( password_in == "Password@1234");
        }
        else{
            cout<<"\nUsername: "<<username_in<<" cannot found"<<endl;
            //condition=false;
        }
    }
    
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
            cin>>isReturnToMenu;
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
            cin>>isReturnToMenu;
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
void Customer_attributes_in_main_fun(Database *sharedDatabase,string userName){
    Customer foundCustomer=sharedDatabase->GetCustomerDatabaselist()->GetCustomer(userName);
    int selection;
    cout << "-------------------------------------------------------" << endl;
    cout<<"Welcome "<<foundCustomer.getUsername()<<endl;
    if(foundCustomer.is_Saving()!=false){
        cout<<"Saving Account"<<endl;
    }
    if(foundCustomer.is_Current()!=false){
        cout<<"Current Account"<<endl;
    }
    cout << "-------------------------------------------------------\n"<<endl;
    cout << "-------------------------------------------------------\n"<<endl;
    //int selection;
    cout << "-------------------------------------------------------" << endl;
    cout << "Customer Operations" << endl;
    cout << "-------------------------------------------------------\n"
         << endl;
    cout << "[ 1 ] Deposit Money" << endl;
    cout << "[ 2 ] Withdraw Money" << endl;
    cout << "[ 3 ] View TRansaction History" << endl;
    cout << "-------------------------------------------------------\n"
         << endl;
    cout << "Enter Operation Number to proceed : ";
    cin >> selection;
    switch (selection)
    {
    case 1: // depositMoney
    {
        char Yes_or_No = 'y';
        double depositAmount =0;
        cout << "Enter the deposit Amount:";
        cin >>depositAmount;
        if(foundCustomer.is_Saving()==true){
             SavingAccount *savingAccount = foundCustomer.getSavingAccount();
            savingAccount->deposit(depositAmount);
            savingAccount->saveTransaction("Deposit", depositAmount);
            cout << "Deposit Successful! Current Balance: " << savingAccount->getBalance() << endl;
            sharedDatabase->GetCustomerDatabaselist()->UpdateCustomer(userName, foundCustomer);
            break;

        
    }
        
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
void Employee_attributes_in_main_fun(Administatrator admin1, Database *sharedDatabase)
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

void select_user_login(Administatrator admin1, Database *sharedDatabase, int role)
{
    bool condition_admin, condition_employee,condition_customer;
    string username_in;
    if (role == 1)
    {
        do
        {
            condition_admin = user_authentication("admin",sharedDatabase);

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
    else if(role==0)
    {
        do
        {
            condition_employee = user_authentication("employee",sharedDatabase);

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
    else if(role==2){

            username_in = search_customer_username(sharedDatabase);
            condition_customer = user_authentication("customer",sharedDatabase);

           if (!condition_customer){
                cout << "Incorrect username or password! Try again\n"<< endl;
           }

        // if admin credential is verified
        if (condition_customer == true)
        {
            cout << "\n\n\tSuccessfully Logged in! Logged in as Customer  \n"<< endl;
            Customer_attributes_in_main_fun(sharedDatabase, username_in);
            cout<<username_in;
            //admin_attributes_in_main_fun(admin1, sharedDatabase);
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
    BankSavingsAccout.deposit(100000);
    int choice;
    bool continueRunning = true;

    do
    {
        system("CLS");
        cout << "\tWelcome to the LMN Banking Management System." << endl;
        cout << "\t---------------------------------------------\n"
            << endl;
        cout << "Select Account Type\n--------------------------" << endl;
        cout << "\n\t[ 0 ] Employee\n\t[ 1 ] Administrator\n\t[ 2 ] Customer\n\t[ 3 ] Shutdown\n\nEnter the choice : ";
        cin >> choice;
        // user authentication & log in
        if(choice==3){
            return 0;
        }
        select_user_login(admin1, &sharedDatabase, choice);

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