#include "dcTimsLine.h"

using namespace std;

dcTimsLine::dcTimsLine(std::string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay){
}

dcTimsLine::~dcTimsLine() {}

void dcTimsLine::action(Player* p){
	//p->setRollDoubleFailCount(0);  to be set in main.cc
	if (p->getLanded()) {this->visit(p);return;}
    int i;
	if (p->getRollDoubleFailCount() == 3) {
		cout << "Choose one of the following two options because you've failed too many roll doubles attempts:" << endl;
		cout << "1. Pay $50" << endl;
		cout << "2. Use Roll Up the Rim (if you have one)" << endl;
		cout << "Type 1 or 2: ";

		while (cin >> i) {
            cin.ignore();
			if (i == 1) {
				p->addBalance(-50);
				p->setLanded(true);
				p->setRollDoubleFailCount(0);
				return;
			} else if (i == 2) {
				for (int j=0; j<4; j++){
					if ((*(rollUpRim::getInstance()+j))->getOwner() == p) {
						(*(rollUpRim::getInstance()+j))->setOwner(NULL);
						p->setRollDoubleFailCount(0);
						p->setLanded(true);
						return;
					}
				}

				cout << "It seems you don't have any RollUpRims pass. Sorry you must pay." << endl;
				p->addBalance(-50);
				p->setLanded(true);
				p->setRollDoubleFailCount(0);
				return;
			} else {
				cout << "Please choose the correct option." << endl;
			}
		}
        cin.ignore();

	} 
    else if (p->getRollDoubleFailCount() == 0) {
        this->visit(p);
        cout << "Stay in DC Tims Line." << endl;
        p->setRollDoubleFailCount(1);
        return;
    }
    
    else {
		cout << "Choose one of the following three options:" << endl;
		cout << "1. Roll doubles" << endl;
		cout << "2. Pay $50" << endl;
		cout << "3. Use Roll Up the Rim (if you have one)" << endl;
		cout << "Type 1, 2 or 3: ";

		while (cin >> i){
            cin.ignore();
			if (i == 1) {
				bool success = p->isDouble();
				if (success) {
					p->setLanded(true);
					p->setRollDoubleFailCount(0);
					return;
				} else {
					p->setRollDoubleFailCount(p->getRollDoubleFailCount()+1);
					cout << "Sorry you have to say in the Tims line for the next round." << endl;
					p->setLanded(false);
					devisit(p);
					return; // player does not leave the line
				}
			} else if (i == 2) {
					p->addBalance(-50);
					p->setLanded(true);
					p->setRollDoubleFailCount(0);
					return;
			} else if (i == 3) {

				for (int j=0; j<4; j++){
					if ((*(rollUpRim::getInstance()+j))->getOwner() == p) {
						(*(rollUpRim::getInstance()+j))->setOwner(NULL);
						p->setRollDoubleFailCount(0);
						p->setLanded(true);
						return;
					}
				}
				cout << "It seems you don't have any RollUpRims. Please choose 1 or 2: ";
			} else {
				cout << "Please choose the correct option." << endl;
			}			
		}// while
	}
}


void dcTimsLine::setCost(){ return; }
void dcTimsLine::setOwner(Owner*){ return; }
void dcTimsLine::addNeighbour(Tile*){ return; }
