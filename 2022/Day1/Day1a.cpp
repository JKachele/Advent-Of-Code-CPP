/*************************************************
 *Project-------Advent_Of_Code
 *File----------Day1a.cpp
 *Author--------Justin Kachele
 *Date----------12/1/22
 *License-------Mozilla Public License Version 2.0
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
        return 1;
    }
//    cout << numLines << "\n\n" << input << endl;

    int foodItems[numLines];
    string delimiter = "\n";
    for (int i = 0; i < numLines; i++) {
        string token = input.substr(0, input.find(delimiter));
        if (!token.empty()) {
            foodItems[i] = stoi(token);
        } else {
            foodItems[i] = -1;
        }
        input.erase(0, input.find(delimiter) + delimiter.length());
    }

    for (int i = 0; i < numLines; i++) {
        cout << "[" << foodItems[i] << "], ";
    }

    int mostCalories = 0;
    int calorieCount = 0;
    for (int i = 0; i < numLines; i++) {
        if (foodItems[i] != -1) {
            calorieCount += foodItems[i];
        } else {
            if (calorieCount > mostCalories) {
                mostCalories = calorieCount;
            }
            calorieCount = 0;
        }
    }

    cout << "\nMost calories: " << mostCalories << endl;
    return 0;
}

string getInput() {
    std::ifstream inputFileStream{"input.txt"};
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
