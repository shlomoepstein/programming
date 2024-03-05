#include <iostream>
#include <array>
#include <string>
#include <locale>
#include <ios>
#include <limits>
#include <cmath>

#include <fmt/format.h>

using std::cout, std::cin,
      std::array,
      fmt::print;

void clearInputBuffer ();


int main () {
    std::locale::global(std::locale("en_US.UTF-8"));

    double loanAmount,
           interestRate,
           payment,
           interest,
           balance,
           totalInterest;
    int    month,
           loanWidth;
    char   goAgain;

    cout << "╭────╥─────────────────╥────╮\n"
         << "╞════╣ Loan Calculator ╠════╡\n"
         << "╰────╨─────────────────╨────╯\n";

    do {
        cout << "\nEnter the loan amount: ";
        cin >> loanAmount;
        cout << "Enter the interest rate (%): ";
        cin >> interestRate;
        clearInputBuffer();

        interestRate /= 100;

        loanWidth = std::to_string(static_cast<long>(loanAmount)).length();
        loanWidth += (loanWidth - 1) / 3;
        array<int, 4> cols = {6, loanWidth + 4, loanWidth + 3, loanWidth + 5};
        if (cols[1] < 7) cols[1] = 7;
        if (cols[2] < 8) cols[2] = 8;
        if (cols[3] < 7) cols[3] = 7;

        print("\n╭{:─<{}}┬{:─<{}}┬{:─<{}}┬{:─<{}}╮\n"
              , "", cols[0], "", cols[1], "", cols[2], "", cols[3]);
        print("│{:^{}}│{:^{}}│{:^{}}│{:^{}}│\n"
              , "Month", cols[0], "Payment", cols[1], "Interest", cols[2], "Balance", cols[3]);
        print("├{:─<{}}┼{:─<{}}┼{:─<{}}┼{:─<{}}┤\n"
              , "", cols[0], "", cols[1], "", cols[2], "", cols[3]);

        month = 0;
        totalInterest = 0;
        balance = loanAmount;
        payment = loanAmount / 20;

        print("│{:<{}}│{:>{}}│{:>{}}│{:>{}.2Lf}│\n"
              , "-", cols[0], "-.--", cols[1], "-.--", cols[2], balance, cols[3]);

        while (balance > 0) {
            month++;
            interest = round(balance * interestRate / 12 * 100) / 100;
            totalInterest += interest;
            balance += interest;
            payment = payment < balance ? payment : balance;
            balance -= payment;

            print("│{:<{}}│{:>{}.2Lf}│{:>{}.2Lf}│{:>{}.2Lf}│\n"
                  , month, cols[0], payment, cols[1], interest, cols[2], balance, cols[3]);
        }

        print("╰{:─<{}}┴{:─<{}}┴{:─<{}}┴{:─<{}}╯\n", "", cols[0], "", cols[1], "", cols[2], "", cols[3]);

        print("\nTotal interest: {:.2Lf}\n", totalInterest);
        print("Interest as annualized percentage: {:.2f}%\n"
              , totalInterest / (month / 12.0) / loanAmount * 100);

        cout << "\nNew calculation (y, n)? ";
        cin >> goAgain;
    } while (goAgain == 'Y' || goAgain == 'y');

    return 0;
}


void clearInputBuffer () {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
