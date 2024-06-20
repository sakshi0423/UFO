#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

const vector<string> codewords = {
    "spaceship", "galaxy", "asteroid", "planet", "satellite", "comet", "star", "universe", "alien", "meteorite"
};

void display_status(const vector<char>& incorrect, const string& answer) {
    cout << "\nIncorrect Guesses: ";
    for (char c : incorrect) {
        cout << c << ' ';
    }
    cout << "\nCodeword: ";
    for (char c : answer) {
        cout << c << ' ';
    }
    cout << endl;
}

void display_misses(int misses) {
    if (misses == 0 || misses == 1) {
        cout << "                 .\n"
             << "                 |\n"
             << "              .-\"^\"-.\n"
             << "             /_....._\\\n"
             << "         .-\"`         `\"-.\n"
             << "        (  ooo  ooo  ooo  )\n"
             << "         '-.,_________,.-'\n"
             << "              /     \\    \n"
             << "             /   0   \\    \n"
             << "            /  --|--  \\  \n"
             << "           /     |     \\  \n"
             << "          /     / \\     \\ \n"
             << "         /               \\ \n";
    } else if (misses == 2) {
        cout << "                 .\n"
             << "                 |\n"
             << "              .-\"^\"-.\n"
             << "             /_....._\\\n"
             << "         .-\"`         `\"-.\n"
             << "        (  ooo  ooo  ooo  )\n"
             << "         '-.,_________,.-'\n"
             << "              /  0  \\    \n"
             << "             / --|-- \\    \n"
             << "            /    |    \\  \n"
             << "           /    / \\    \\ \n"
             << "          /             \\ \n"
             << "         /               \\ \n";
    } else if (misses == 3) {
        cout << "                 .\n"
             << "                 |\n"
             << "              .-\"^\"-.\n"
             << "             /_....._\\\n"
             << "         .-\"`         `\"-.\n"
             << "        (  ooo  ooo  ooo  )\n"
             << "         '-.,_________,.-'\n"
             << "              /--|--\\    \n"
             << "             /   |   \\    \n"
             << "            /   / \\   \\  \n"
             << "           /           \\ \n"
             << "          /             \\ \n"
             << "         /               \\ \n";
    } else if (misses == 4) {
        cout << "                 .\n"
             << "                 |\n"
             << "              .-\"^\"-.\n"
             << "             /_....._\\\n"
             << "         .-\"`         `\"-.\n"
             << "        (  ooo  ooo  ooo  )\n"
             << "         '-.,_________,.-'\n"
             << "              /  |  \\    \n"
             << "             /  / \\  \\    \n"
             << "            /         \\  \n"
             << "           /           \\ \n"
             << "          /             \\ \n"
             << "         /               \\ \n";
    } else if (misses == 5) {
        cout << "                 .\n"
             << "                 |\n"
             << "              .-\"^\"-.\n"
             << "             /_....._\\\n"
             << "         .-\"`         `\"-.\n"
             << "        (  ooo  ooo  ooo  )\n"
             << "         '-.,_________,.-'\n"
             << "              / / \\ \\    \n"
             << "             /       \\    \n"
             << "            /         \\  \n"
             << "           /           \\ \n"
             << "          /             \\ \n"
             << "         /               \\ \n";
    } else if (misses == 6) {
        cout << "                 .\n"
             << "                 |\n"
             << "              .-\"^\"-.\n"
             << "             /_....._\\\n"
             << "         .-\"`         `\"-.\n"
             << "        (  ooo  ooo  ooo  )\n"
             << "         '-.,_________,.-'\n"
             << "              /     \\    \n"
             << "             /       \\    \n"
             << "            /         \\  \n"
             << "           /           \\ \n"
             << "          /             \\ \n"
             << "         /               \\ \n";
    }
}

bool play_game() {
    string codeword = codewords[rand() % codewords.size()];
    string answer(codeword.size(), '_');
    vector<char> incorrect;
    int misses = 0;

    cout << "=============\n";
    cout << "UFO: The Game\n";
    cout << "=============\n";
    cout << "Instructions: save your friend from alien abduction by guessing the letters in the codeword.\n";

    while (answer != codeword && misses < 6) {
        display_status(incorrect, answer);
        display_misses(misses);

        cout << "Please enter your guess: ";
        char guess;
        cin >> guess;

        if (find(codeword.begin(), codeword.end(), guess) != codeword.end()) {
            for (size_t i = 0; i < codeword.size(); ++i) {
                if (codeword[i] == guess) {
                    answer[i] = guess;
                }
            }
            cout << "Correct!\n";
        } else {
            cout << "Incorrect! The tractor beam pulls the person in further.\n";
            incorrect.push_back(guess);
            ++misses;
        }
    }

    display_status(incorrect, answer);
    display_misses(misses);

    if (answer == codeword) {
        cout << "Hooray! You saved the person and earned a medal of honor!\n";
        cout << "Codeword was: " << codeword << endl;
    } else {
        cout << "Oh no! The UFO just flew away with another person!\n";
        cout << "Codeword was: " << codeword << endl;
    }

    cout << "Would you like to play again? [y/n] ";
    char response;
    cin >> response;
    return response == 'y';
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    while (play_game()) {
        // Loop to play the game again if the player chooses to
    }

    return 0;
}
