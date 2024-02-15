/*Project-------Advent_Of_Code
 *File----------Day4a.cpp
 *Author--------Justin Kachele
 *Date----------1/2/23
 *License-------GNU General Public License v3.0
 ******************************************/
#include <iostream>
#include <fstream>
#include <vector>

using std::cout, std::endl, std::cerr, std::string, std::vector;

int solvePuzzle(const vector<string> &input) {
    int solution = 0;

    return solution;
}

vector<string> getInput() {
    std::ifstream inputFileStream{"2022/Day4/input.txt"};
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
