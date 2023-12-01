/*Project-------Advent_Of_Code
 *File----------Day3b.cpp
 *Author--------Justin Kachele
 *Date----------1/1/23
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

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

bool* getHashTable(const string& str, bool* table) {
    for (char c: str) {
        table[c] = true;
    }
    return table;
}

int solvePuzzle(const vector<string>& input) {
    int solution = 0;
    for (int i = 0; i < input.size(); i += 3) {
        char result;
        const string& sac1 = input[i];
        const string& sac2 = input[i + 1];
        const string& sac3 = input[i + 2];
        bool* hashSac2{new bool[128]{}};
        bool* hashSac3{new bool[128]{}};
        hashSac2 = getHashTable(sac2, hashSac2);
        hashSac3 = getHashTable(sac3, hashSac3);
        for(char c: sac1) {
            if (hashSac2[c] && hashSac3[c]) {
                result = c;
                break;
            }
        }
        solution += getPriority(result);
        delete[] hashSac2;
        delete[] hashSac3;
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
    clock_t t_CPU;
    t_CPU = clock();
    auto t_WallStart = std::chrono::high_resolution_clock::now();

    for (string &s: input) {
        cout << "{" << s << "}, ";
    }
    cout << endl;

    int solution = solvePuzzle(input);
    cout << solution << endl;
    t_CPU = clock() - t_CPU;
    cout << "CPU Time: " << (t_CPU * 1000000) / CLOCKS_PER_SEC << "ns" << endl;
    auto t_WallEnd= std::chrono::high_resolution_clock::now();
    cout << "Real Time: " <<
    std::chrono::duration<double, std::milli>(t_WallEnd-t_WallStart).count() * 1000 <<
    "ns" << endl;

    return 0;
}
