#include <iostream>
#include <string>
#include <utility>

using std::cout, std::cin,
      std::string;

struct Player {
    string name;
    double time;
};


int main () {
    Player players[3];
    string myLovelyNewline;

    cout << "Enter the name of first runner: ";
    std::getline(cin, players[0].name);
    cout << "Time it took " << players[0].name << " to finish race: ";
    cin >> players[0].time;
    while (players[0].time <= 0) {
        cout << "Positive numbers only. ";
        cin >> players[0].time;
    }

    cout << "Enter the name of second runner: ";
    std::getline(cin, myLovelyNewline);
    std::getline(cin, players[1].name);
    cout << "Time it took " << players[1].name << " to finish race: ";
    cin >> players[1].time;
    while (players[1].time <= 0) {
        cout << "Positive numbers only. ";
        cin >> players[1].time;
    }

    cout << "Enter the name of third runner: ";
    std::getline(cin, myLovelyNewline);
    std::getline(cin, players[2].name);
    cout << "Time it took " << players[2].name << " to finish race: ";
    cin >> players[2].time;
    while (players[2].time <= 0) {
        cout << "Positive numbers only. ";
        cin >> players[2].time;
    }

    if (players[0].time > players[1].time) std::swap(players[0], players[1]);
    if (players[1].time > players[2].time) std::swap(players[1], players[2]);
    if (players[0].time > players[1].time) std::swap(players[0], players[1]);

    cout << "\nFirst Place: " << players[0].name << "\n"
         << "Second Place: " << players[1].name << "\n"
         << "Third Place: " << players[2].name << std::endl;

    return 0;
}
