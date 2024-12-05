#include<iostream>
#include "Player.h"
#include "Board.h"

using namespace std;

int main(){
    fstream inFile("character.txt");
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string header;
    getline(inFile, header);

    int userInput;
    cout << "Enter the line number (1-5): ";
    cin >> userInput;

    if (userInput < 1 || userInput > 5) {
        cerr << "Invalid line number!" << endl;
        return 1;
    }

    string line;
    int currentLine = 0;
    vector<int> stats;

    while (getline(inFile, line)) {
        currentLine++;
        if (currentLine == userInput) {
            stringstream ss(line);
            string value;

            getline(ss, value, '|');
            while (getline(ss, value, '|')) {
                stats.push_back(stoi(value));
            }
            break;
        }
    }

    inFile.close();

    if (stats.empty()) {
        cout << "No stats found for the selected line!" << endl;
        return 1;
    }

    cout << "Stats for the selected line:" << endl;
    for (int stat : stats) {
        cout << stat << " ";
    }
    cout << endl;
}
