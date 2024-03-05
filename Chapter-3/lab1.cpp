#include <iostream>
#include <string>

using std::cout, std::cin, std::endl,
      std::string;

enum Move {
    rock,
    paper,
    scissors
};

Move getMove ();
string reason (Move winningMove);

int main () {

    Move player1,
         player2;
    int  player1winCount = 0,
         player2winCount = 0;
    char goAgain;

    cout << "Rock-Paper-Scissors\n";

    do {
        cout << "\nPlayer 1 (r, p, s): ";
        player1 = getMove();
        cout << "Player 2 (r, p, s): ";
        player2 = getMove();

        if (player1 == player2) {
            cout << "\nIt's a tie\n";
        } else if (player1 == (player2 + 1) % 3) {
            cout << "\nPlayer 1 wins: " << reason(player1) << "\n";
            player1winCount++;
        } else {
            cout << "\nPlayer 2 wins: " << reason(player2) << "\n";
            player2winCount++;
        }

        cout << "\nGo again (y, n)? ";
        cin >> goAgain;
    } while (goAgain == 'Y' || goAgain == 'y');

    cout << "\nPlayer 1 won " << player1winCount << " time" << (player1winCount == 1 ? "\n" : "s\n")
         << "Player 2 won " << player2winCount << " time" << (player2winCount == 1 ? "" : "s") << endl;

    return 0;
}


Move getMove () {
    char input;

    while (true) {
        cin >> input;

        switch (input) {
            case 'R':
            case 'r':
                return rock;
            case 'P':
            case 'p':
                return paper;
            case 'S':
            case 's':
                return scissors;
        }

        cout << "Invalid input, try again: ";
    }
}


string reason (Move winningMove) {
    switch (winningMove) {
        case rock:
            return "rock breaks scissors";
        case paper:
            return "paper covers rock";
        case scissors:
            return "scissors cuts paper";
    }
}
