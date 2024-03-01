#include <cmath>
#include <iostream>

using std::cout, std::cin, std::endl;

double lbToKg (double n);
double inToCm (double n);


int main () {
    double age,
           height,
           weight,
           bmr;
    char   sex;

    cout << "BMR Calculator: Harris-Benedict equation\n\n"
         << "Enter your age in years: ";
    cin >> age;
    cout << "Enter your height in inches: ";
    cin >> height;
    cout << "Enter your weight in pounds: ";
    cin >> weight;
    while (true) {
        cout << "Enter your assigned sex at birth (m, f): ";
        cin >> sex;

        if (sex == 'M' || sex == 'm' ||
            sex == 'F' || sex == 'f') {
            break;
        }

        cout << "Unsupported model\n";
    }

    bmr = (10 * lbToKg(weight))
        + (6.25 * inToCm(height))
        - (5 * age);

    if (sex == 'M' || sex == 'm') {
        bmr += 5;
    }
    if (sex == 'F' || sex == 'f') {
        bmr -= 161;
    }

    cout << "\nYour basal metabolic rate is " << static_cast<int>(std::round(bmr)) << endl;

    return 0;
}


double lbToKg (double n) {
    return n * 0.45359237;
}


double inToCm (double n) {
    return n * 2.54;
}
