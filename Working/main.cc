#include "gameBoard.h"
#include "boardDisplay.h"
#include "rollUpRim.h"

#include "owner.h"
#include "player.h"
#include "school.h"

#include "building.h"
#include "acadBuilding.h"
#include "residence.h"
#include "gym.h"

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

const string playerNames[8] = {"Goose", "GRT Bus", "Doughnut", "Professor", "Student", "Money", "Laptop", "Pink Tie"};
string playerChar = " GBDPS$LT "; // adding space at both end of the string to avoid error when taking substring
const int ownableTileIndex[28]={1,3,5,6,8,9,11,12,13,14,15,16,18,19,21,23,24,25,26,27,28,29,31,32,34,35,37,39};

// initialize player; return the number of player
int initPlayer(GameBoard* board) {
	map<string, int> checkNameDup;

    cout << "Please enter the number of players - choose a number from TWO to EIGHT: "; 
	int numPlayer;
	while (true) {
		if (!(cin >> numPlayer)) {
            if (cin.eof()) {return 0;}
			cin.clear();
			cin.ignore();
		} else if (numPlayer > 8 || numPlayer < 2) {
			cout << "Please enter the correct number of players [2-8].";
		} else { 
			cout << "There will be " << numPlayer << " players in this game. " << endl;
			break; 
		}
	}

	string name;
	char charPiece;
	Player* p;

	for (int i=0; i<numPlayer; i++){
		// getting name
		cout << "Enter a name for Player" << i << ": ";
		cin >> ws;
        if (cin.eof()) {return 0;}
		cin >> name;
        if (cin.eof()) {return 0;}
		while (checkNameDup.count(name)>0) {
			cout << "The name is already taken. Please pick another: ";
			cin >> name;
            if (cin.eof()) {return 0;}
		}
		checkNameDup[name]=i;

		// getting char
		while (true) {
			cout << "Please pick a char of the following to represent yourself -" << playerChar <<":";
			cin >> ws;
            if (cin.eof()) {return 0;}
			cin >> charPiece;
            if (cin.eof()) {return 0;}
			if (playerChar.find(charPiece) == -1) { cout << "Please pick the correct char." << endl;}
			else {
				playerChar = playerChar.substr(0,playerChar.find(charPiece)) + playerChar.substr(playerChar.find(charPiece)+1);
				break;
			}
		}

		p = new Player(name, charPiece, 0, board->getRindex(0), board->getCindex(0));
        Tile *t = board->getTile(p->getPos());
        t->visit(p);
        p->notifyDisplay(t);
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
    if (cin.eof()) {return 0;}
	for(int i = 0; i < numPlayer; i++){
		in >> name;
        if (cin.eof()) {return 0;}
		in >> c;
        if (cin.eof()) {return 0;}
		in >> cups;
        if (cin.eof()) {return 0;}
		in >> money;
        if (cin.eof()) {return 0;}
		in >> index;
        if (cin.eof()) {return 0;}
		timsCup += cups;

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
			if(timsLine == 1){
				in >> timsTurn;
				if(timsTurn < 0 || timsTurn > 2){
					cerr << "Invalid number of turns in line for " << name << endl;
					return 0;
				}
			}
		}
		// if total cups greater than 4, terminate
		if (timsCup > 4) {
			cerr << "Invalid number of Cups for " << name << endl;
			return 0;
		}

		// load player to the gameboard
		p = new Player(name, c, index, board->getRindex(index), board->getCindex(index));
        p->addBalance(money - p->getBalance());
		board->addPlayer(p);
        
        for (int i = timsCup-cups; i<4 ; ++i) {
            rollUpRim::getInstance()[i]->setOwner(p);
        }

		p->setRollDoubleFailCount(timsTurn);
		cout << name << " with char " << c << " is loaded" << endl;
        
        board->getTile(p->getPos())->visit(p);
	}

/****** loading Players to board finished; now loading Tiles ******/

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

	string tileName, owner;
	int improvements, tileIndex;

	while(in >> tileName){
		tileIndex = tileNameMap[tileName];
		if(tileIndex == 0){ // if key tileName does not exist in map, default value of int - zero - is returned
			cerr << "Invalid tile name: " << tileName << endl;
			return 0;
		}

		// get Tile and set Owner
		Tile* dcastTile = board->getTile(tileIndex);
		Building *ownedTile = dynamic_cast<Building *>(dcastTile);
		if (!ownedTile) {
			cerr << "Cast failed..." << endl;
			return 0;
		}
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
			ownedTile->setMort(ownedTile->getCost()/2);
		} else if (improvements < 0 || improvements > 5){
			cerr << "Invalid number of improvements for " << tileName << endl;
			return 0;
		} else {
			AcadBuilding *acadTile = dynamic_cast<AcadBuilding *>(ownedTile);
			if(acadTile){
				for(int j=0; j<improvements; j++){
					acadTile->improv();
					int pay = acadTile->getPay();
					pay = 0;
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
	numPlayer = board->getNumPlayer();
	// create file; overwrite if it already exists
	oof.open(file.c_str(), ios_base::trunc);
	oof << numPlayer << endl; // print number of players

	// prints player info
	for(int i = 0; i < numPlayer; i++){
		int timsCount = 0;
		Player* p = board->getCurPlayer();
		string name = p->getName();

		oof << name << " " << p->getChar() << " ";
		for (int j=0; j<4; j++){ // get the number of RollUpRims owned by Player p
			if ( (rollUpRim::getInstance())[j]->getOwner()->getName() == name ) { timsCount++; }
		}
		oof << timsCount << " ";
        oof << p->getBalance() << " ";
		int pos = p->getPos();
		oof << pos;
		// additional information if player is in DC Tims Line
		if(pos == 10){
			if(p->getLanded()){ oof << " 0"; }
			else { oof << " 1 " << p->getRollDoubleFailCount(); }
		}
		oof << endl;
        board->setCurPlayer();
	}
    
	/********** Player info saved; now saving Tile info ***********/

	for(int i = 0; i < 28; i++){
		Tile* dcastTile = board->getTile(ownableTileIndex[i]);
		Building *ownedTile = dynamic_cast<Building *>(dcastTile);
		if (!ownedTile) {
			cerr << "Cast failed..." << endl;
			return;
		}
		//Building* ownedTile = board->getTile(ownableTileIndex[i]);
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
    cout << "Game saved succesfully!" << endl;
}

int main(int argc, char* argv[]) {
	int numPlayer;
	string cmd;
	// set up gameBoard
    BoardDisplay *display = BoardDisplay::getInstance();
    rollUpRim **cups = rollUpRim::getInstance();

    GameBoard* board=GameBoard::getInstance(display,cups);

	for(int i=0; i<4; i++){
		(*(rollUpRim::getInstance()+i))->setOwner(School::getInstance());
	}

	//if (argc > 1) { cmd = argv[1]; }

	//cout << "Init finished"<< endl;
	//while (true){
		bool loaded =false;
        int argCount=1;
        while (argCount < argc){
            cmd = argv[argCount];
    		if (cmd == "-load") {
	    		string file = argv[argCount+1];
		    	ifstream ifs(file.c_str());
		    	if(ifs.good()){
			    	numPlayer = loadGame(ifs, board);
                    if (cin.eof()) {cin.clear(); cin.ignore(); return 0;}
                    else if(numPlayer == 0){
					    cerr << "The save file has incorrect format. ";
					    cerr << "Please choose another file to start a new game. " << endl;
                        return 0;
				    } else { 
					    loaded = true;
					    cout << "Game is loaded. "<< endl;
                        argCount += 2;
					//break; 
				    }
			    }else{
				    cerr << "There is no such saved game. " ;
				    cerr << "Please choose the correct file to start a new game." << endl;
                    return 0;
			    }
		    }
		    else if (cmd == "-testing") { 
                board->setTesting(true); 
                argCount++;
                cout << "Testing dice loaded" << endl;} 		
		    else {
			    cerr << "Invalid command. Please starting a new game...";
                return 0;
		    }
        }
		if (!loaded){
			cout << "The game is about to START." << endl;
			numPlayer = initPlayer(board);
            if (cin.eof()) {cin.clear(); cin.ignore(); return 0;}
            cin.ignore();
			//break;
		}
	//}

	cmd = "";
	string options;
	int dice;
    board->setCurPlayer();
	Player *p = board->getCurPlayer(); 

	while (board->getNumPlayer() != 1){
        p = board->getCurPlayer();
        cout << (*(board->getDisplay()));
		cout << p->getName() << "'s turn begins" << endl;
        if (p->getLanded() == false) {
            cout << "You are in DC Tims Line." << endl;
            (board->getTile(10))->action(p);
        }
        int numRolls = 0;
        cout << "Command?" << endl;

        while (getline(cin, options)) {
			istringstream iss(options);
			iss >> cmd;
			if (cmd == "trade") { p->makeTrade(options); cout << "End of Trade" << endl;}
			else if (cmd == "improve") { p->makeImprove(options); }
			else if (cmd == "mortgage") { p->makeMortgage(options); }
			else if (cmd == "unmortgage") {p->unMortgage(options); }
			else if (cmd == "asset") { p->asset(); }
			else if (cmd == "save") { 
				string file;
				iss >> file;
				saveGame(file, board); 
			}
            else if (cmd == "next") {
                if (p->getLanded() == true) {
                    cout << "You must roll!" << endl;
                }
                else {
				    cout << p->getName() <<"'s turn is over." << endl;
                    break;
                }
            }
			else if (cmd == "roll") {
                if (p->getLanded() == false) {
                    cout << "You are in DC Tims Line. Can't roll." << endl;
                    cout << "Please use next!" << endl;
                }
                
                else if (board->getTesting() == true && options.length() > 4) {
                    int die1, die2;
                    iss >> die1 >> die2;
                    if (die1 == die2) {dice = -1;}
                    else {dice = die1 + die2;}
				    if (dice == -1 && numRolls < 2) {
                        cout << "You rolled doubles! roll again!" << endl;
                        numRolls++;
                    }
                    else if (dice == -1 && numRolls == 2) {
                        cout << "You have been sent to DC Tims Line." << endl; 
                        p->goToIndex(10); 
				        cout << p->getName() <<"'s turn is over." << endl;
                        break;
                    }
				    else {
					    p->makeMove(dice); 
                        if (cin.eof()) {return 0;}
				        cout << p->getName() <<"'s turn is over." << endl;
                        break;
				    }
                }
                else {
                    dice = p->rollDice();
				    if (dice == -1 && numRolls < 2) {
                        numRolls++;
                    }
                    else if (dice == -1 && numRolls == 2) {
                        cout << "You have been sent to DC Tims Line." << endl; 
                        p->goToIndex(10); 
				        cout << p->getName() <<"'s turn is over." << endl;
                        break;
                    }
				    else {
					    p->makeMove(dice); 
                        if (cin.eof()) {return 0;}
				        cout << p->getName() <<"'s turn is over." << endl;
                        break;
				    }

                }
			}
			else {
				cerr << "Please enter a valid command. " << endl;
			}
			//else if (cmd == "next") { break; }
		}// while
        
        if (cin.eof()) {cin.clear(); cin.ignore();return 0;}

        board->setCurPlayer();

		if (p->getBalance() == -1){
			cout << "DUANG DUANG! " << p->getName()  << " " << p->getChar() << " declares bankruptcy. " << endl;
			board->deletePlayer(p->getChar());
		}
	}
    
	cout << board->getCurPlayer()->getName() << " wins the game!" << endl;
	board->deletePlayer(board->getCurPlayer()->getChar());
	cout << "Game existing...." << endl;
	//GameBoard::cleanup();
	return 1;
}	
