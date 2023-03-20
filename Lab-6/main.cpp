#include <iostream>
#include <algorithm>

using namespace std;

struct Fraction {
    int whole_number;
    int numerator;
    int denominator;
};

// Function to prompt user for input and return a Fraction object
Fraction enterFractionValue();
// Function to reduce the given fraction and return the reduced Fraction object
Fraction reduceFraction(Fraction fraction);
// Function to display the given fraction in the proper format
void displayFraction(Fraction fraction);
// Function to prompt the user to enter a valid denominator
void promptDenominator(int &denominator);

Fraction enterFractionValue() {
    Fraction f;
    // Prompt user to enter whole number, numerator, and denominator
    cout << "Enter the whole number: ";
    cin >> f.whole_number;
    cout << "\nEnter the numerator: ";
    cin >> f.numerator;
    cout << "\nEnter the denominator: ";
    cin >> f.denominator;
    // Ensure the denominator is valid
    promptDenominator(f.denominator);
    return f;
}

void promptDenominator(int &denominator) {
    // Check if the denominator is 0 and ask for a valid input if it is
    while (denominator == 0) {
        cout << "Denominator cannot be 0. Please enter a valid denominator: ";
        cin >> denominator;
    }
}

Fraction reduceFraction(Fraction fraction) {
    // Calculate the mixed number numerator
    int mixed_number_numerator = fraction.whole_number * fraction.denominator + fraction.numerator;
    // Find the greatest common divisor
    int gcd = __gcd(mixed_number_numerator, fraction.denominator);

    // Reduce the fraction using the gcd
    fraction.numerator = mixed_number_numerator / gcd;
    fraction.denominator /= gcd;
    // Update the whole number and numerator if necessary
    fraction.whole_number = fraction.numerator / fraction.denominator;
    fraction.numerator %= fraction.denominator;

    return fraction;
}

void displayFraction(Fraction fraction) {
    // Display the whole number if it exists
    if (fraction.whole_number != 0) {
        cout << fraction.whole_number << " ";
    }

    // Display the numerator and denominator if the numerator exists
    if (fraction.numerator != 0) {
        cout << fraction.numerator << "/" << fraction.denominator;
    }

    // Display 0 if both the whole number and the numerator are 0
    if (fraction.whole_number == 0 && fraction.numerator == 0) {
        cout << "0";
    }

    cout << endl;
}

int main() {
    Fraction f;

    // Continue to get Fraction values from the user until both the whole number and the numerator are 0
    do {
        f = enterFractionValue();

        if (f.whole_number == 0 && f.numerator == 0) {
            break;
        }

        displayFraction(f);
        f = reduceFraction(f);
        displayFraction(f);
    } while (true);

    return 0;
}
