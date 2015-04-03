#include "gameBoard.h"

using namespace std;

GameBoard::GameBoard(School *admin, BoardDiaply *theDisplay, int numPlayers, rollUpRim *cups): 
     admin(admin), theDisplay(theDisplay),curPlayer(NULL),numPlayer(numPlayer),cups(cups) 
{
    for (int i=0; i<40; i++) {
        if (i == 1) {tils[i] = new AcadBuilding("AL", 1, 51，9, "Arts1");
                     tils[i]->setCost();}
        else if (i == 2) {tiles[i] = ;}
        else if (i == 3) {tiles[i] = new AcadBuilding("ML", 3, 51, 7, "Arts1");
                          tils[i]->setCost();}
        else if (i == 4) {tiles[i] = ;}
        else if (i == 5) {tiles[i] = new Residence("MKV", 5, 51, 5); 
                          tils[i]->setCost();}
        else if (i == 6) {tiles[i] = new AcadBuilding("ECH", 6, 51, 4, "Arts2");
                          tils[i]->setCost();}
        else if (i == 7) {tiles[i] = ;}
        else if (i == 8) {tiles[i] = new AcadBuilding("PAS", 8, 51, 2, "Arts2");
                          tils[i]->setCost();}
        else if (i == 9) {tiles[i] = new AcadBuilding("HH", 9, 51, 1, "Arts2");
                          tils[i]->setCost();}
        else if (i == 10) {tiles[i] = ;}
        else if (i == 11) {tiles[i] = new AcadBuilding("RCH", 11, 46, 0, "Eng");
                           tils[i]->setCost();}
        else if (i == 12) {tiles[i] = new Gym("PAC", 12, 41, 0);
                           tils[i]->setCost();}
        else if (i == 13) {tiles[i] = new AcadBuilding("DWE", 13, 36, 0, "Eng");
                           tils[i]->setCost();}
        else if (i == 14) {tiles[i] = new Acadbuilding("CPH", 14, 31, 0, "Eng");
                           tils[i]->setCost();}
        else if (i == 15) {tiles[i] = new Residence("UWP", 15, 26, 0);
                           tils[i]->setCost();}
        else if (i == 16) {tiles[i] = new Acadbuilding("LHI", 16, 21, 0, "Health");
                           tils[i]->setCost();}
        else if (i == 17) {tiles[i] = ;}
        else if (i == 18) {tiles[i] = new AcadBuilding("BMH", 18, 11, 0, "Health");
                           tils[i]->setCost();}
        else if (i == 19) {tiles[i] = new Acadbuilding("OPT", 19, 6, 0, "Health");
                           tils[i]->setCost();}
        else if (i == 20) {tiles[i] = ;}
        else if (i == 21) {tiles[i] = new AcadBuilding("EV1", 21, 1, 1, "Env");
                           tils[i]->setCost();}
        else if (i == 22) {tiles[i] = ;}
        else if (i == 23) {tiles[i] = new AcadBuilding("EV2", 23, 1, 3, "Env");
                           tils[i]->setCost();}
        else if (i == 24) {tiles[i] = new AcadBuilding("EV3", 24, 1, 4, "Env");
                           tils[i]->setCost();}
        else if (i == 25) {tiles[i] = new Residence("V1", 25, 1, 5);
                           tils[i]->setCost();}
        else if (i == 26) {tiles[i] = new AcadBuilding("PHYS", 26, 1, 6, "Sci1");
                           tils[i]->setCost();}
        else if (i == 27) {tiles[i] = new AcadBuilding("B1", 27, 1, 7, "Sci1");
                           tils[i]->setCost();}
        else if (i == 28) {tiles[i] = new Gym("CIF", 28, 1, 8);
                           tils[i]->setCost();}
        else if (i == 29) {tiles[i] = new AcadBuilding("B2", 29, 1, 9, "Sci1");
                           tils[i]->setCost();}
        else if (i == 30) {tiles[i] = ;}
        else if (i == 31) {tiles[i] = new AcadBuilding("EIT", 31, 6, 10, "Sci2");
                           tils[i]->setCost();}
        else if (i == 32) {tiles[i] = new AcadBuilding("ESC", 32, 11, 10, "Sci2");
                           tils[i]->setCost();}
        else if (i == 33) {tiles[i] = ;}
        else if (i == 34) {tiles[i] = new AcadBuilding ("C2", 34, 21, 10, "Sci2");
                           tils[i]->setCost();}
        else if (i == 35) {tiles[i] = Residence("REV", 35, 26, 10);
                           tils[i]->setCost();}
        else if (i == 36) {tiles[i] = ;}
        else if (i == 37) {tiles[i] = new AcadBuilding("MC", 37, 36, 10, "Math");
                           tils[i]->setCost();}
        else if (i == 38) {tiles[i] = ;}
        else if (i == 39) {tiles[i] = new AcadBuilding("DC", 39, 46, 10, "Math");
                           tils[i]->setCost();}
        else if (i == 0) {tiles[i] = ;}
    }
    for (int i=0; i<40; i++) {
        if (i == 1) {tiles[i]->addNeighbour(tiles[3]);}        
        else if (i == 3) {tiles[i]->addNeighbour(tiles[1]);}
        else if (i == 5) {tiles[i]->addNeighbour(tiles[15]);
                          tiles[i]->addNeighbour(tiles[25]);
                          tiles[i]->addNeighbour(tiles[35]);}
        else if (i == 6) {tiles[i]->addNeighbour(tiles[8]);
                          tiles[i]->addNeighbour(tiles[9]);}        
        else if (i == 8) {tiles[i]->addNeighbour(tiles[6]);
                          tiles[i]->addNeighbour(tiles[9]);}         
        else if (i == 9) {tiles[i]->addNeighbour(tiles[6]);
                          tiles[i]->addNeighbour(tiles[8]);}          
        else if (i == 11) {tiles[i]->addNeighbour(tiles[13]);
                           tiles[i]->addNeighbour(tiles[14]);}     
        else if (i == 12) {tiles[i]->addNeighbour(tiles[28]);}
        else if (i == 13) {tiles[i]->addNeighbour(tiles[11]);
                           tiles[i]->addNeighbour(tiles[14]);}           
        else if (i == 14) {tiles[i]->addNeighbour(tiles[11]);
                           tiles[i]->addNeighbour(tiles[13]);}           
        else if (i == 15) {tiles[i]->addNeighbour(tiles[5]);
                           tiles[i]->addNeighbour(tiles[25]);
                           tiles[i]->addNeighbour(tiles[35]);}
        else if (i == 16) {tiles[i]->addNeighbour(tiles[18]);
                           tiles[i]->addNeighbour(tiles[19]);}          
        else if (i == 17) {tiles[i]->addNeighbour(tiles[16]);
                           tiles[i]->addNeighbour(tiles[19]);}           
        else if (i == 19) {tiles[i]->addNeighbour(tiles[16]);
                           tiles[i]->addNeighbour(tiles[18]);}           
        else if (i == 21) {tiles[i]->addNeighbour(tiles[23]);
                           tiles[i]->addNeighbour(tiles[24]);}           
        else if (i == 23) {tiles[i]->addNeighbour(tiles[21]);
                           tiles[i]->addNeighbour(tiles[24]);}           
        else if (i == 24) {tiles[i]->addNeighbour(tiles[21]);
                           tiles[i]->addNeighbour(tiles[23]);}          
        else if (i == 25) {tiles[i]->addNeighbour(tiles[5]);
                           tiles[i]->addNeighbour(tiles[15]);
                           tiles[i]->addNeighbour(tiles[35]);}
        else if (i == 26) {tiles[i]->addNeighbour(tiles[27]);
                           tiles[i]->addNeighbour(tiles[29]);}           
        else if (i == 27) {tiles[i]->addNeighbour(tiles[26]);
                           tiles[i]->addNeighbour(tiles[29]);}           
        else if (i == 28) {tiles[i]->addNeighbour(tiles[12]);}
        else if (i == 29) {tiles[i]->addNeighbour(tiles[26]);
                           tiles[i]->addNeighbour(tiles[27]);}          
        else if (i == 31) {tiles[i]->addNeighbour(tiles[32]);
                           tiles[i]->addNeighbour(tiles[34]);}           
        else if (i == 32) {tiles[i]->addNeighbour(tiles[31]);
                           tiles[i]->addNeighbour(tiles[34]);}            
        else if (i == 34) {tiles[i]->addNeighbour(tiles[31]);
                           tiles[i]->addNeighbour(tiles[32]);}               
        else if (i == 35) {tiles[i]->addNeighbour(tiles[5]);
                           tiles[i]->addNeighbour(tiles[15]);
                           tiles[i]->addNeighbour(tiles[25]);}
        else if (i == 37) {tiles[i]->addNeighbour(tiles[39]);}
        else if (i == 39) {tiles[i]->addNeighbour(tiles[37]);}
    }
}

