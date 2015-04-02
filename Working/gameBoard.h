#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#define NUM_TILES 40
#define NUM_CUPS 4
#define NUM_PLAYERS 8

#include <iostream>
#include <string>
#include <fstream>
#include "tile.h"
#include "owner.h"
#include "boardDisplay.h"
#include "rollUpRim.h"

class Tile;

class GameBoard{
    GameBoard *instance = 0;
    Tile* tiles[NUM_TILES];
    Player* players[NUM_PLAYERS];
    Owner* admin;
    boardDisplay* display;
    Owner* curPlayer
    int numPlayers;
    rollUpRim cups[NUM_CUPS];
  public:
    GameBoard();
    GameBoard *getInstance();
    Owner* getCurPlayer();
    void setCurPlayer();
    Tile* getTile(int t);
    int getRindex(int pos);
    int getCindex(int pos);
    void addPlayer(string name, char c);
    void deletePlayer(string name);
    Tile* notifyTile(int t);
    ~GameBoard();
};

#endif