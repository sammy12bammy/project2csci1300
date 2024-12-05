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

    //player 1 choice for board type
    char p1choice;
    cout<<"Player 1 would you like to go to the prideland or cub training?"<<endl;
    while(true){
        cout<<"Enter [y] for prideland or [c] for cub training"<<endl;
        cin>>p1choice;
        if(p1choice == 'y'){
            break;
        } else if(p1choice == 'c'){
            break;
        } else {
            cout<<"Invalid choice option"<<endl;
        }
    }
    //player 2 choice for board type
    char p2choice;
    cout<<"Player 2 would you like to go to the prideland or cub training?"<<endl;
    while(true){
        cout<<"Enter [y] for prideland or [c] for cub training"<<endl;
        cin>>p2choice;
        if(p2choice == 'y'){
            break;
        } else if(p2choice == 'c'){
            break;
        } else {
            cout<<"Invalid choice option"<<endl;
        }
    }
    //initalize board
    Board board(2);
    board.initializeBoard(p1choice, p2choice);
}
