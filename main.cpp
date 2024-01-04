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
using namespace std;

class Profile {
public:
    string username;
    string password = "Password@1234";

public:
    Profile(string name) : username(name) {}
};

class Employee : public Profile {
private:
    int no;

public:
    Employee() : Profile("Employee"), no(0) {}

    Employee(string employeeName) : Profile(employeeName) {
        cout << "Employee created" << endl;
    }
};

class database {
protected:
    int employee_count=0;
    Employee* employeelist = new Employee[20];
};

class Administatrator : public Profile, public database {
public:
    Administatrator() : Profile("Admin") {
        cout << "Administrator created" << endl;
    }
    void create_employee()
    {
        employee_count++;
        Employee newemployee("Employee1");
        if(employee_count<20)
            employeelist[employee_count-1] = newemployee;

    }
};

int main() {
    Administatrator admin1;
    admin1.create_employee();
    admin1.create_employee();
    admin1.create_employee();
    admin1.create_employee();

    return 0;
}

