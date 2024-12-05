#include<iostream>
#include "Player.h"
#include "Board.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void() displayCharacters(){
   cout<<"Press 1-5 to select your character"<<endl;
   cout<<"1 - Apollo|5|500|500|1000|20000"<<endl;
   cout<<2 - Mane|8|900|600|600|20000"<<endl;
   cout<<3 - Elsa|12|900|700|500|20000"<<endl;
   cout<<4 - Zuri|7|600|500|900|20000<<endl;
   cout<<5 - Roary|18|1000|500|500|20000<<endl;
}

int main(){

   

    fstream inFile("character.txt");
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string header;
    getline(inFile, header);

    int userInput;
    displayCharacters();
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
    for (int i = 0; i < 6; i++) {
        cout << stats[i] << " ";
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



   


    return 0;
}
