#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#define NUM_TILES 40
#define NUM_CUPS 4
#define NUM_PLAYERS 8

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "tile.h"
#include "owner.h"
#include "boardDisplay.h"
#include "rollUpRim.h"

class Tile;

class GameBoard{
    static GameBoard *instance = 0;
    Tile* tiles[NUM_TILES];
    vector<Player *> players (NUM_PLAYERS);
    Owner* admin;
   BoardDisplay* theDisplay;
    Owner* curPlayer
    int numPlayers;
  
public:
    rollUpRim *cups[NUM_CUPS];
    GameBoard();
    static GameBoard getInstance();

    Owner* getCurPlayer();
    void setCurPlayer();

    BoardDisplay * getDisplay();

    void setTile(Tile *);
    Tile **getTiles();
    Tile* getTile(int t);

    int getRindex(int pos);
    int getCindex(int pos);

    void addPlayer(string, char);
    void addPlayer(string, char, int);
    void deletePlayer(string name);

    static void cleanup();
};

#endif