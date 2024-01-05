#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <string>
#include "linklist.h"
using namespace std;

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

#endif