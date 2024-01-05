#include <iostream>
#include <string>
#include "Database.h"
#include "Profile.h"
#include "Employee.h"
using namespace std;

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