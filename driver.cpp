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
    int ran = rand() % 6 + 1;
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

void displayAdvisors(){
    cout<<"1. Rafiki - Invisibility (the ability to become un-seen)"<<endl;
    cout<<"2. Nala - Night Vision (the ability to see clearly in darkness)"<<endl;
    cout<<"3. Sarabi - Energy Manipulation (the ability to shape and control the properties of energy)"<<endl;
    cout<<" 4. Zazu - Weather Control (the ability to influence and manipulate weather patterns)"<<endl;
    cout<<"5. Sarafina - Super Speed (the ability to run 4x faster than the maximum speed of lions)"<<endl;  
}

//returns the number of spots that the move will move
/*
!!!!!!!!!!!
This code breaks if the input is a string or a char

*/
int mainMenu(Player player, Board board){
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
            int userInput;
            cout<<"Pride points: "<<player.getPridePoints()<<endl;
            cout<<"Your spot in the leaderpoint"<<endl;
            break;
            cout<<"Would you like to send a message to your opponent? Press 1 for yes or 2 for no"<<endl;
            if(userInput == 1){
                string message;
                cin >> message;
                cout<<"Message from player:"<<player.getName()<<message<<endl;
            }

        case 2:
            cout<<player.getName()<<" name: "<<player.getName()<<endl;
            cout<<player.getName()<<" age: "<<player.getAge()<<endl;
            break;
        case 3:
            board.displayBoard();
            break;
        case 4:
            int userInput;
            if(player.getAdvisor() == 0){
                cout<<"You do not currently have an advisor"<<endl;
            }else if(player.getAdvisor() == 1){
                cout<<"Your current advisor is Rafiki "<<endl;
            }else if(player.getAdvisor() == 1){
                cout<<"Your current advisor is Nala"<<endl;
            }else if(player.getAdvisor() == 1){
                cout<<"Your current advisor is Sarabi"<<endl;
            }else if(player.getAdvisor() == 1){
                cout<<"Your current advisor is Zazu"<<endl;
            }else if(player.getAdvisor() == 1){
                cout<<"Your current advisor is Sarafina"<<endl;
            }
            cout<<"Press 1 to change advisor, or press 2 to keep your current advisor"<<endl;
            cin >> userInput;

            if(userInput == 2){
                cout<<"Please select an advisor"<<endl;

                cout<<"Enter a number 1-5"<<endl;
                displayAdvisors();

                cin >> userInput;

                player.setAdvisor(userInput);

            }

            break;
        case 5:
            int num = spinner();
            cout<<"You moved up "<<num<<" spots"<<endl;
            return num;
            break;
    }
    return 0;
}
//makes changes to player if they choose cubTraining
//prompts user to choice adivor
void cubTraining(Player p){
    int userInput;
    p.trainCub(500,500,1000);
    cout<<p.getName()<<", you have gotten more stamina, strength, and wisdom, but your pride points have decreased"<<endl;
    cout<<"Please select an advisor"<<endl;

    cout<<"Enter a number 1-5"<<endl;
    displayAdvisors();

    cin >> userInput;

    p.setAdvisor(userInput);
    
}


//if the user chooses to get to pridelands
void prideLand(Player p){
    p.toPrideLands();
    cout<<p.getName()<<", you have increased your pridepoints and stamina, strength, and wisdom"<<endl;
    cout<<"You do not get a advisor but can choose one if you land on the advisor tile"<<endl;
}

