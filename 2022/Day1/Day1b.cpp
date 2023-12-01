/*Project-------Advent_Of_Code
 *File----------Day1b.cpp
 *Author--------Justin Kachele
 *Date----------12/1/22
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include <iostream>
#include <fstream>
using std::cout, std::endl, std::cerr, std::string;

string getInput();
int numLines;

void printIntArray(int* array, int num) {
    for (int i = 0; i < num; i++) {
        cout << "[" << array[i] << "], ";
    }
    cout << endl;
}

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

    printIntArray(foodItems, numLines);

    int numElves = 0;
    for (int i = 0; i < numLines; i++) {
        if (foodItems[i] == -1) {
            numElves++;
        }
    }

    int elvesCalories[numElves];
    int elfIndex = 0;
    int calorieCounter = 0;
    for (int i = 0; i < numLines; i++) {
        if (foodItems[i] != -1) {
            calorieCounter += foodItems[i];
        } else {
            elvesCalories[elfIndex] = calorieCounter;
            elfIndex++;
            calorieCounter = 0;
        }
    }

    printIntArray(elvesCalories, numElves);

    // Reverse Bubble Sort
    for (int i = 0; i < numElves - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < numElves - i - 1; j++) {
            if (elvesCalories[j] < elvesCalories[j + 1]) {
                std::swap(elvesCalories[j], elvesCalories[j+1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    printIntArray(elvesCalories, numElves);

    cout << elvesCalories[0] + elvesCalories[1] + elvesCalories[2] << endl;

    return 0;
}

string getInput() {
    std::ifstream inputFileStream{"../2022/Day1/input.txt"};
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