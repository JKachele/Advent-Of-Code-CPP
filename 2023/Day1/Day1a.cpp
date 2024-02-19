/*************************************************
*Project-------Advent_Of_Code
*File----------Day1a
*Author--------Justin Kachele
*Created-------Friday Dec 1, 2023
*License-------GNU General Public License v3.0
************************************************/
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::cerr;
using std::string;

string getInput();
int numLines;

int main() {
    string input = getInput();
    if (input.empty()) {
        cerr << "Input is empty" << endl;
        return 1;
    }
    cout << numLines << "\n\n" << input << endl;

    return 0;
}

string getInput() {
    // std::ifstream inputFileStream{
    //     "C:\\Users\\e454984\\Documents\\Programming\\C_C++\\Advent-Of-Code-CPP\\2023\\Day1\\input.txt"
    // };
    std::ifstream inputFileStream{"2023/Day1/input.txt"};
    if(!inputFileStream) {
        cerr << "File Not Found!" << endl;
        return "";
    }
    string input;
    while(inputFileStream) {
        string line;
        getline(inputFileStream, line);
        input += line;
        input += "\n";
        numLines++;
    }
    inputFileStream.close();
    return input;
}
