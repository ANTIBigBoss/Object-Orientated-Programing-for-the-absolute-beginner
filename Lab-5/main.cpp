// Mitchell
// Case Project 1 - Lab 5
// 2023-02-15

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

// Dynamically allocates an array of Fraction objects with the size specified by
// the size parameter.
Fraction *array_of_fractions() {
  Fraction *array = new Fraction[5];
  // Returns a pointer to the first element of the array (Fraction*).
  return array;
}

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
  cout << "\n";
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

// Function to add an array of fractions and return the sum as a new fraction
Fraction add(Fraction *fractions, int size) {
  Fraction sum = fractions[0];
  for (int i = 1; i < size; i++) {
    sum = add(sum, fractions[i]);
  }
  return sum;
}

// Function to calculate the averages of all 5 fractions
void average(Fraction *fractions, int size) {
  Fraction sum = add(fractions, size);
  simplify_fraction(sum);
  int averageNumerator = sum.numerator / size;
  int averageDenominator = sum.denominator;
  Fraction averageFraction = {averageNumerator, averageDenominator, 0};
  simplify_fraction(averageFraction);
  print(averageFraction);
}

// Main function
int main() {
  Fraction f1, f2, f3, f4, f5;

  // Gets the input of the fractions
  // Added in extra cout statements so I didn't have to modify the lab 4
  // functions too much also makes it look cleaner too on output
  cout << "\nEnter the first fraction\n\n";
  get_fraction(f1);
  cout << "\nEnter the second fraction:\n\n";
  get_fraction(f2);
  cout << "\nEnter the third fraction:\n\n";
  get_fraction(f3);
  cout << "\nEnter the fourth fraction:\n\n";
  get_fraction(f4);
  cout << "\nEnter the fifth fraction:\n\n";
  get_fraction(f5);

  // Print the fractions
  cout << "Fraction 1\n";
  print(f1);
  cout << "\nFraction 2\n";
  print(f2);
  cout << "\nFraction 3\n";
  print(f3);
  cout << "\nFraction 4\n";
  print(f4);
  cout << "\nFraction 5\n";
  print(f5);

  Fraction fractions[] = {f1, f2, f3, f4, f5};

  Fraction sum = add(fractions, 5);
  cout << "\nSum of all fractions\n";
  print(sum);

  cout << "\nAverage of all fractions\n";
  average(fractions, 5);

  return 0;
}