#include<iostream>
#include "Player.h"
#include "Board.h"
#include <fstream>
#include <sstream>
#include <vector>
//for spinner function
#include <thread> 
#include <chrono>
//random num
#include <cstdlib>

using namespace std;

/*
THis generates a random number between 1 and 6 with a slight delay
*/
int spinner(){
    cout<<"Picking random number between 1-6"<<endl;
    //sleeps for 3 seconds
    for(int i = 0; i < 6; ++i){
        cout<<".";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout<<endl;
    int ran = rand() % 6;
    cout<<"The random number is "<<ran<<endl;
    return ran;

}
//menu for display character options
void displayCharacters(){
   cout<<"Press 1-5 to select your character"<<endl;
   cout<<"1 - Apollo|5|500|500|1000|20000"<<endl;
   cout<<"2 - Mane|8|900|600|600|20000"<<endl;
   cout<<"3 - Elsa|12|900|700|500|20000"<<endl;
   cout<<"4 - Zuri|7|600|500|900|20000"<<endl;
   cout<<"5 - Roary|18|1000|500|500|20000"<<endl;
}

//displays the menu
void displayMenu(){
    cout<<"Main menu"<<endl;
    cout<<"1. Check Player Progress"<<endl;
    cout<<"2. Review Character"<<endl;
    cout<<"3. Check Position"<<endl;
    cout<<"4. Review your Advisor"<<endl;
    cout<<"5. Move Forward"<<endl;
}

//returns the number of spots that the move will move
int mainMenu(Player player){
    displayMenu();
    int choice;
    cout<<"Enter choice: "<<endl;
    cin>>choice;
    while(choice < 1 || choice > 5){
        cout<<"Invalid Choice"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>choice;
    }
    switch(choice){
        case 1:
            cout<<"Pride points: "<<player.getPridePoints()<<endl;
            cout<<"Your spot in the leaderpoint"<<endl;
            break;
        case 2:
            cout<<player.getName()<<" name: "<<player.getName()<<endl;
            cout<<player.getName()<<" age: "<<player.getAge()<<endl;
            break;
        case 3:
            //??
            break;
        case 4:
            //?? 
            break;
        case 5:
            int num = spinner();
            cout<<"You moved up "<<num<<" spots"<<endl;
            return num;
            break;
    }
    return 0;
}

int main(){
    //check if txt file opened properlly
    fstream inFile("character.txt");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }


    //player 1
    string header;
    getline(inFile, header);

    int userInput;
    cout<<"Welcome Player 1, please select your character"<<endl;
    displayCharacters();
    cout << "Enter the line number (1-5): ";
    cin >> userInput;
    while(userInput < 1 || userInput > 5){
        cout<<"Invalid Input"<<endl;
        cout<<"Please select character for player 2"<<endl;
        cin>>userInput;
    }

    string line;
    int currentLine = 0;
    vector<string> stats;

    while(getline(inFile, line)) {
        currentLine++;
        if (currentLine == userInput) {
            stringstream ss(line);
            string value;

            while (getline(ss, value, '|')) {
                stats.push_back(value);
            }
            break;
        }
    }

    //make a player class for p1
    cout << endl;
    Player p1(stats[0],stoi(stats[2]),stoi(stats[3]),stoi(stats[4]));
    p1.setPridePoints(stoi(stats[5]));
    p1.setAge(stoi(stats[1]));
    
    //player 2 character choice
    cout<<"Welcome player 2, please select your character"<<endl;
    displayCharacters();
    cin>>userInput;
    while(userInput < 1 || userInput > 5){
        cout<<"Invalid Input"<<endl;
        cout<<"Please select character for player 2"<<endl;
        cin>>userInput;
    }
    
    currentLine = 0;
    vector<string> stats2;

    while(getline(inFile, line)) {
        currentLine++;
        if (currentLine == userInput) {
            stringstream ss(line);
            string value;

            while (getline(ss, value, '|')) {
                stats2.push_back(value);
            }
            break;
        }
    }
    //make player class for p2
    Player p2(stats2[0],stoi(stats2[2]),stoi(stats2[3]),stoi(stats2[4]));
    p2.setPridePoints(stoi(stats2[5]));
    p2.setAge(stoi(stats2[1]));
    //close file input
    inFile.close();

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
    cout<<"Player 1"<<endl;
    p1.printStats();
    cout<<endl;
    cout<<"Player 2"<<endl;
    p2.printStats();

    mainMenu(p1);

    return 0;
}
