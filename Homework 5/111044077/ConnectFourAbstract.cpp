/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectFour.cpp
 * Author: mesut bunaldı 111044077

        HW04

 * 
 * Created on October 15, 2017, 8:16 PM
 */




#include "ConnectFourAbstract.h"

namespace CellSpace {

    ConnectFourAbstract::ConnectFourAbstract() {
        //default value 5x5  
        setRowSize(5);
        setColSize(5);
        resizeBoard();
    }

    ConnectFourAbstract::ConnectFourAbstract(int row, int col) {
        setRowSize(row);
        setColSize(col);
        resizeBoard();
    }

    ConnectFourAbstract::~ConnectFourAbstract() {
        clearBoard();
    }

    int rowCount(string fileName) {
        fstream tmpCount;
        string tmpStr;
        int totalRow = 0;
        tmpCount.open(fileName);
        while (!tmpCount.eof()) {
            ++totalRow;
            getline(tmpCount, tmpStr);
        }
        tmpCount.close();
        return totalRow;
    }
    char ConnectFourAbstract::convertLetter(char in){
        if(in<='Z' && in>='A')
          return in-('Z'-'z');
        return in;
    }
    ConnectFourAbstract& ConnectFourAbstract::operator=(const ConnectFourAbstract& other) {
        setRowSize(other.getRowSize());
        setColSize(other.getColSize());
        setPlayerRank(other.getPlayerRank());
        setStatement(other.getStatement());
        setGameType(other.getGameType());
        setGameMode(other.getGameMode());
        resizeBoard();
        for (int row = 0; row < getRowSize(); ++row) {
            for (int col = 0; col < getColSize(); ++col) {
                board[row][col].setCellType(other.board[row][col].getCellType());
            }
        }
        return *this;
    }

    ConnectFourAbstract::ConnectFourAbstract(string fileName) {
        fstream file, tmpCount;
        string rowStr, tmpStr;
        int maxCol, row = 0, totalRow = 0;
        statementOfConstructor = true;
        int* cols;
        tmpCount.open(fileName);
        while (!tmpCount.eof()) {
            ++totalRow;
            getline(tmpCount, tmpStr);
        }
        tmpCount.close();
        cols = new int[totalRow];
        file.open(fileName);
        getline(file, rowStr);
        while (!file.eof()) {
            ++row;
            maxCol = rowStr.length();
            cols[row - 1] = maxCol;
            getline(file, rowStr);
        }
        file.close();
        setRowSize(row);
        setColSize(findBigCol(cols, row));
        resizeBoard();
        fillBoard(fileName);
        delete []cols;
    }

    int ConnectFourAbstract::findBigCol(int a[], int size) {
        int max = a[0];
        for (int i = 1; i < size; ++i) {
            if (a[i] > max)
                max = a[i];
        }
        return max;
    }

    void ConnectFourAbstract::chooseGameType() {
        char gameTypeVal;
        bool check = false;
        do {
            cout << "player | computer : " << endl;
            cin>>gameTypeVal;
            if(gameTypeVal=='p')
                gameTypeVal='P';
            else if(gameTypeVal=='c')
                gameTypeVal='C';
            
            if (gameTypeVal == 'P' || gameTypeVal == 'C' ) {
                setGameType(gameTypeVal);
                check = true;
            }
        } while (check == false);
    }

    void ConnectFourAbstract::setGameBoard() {
        int row, col;
        bool check = false;
        char tmp;
        do {
            cout << "Give to me row size :" << endl;
            cin>>row;
            if (!cin) {  
                cerr << "int olmayan değer girdin!!!" << endl;
                cin.clear();
                cin.ignore(256,'\n');               
                check = false;
               
            } else if (row <= 0) {
                cerr << "Board boyutları negatif değer alamaz!!!" << endl;
                check = false;
            } else {
                setRowSize(row);
                check = true;
            }

        } while (check == false);

        check=false;
        do {
        cout << "Give to me column size :" << endl;
        cin>>col;
        
        if (!cin) {  
                cerr << "int olmayan değer girdin!!!" << endl;
                cin.clear();
                cin.ignore(256,'\n');               
                check = false;
               
            } else if (col <= 0) {
                cerr << "Board boyutları negatif değer alamaz!!!" << endl;
                check = false;
            } else {
                setColSize(col);
                check = true;
            }

        } while (check == false);
        
        resizeBoard();
        fillBoard();
    }

