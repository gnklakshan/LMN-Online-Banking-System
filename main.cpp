//LMN-Online-Banking-System
//
#include<iostream>
#include<string>
 
 using namespace std;

 class User{
   protected:
   string username;
   string password = "Password@1234";

   public:
   User(string AdminName) 
   {
      this->username = AdminName;
   }
 };

 //Administrator class
class Administrator  : User
{
    private:

    public:

    
};

//Customer class
class Customer : private User
{
   private:


   public:

};

//Employee class
class Employee : private User 
{
   private:
    Customer customer;

   public:
   void addCustomer(string username){
        
   }

};


//Main class
 int main(){

   Admi

    return 0;
 }