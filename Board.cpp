#include "Board.h"
using namespace std;
#include<iostream>

#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"  /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"


void Board::initializeBoard(char p1, char p2)
{
    if(p1 == 'y'){
        //initialize pride land code
        initializeTilesPride(0);
    } else{
        //initalize Cub training
        initializeTilesCub(0);
    }
    if(p2 == 'y'){
        initializeTilesPride(1);
    } else {
        initializeTilesCub(1);
    }
    // Seed random number generator in your main function once
    /*
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i);  // This ensures each lane has a unique tile distribution
    }
    */
}

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

/*
This randomly initizlazes a board with 30 grean tiles and a 20% chance of getting every other 
type of tile

*/
void Board::initializeTiles(int player_index)
{
    srand(time(0));
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } 
        else if (i == 0) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        } 
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count)) {
            temp.color = 'G';
            green_count++;
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            int color_choice = rand() % 5;
            switch (color_choice)
            {
                case 0:
                    temp.color = 'B'; // Blue
                    break;
                case 1:
                    temp.color = 'P'; // Pink
                    break;
                case 2:
                    temp.color = 'N'; // Brown
                    break;
                case 3:
                    temp.color = 'R'; // Red
                    break;
                case 4:
                    temp.color = 'U'; // Purple
                    break;
            }
        }

        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}
/*
Initalizes a board with prideland specifications

 */
void Board::initializeTilesPride(int player_index){
    srand(time(0));
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    //half of the board
    int half = _BOARD_SIZE / 2;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } 
        else if (i == 0) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        } 
        else if (green_count < 20 && (rand() % (total_tiles - i) < 20 - green_count)) {
            temp.color = 'G';
            green_count++;
        }
        else
        {
            //if before half
            if(i < half){
                //25 for graveyard, 25 for hyena, 20 for advisor, 5 percent for oasis, 25 for challeneg
                int color_choice = rand() % 100 + 1;
                if(color_choice < 25){
                    temp.color = 'N';
                } else if(color_choice < 50){
                    temp.color = 'R';
                } else if(color_choice < 70){
                    temp.color = 'P';
                } else if(color_choice < 75){
                    temp.color = 'B';
                } else{
                    temp.color = 'U';
                }
            } else {
                //15 for graveyard , 15 for hyena, 20 for advisor, 25 for oasis
                int color_choice = rand() % 100 + 1;
                if(color_choice < 15){
                    temp.color = 'N';
                } else if(color_choice < 30){
                    temp.color = 'R';
                } else if(color_choice < 50){
                    temp.color = 'P';
                } else if(color_choice < 75){
                    temp.color = 'B';
                } else{
                    temp.color = 'U';
                }
            }
        }

        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}
/*
Cub training

*/
void Board::initializeTilesCub(int player_index){
    srand(time(0));
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    //half of the board
    int half = _BOARD_SIZE / 2;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } 
        else if (i == 0) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        } 
        else if (green_count < 29 && (rand() % (total_tiles - i) < 29 - green_count)) {
            temp.color = 'G';
            green_count++;
        }
        else
        {
            /*
            These players are less likely to visit a negative tile throughout the game, because their advisors will
            help them avoid them. So they have a 20% chance for a graveyard and a 20% for a hyena tile at any
            point during the game.
            hese players already have an advisor and are less likely to seek one out, so there is a 15% chance for
            a tile to be an advisor tile.
            • These players are likely steered towards the easy path with an oasis at the beginning of their journey
            by their advisor. In the first half of the lane each special tile has a 25% chance of being an oasis. In
            the second half, they have a 15% chance of being an oasis.
            • These players are more likely to want to test themselves after their training. In the first half of the
            lane there is a 20% chance of finding a challenge tile. In the second half, there is a 30% chance.

            */
            if(i < half){
                
                int color_choice = rand() % 100 + 1;
                if(color_choice < 20){
                    temp.color = 'N';
                } else if(color_choice < 40){
                    temp.color = 'R';
                } else if(color_choice < 55){
                    temp.color = 'P';
                } else if(color_choice < 80){
                    temp.color = 'B';
                } else{
                    temp.color = 'U';
                }
            } else {
                //15 for graveyard , 15 for hyena, 20 for advisor, 25 for oasis
                double color_choice = rand() % 100 + 1;
                if(color_choice < 20){
                    temp.color = 'N';
                } else if(color_choice < 40){
                    temp.color = 'R';
                } else if(color_choice < 55){
                    temp.color = 'P';
                } else if(color_choice < 70){
                    temp.color = 'B';
                } else{
                    temp.color = 'U';
                }
            }
        }

        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}
Board::Board()
{
    _player_count = 1;

    // Initialize player position
    _player_position[0] = 0;

    // Initialize tiles
    initializeTiles(0);
}

Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }

    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }

    // Initialize tiles

    //initializeBoard();
}

bool Board::isPlayerOnTile(int player_index, int pos)
{
    if (_player_position[player_index] == pos)
    {
        return true;
    }
    return false;
}
char Board::getTileColor(int player_index, int pos){
    return _tiles[player_index][pos].color;
}

void Board::displayTile(int player_index, int pos)
{
    // string space = "                                       ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    if (_tiles[player_index][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[player_index][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[player_index][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[player_index][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[player_index][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[player_index][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[player_index][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[player_index][pos].color == 'Y')
    {
        color = GREY;
    }

     if (player == true)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_index, i);
    }
    cout << endl;
}

void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0) {
            cout << endl;  // Add an extra line between the two lanes
        }
    }
}
//overload for moving player
void Board::movePlayer(int player_index, int amount){
    _player_position[player_index] += amount;
}

bool Board::movePlayer(int player_index)
{
    // Increment player position
    _player_position[player_index]++;
    if (_player_position[player_index] == _BOARD_SIZE - 1)
    {
        // Player reached last tile
        return true;
    }
    return false;
}

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}