    void ConnectFourAbstract::clearBoard() {
        
        for (int i = 0; i < getRowSize(); i++){
            delete[] board[i];
        }
        delete[] board;
    }

    void ConnectFourAbstract::resizeBoard() {

        board = new Cell*[getRowSize()];
        for (int i = 0; i < getRowSize(); ++i)
            board[i] = new Cell[getColSize()];
    }

    void ConnectFourAbstract::fillBoard() {
        for (int row = 0; row < getRowSize(); ++row) {
            for (int col = 0; col < getColSize(); ++col) {
                board[row][col].setCellType('.');
            }
        }
    }
    //parametre olarak dosya adı alan boardı dolduran fonk.

    void ConnectFourAbstract::fillBoard(string fName) {
        fstream file;
        string tmpStr;
        file.open(fName.c_str());
        for (int row = 0; row < getRowSize(); ++row) {
            getline(file, tmpStr);
            tmpStr.reserve(getColSize() + 10);
            tmpStr.resize(getColSize());
            for (int col = 0; col < getColSize(); ++col) {
                if (tmpStr[col] == '*')
                    board[row][col].setCellType('.');
                else
                    board[row][col].setCellType(' ');
            }
        }
    }

    void ConnectFourAbstract::showBoard() {
        cout << endl;
        for (int cName = 0; cName < getColSize(); ++cName)
            cout << static_cast<char> (cName + 65) << " ";
        cout << endl;
        for (int row = 0; row < getRowSize(); ++row) {
            for (int col = 0; col < getColSize(); ++col) {
                cout << board[row][col].getCellType() << " ";
            }
            cout << endl;
        }
    }

