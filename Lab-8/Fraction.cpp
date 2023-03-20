// Mitchell
// 3-19-2023
// Lab 8-A
#include <iostream>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

class Fraction {
private:
    int whole_number;  // Holds the whole number part of the fraction
    int numerator;     // Holds the numerator of the fraction
    int denominator;   // Holds the denominator of the fraction

public:
    static const char SEPARATOR = '/';  // The symbol that separates the numerator and denominator when displaying a Fraction

    // Constructor with two parameters (numerator and denominator)
    Fraction(int num = 0, int denom = 1) : whole_number(0), numerator(num), denominator(denom) {
        if (denominator == 0) {
            denominator = 1;
        }
        reduceFraction();
    }

    // Constructor with three parameters (whole number, numerator, and denominator)
    Fraction(int whole, int num, int denom) : whole_number(whole), numerator(num), denominator(denom) {
        if (denominator == 0) {
            denominator = 1;
        }
        reduceFraction();
    }

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
        string input;
        
        cout << "Enter the whole number (press enter for 0): ";
        getline(cin, input);
        whole_number = input.empty() ? 0 : stoi(input);
        
        cout << "Enter the numerator (press enter for 0): ";
        getline(cin, input);
        numerator = input.empty() ? 0 : stoi(input);
        
        cout << "Enter the denominator: ";
        cin >> denominator;
        cin.ignore();
        if (denominator == 0) {
            denominator = 1;
        }
        reduceFraction();
    }

    // Function to reduce the given fraction and update the Fraction object
    void reduceFraction() {
        int gcd = __gcd(numerator, denominator);  // Calculate the greatest common divisor (GCD)
        numerator /= gcd;                         // Reduce the numerator by dividing it by the GCD
        denominator /= gcd;                       // Reduce the denominator by dividing it by the GCD
        whole_number += numerator / denominator;  // Update the whole number
        numerator %= denominator;                 // Update the numerator
        if (numerator == 0) {
            denominator = 1;
        }
    }

    // Function to display the given fraction in the proper format
    void displayFraction() const {
        cout << whole_number;
        if (numerator != 0) {
            cout << " " << numerator << SEPARATOR << denominator;
        } else {
            cout << " 0/1";
        }
        cout << endl;
    }
};

int main() {
    Fraction f;  // Declare a Fraction object for user input

    while (true) {
        f.enterFractionValue();  // Get Fraction values from the user

        if (f.getNumerator() == 0 && f.getWholeNumber() == 0) {
            break;  // End the program when both the whole number and numerator are 0
        }

        f.reduceFraction();   // Reduce the Fraction
        f.displayFraction();  // Display the Fraction
    }

    return 0;
}