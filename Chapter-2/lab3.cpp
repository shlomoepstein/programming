#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include <ios>

using std::cout, std::cin,
      std::string, std::ostringstream;

// clears the input buffer until it hits a newline
void clearInputBuffer ();
// formats a dollar amount nicely
string dollarString (double amount);


int main () {
    const float
          WEEKDAY = 0.4f,
          OFF_HOURS = 0.25f,
          WEEKEND = 0.15f;
    char  dayOfWeek,
          goAgain;
    int   startTime,
          callLength;
    float rate,
          total,
          runningTotal = 0;

    cout << "\n**Long-Distance Call Calculator**\n";

    do {
        // We only need to differentiate between Saturday/Sunday and weekdays, so I'm only reading the
        // first character. This allows the user to input the day in any format, as long as it starts
        // with the right character
        cout << "\nEnter the day of week of call: ";
        cin >> dayOfWeek;
        clearInputBuffer();
        // We only need the hour portion of the time and can throw away everything after the ':'
        cout << "Enter call start time (24-hour format): ";
        cin >> startTime;
        clearInputBuffer();
        cout << "Enter length of call in minutes: ";
        cin >> callLength;

        if (dayOfWeek == 'S' || dayOfWeek == 's') {
            rate = WEEKEND;
        } else if (startTime < 8 || startTime >= 18) {
            rate = OFF_HOURS;
        } else {
            rate = WEEKDAY;
        }

        total = callLength * rate;
        runningTotal += total;

        cout << "\nRate:      " << std::setw(8) << dollarString(rate)
             << "\nThis call: " << std::setw(8) << dollarString(total)
             << "\nTotal:     " << std::setw(8) << dollarString(runningTotal)
             << "\n\n";

        do {
            // The same technique as before (of only reading a char) allows us to match "Y", "yes",
            // "no", "nope", "yea", "No", etc. with very simple logic
            cout << "Would you like to add another call? (y, n): ";
            cin >> goAgain;
            clearInputBuffer();
        } while (goAgain != 'Y' && goAgain != 'y' &&
                 goAgain != 'N' && goAgain != 'n');

    } while (goAgain == 'Y' || goAgain == 'y');
}


void clearInputBuffer () {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


string dollarString (double amount) {
    ostringstream oss;

    oss << std::fixed << std::setprecision(2);
    oss << "$" << amount;

    return oss.str();
}
