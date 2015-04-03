#include "boardDisplay.h"
#include "gameBoard.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

BoardDisplay::BoardDisplay(): {
    display = new string *[56];
    for (int i=0; i<56; ++i) {
        display[i] = new string[11];

        // first line
        if (i == 0) {
            for (int j=0; j<11; ++j) {
                display[i][j]="__________";
            }
        }//if

        if (i == 1) {
            display[i][0]="|Goose   |";
            display[i][1]="|        |";
            display[i][2]="|NEEDLES |";
            display[i][3]="|        |";
            display[i][4]="|        |";
            display[i][5]="|V1      |";
            display[i][6]="|        |";
            display[i][7]="|        |";
            display[i][8]="|CIF     |";
            display[i][9]="|        |";
            display[i][10]="|GO TO   |";
        }

        if (i == 2) {
            display[i][0]="|Nesting |";
            display[i][1]="|--------|";
            display[i][2]="|HALL    |";
            display[i][3]="|--------|";
            display[i][4]="|--------|";
            display[i][5]="|        |";
            display[i][6]="|--------|";
            display[i][7]="|--------|";
            display[i][8]="|        |";
            display[i][9]="|--------|";
            display[i][10]="|TIMS    |";
        }

        if (i == 3) {
            display[i][0]="|        |";
            display[i][1]="|EV1     |";
            display[i][2]="|        |";
            display[i][3]="|EV2     |";
            display[i][4]="|EV3     |";
            display[i][5]="|        |";
            display[i][6]="|PHYS    |";
            display[i][7]="|B1      |";
            display[i][8]="|        |";
            display[i][9]="|B2      |";
            display[i][10]="|        |";
        }

        if (i == 4) {
            for (int j=0; j<11; ++j) {
                display[i][j]="|        |";
            }
        }

        if (i == 5) {
            for (int j=0; j<11; ++j) {
                display[i][j]="|________|";
            }
        }

        if (i ==6 || i==9 || i == 11 || i == 14 || i == 17 ||i == 18 || i == 19 ||
            i == 21 || i == 24 || i == 27 || i == 28 || i == 29 || i == 34 ||
            i == 36 || i == 39 || i == 43 || i == 44 || i == 46 || i == 49) {
            for (int j =0; j<11; ++j) {
                if (j == 0 || j == 10) {
                    display[i][j] = "|        |";
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 7 || i == 10 || i == 12 || i == 15 || i == 20 || i == 22 ||
            i == 25 || i == 30 || i == 35 || i == 37 || i == 40 || i == 45 ||
            i == 47 ) {
            for (int j =0; j<11; ++j) {
                if (j == 0 || j == 10) {
                    display[i][j] = "|--------|";
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 8) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|OPT     |";
                }
                else if (j == 10) {
                    display[i][j] = "|EIT     |"
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 13) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|BMH     |";
                }
                else if (j == 10) {
                    display[i][j] = "|ESC     |"
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 16) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|SLC     |";
                }
                else if (j == 10) {
                    display[i][j] = "|SLC     |"
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 23) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|LHI     |";
                }
                else if (j == 10) {
                    display[i][j] = "|C2      |"
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 26) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|UWP     |";
                }
                else if (j == 10) {
                    display[i][j] = "|REV     |"
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 31) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|        |";
                }
                else if (j == 10) {
                    display[i][j] = "|NEEDLES |"
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 32) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|--------|";
                }
                else if (j == 10) {
                    display[i][j] = "|HALLS   |"
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 33) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|CPH     |";
                }
                else if (j == 10) {
                    display[i][j] = "|        |"
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 38) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|DWE     |";
                }
                else if (j == 10) {
                    display[i][j] = "|MC      |"
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 41) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|PAC     |";
                }
                else if (j == 10) {
                    display[i][j] = "|COOP    |"
                }
                else {
                    display[i][j] = "          ";
                }
            }

        if (i == 42) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|        |";
                }
                else if (j == 10) {
                    display[i][j] = "|FEE     |"
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 48) {
            for (int j =0; j<11; ++j) {
                if (j == 0) {
                    display[i][j] = "|RCH     |";
                }
                else if (j == 10) {
                    display[i][j] = "|DC      |"
                }
                else {
                    display[i][j] = "          ";
                }
            }
        }

        if (i == 50) {
            for (int j =0; j<11; ++j) {
                if (j == 0 || J == 10) {
                    display[i][j] = "|________|";
                }
                else {
                    display[i][j] = "__________";
                }
            }
        }

        if (i == 51) {
            display[i][0]="|DC Tims |";
            display[i][1]="|        |";
            display[i][2]="|        |";
            display[i][3]="|NEEDLES |";
            display[i][4]="|        |";
            display[i][5]="|MKV     |";
            display[i][6]="|TUITION |";
            display[i][7]="|        |";
            display[i][8]="|SLC     |";
            display[i][9]="|        |";
            display[i][10]="|COLLECT |";
        }

        if (i == 52) {
            display[i][0]="|Line    |";
            display[i][1]="|--------|";
            display[i][2]="|--------|";
            display[i][3]="|HALL    |";
            display[i][4]="|--------|";
            display[i][5]="|        |";
            display[i][6]="|        |";
            display[i][7]="|--------|";
            display[i][8]="|        |";
            display[i][9]="|--------|";
            display[i][10]="|OSAP    |";
        }

        if (i == 53) {
            display[i][0]="|        |";
            display[i][1]="|HH      |";
            display[i][2]="|PAS     |";
            display[i][3]="|        |";
            display[i][4]="|ECH     |";
            display[i][5]="|        |";
            display[i][6]="|        |";
            display[i][7]="|ML      |";
            display[i][8]="|        |";
            display[i][9]="|AL      |";
            display[i][10]="|        |";
        }

        if (i == 54) {
            for (int j=0; j<11; ++j) {
                display[i][j]="|        |";
            }
        }

        if (i == 55) {
            for (int j=0; j<11; ++j) {
                display[i][j]="|________|";
            }
        }
    }
}

BoardDisplay::getInstance() {
    if (instance == NULL) {
        instance = new BoardDisplay();
        atexit(cleanup);
    }
    return instance;
}

void BoardDisplay::cleanup() {
    delete instance;
}

static string drawString(int i) {
    if (i == 0) {return "        ";}
    else if (i == 1) {return "       ";}
    else if (i == 2) {return "      ";}
    else if (i == 3) {return "     ";}
    else if (i == 4) {return "    ";}
    else if (i == 5) {return "   ";}
    else if (i == 6) {return "  ";}
    else if (i == 7) {return " ";}
}

void updateImpro(Tile *t) {
    int r = t->getRindex();
    int c = t->getCindex();

    int cl = t->getCurLevel();
    string lvl = "";
    if (cl == 1) {lvl = "*";}
    else if (cl == 2) {lvl = "**";}
    else if (cl == 3) {lvl = "***";}
    else if (cl == 4) {lvl = "****";}
    else if (cl == 5) {lvl = "*****";}

    display[i][j] = "|" + lvl + drawString(lvl.length()) + "|";
}

void updatePos(Tile *t) {
    int r = t->getRindex();
    int c = t->getCindex();

    vector<Player *> visitors = t->getVisitors();
    string p = "";
    for (int i =0; i<visitors.size(); ++i) {
        p += visitors[i]->getChar();
    }
    display[r+3][c] = "|" + p + drawString(p.length()) + "|";
}

ostream & opearator<<(ostream& out, const boardDisplay& d) {
    for (int i = 0; i<56; ++i) {
        for (int j=0; j<11; ++j) {
            out << d[i][j];
        }
        out << endl;
    }
    return out;
}
