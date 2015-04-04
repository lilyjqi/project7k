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
#include "school.h"

class Tile;

class GameBoard{
    static GameBoard *instance;
    Tile* tiles[NUM_TILES];
    std::vector<Player*> players;
    std::map<std::string, Player*> pNamesMap;
    Owner* admin;
    BoardDisplay* theDisplay;
    Player* curPlayer;
    int numPlayers;
  
public:
    rollUpRim *cups[NUM_CUPS];
    GameBoard(School *admin, BoardDisplay *theDisplay, int numPlayers, rollUpRim *cups);
    static GameBoard getInstance(School *admin, BoardDiaply *display, int numPlayers, rollUpRim *cups);

    Player* getCurPlayer();
    Player* getPlayer(std::string);
    void setCurPlayer();

    BoardDisplay* getDisplay();

    void setTile(Tile*);
    Tile** getTiles();
    Tile* getTile(int t);
    Tile* getTile(std::string); // can only be used on Buildings

    int getRindex(int pos);
    int getCindex(int pos);

    void addPlayer(Player*);
    void deletePlayer(std::string);

    static void cleanup();
};

#endif
