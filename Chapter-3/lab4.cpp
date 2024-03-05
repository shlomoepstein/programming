#include <iostream>
#include <ios>
#include <limits>

using std::cout, std::cin, std::endl;

void clearInputBuffer () {
    if (cin.fail()) cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main () {
    int pile = 23,
        userMove,
        compMove;

    cout << "╭──────────────────╮\n"
         << "│  The Game of 23  │\n"
         << "╰──────────────────╯\n";

    do {
        cout << "\nThere " << (pile == 1 ? "is " : "are ") << pile
             << " toothpick" << (pile == 1 ? "" : "s") << " left.\n"
             << "\nYour turn (1, 2, or 3): ";
        cin >> userMove;

        while (userMove < 1 || userMove > 3 || userMove > pile) {
            clearInputBuffer();
            cout << "Sorry, that's not a valid move.\n"
                 << "Try again (1, 2, or 3): ";
            cin >> userMove;
        }

        pile -= userMove;

        if (pile > 4) {
            compMove = 4 - userMove;
        } else if (pile > 1) {
            compMove = pile - 1;
        } else if (pile == 1) {
            cout << "\nI took the last toothpick.\n"
                 << "You win!" << endl;
            return 0;
        } else {
            cout << "\nYou took the last toothpick.\n"
                 << "You lose." << endl;
            return 0;
        }

        pile -= compMove;

        cout << "You took " << userMove << " toothpick" << (userMove == 1 ? ".\n" : "s.\n");
        cout << "I took " << compMove << " toothpick" << (compMove == 1 ? ".\n" : "s.\n");
    } while (pile > 0);

    return 0;
}
