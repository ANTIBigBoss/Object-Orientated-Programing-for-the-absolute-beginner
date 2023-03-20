#include <iostream>
#include <algorithm>

using namespace std;

class Fraction {
private:
    int whole_number;  // Holds the whole number part of the fraction
    int numerator;     // Holds the numerator of the fraction
    int denominator;   // Holds the denominator of the fraction

public:
    static const char SEPARATOR = '/';  // The symbol that separates the numerator and denominator when displaying a Fraction

    // Function to get the whole number of the Fraction object
    int getWholeNumber() const {
        return whole_number;
    }

    // Function to get the numerator of the Fraction object
    int getNumerator() const {
        return numerator;
    }

    // Function to prompt user for input and set the values of the Fraction object
    void enterFractionValue() {
        cout << "Enter the whole number: ";
        cin >> whole_number;
        cout << "Enter the numerator: ";
        cin >> numerator;
        cout << "Enter the denominator: ";
        cin >> denominator;
        while (denominator == 0) {
            cout << "Denominator cannot be 0. Please enter a valid denominator: ";
            cin >> denominator;
        }
    }

    // Function to reduce the given fraction and update the Fraction object
    void reduceFraction() {
        int gcd = __gcd(numerator, denominator);  // Calculate the greatest common divisor (GCD)
        numerator /= gcd;                         // Reduce the numerator by dividing it by the GCD
        denominator /= gcd;                       // Reduce the denominator by dividing it by the GCD
        whole_number += numerator / denominator;  // Update the whole number
        numerator %= denominator;                 // Update the numerator
    }

// Function to display the given fraction in the proper format
   void displayFraction() const {
        cout << whole_number;
        if (numerator != 0) {
            cout << " " << numerator << SEPARATOR << denominator;
        }
        cout << endl;
    }
};

int main() {
    Fraction f;  // Declare a Fraction object

    while (true) {
        f.enterFractionValue();  // Get Fraction values from the user

        if (f.getNumerator() == 0 && f.getWholeNumber() == 0) {
            break;  // End the program when both the whole number and numerator are 0
        }

        f.displayFraction();  // Display the Fraction
        f.reduceFraction();   // Reduce the Fraction
        f.displayFraction();  // Display the Fraction again
    }

    return 0;
}
