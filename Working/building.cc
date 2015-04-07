#include "building.h"
#include "school.h"
#include "player.h"
#include <sstream>

using namespace std;

Building::Building(string name, int position, int rindex, int cindex, int numNeighbours, BoardDisplay *theDisplay):
    Tile(name, position, rindex, cindex, theDisplay),
    neighbours(NULL),cost(0),mort(0),numNeighbours(numNeighbours),
    owner(School::getInstance()) {}

Building::~Building() {
    delete [] neighbours;
}

void Building::action(Player *) {return;}

void Building::setOwner(Owner * o) {
    owner = o;
}

void Building::setMort(int b) {
    mort = b;
}

bool Building::isMort() {
    if (mort == 0) { return false;}
    else {return true;}
}

int Building::getMort() {
    return mort;
}

Owner * Building::getOwner() const{ return owner; }

void Building::auction(GameBoard *gb) {
    vector<Player *> players = gb->getPlayers();
    int p = players.size();
    for (int j=0; j<p; ++j) {
        if (players[j]->getBalance() == -1) {
            players.erase(players.begin() + j);
        }   
    }
    p = players.size();
    int bid = 1;
    int amount;
    string cmd;
    cout << "Bidding for Building " << this->getName() << endl;
    while (p > 1) {
        for (int i=0; i< p; ++i) {
            Player *cur = players[i];
            cout << "Player " << cur->getName() << ", please bid." << endl;
            cout << "Lowest bid is " << bid << endl;
            cout << "Please enter <raise $> or <withdraw>." << endl;
            getline(cin, cmd);
            if (cmd == "withdraw") {
                players.erase(players.begin()+i);
                p--;
                i--;
                if (p == 1) {break;}
            }
            else {
                istringstream iss(cmd);
                iss >> cmd;
                iss >> amount;
                if (amount <= bid) {
                    cout << "Invalid Bid! Please bid again" << endl;
                    --i;
                }
                else {
                    bid = amount;
                }
            }
        }
    }
    if (players[0]->getBalance() < bid) {
        players[0]->noMoney();
        if (cin.eof()) {return;}
        if (players[0]->getBalance() == -1) {return;}
    }
    else {
        // if building is on mortgage
        if (this->isMort()) {
            int principle = this->getMort();
            players[0]->addBalance(-0.1*principle);

            cout << "Player " << players[0]->getName() << " , do you want to unmortgage " << this->getName() << " now? (y/n)" << endl;
            string decision = "";
            while (cin >> decision) {
                if (cin.eof()) {return;}
                if (decision == "y") {
                    players[0]->addBalance(-principle);
                    this->setMort(0);
                    break;
                 }
                else if (decision == "n") {
                    this->setMort(principle*1.1);
                    break;
                }
                else {
                    cout << "Please enter <y> or <n>." << endl;
                }
            }
            cin.ignore();
        }
        this->setOwner(players[0]);
        players[0]->addBalance(-bid);
        players[0]->addBuilding(this);
        cout << "Player " << players[0]->getName() << " won the bid!" << endl;
    }
}
