/*Project-------Advent_Of_Code
 *File----------Day4bNoHash.cpp
 *Author--------Justin Kachele
 *Date----------1/2/23
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
        char result = 0;
        const string& sac1 = input[i];
        const string& sac2 = input[i + 1];
        const string& sac3 = input[i + 2];
        for(char c1: sac1) {
            for(char c2: sac2) {
                for(char c3: sac3) {
                    if (c1 == c2 && c2 == c3 && c1 == c3) {
                        result = c1;
                        break;
                    }
                }
                if (result != 0) {
                    break;
                }
            }
            if (result != 0) {
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
