#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#define NUM_TILES 40
#define NUM_CUPS 4

#include <iostream>
#include <string>
#include <fstream>
#include "tile.h"
#include "owner.h"
#include "boardDisplay.h"
#include "rollUpRim.h"

class Tile;

class GameBoard{
    Tile* tiles[NUM_TILES];
    Owner* players;
    Owner* admin;
    boardDisplay* display;
    Owner* curPlayer
    int numPlayers;
    rollUpRim cups[NUM_CUPS];
  public:
    rollUpRim cups[NUM_CUPS]; // private field with a getter a better option?
    GameBoard();
    Owner* getCurPlayer();
    void setCurPlayer();
    void addOwner(char o);
    void deleteOwner(int n);
    Tile* getTile(int t);
    Tile* notifyTile(int t);
    int tileToPos(std::string s);

    ~GameBoard();
};

#endif