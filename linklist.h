#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

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
};

#endif