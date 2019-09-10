
#include "ConnectFourPlusUndo.h"

namespace CellSpace {

    ConnectFourPlusUndo::ConnectFourPlusUndo() {
        //no parameter constructor
    }

    ConnectFourPlusUndo::~ConnectFourPlusUndo() {
        //destructor
    }
    //check commands for undo , save and load

    bool ConnectFourPlusUndo::checkCommand(string tempCommand) {
        string fileName;
        if (tempCommand == "LOAD" || tempCommand=="load") {
            getline(cin, fileName);
            readFromFile(fileName.c_str());
            return true;
        } else if (tempCommand == "SAVE" || tempCommand=="save") {
            getline(cin, fileName);
            writeToFile(fileName.c_str());
            return true;
        } else if (tempCommand == "UNDO" || tempCommand=="undo") {

            if (moves.size() != 0) {
                board[moves.at(moves.size() - 1)][moves.at(moves.size() - 2)].setCellType('.');
                moves.pop_back();
                moves.pop_back();
                if (getGameType() == 'P') {
                    if (getPlayerRank() == 1)
                        setPlayerRank(2); //for user2
                    else
                        setPlayerRank(1);
                } else if (getGameType() == 'C') {
                    if (getPlayerRank() == 1)
                        setPlayerRank(3); //for computer
                    else
                        setPlayerRank(1);
                }

            } else {
                cout << "Game board is empty" << endl;
            }
            return true;
        }
    }
    //play for computer

    int ConnectFourPlusUndo::play() {
        if (getPlayerRank() == 3) {
            setPlayerRank(1);
            for (int row = getRowSize() - 1; row >= 0; --row) {
                for (int col = 0; col < getColSize(); ++col) {
                    if (board[row][col].getCellType() == '.') {
                        board[row][col].setCellType('O');
                        moves.push_back(col); //hamlenin columnu kaydettik
                        moves.push_back(row); //hamlenin rowunu kaydettik
                        return 1;
                    } else if (row - 3 > 0 &&
                            board[row][col].getCellType() == 'X' &&
                            board[row - 1][col].getCellType() == 'X' &&
                            board[row - 2][col].getCellType() == 'X' &&
                            board[row - 3][col].getCellType() == '.') {
                        board[row - 3][col].setCellType('O');
                        moves.push_back(col); //hamlenin columnu kaydettik
                        moves.push_back(row - 3); //hamlenin rowunu kaydettik
                        return 1;
                    } else if (col - 3 > 0 &&
                            board[row][col].getCellType() == 'X' &&
                            board[row][col - 1].getCellType() == 'X' &&
                            board[row][col - 2].getCellType() == 'X' &&
                            board[row][col - 3].getCellType() == '.') {
                        board[row][col - 3].setCellType('O');
                        moves.push_back(col - 3); //hamlenin columnu kaydettik
                        moves.push_back(row); //hamlenin rowunu kaydettik
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    //play for users (user 1 and user 2)

    void ConnectFourPlusUndo::play(int colVal) {
        if ((colVal < getColSize()) && colVal >= 0) {
            int rowVal = getRowSize() - 1;
            if (getPlayerRank() == 1) {//user1
                bool check = false;
                for (int row = getRowSize() - 1; row >= 0; --row) {
                    if (board[row][colVal].getCellType() == '.' && check == false && getPlayerRank() != 3) {
                        board[row][colVal].setCellType('X');

                        moves.push_back(colVal); //hamlenin columnu kaydettik
                        moves.push_back(row); //hamlenin rowunu kaydettik
                        if (getGameType() == 'P')
                            setPlayerRank(2); //for user2
                        else if (getGameType() == 'C') {
                            setPlayerRank(3); //for computer
                        }
                        check = true;
                    } else if (board[row][colVal].getCellType() != '.' && board[row][colVal].getCellType() != ' ') {
                        setPlayerRank(1);
                    }
                }
            } else if (getPlayerRank() == 2) {//user2 
                bool check = false;
                for (int row = getRowSize() - 1; row >= 0; --row) {
                    if (board[row][colVal].getCellType() == '.' && check == false) {
                        board[row][colVal].setCellType('O');

                        moves.push_back(colVal); //hamlenin columnu kaydettik
                        moves.push_back(row); //hamlenin rowunu kaydettik
                        setPlayerRank(1);
                        check = true;
                    } else if (board[row][colVal].getCellType() != '.' && board[row][colVal].getCellType() != ' ') {

                        setPlayerRank(2);
                    }
                }
            }

        } else
            cout << "move is illegal" << endl;
    }
    //read game function from file

    void ConnectFourPlusUndo::readFromFile(string fileName) {//reader function

        ifstream myfile, file;
        char gameTypeVal;
        int movesString;
        int rowSizeVal, colSizeVal, typeOfUserVal;
        myfile.open(fileName.c_str());
        if (myfile.fail()) {
            cerr << "Do not find file..." << endl;
            exit(1);
        }
        myfile>>rowSizeVal;
        myfile>>colSizeVal;
        myfile>>typeOfUserVal;
        myfile>>gameTypeVal;
        myfile>>movesString;
        while (movesString != -1) {

            moves.push_back(movesString);
            myfile>>movesString;
        }
        clearBoard();
        setRowSize(rowSizeVal);
        setColSize(colSizeVal);
        setPlayerRank(typeOfUserVal);
        setGameType(gameTypeVal);
        resizeBoard();
        string tmpStr;
        cout << "Read from file >>" << fileName << endl;
        getline(myfile, tmpStr);
        for (int i = 0; i < getRowSize(); ++i) {
            getline(myfile, tmpStr);
            for (int j = 0; j < getColSize(); ++j) {
                board[i][j].setCellType(tmpStr[j]);
            }

        }
        myfile.close();
    }
    //write game function to file

    void ConnectFourPlusUndo::writeToFile(string fileName) {//writer function 
        ofstream myfile;
        //buraya file name gelecek
        myfile.open(fileName.c_str());
        myfile << getRowSize() << endl;
        myfile << getColSize() << endl;
        //player rank sıra kimdeyse onu gösterecek
        myfile << getPlayerRank() << endl;
        //gameType
        myfile << getGameType() << endl;
        for (int i = 0; i < moves.size(); ++i)//hamleler
            myfile << moves.at(i) << endl;
        myfile << -1 << endl;

        for (int i = 0; i < getRowSize(); i++) {
            for (int j = 0; j < getColSize(); j++) {
                myfile << (board[i][j].getCellType());
            }
            myfile << endl;
        }
        myfile.close();
        cout << "Game is saved >> " << fileName << endl;

    }

}