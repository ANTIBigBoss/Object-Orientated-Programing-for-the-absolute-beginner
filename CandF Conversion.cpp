// Program that asks for the degrees of temperature then asks if it is Farenheit
// or Celcius and then converts it into the opposite.

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
int main() {
  int temp;
  string choice;
  cout << "Will you be using Fahrenheit or Celcius? ";
  cin >> choice;
  if (choice == "F") {
    cout << "Please enter the temperature in Fahrenheit: ";
    cin >> temp;
    temp = (temp - 32) * 5 / 9;
    cout << "The converted temperature is " << temp << " degrees Celcius." << endl;
  } else if (choice == "C") {
    cout << "Please enter the temperature in Celcius: ";
    cin >> temp;
    temp = (temp * 1.8) + 32;
    cout << "The converted temperature is " << temp << " degrees Fahrenheit." << endl;
  } else {
    cout << "Please enter a valid choice: F or C." << endl;
  }
  return 0;
}