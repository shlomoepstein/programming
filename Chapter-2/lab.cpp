#include <iostream>

using std::cout, std::cin, std::endl;

int main () {
   int quarters, dimes, nickels, worth;

   cout << "How many quarters? ";
   cin >> quarters;
   cout << "How many dimes? ";
   cin >> dimes;
   cout << "How many nickels? ";
   cin >> nickels;

   worth = quarters * 25 + dimes * 10 + nickels * 5;

   cout << "\nYour net worth is " << worth << " cents.";

   if (worth >= 500) {
      cout << " That's" << (worth % 100 != 0 ? " more than " : " ") << worth / 100 << " dollars!\n"
           << "Can I have a donation?" << endl;
   } else {
      cout << " That's" << (worth % 100 != 0 ? " less than " : " ") << worth / 100 + 1 << " dollars.\n"
           << "Perhaps you should seek employment." << endl;
   }

   return 0;
}
