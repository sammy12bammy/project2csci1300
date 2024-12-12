//sam and sutchin

#include "Tile.h"
#include<string>
#ifndef BOARD_H
#define BOARD_H

using namespace std;

class Board  {
    private:
        static const int _BOARD_SIZE = 52;
        Tile _tiles[2][_BOARD_SIZE];
        static const int _MAX_PLAYERS = 2;
        int _player_count;
        int _player_position[_MAX_PLAYERS];
        void displayTile(int player_index, int pos);
        void initializeTiles(int player_index);
        //pride land
        void initializeTilesPride(int player_index);
        //cub
        void initializeTilesCub(int player_index);
        bool isPlayerOnTile(int player_index, int pos);
    public:
        Board();
        Board(int player_count);
        char getTileColor(int player_index, int pos);
        void displayTrack(int player_index);
        void initializeBoard(char p1, char p2);
        void displayBoard();
        bool movePlayer(int player_index);
        void movePlayer(int, int);
        int getPlayerPosition(int player_index) const;
};

#endif