//for when the game if finished, array sort here
void displayEndGame(){

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
            prideLand(p1);
            break;
        } else if(p1choice == 'c'){
            cubTraining(p1);
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
            prideLand(p2);
            break;
        } else if(p2choice == 'c'){
            cubTraining(p2);
            break;
        } else {
            cout<<"Invalid choice option"<<endl;
        }
    }
    //initalize board
    Board board(2);
    board.initializeBoard(p1choice, p2choice);
    /*
    stat check

    cout<<"Player 1"<<endl;
    p1.printStats();
    cout<<endl;
    cout<<"Player 2"<<endl;
    p2.printStats();
    */
    board.displayBoard();


    bool game = true;
    //keeps track of whos going
    bool p1Going = true;

    //check if one player is done

    /*
    The game work we just need to figure out how to impliment the spinner
    Also we need to make sure that the second player can still continue
    playing if the first player reached the end
    */

    while(game){
        //if both players have reached the end
        if(board.getPlayerPosition(1) == 52 && board.getPlayerPosition(2) == 52){
            game = false;
            displayEndGame();
        }
        if(p1Going){
            //flips characters   
            p1Going = !p1Going;
            //let user know who is goig
            cout<<"Player 1 is going"<<endl;
            //prompt menu and move user
            int move = mainMenu(p1);
            p1.addPlayerMoves(move);
            //change this make it is move to however much they spun
            board.movePlayer(0);

            //check tile
            //if tile is green - 20% of random event
            //if tile is blue extra turn, 200 stamina, strength, and wisdom
            //if pink Stamina, Strength, and Wisdom Points increase by 300, choose adivosor (or switch)
            //if red tile - move back 10 tiles and lose 100 Stamina, Strength, and Wisdom Points.
            //if brown color returns the player to their previous position, Stamina Points decrease by 300 Points.
            //if purple , choice random riddle - if right then 500 wisom

            char curTile = board.getTileColor(0, p1.getPlayerPos());
            switch(curTile){
                case 'G':
                    int ran = rand() % 6 + 1;
                    if(ran == 1){
                        int ran2 = rand() % 6 + 1;
                        if(ran2 == 1){
                            cout<<"A desert storm sweeps through the territory"<<endl;

                            if(p1.getAdvisor() == 4){
                                cout<<"Your advisor helps you safely bypass the storm"<<endl;
                            }else{
                                cout<<"You lose 500 pride points"<<endl;
                                p1.addPridePoints(-500);
                            }
                        }
                        if(ran2 == 2 and p1choice == 'c'){
                            cout<<"You are fatigued from intense training with pride warriors"<<endl;
                            
                            if(p1.getAdvisor() == 3){
                                cout<<"Your advisor nurses you back to health"<<endl;
                            }else{
                                cout<<"You lose 200 pride points"<<endl;
                                p1.addPridePoints(-200);
                            }
                            
                        }
                        if(ran2 == 3 and p1choice = 'y'){
                            cout<<"You endure challenging night watch duty under pitch-black conditions"<<endl;

                            if(p1.getAdvisor() == 2){
                                cout<<"Your advisor guides you until the morning"<<endl;
                            }else{
                                cout<<"You lose 4000 pride points"<<endl;
                                p1.addPridePoints(-400);
                            }
                        }
                        if(ran2 == 4 and p1choice = 'y'){

                            cout<<"You gain extra energy from bountiful season"<<endl;
                            cout<<"You gain 800 pride points"<<endl;

                            p1.addPridePoints(800);
                        }
                        if(ran2 == 5 and p1choice = 'c'){
                            cout<<"You observe a rare natural phenomenon"<<endl;
                            cout<<"You gain 600 pride points"<<endl;

                            p1.addPridePoints(600);

                        }
                        if(ran2 == 6 and p1choice = 'y'){

                            cout<<"You gained wisdom from observing Rafiki’s rituals"<<endl;
                            cout<<"You gain 500 pride points"<<endl;
                        }
                    }
                    break;
                case 'B':
                    cout<<"You landed on a oasis tile. Your stats have been updated"<<endl;
                    p1.addStamina(200);
                    p1.addStrength(200);
                    p1.addWisdom(200);
                    break;
                case 'P':

                    break;
                case 'R':
                    //change player pos in player class -10
                    //update board
                    //loss stats
                    cout<<": Uh-oh, you’ve stumbled into the Graveyard!"<<endl;
                    board.movePlayer(0,-10);
                    p1.addPlayerMoves(-10);
                    p1.addStamina(-100);
                    p1.addStrength(-100);
                    p1.addWisdom(-100);
                    break;
                case 'N':

                    break;
                case 'U':

                    break;
                case 'O':
                    //end game
                    break;
                default:
            }

        } else {
            p1Going = !p1Going;
            cout<<"Player 2 is going"<<endl;
            int move = mainMenu(p2);
            board.movePlayer(1);
        }
        board.displayBoard();
    }

    return 0;
}
