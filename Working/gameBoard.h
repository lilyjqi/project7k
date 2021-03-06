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
    BoardDisplay* theDisplay;
    Player* curPlayer;
    bool testingDice;
    int numPlayers;
  
public:
    rollUpRim **cups;
    GameBoard(BoardDisplay *theDisplay, rollUpRim **cups);
    static GameBoard* getInstance(BoardDisplay *display, rollUpRim **cups);
    ~GameBoard();

    Player* getCurPlayer();
    Player* getPlayer(std::string);
    std::vector<Player *> getPlayers();
    void setCurPlayer();
    int getNumPlayer() const;

    BoardDisplay* getDisplay();

    Tile** getTiles();
    Tile* getTile(int t);
    Tile* getTile(std::string); // can only be used on Buildings

    int getRindex(int );
    int getCindex(int );

    void addPlayer(Player*);
    void deletePlayer(char);

    void setTesting(bool);
    bool getTesting();

    static void cleanup();
};

#endif
