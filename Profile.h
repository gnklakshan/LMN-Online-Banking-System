#ifndef PROFILE_H
#define PROFILE_H
#include <iostream>
#include <string>

using namespace std;

class Profile
{
public:
    string username;
    string password = "Password@1234";

public:
    Profile(string name) : username(name){}
};
#endif