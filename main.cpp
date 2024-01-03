//LMN-Online-Banking-System
//
#include<iostream>
#include<string>
 
 using namespace std;

 class Bank{
   protected:
   string username;
   string password;

   public:
   Bank(string username,string password) {
      this->username =(username);
      this->password=(password);
   }
 };

//Customer class
class Customer
{
   private:
   

   public:

};

//Employee class
class Employee
{
   private:
    Customer customer;

   public:
   void addCustomer(string username){
        
   }

};



//Administrator class
class Administrator{
    private:

    public:
    
};



//Main class
 int main(){

   

    return 0;
 }