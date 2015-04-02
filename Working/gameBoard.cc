#include "gameBoard.h"

using namespace std;

GameBoard::GameBoard(Owner *admin, BoardDiaply *display, int numPlayers, rollUpRim *cups): 
     admin(admin), display(display),numPlayer(numPlayer),cups(cups) 
{
    for (int i=0; i<40; i++) {
        if (i == 2) {tils[i] = new AcadBuilding("AL", 2, 51，82, "Arts1");}
        else if (i == 3) {tiles[i] = ;}
        else if (i == 4) {tiles[i] = new AcadBuilding("ML", 4, 51, 64, "Arts1");}
        else if (i == 5) {tiles[i] = ;}
        else if (i == 6) {tiles[i] = new Residence("MKV", 6, 51, 46);}
        else if (i == 7) {tiles[i] = new AcadBuilding("ECH", 7, 51, 37, "Arts2");}
        else if (i == 8) {tiles[i] = ;}
        else if (i == 9) {tiles[i] = new AcadBuilding("PAS", 9, 51, 19, "Arts2");}
        else if (i == 10) {tiles[i] = new AcadBuilding("HH", 10, 51, 10, "Arts2");}
        else if (i == 11) {tiles[i] = ;}
        else if (i == 12) {tiles[i] = new AcadBuilding("RCH", 12, 46, 1, "Eng");}
        else if (i == 13) {tiles[i] = new Gym("PAC", 13, 41, 1);}
        else if (i == 14) {tiles[i] = new AcadBuilding("DWE", 14, 36, 1, "Eng");}
        else if (i == 15) {tiles[i] = new Acadbuilding("CPH", 15, 31, 1, "Eng");}
        else if (i == 16) {tiles[i] = new Residence("UWP", 16, 26, 1);}
        else if (i == 17) {tiles[i] = new Acadbuilding("LHI", 17, 21, 1, "Health");}
        else if (i == 18) {tiles[i] = ;}
        else if (i == 19) {tiles[i] = new AcadBuilding("BMH", 19, 11, 1, "Health");}
        else if (i == 20) {tiles[i] = new Acadbuilding("OPT", 20, 6, 1, "Health");}
        else if (i == 21) {tiles[i] = ;}
        else if (i == 22) {tiles[i] = new AcadBuilding("EV1", 22, 1, 10, "Env");}
        else if (i == 23) {tiles[i] = ;}
        else if (i == 24) {tiles[i] = new AcadBuilding("EV2", 24, 1, 28, "Env");}
        else if (i == 25) {tiles[i] = new AcadBuilding("EV3", 25, 1, 37, "Env");}
        else if (i == 26) {tiles[i] = new Residence("V1", 26, 1, 46);}
        else if (i == 27) {tiles[i] = new AcadBuilding("PHYS", 27, 1, 55, "Sci1");}
        else if (i == 28) {tiles[i] = new AcadBuilding("B1", 28, 1, 64, "Sci1");}
        else if (i == 29) {tiles[i] = new Gym("CIF", 29, 1, 73);}
        else if (i == 30) {tiles[i] = new AcadBuilding("B2", 30, 1, 82, "Sci1");}
        else if (i == 31) {tiles[i] = ;}
        else if (i == 32) {tiles[i] = new AcadBuilding("EIT", 32, 6, 91, "Sci2");}
        else if (i == 33) {tiles[i] = new AcadBuilding("ESC", 33, 11, 91, "Sci2");}
        else if (i == 34) {tiles[i] = ;}
        else if (i == 35) {tiles[i] = new AcadBuilding ("C2", 35, 21, 91, "Sci2");}
        else if (i == 36) {tiles[i] = Residence("REV", 36, 26, 91);}
        else if (i == 37) {tiles[i] = ;}
        else if (i == 38) {tiles[i] = new AcadBuilding("MC", 38, 36, 91, "Math");}
        else if (i == 39) {tiles[i] = ;}
        else if (i == 40) {tiles[i] = new AcadBuilding("DC", 40, 46, 91, "Math");}
        else if (i == 1) {tiles[i] = ;}
    }
    for (int i=0; i<40; i++) {
        if (i == 2) {tiles[i]->addNeighbour(tiles[4]);}        
        else if (i == 4) {tiles[i]->addNeighbour(tiles[2]);}
        else if (i == 6) {tiles[i]->addNeighbour(tiles[16]);
                          tiles[i]->addNeighbour(tiles[26]);
                          tiles[i]->addNeighbour(tiles[36]);}
        else if (i == 7) {tiles[i]->addNeighbour(tiles[9]);
                          tiles[i]->addNeighbour(tiles[10]);}        
        else if (i == 9) {tiles[i]->addNeighbour(tiles[7]);
                          tiles[i]->addNeighbour(tiles[10]);}         
        else if (i == 10) {tiles[i]->addNeighbour(tiles[7]);
                           tiles[i]->addNeighbour(tiles[9]);}          
        else if (i == 12) {tiles[i]->addNeighbour(tiles[14]);
                           tiles[i]->addNeighbour(tiles[15]);}     
        else if (i == 13) {tiles[i]->addNeighbour(tiles[29]);}
        else if (i == 14) {tiles[i]->addNeighbour(tiles[12]);
                           tiles[i]->addNeighbour(tiles[15]);}           
        else if (i == 15) {tiles[i]->addNeighbour(tiles[12]);
                           tiles[i]->addNeighbour(tiles[14]);}           
        else if (i == 16) {tiles[i]->addNeighbour(tiles[6]);
                           tiles[i]->addNeighbour(tiles[26]);
                           tiles[i]->addNeighbour(tiles[36]);}
        else if (i == 17) {tiles[i]->addNeighbour(tiles[19]);
                           tiles[i]->addNeighbour(tiles[20]);}          
        else if (i == 18) {tiles[i]->addNeighbour(tiles[17]);
                           tiles[i]->addNeighbour(tiles[20]);}           
        else if (i == 20) {tiles[i]->addNeighbour(tiles[17]);
                           tiles[i]->addNeighbour(tiles[19]);}           
        else if (i == 22) {tiles[i]->addNeighbour(tiles[24]);
                           tiles[i]->addNeighbour(tiles[25]);}           
        else if (i == 24) {tiles[i]->addNeighbour(tiles[22]);
                           tiles[i]->addNeighbour(tiles[25]);}           
        else if (i == 25) {tiles[i]->addNeighbour(tiles[22]);
                           tiles[i]->addNeighbour(tiles[24]);}          
        else if (i == 26) {tiles[i]->addNeighbour(tiles[6]);
                           tiles[i]->addNeighbour(tiles[16]);
                           tiles[i]->addNeighbour(tiles[36]);}
        else if (i == 27) {tiles[i]->addNeighbour(tiles[28]);
                           tiles[i]->addNeighbour(tiles[30]);}           
        else if (i == 28) {tiles[i]->addNeighbour(tiles[27]);
                           tiles[i]->addNeighbour(tiles[30]);}           
        else if (i == 29) {tiles[i]->addNeighbour(tiles[13]);}
        else if (i == 30) {tiles[i]->addNeighbour(tiles[27]);
                           tiles[i]->addNeighbour(tiles[28]);}          
        else if (i == 32) {tiles[i]->addNeighbour(tiles[33]);
                           tiles[i]->addNeighbour(tiles[35]);}           
        else if (i == 33) {tiles[i]->addNeighbour(tiles[32]);
                           tiles[i]->addNeighbour(tiles[35]);}            
        else if (i == 35) {tiles[i]->addNeighbour(tiles[32]);
                           tiles[i]->addNeighbour(tiles[33]);}               
        else if (i == 36) {tiles[i]->addNeighbour(tiles[6]);
                           tiles[i]->addNeighbour(tiles[16]);
                           tiles[i]->addNeighbour(tiles[26]);}
        else if (i == 38) {tiles[i]->addNeighbour(tiles[40]);}
        else if (i == 40) {tiles[i]->addNeighbour(tiles[38]);}
    }
    curPlayer = players[0];
    cups = rollUpRim::getInstance();
}

