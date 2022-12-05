/*Project-------Advent_Of_Code
 *File----------Day2a.cpp
 *Author--------Justin Kachele
 *Date----------12/1/22
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout, std::endl, std::cerr, std::string;

string getInput();

int numLines;

int main() {
    string input = getInput();
    if (input.empty()) {
        return 1;
    }
    cout << input << endl;
    return 0;
}

string getInput() {
    std::ifstream inputFileStream{"2022/Day2/input.txt"};
    if (!inputFileStream) {
        cerr << "File Not Found!" << endl;
        return "";
    }
    string input;
    while (inputFileStream) {
        string line;
        getline(inputFileStream, line);
        input += line;
        input += "\n";
        numLines++;
    }
    inputFileStream.close();
    return input;
}