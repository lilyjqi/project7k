#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

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
    Tile** tiles;
    std::vector<Player*> players;
    std::map<std::string, Player*> pNamesMap;
    Owner* admin;
    BoardDisplay* theDisplay;
    Player* curPlayer;
    int numPlayers;
  
public:
    rollUpRim **cups;
    GameBoard(School *admin, BoardDisplay *theDisplay, rollUpRim **cups);
    static GameBoard* getInstance(School *admin, BoardDisplay *display, rollUpRim *cups);

    Player* getCurPlayer();
    Player* getPlayer(std::string);
    void setCurPlayer();

    BoardDisplay* getDisplay();

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