    int ConnectFourAbstract::getCommand(int choose) {
        int resultOfCheckWin = 0;
        if (getGameType() == 'P') {
            string p1, p2;
            cout << endl << "P" << getPlayerRank() << ":";
            cin>>p1;
            if (cin.eof())
                exit(0);
            //burada load ya da save yapılmış mı kontrol ediyoruz
            bool commandStatement = checkCommand(p1);
            if (commandStatement != true)
                play(static_cast<int> (convertLetter(p1[0]))-97);
            commandStatement = false;
            resultOfCheckWin = checkWin();
            showBoard();
            if (resultOfCheckWin != 0)
                return resultOfCheckWin;
            cout << endl << "P" << getPlayerRank() << ":";
            cin>>p2;
            if (cin.eof())
                exit(0);
            //burada load ya da save yapılmış mı kontrol ediyoruz
            commandStatement = checkCommand(p2);
            if (commandStatement != true)
                play(static_cast<int>(convertLetter(p2[0]))-97);
            commandStatement = false;
            resultOfCheckWin = checkWin();
            showBoard();
            if (resultOfCheckWin != 0)
                return resultOfCheckWin;

        } else if (getGameType() == 'C') {
            string p1;
            cout << endl << "P" << getPlayerRank() << ":";
            cin>>p1;
            if (cin.eof())
                exit(0);
            //burada load ya da save yapılmış mı kontrol ediyoruz
            bool commandStatement = checkCommand(p1);
            if (commandStatement != true)
                 play(static_cast<int> (convertLetter(p1[0]))-97);
            commandStatement = false;
            resultOfCheckWin = checkWin();
            showBoard();
            if (resultOfCheckWin != 0)
                return resultOfCheckWin;
            play();
            resultOfCheckWin = checkWin();
            showBoard();
            if (resultOfCheckWin != 0)
                return resultOfCheckWin;


        }
        return resultOfCheckWin;
    }
    //check for load or save command
    bool ConnectFourAbstract::checkCommand(string tempCommand) {
        string fileName;
        
        if (tempCommand == "LOAD" || tempCommand=="load") {      
            getline(cin, fileName);
            readFromFile(fileName.c_str());
            return true;
        } else if (tempCommand == "SAVE" || tempCommand=="save") {
        
            
            getline(cin, fileName);
            writeToFile(fileName.c_str());
            return true;
        }
    }
    //play function for computer
    int ConnectFourAbstract::play() {
        if (getPlayerRank() == 3) {
            setPlayerRank(1);
            for (int row = getRowSize() - 1; row >= 0; --row) {
                for (int col = 0; col < getColSize(); ++col) {
                    if (board[row][col].getCellType() == '.') {
                        board[row][col].setCellType('O');
                        return 1;
                    } else if (row - 3 > 0 &&
                            board[row][col].getCellType() == 'X' &&
                            board[row - 1][col].getCellType() == 'X' &&
                            board[row - 2][col].getCellType() == 'X' &&
                            board[row - 3][col].getCellType() == '.') {
                        board[row - 3][col].setCellType('O');
                        return 1;
                    } else if (col - 3 > 0 &&
                            board[row][col].getCellType() == 'X' &&
                            board[row][col - 1].getCellType() == 'X' &&
                            board[row][col - 2].getCellType() == 'X' &&
                            board[row][col - 3].getCellType() == '.') {
                        board[row][col - 3].setCellType('O');
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    //play function for users (user 1 and user 2)
    void ConnectFourAbstract::play(int colVal) {
        if ((colVal < getColSize()) && colVal >= 0) {
            int rowVal = getRowSize() - 1;
            if (getPlayerRank() == 1) {//user1
                bool check = false;
                for (int row = getRowSize() - 1; row >= 0; --row) {
                    if (board[row][colVal].getCellType() == '.' && check == false && getPlayerRank() != 3) {
                        board[row][colVal].setCellType('X');
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
                        setPlayerRank(1);
                        check = true;
                    } else if (board[row][colVal].getCellType() != '.' && board[row][colVal].getCellType() != ' ') {

                        setPlayerRank(2);
                    }
                }
            }

        } else
            cerr << "move is illegal" << endl;
    }
    //read game from file
    void ConnectFourAbstract::readFromFile(string fileName) {
        ifstream myfile, file;
        char gameTypeVal;
        int rowSizeVal, colSizeVal, typeOfUserVal;
        myfile.open(fileName.c_str());
        if(myfile.fail()){
            cerr<<"Do not find file..."<<endl;
            exit(1);
        }
        myfile>>rowSizeVal;
        myfile>>colSizeVal;
        myfile>>typeOfUserVal;
        myfile>>gameTypeVal; 
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
    //write game to file 
    void ConnectFourAbstract::writeToFile(string fileName) {
        ofstream myfile;
        //buraya file name gelecek
        myfile.open(fileName.c_str());
        myfile << getRowSize() << endl;
        myfile << getColSize() << endl;
        //player rank sıra kimdeyse onu gösterecek
        myfile << getPlayerRank() << endl;
        //gameType
        myfile << getGameType() << endl;
        for (int i = 0; i < getRowSize(); i++) {
            for (int j = 0; j < getColSize(); j++) {
                myfile << (board[i][j].getCellType());
            }
            myfile << endl;
        }
        myfile.close();
        cout << "Game is saved >> " << fileName << endl;
    }
    //check win function for check winner
    //diagonal , vertical and horizontal check
    int ConnectFourAbstract::checkWin() {
        int counter = 0;
        for (int row = 0; row < getRowSize(); ++row) {
            for (int col = 0; col < getColSize(); ++col) {
                if (board[row][col].getCellType() == '.')
                    ++counter;
                if ((row < getRowSize() - 3 &&
                        row >= 0) && board[row][col].getCellType() == 'X' &&
                        board[row + 1][col].getCellType() == 'X' &&
                        board[row + 2][col].getCellType() == 'X' &&
                        board[row + 3][col].getCellType() == 'X') {
                    board[row][col].setCellType('x');
                    board[row + 1][col].setCellType('x');
                    board[row + 2][col].setCellType('x');
                    board[row + 3][col].setCellType('x');
                    return 1;
                }
                if ((col < getColSize() - 3 && col >= 0) &&
                        (board[row][col].getCellType() == 'X' &&
                        board[row][col + 1].getCellType() == 'X' &&
                        board[row][col + 2].getCellType() == 'X' &&
                        board[row][col + 3].getCellType() == 'X')) {
                    board[row][col].setCellType('x');
                    board[row][col + 1].setCellType('x');
                    board[row][col + 2].setCellType('x');
                    board[row][col + 3].setCellType('x');
                    return 1;
                }

                if ((col >= 3 && row < getRowSize() - 3) &&
                        (board[row][col].getCellType() == 'X' &&
                        board[row + 1][col - 1].getCellType() == 'X' &&
                        board[row + 2][col - 2].getCellType() == 'X') &&
                        board[row + 3][col - 3].getCellType() == 'X') {
                    board[row][col].setCellType('x');
                    board[row + 1][col - 1].setCellType('x');
                    board[row + 2][col - 2].setCellType('x');
                    board[row + 3][col - 3].setCellType('x');
                    return 1;
                }
                if ((col < getColSize() - 3 && row < getRowSize() - 3) &&
                        (board[row][col].getCellType() == 'X' &&
                        board[row + 1][col + 1].getCellType() == 'X' &&
                        board[row + 2][col + 2].getCellType() == 'X') &&
                        board[row + 3][col + 3].getCellType() == 'X') {
                    board[row][col].setCellType('x');
                    board[row + 1][col + 1].setCellType('x');
                    board[row + 2][col + 2].setCellType('x');
                    board[row + 3][col + 3].setCellType('x');
                    return 1;
                }


                if ((row < getRowSize() - 3 && row >= 0) &&
                        board[row][col].getCellType() == 'O' &&
                        board[row + 1][col].getCellType() == 'O' &&
                        board[row + 2][col].getCellType() == 'O' &&
                        board[row + 3][col].getCellType() == 'O') {
                    board[row][col].setCellType('o');
                    board[row + 1][col].setCellType('o');
                    board[row + 2][col].setCellType('o');
                    board[row + 3][col].setCellType('o');
                    return 2;
                }
                if ((col < getColSize() - 3 && col >= 0) &&
                        (board[row][col].getCellType() == 'O' &&
                        board[row][col + 1].getCellType() == 'O' &&
                        board[row][col + 2].getCellType() == 'O' &&
                        board[row][col + 3].getCellType() == 'O')) {
                    board[row][col].setCellType('o');
                    board[row][col + 1].setCellType('o');
                    board[row][col + 2].setCellType('o');
                    board[row][col + 3].setCellType('o');
                    return 2;
                }

                if ((col >= 3 && row < getRowSize() - 3) &&
                        (board[row][col].getCellType() == 'O' &&
                        board[row + 1][col - 1].getCellType() == 'O' &&
                        board[row + 2][col - 2].getCellType() == 'O') &&
                        board[row + 3][col - 3].getCellType() == 'O') {
                    board[row][col].setCellType('o');
                    board[row + 1][col - 1].setCellType('o');
                    board[row + 2][col - 2].setCellType('o');
                    board[row + 3][col - 3].setCellType('o');
                    return 2;
                }
                if ((col < getColSize() - 3 && row < getRowSize() - 3) &&
                        (board[row][col].getCellType() == 'O' &&
                        board[row + 1][col + 1].getCellType() == 'O' &&
                        board[row + 2][col + 2].getCellType() == 'O') &&
                        board[row + 3][col + 3].getCellType() == 'O') {
                    board[row][col].setCellType('o');
                    board[row + 1][col + 1].setCellType('o');
                    board[row + 2][col + 2].setCellType('o');
                    board[row + 3][col + 3].setCellType('o');
                    return 2;
                }
            }

        }
        if (counter == 0) {
            cerr << "Board is full. You can not move. You can start new game..." << endl;
            return -1;
        }
        return 0;
    }
    //engine function for class
    void ConnectFourAbstract::playGame() {
        setGameBoard();
        chooseGameType();
        int result = 0;
        do {
            result = getCommand(1);
            if (result == 1)
                cout << "User1 is winner!!!" << endl;
            else if (result == 2 && getGameType() == 'P')
                cout << "User2 is winner!!!" << endl;
            else if (result == 2 && getGameType() == 'C')
                cout << "Computer is winner!!!" << endl;
        } while (result == 0);

    }

}



