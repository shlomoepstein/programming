#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout, std::cin, std::endl;


int main () {
    const double TOLERANCE = 1e-7;

    double number,
           guess,
           nextGuess,
           difference = TOLERANCE + 1;  // ensure that difference starts off bigger than TOLERANCE
    int    count = 0;

    cout << "Square root: Babylonian method\n\n"
         << "Enter a number: ";
    cin >> number;

    guess = number / 2;

    while (difference > TOLERANCE) {
        nextGuess = (guess + number / guess) / 2;
        difference = abs(guess - nextGuess);
        guess = nextGuess;
        count++;
    }

    cout << "Got the square root in " << count << " iterations\n"
         << "The square root is " << std::fixed << std::setprecision(6) << guess << endl;

    return 0;
}
