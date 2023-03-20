#include <algorithm>
#include <iostream>

using namespace std;

// Structure to hole in the values of the whole number, numerator and
// denominator
struct Fraction {
  int numerator;
  int denominator;
  int whole_number;
};

int main() {
  // Declaring the 3 Fraction objects
  Fraction f1, f2, f3;

  // Prompt the user for values for each field of two Fraction objects
  cout << "Enter the whole number portion of the first Fraction: ";
  cin >> f1.whole_number;
  cout << "\nEnter the first numerator: ";
  cin >> f1.numerator;
  cout << "\nEnter the first denominator: ";
  cin >> f1.denominator;
  cout << "]nEnter the whole number portion of the second Fraction: ";
  cin >> f2.whole_number;
  cout << "\nEnter the second numerator: ";
  cin >> f2.numerator;
  cout << "\nEnter the second denominator: ";
  cin >> f2.denominator;

  // If the denominator is 0, force it to 1
  if (f1.denominator == 0)
    f1.denominator = 1;
  if (f2.denominator == 0)
    f2.denominator = 1;
  // If the whole number portion is 0, just display the fraction portion
  if (f1.whole_number == 0) {
    cout << "\nYour fraction is: " << f1.numerator << "/"
              << f1.denominator;
    cout << endl;
  }
  if (f1.whole_number != 0) {
    cout << "\nYour fraction is: " << f1.whole_number << " "
              << f1.numerator << "/" << f1.denominator << endl;
  }
  if (f2.whole_number == 0) {
    cout << "\nYour fraction is: " << f2.numerator << "/"
              << f2.denominator;
    cout << endl;
  }
  if (f2.whole_number != 0) {
    cout << "\nYour fraction is: " << f2.whole_number << " "
              << f2.numerator << "/" << f2.denominator << endl;
  }

  
  // If the value of the first Fraction is greater than, equal to, or less
  // than the value of the second Fraction, display the appropriate message

  // Displays if fractions are higher, lower or equal to each other


  
  // Simplify the fraction
  int gcd1 = __gcd(f1.numerator, f1.denominator);
  f1.numerator /= gcd1;
  f1.denominator /= gcd1;
  int gcd2 = __gcd(f2.numerator, f2.denominator);
  f2.numerator /= gcd2;
  f2.denominator /= gcd2;
  // If the numerator is greater than or equal to the denominator, convert the
  // fraction back to a mixed number
  if (f1.numerator >= f1.denominator) {
    f1.whole_number = f1.numerator / f1.denominator;
    f1.numerator = f1.numerator % f1.denominator;
  }
  if (f2.numerator >= f2.denominator) {
    f2.whole_number = f2.numerator / f2.denominator;
    f2.numerator = f2.numerator % f2.denominator;

    cout << "\nYour fraction is: " << f1.whole_number << " "
              << f1.numerator << "/" << f1.denominator << endl;
    cout << "\nYour fraction is: " << f2.whole_number << " "
              << f2.numerator << "/" << f2.denominator << endl;
    // Prompt the user to enter an arithmetic operation: +, or *.
    char choice;
    cout << "\nEnter an arithmetic operation: ";
    cin >> choice;
    if (choice == '+') {
      f3.whole_number = f1.whole_number + f2.whole_number;
      int common_denominator1 = f1.denominator * f2.denominator;
      f3.numerator =
          (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
      f3.denominator = common_denominator1;
      //figure out the new whole number
      f3.whole_number = f3.whole_number / common_denominator1;
      cout << "\nThe sum of the two fractions using addition is: "
                << f3.whole_number << " " << f3.numerator << "/" << f3.denominator
                << endl;
    }
    if (choice == '*') {
      f3.whole_number = f1.whole_number * f2.whole_number;
      int common_denominator2 = f1.denominator * f2.denominator;
      f3.numerator =
          (f1.numerator * f2.denominator) * (f2.numerator * f1.denominator);
      f3.denominator = common_denominator2;
      //figure out the new whole number
      
      cout << "\nThe product of the two fractions using multiplication is: "
                << f3.whole_number << " " << f3.numerator << "/" << f3.denominator
                << endl;
    }
    return 0;
  }
}
