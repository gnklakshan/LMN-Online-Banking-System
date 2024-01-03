#include<iostream> 
 
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

 int main(){

   

    return 0;
 }