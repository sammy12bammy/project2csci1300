#include<iostream>
#include "Player.h"
#include "Board.h"

using namespace std;

int main(){
    Player p = Player();
    p.printStats();

    Player sam = Player("Sam", 1000, 1000, 1000);
    sam.printStats();

    Player sutchin = Player("Sutchin", 1000, 1000, 1000);
    sutchin.printStats();

    Board board;
    //board 1 takes you to pridelands and board 2 takes you to cub training
    board.initializeBoard('y','n');
    board.displayBoard();
    return 0;
}