static GameBoard * GameBoard::getInstance(School *admin, BoardDiaply *display, int numPlayers, rollUpRim *cups) {
    if (!instance) {
        instance = new GameBoard(Owner *admin, BoardDiaply *display, int numPlayers, rollUpRim *cups);
        atexist(cleanup);
    }
    return instance;
}

Player * GameBoard::getCurPlayer() {
    cout << “Current Player is ” << curPlayer->getName() << endl;
    return curPlayer;
}

void GameBoard::setCurPlayer() {
    if (curPlayer == NULL) {
        curPlayer = players[0];
    }
    else if (curPlayer == players[numPlayer-1]) {
        curPlayer = players[0];
    }
    else {
        curPlayer = *(&curPlayer + 1);
    }
}

BoardDisplay * GameBoard::getDisplay() {
    return theDisplay();
}

void GameBoard::setTile(Tile *t) {
    int p = t->getPos();
    tils[p] = t;
    theDisplay->updateImpro(t);
}

Tile ** GameBoard::getTiles() {
   return tiles;
}

Tile *GameBoard::getTile(int t) {
    return tiles[t];
}

int GameBoard::getRindex(int pos) {
    return tiles[pos]->getRow();
}

int GameBoard::getCindex(int pos) {
    return tiles[pos]->getCol();
}

void GameBoard::addPlayer(Player *p) {
    players.push_back(p);
    numPlayer++;
}

Player * GameBoard::getPlayer(string s){
     if(pNamesMap.count(s)){ return pNamesMap[s]; }
	else{ return NULL; }
}

void GameBoard::deletePlayer(char c) {
    for (int i=0; i<players.size(); ++i) {
        if (players.at(i)->getChar() == c) {
            players.erase(players.begin()+i); 
            cout << “Player ” << players.at(i)->getName() << “ is deleted.“ << endl;
            break;
        }
    }
}

GameBoard::~GameBoard() {
    delete tiles;
    player.clear();
}

static void GameBoard::cleanup() {
    delete instance;
}
