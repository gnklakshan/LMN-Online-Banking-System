#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
using namespace std;

class Customer
{
private:
    string username;
    string Name;
    string contract_no;

public:
    Customer() {}
    Customer(string UserName,string name, string Phone_no) : username(UserName), contract_no(Phone_no),Name(name)
    {
        cout << "\n\tCustomer created : [Username : " << UserName << " ]\n" << endl;
    }
    void printname()
    {
        cout << username << endl;
    }
};

#endif