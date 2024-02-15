/*Project-------Advent_Of_Code
 *File----------Day2b.cpp
 *Author--------Justin Kachele
 *Date----------12/22/22
 *License-------GNU General Public License v3.0
 ******************************************/
#include <iostream>
#include <fstream>
#include <vector>

using std::cout, std::endl, std::cerr, std::string, std::vector;

int getGameScore(unsigned int p1, unsigned int p2) {
    int score = 0;
    switch (p2) {
        // Loose
        case 0:
            score = ((int(p1) + 2) % 3) + 1;
            break;
        // Tie
        case 1:
            score = int(p1) + 1;
            score += 3;
            break;
        // Win
        case 2:
            score = ((int(p1) + 1) % 3) + 1;
            score += 6;
            break;
        default:
            cerr << "Invalid Game" << endl;
    }

    return score;
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