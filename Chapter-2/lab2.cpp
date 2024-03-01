#include <iostream>
#include <iomanip>

using std::cout, std::cin, std::endl;
using std::fixed, std::setprecision;

int main () {
   double fahrenheit, celsius;

   cout << "Enter the temperature in degrees fahrenheit: ";
   cin >> fahrenheit;

   celsius = (fahrenheit - 32) * 5 / 9;

   cout << fixed << setprecision(1)
        << "\nIt is " << celsius << " degrees celsius." << endl;

   return 0;
}
