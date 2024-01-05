#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include "Database.h"
#include "Profile.h"
using namespace std;

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
            database1->GetCustomerDatabaselist()->AddCustomer(newcustomer);
        }
    }
};

#endif