#include <iostream>
#include <iomanip>

using std::cout, std::endl;

bool isPrime (int n);

int main () {
    cout << "The first 100 prime numbers are\n";

    cout << std::left;
    for (int i = 0, count = 0; true; i++) {
        if (isPrime(i)) {
            cout << std::setw(5) << i;
            count++;

            if (count % 10 == 0) {
                cout << endl;
            }

            if (count == 100) {
                break;
            }
        }
    }

    return 0;
}


bool isPrime (int n) {
    if (n == 0 || n == 1) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
