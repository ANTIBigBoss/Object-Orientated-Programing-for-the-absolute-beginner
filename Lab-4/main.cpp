// Mitchell
// Lab 4
// 2023-02-08

// Include algorithm for the GCD (Greatest common denominator) of two numbers
#include <algorithm>
#include <iostream>

using namespace std;

// Structure for storing the objects of the fraction
struct Fraction {
  int numerator;
  int denominator;
  int whole_number;
};

// Function to check the denominaor of the fraction and make sure it's not 0
void check_denominator(int &denominator) {
  while (denominator <= 0) {
    cout << "Invalid denominator. Please enter a positive integer: ";
    cin >> denominator;
  }
}

// Function to simplify the fraction using GCD from Algorithm library
void simplify_fraction(Fraction &f) {
  f.numerator += f.whole_number * f.denominator;
  f.whole_number = 0;
  int gcd = __gcd(f.numerator, f.denominator);
  f.numerator /= gcd;
  f.denominator /= gcd;
}

// Function to get the input of the two fractions from the user
void get_fraction(Fraction &f) {
  cout << "Enter the whole number: ";
  cin >> f.whole_number;
  cout << "Enter the numerator: ";
  cin >> f.numerator;
  cout << "Enter the denominator: ";
  cin >> f.denominator;
  check_denominator(f.denominator);
  simplify_fraction(f);
}

// Function to print the fractions with if statements to determine is it's only
// a whole number, only a fraction or has both
void print(Fraction fraction) {
  fraction.whole_number += fraction.numerator / fraction.denominator;
  fraction.numerator = fraction.numerator % fraction.denominator;
  int gcd = __gcd(fraction.numerator, fraction.denominator);
  fraction.numerator /= gcd;
  fraction.denominator /= gcd;

  if (fraction.whole_number == 0) {
    if (fraction.numerator == 0) {
      cout << "\nYour fraction is: 0" << endl;
    } else {
      cout << "\nYour fraction is: " << fraction.numerator << "/"
           << fraction.denominator << endl;
    }
  } else {
    if (fraction.numerator == 0) {
      cout << "\nYour fraction is: " << fraction.whole_number << endl;
    } else {
      cout << "\nYour fraction is: " << fraction.whole_number << " "
           << fraction.numerator << "/" << fraction.denominator << endl;
    }
  }
}

// Function to add two fractions and make a new fraction
Fraction add(Fraction f1, Fraction f2) {
  Fraction f;
  f.denominator = f1.denominator * f2.denominator;
  f.numerator =
      (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
  f.whole_number = f1.whole_number + f2.whole_number;
  simplify_fraction(f);
  return f;
}

// Function to multiply two fractions and make a new fraction
Fraction multiply(Fraction f1, Fraction f2) {
  Fraction f;
  int mixed_numerator_1 = f1.whole_number * f1.denominator + f1.numerator;
  int mixed_numerator_2 = f2.whole_number * f2.denominator + f2.numerator;
  f.numerator = mixed_numerator_1 * mixed_numerator_2;
  f.denominator = f1.denominator * f2.denominator;
  simplify_fraction(f);
  return f;
}

// Main function
int main() {
  Fraction f1, f2;

  get_fraction(f1);
  get_fraction(f2);
  print(f1);
  print(f2);
  string input;
  // Ask user which arthmetic operation they want to perform
  cout << "\nWould you like to add or multiply the two fraction? (+/*): ";
  cin >> input;
  if (input == "+") {
    Fraction f3 = add(f1, f2);
    print(f3);
  } else if (input == "*") {
    Fraction f3 = multiply(f1, f2);
    print(f3);
  }
  return 0;
  }
