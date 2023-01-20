#include<iostream>
using namespace std;
class Car
{
   private:
      bool isIgnitionOn;
      int speed;
      public:
      void turnIgnitionOn();
      void turnIgnitionOff();
      void setSpeed(int);
      void showCar();
};
void Car::showCar()
{
   if(isIgnitionOn)
      cout << "Ignition is on. ";
   else
      cout << "Ignition is off. ";
   cout << "Speed is " << speed << endl;
}
void Car::turnIgnitionOn()
{
   isIgnitionOn = true;
}
void Car::turnIgnitionOff()
{
   speed = 0;
   isIgnitionOn = false;
}
void Car::setSpeed(int mph)
{
   const int STD_LIMIT = 65;
   if(isIgnitionOn)
      if (mph <= STD_LIMIT)
         speed = mph;
     else
         speed = STD_LIMIT;
   else
      cout << "Can't set speed - ignition is off!" << endl;
}
int main()
{
   Car myCar;
   myCar.turnIgnitionOn();
   myCar.setSpeed(35);
   myCar.showCar();
   myCar.setSpeed(70);
   myCar.showCar();
   myCar.turnIgnitionOff();
   myCar.showCar();
   return 0;
}