GameBoard * GameBoard::getInstance(Owner *admin, BoardDiaply *display, int numPlayers, rollUpRim *cups) {
    if (!instance) {
        instance = new GameBoard(Owner *admin, BoardDiaply *display, int numPlayers, rollUpRim *cups);
        atexist(cleanup);
    }
    return instance;
}

Owner * GameBoard::getCurPlayer() {
    return curPlayer;
}

void GameBoard::setCurPlayer() {
    curPlayer = *(&curPlayer + 1);
}

Tile *GameBoard::getTile(int t) {
    return tiles[t];
}

int GameBoard::getRindex(int pos) {
    return tiles[pos]->getRindex();
}

int GameBoard::getCindex(int pos) {
    return tiles[pos]->getCindex();
}

void GameBoard::addPlayer(string name, char c) {
    for (int i=0; i<8; i++) {
        if (players[i] == NULL) {
            srand(time(NULL));
            int p = rand()%40+1;
            int r = getRindex(p);
            int c = getCindex(p);
            players[i] = new Player(name, c, pos, r, c);
            numPlayers ++;
            break;
        }
    }
}

void GameBoard::deletePlayer(string name) {
    for (int i=0; i<8; i++) {
        if (player[i]->getName() == name) {
            if (i == 7) {
                delete player[i];
                break;
            }
            else {
                Player *temp = player[i];
                player[i] = player[i+1];
                delete player[i];
                break;
            }
        }
    }
}
