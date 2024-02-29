#include <iostream>

using std::cout, std::cin, std::endl;

int main () {
   int x, y, sum, product;

   cout << "Enter an integer: ";
   cin >> x;
   cout << "Enter another integer: ";
   cin >> y;

   sum = x + y;
   product = x * y;

   cout << "The sum is " << sum << ", the product is " << product << "." << endl;

   return 0;
}
