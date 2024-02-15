/*Project-------Advent_Of_Code
 *File----------Day2a.cpp
 *Author--------Justin Kachele
 *Date----------12/1/22
 *License-------GNU General Public License v3.0
 ******************************************/
#include <iostream>
#include <fstream>
#include <vector>

using std::cout, std::endl, std::cerr, std::string, std::vector;

int getGameScore(unsigned int p1, unsigned int p2) {
    // Tie
    if (p1 == p2) {
        return 3 + (int(p2) + 1);
    }
    // Rock Vs Paper: win
    if (p1 == 0 && p2 == 1) {
        return 6 + (int(p2) + 1);
    }
    // Paper Vs Rock: Loose
    if (p1 == 1 && p2 == 0) {
        return 0 + (int(p2) + 1);
    }
    // Rock Vs Scissors: loose
    if (p1 == 0 && p2 == 2) {
        return 0 + (int(p2) + 1);
    }
    // Scissors Vs Rock: win
    if (p1 == 2 && p2 == 0) {
        return 6 + (int(p2) + 1);
    }
    // Paper Vs Scissors: win
    if (p1 == 1 && p2 == 2) {
        return 6 + (int(p2) + 1);
    }
    // Scissors Vs Paper: Loose
    if (p1 == 2 && p2 == 1) {
        return 0 + (int(p2) + 1);
    }

    cerr << "Invalid Game!" << endl;
    return 0;
}

int play(const vector<string>& games) {
    int score = 0;
    for (string s: games) {
        char p1Char = s[0];
        // Convert from ABC to 012
        unsigned int p1 = int(p1Char) - 65;
        char p2Char = s[2];
        // Convert from XYZ to 012
        unsigned int p2 = int(p2Char) - 88;
        score += getGameScore(p1, p2);
    }

    return score;
}

vector<string> getInput() {
    std::ifstream inputFileStream{"2022/Day2/input.txt"};
    vector<string> input;
    if (!inputFileStream) {
        cerr << "File Not Found!" << endl;
        return input;
    }
    while (inputFileStream) {
        string line;
        getline(inputFileStream, line);
        if (!line.empty())
            input.push_back(line);
    }
    inputFileStream.close();

    return input;
}

int main() {
    vector<string> input = getInput();

    for (string &s: input) {
        cout << "{" << s << "}, ";
    }
    cout << endl;

    int score = play(input);

    cout << score << endl;

    return 0;
}
