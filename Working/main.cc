#include "gameBoard.h"
#include "boardDisplay.h"
#include "rollUpRim.h"

#include "owner.h"
#include "player.h"
#include "school.h"
//#include "normalStream.h"

#include "ownedTile.h"
#include "ownableTile.h"
#include "acadBuilding.h"
#include "residence.h"
#include "gym.h"

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

//#define START_MONEY 1500

using namespace std;

const string playerNames[8] = {"Goose", "GRT Bus", "Doughnut", "Professor", "Student", "Money", "Laptop", "Pink Tie"};
string playerChar = " GBDPS$LT "; // adding space at both end of the string to avoid error when taking substring

GameBoard *board = GameBoard::getInstance();
int ownableTileIndex[28]={1,3,5,6,8,9,11,12,13,14,15,16,18,19,21,23,24,25,26,27,28,29,31,32,34,35,37,39};

// mapping for building name and index
map<string, int> tileNameMap;
tileNameMap["AL"]=1;
tileNameMap["ML"]=3;
tileNameMap["MKV"]=5;
tileNameMap["ECH"]=6;
tileNameMap["PAS"]=8;
tileNameMap["HH"]=9;
tileNameMap["RCH"]=11;
tileNameMap["PAC"]=12;
tileNameMap["DWE"]=13;
tileNameMap["CPH"]=14;
tileNameMap["UWP"]=15;
tileNameMap["LHI"]=16;
tileNameMap["BMH"]=18;
tileNameMap["OPT"]=19;
tileNameMap["EV1"]=21;
tileNameMap["EV2"]=23;
tileNameMap["EV3"]=24;
tileNameMap["V1"]=25;
tileNameMap["PHYS"]=26;
tileNameMap["B1"]=27;
tileNameMap["CIF"]=28;
tileNameMap["B2"]=29;
tileNameMap["EIT"]=31;
tileNameMap["ESC"]=32;
tileNameMap["C2"]=34;
tileNameMap["REV"]=35;
tileNameMap["MC"]=37;
tileNameMap["DC"]=39;

// initialize player; return the number of player
int initPlayer(GameBoard* board) {
	map<string, int> checkNameDup;

	cout << "Please enter the number of players - choose a number from TWO to EIGHT."
	int numPlayer;
	while (true) {
		if (!(cin >> numPlayer)) {
			cin.clear();
			cin.ignore();
		} else if (numPlayer > 8 || numPlayer < 2) {
			cout << "Please enter the correct number of players [2-8]."
		} else { 
			cout << "There will be " << numPlayer << " players in this game. "
			break; 
		}
	}

	string name;
	char charPiece;
	Player* p;

	for (int i=0; i<numPlayer; i++){
		// getting name
		cout << "Enter a name for Player" << i << ": "
		cin >> ws;
		cin >> name;
		while (checkNameDup.count(name)>0) {
			cout << "The name is already taken. Please pick another: ";
			cin >> name;
		}
		checkNameDup[name]=i;

		// getting char
		while (true) {
			cout << "Please pick a char of the following to represent yourself:" << playerChar
			cin >> ws;
			cin >> charPiece;
			if (playerChar.find(charPiece) == -1) { cout << "Please pick the correct char." << endl;}
			else {
				playerChar = playerChar.substr(0,playerChar.find(charPiece)) + playerChar.substr(playerChar.find(charPiece)+1);
				break;
			}
		}

		srand(time(NULL));
   		int pos = rand()%40;
   		while (pos ==  30) { pos = rand()%40; } // make sure pos != 30
		p = new Player(name, charPiece, pos, board->getRindex(pos), board->getCindex(pos));
		board->addPlayer(p);
		p->setRollDoubleFailCount(0);
		cout << name << " with char " << charPiece << " is created" << endl;
	}

	return numPlayer;
}

