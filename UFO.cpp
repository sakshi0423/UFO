#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// List of possible codewords
const vector<string> codewords = {
    "spaceship", "galaxy", "asteroid", "planet", "satellite", "comet", "star", "universe", "alien", "meteorite"
};

// Function to display the current game status: incorrect guesses and the current state of the answer
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

// Function to display the visual representation of the number of misses
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

// Function to play the game
bool play_game() {
    // Select a random codeword from the list
    string codeword = codewords[rand() % codewords.size()];
    // Initialize the answer with underscores
    string answer(codeword.size(), '_');
    // Vector to store incorrect guesses
    vector<char> incorrect;
    // Initialize the number of misses
    int misses = 0;

    cout << "=============\n";
    cout << "UFO: The Game\n";
    cout << "=============\n";
    cout << "Instructions: save your friend from alien abduction by guessing the letters in the codeword.\n";

    // Main game loop
    while (answer != codeword && misses < 6) {
        // Display current status and misses
        display_status(incorrect, answer);
        display_misses(misses);

        // Prompt player for a guess
        cout << "Please enter your guess: ";
        char guess;
        cin >> guess;

        // Check if the guess is in the codeword
        if (find(codeword.begin(), codeword.end(), guess) != codeword.end()) {
            // Update the answer with the correct guess
            for (size_t i = 0; i < codeword.size(); ++i) {
                if (codeword[i] == guess) {
                    answer[i] = guess;
                }
            }
            cout << "Correct!\n";
        } else {
            // Add the incorrect guess to the list and increment misses
            cout << "Incorrect! The tractor beam pulls the person in further.\n";
            incorrect.push_back(guess);
            ++misses;
        }
    }

    // Display final status and misses
    display_status(incorrect, answer);
    display_misses(misses);

    // Check if the player has won or lost
    if (answer == codeword) {
        cout << "Hooray! You saved the person and earned a medal of honor!\n";
        cout << "Codeword was: " << codeword << endl;
    } else {
        cout << "Oh no! The UFO just flew away with another person!\n";
        cout << "Codeword was: " << codeword << endl;
    }

    // Prompt to play again
    cout << "Would you like to play again? [y/n] ";
    char response;
    cin >> response;
    return response == 'y';
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Loop to play the game again if the player chooses to
    while (play_game()) {
        // Empty loop body as play_game() handles everything
    }

    return 0;
}
