/*Project-------Advent_Of_Code
 *File----------Day3a.cpp
 *Author--------Justin Kachele
 *Date----------12/24/22
 *License-------GNU General Public License v3.0
 ******************************************/
#include <iostream>
#include <fstream>
#include <vector>

using std::cout, std::endl, std::cerr, std::string, std::vector;

int getPriority(const char& c) {
    int priority;
    if ((int)c >= 97) {
        // Lowercase Letters get 1 - 26
        priority = (int)c - 96;
    } else {
        // Uppercase Letters get 27 - 52
        priority = (int)c - 38;
    }
    return priority;
}

int solvePuzzle(const vector<string>& input) {
    int solution = 0;
    for (const string& sack: input) {
        char result;
        unsigned int sackSize = sack.size() / 2;
        string sac1 = sack.substr(0, sackSize);
        string sac2 = sack.substr(sackSize, sackSize);

        // Hash table: Index = ASCII code for char
        bool hashTable[128]{};
        for (char c: sac2) {
            hashTable[c] = true;
        }

        for (const char& c: sac1) {
            if (hashTable[c]) {
                result = c;
                break;
            }
        }

        solution += getPriority(result);
    }
    return solution;
}

vector<string> getInput() {
    std::ifstream inputFileStream{"2022/Day3/input.txt"};
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

    int solution = solvePuzzle(input);
    cout << solution << endl;

    return 0;
}