int loadGame(ifstream &in, GameBoard* board){
	int numPlayer, money, index, cups;
	int timsCup = 0;
	int timsLine = 0;
	int timsTurn = 0;
	string name;
	char c;
	Player* p;

	in >> numPlayer;
	for(int i = 0; i < numPlayer; i++){
		in >> name;

		in >> c;
		in >> money;
		in >> cups;
		in >> index;
		totalCups += cups;

		if(index == 30 || index < 0 || index >= 40){
			cerr << "Invalid position for " << name << endl;
			return 0;
		}

		if (cups < 0 || cups > 4) { 
			cerr << "Invalid cups for " << name << endl; 
			return 0;
		} 

		if(index == 10){
			in >> timsLine;
			if(inDCTimsLine == 1){
				in >> timsTurn;
				if(timsTurn < 1 || timsTurn > 3){
					cerr << "Invalid number of turns in line for " << name << endl;
					return 0;
				}
			}
		}
		// if total cups greater than 4, terminate
		if (totalCups > 4) {
			cerr << "Invalid number of Cups for " << name << endl;
			return 0;
		}

		// load player to the gameboard
		p = new Player(name, c, index, board->getRindex(index), board->getCindex(index));
		p->setBalance(money);
		board->addPlayer(p);
		for (int j=0; j<cups; j++){
			rollUpRim::getInstance()+j)->owner == p;
		}
		p->setRollDoubleFailCount(timsTurn);
		cout << name << " with char " << charPiece << " is loaded" << endl;

		BoardDisplay::getInstance()->updatePos(board->getTile(index));
	}

		/****** loading Players to board finished; now loading Tiles ******/

	string tileName, owner;
	int improvements, tileIndex;
	while(in >> tileName){
		tileIndex = tileNameMap[tileName];
		if(tileIndex == 0){ // if key tileName does not exist in map, default value of int - zero - is returned
			cerr << "Invalid tile name: " << tileName << endl;
			return 0;
		}

		// get Tile and set Owner
		Building* ownedTile = board->getTile(tileIndex);
		in >> owner;
		if(owner == "BANK"){
			ownedTile->setOwner(School::getInstance());
		}else{
			p = board->getPlayer(owner);
			p->addBuilding(ownedTile);
			ownedTile->setOwner(p);
		}

		// set Improvements
		in >> improvements;
		if(improvements == -1){
			ownedTile->setMort(ownedTile->getCost());
		} else if (improvements < 0 || improvements > 5){
			cerr << "Invalid number of improvements for " << tileName << endl;
			return 0;
		} else {
			AcadBuilding *acadTile = dynamic_cast<AcadBuilding *>(ownedTile);
			if(acadTile){
				for(int j=0; j<improvements; j++){
					acadTile->improv();
				}
				BoardDisplay::getInstance()->updateImpro(acadTile);
			} else if(improvements != 0){
				cerr << "Invalid number of improvements for " << tileName << endl;
				return 0;
			}
		}
	}

	return numPlayer;
}

void saveGame(string file, GameBoard* board){
	ofstream oof;
	int numPlayer;
	numPlayer = board->players.size();
	// create file; overwrite if it already exists
	oof.open(file.c_str(), ios_base::trunc);
	oof << numPlayer << endl; // print number of players

	// prints player info
	for(int i = 0; i < numPlayer; i++){
		int timsCount = 0;
		Player* p = board->curPlayer;
		string name = p->getName();

		oof << name << " " << p->getChar() << " " << p->getWorth() << " ";
		for (int j=0; j<4; j++){ // get the number of RollUpRims owned by Player p
			if ((rollUpRim::getInstance()+j)->owner->getName() == name) { timsCount++; }
		}
		cout << timsCount << " ";
		int pos = p->getPosition();
		oof << pos;
		// additional information if player is in DC Tims Line
		if(pos == 10){
			//int timsLine = p->getTurnsInLine();
			if(p->getLanded()){ oof << " 0"; }
			else { oof << " 1 " << p->getRollDoubleFailCount(); }
		}
		oof << endl;
	}

	/********** Player info saved; now saving Tile info ***********/

	for(int i = 0; i < 28; i++){
		Building* ownedTile = board->getTile(ownableTileIndex[i]);
		oof<<ownedTile->getName()<<" "<<ownedTile->getOwner()->getName()<< " "; 

		// mortgage and improvements
		if(ownedTile->isMort()){ oof << "-1"; }
		else {
			AcadBuilding* acadTile = dynamic_cast<AcadBuilding*>(ownedTile);
			if(acadTile){ oof << acadTile->getCurLevel(); }
			else{ oof << "0"; }
		}
		oof << endl;
	}
}

int main(int argc, char* argv[]) {
	int numPlayer;
	// set up gameBoard
	GameBoard* board=GameBoard::getInstance(School::getInstance(), BoardDisplay::getInstance(), rollUpRim::getInstance());
	for(int i=0; i<4; i++){
		(rollUpRim::getInstance()+i)->setOwner(School::getInstance());
	}

	while (true){
		if (argv[1] == "-load") {
			string file = argv[2];
			ifstream ifs(file.c_str());
			if(ifs.good()){
				numPlayer = load(ifs);
				if(numPlayer == 0){
					cerr << "The save file has incorrect format. "
					cerr << "Please choose another file to start a new game. " << endl;
				} else { 
					bool loaded = true;
					break; 
				}
			}else{
				cerr << "There is no such saved game. " 
				cerr << "Please choose the correct file to start a new game." << endl;
			}
		}
	
		// else if (argv[1] = "-testing") {...;}
		else if (argc > 1) {
			cerr << "Invalid command. Starting a new game..."
		}
		else {
			cout << "The game is about to START." << endl;
			numPlayer = initPlayer(board);
		}
	}

	int dice;
	Player *p;
	int bankruptPlayer = 0;
	while (bankruptPlayer + 1 != numPlayer){
		while (true){
			board->setCurPlayer();
			*p = board->getCurPlayer();
			if (p->getBalance() != -1) { break; }
		}

		dice = p->rollDice();
		if (dice == -1) { p->goToIndex(10); }
		else { p->makeMove(dice); }
		if (p->getBalance() == -1){
			bankruptPlayer++;
			cout << p->getName() << " is bankrupt."
			board->deletePlayer(p->getChar());
		}
	}

	cout << p->getName() << " wins the game!" << endl;
	cout << "Game existing...." << endl;
	return 1;
}	