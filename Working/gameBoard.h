#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#define NUM_TILES 40
#define NUM_CUPS 4
#define NUM_PLAYERS 8

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "tile.h"
#include "owner.h"
#include "boardDisplay.h"
#include "rollUpRim.h"

class Tile;

class GameBoard{
    static GameBoard *instance = 0;
    Tile* tiles[NUM_TILES];
<<<<<<< HEAD
    vector<Player *> players;
    School* admin;
    BoardDisplay* theDisplay;
    Player * curPlayer
=======
    vector<Player *> players (NUM_PLAYERS);
    std::map<std::string, Player *> pNamesMap;
    Owner* admin;
    BoardDisplay* theDisplay;
    Player* curPlayer
>>>>>>> a3425ce69a8c5fd0ec0835d2e985127dbebaf9d2
    int numPlayers;
  
public:
    rollUpRim *cups[NUM_CUPS];
    GameBoard();
    static GameBoard getInstance();

    Player* getCurPlayer();
<<<<<<< HEAD
=======
    Player * getPlayer(std::string s);
>>>>>>> a3425ce69a8c5fd0ec0835d2e985127dbebaf9d2
    void setCurPlayer();

    BoardDisplay * getDisplay();

    void setTile(Tile *);
    Tile **getTiles();
    Tile* getTile(int t);

    int getRindex(int pos);
    int getCindex(int pos);

    void addPlayer(Player *);
    void deletePlayer(string name);

    static void cleanup();
};

#endif
