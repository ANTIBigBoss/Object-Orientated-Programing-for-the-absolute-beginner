#include<iostream>
using namespace std;
struct Car
{
   int year;
   double mpg;
};
int main()
{
   Car myCar;
   cout << "What year is the car? ";
   cin >> myCar.year;
   cout << "How many miles per gallon does it get? ";
   cin >> myCar.mpg;
   cout << "The " << myCar.year << " car gets " << myCar.mpg << 
       " miles per gallon" << endl;
   return 0;
}