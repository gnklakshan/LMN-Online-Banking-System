//LMN-Online-Banking-System
//
#include<iostream> 
 
 using namespace std;

 class Bank{
   protected:
   string username;
   string password = "Password@1234";

   // public:
   // Bank(string username,string password) {
   //    this->username =(username);
   //    this->password=(password);
   // }
 };

//Customer class
class Customer : private Bank 
{
   private:


   public:

};

//Employee class
class Employee : private Bank 
{
   private:

   public:

};


//Administrator class
class Administrator :private Bank 
{
    private:

    public:
    
};


//Main class
 int main(){
   Bank LMNBank;
   

   

    return 0;
 }