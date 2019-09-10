/* 
 * File:   ConnectFourAbstract.h
 * Author: mesut bunaldı 111044077

        HW05
 *
 * Created on november 15, 2017, 8:16 PM
 */

#ifndef CONNECTFOURABSTRACT_H
#define CONNECTFOURABSTRACT_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Cell.h"
using namespace std;

namespace CellSpace {

    class ConnectFourAbstract {
    public:
        //no parameter constructor ///   
        ConnectFourAbstract();
        //file name parameter constructor 
        ConnectFourAbstract(string fileName);
        //one parameter constructor  
        ConnectFourAbstract(int row, int col);
        //destructor
        ~ConnectFourAbstract();
        //setters
        void setGameBoard(); //set size row and column //ok
        inline void setRowSize(int rowSizeVal) {rowSize = rowSizeVal;}; //board row
        inline void setColSize(int colSizeVal) {colSize = colSizeVal;}; //board col 
        inline void setGameType(char typeVal) {gameType = typeVal;}; //PVP or PVC    ok
        inline void setGameMode(char gameModeVal) {gameMode = gameModeVal;};
        inline void setPlayerRank(int rankVal) {playerRank = rankVal;};
        inline void setStatement(int statementVal) {boardStatement = statementVal;};
        void chooseGameType(); //p or c ok 
        inline void setStatementOfConstructor(bool statementVal) {statementOfConstructor = statementVal;};
        //getters
        inline char getGameType()const {return gameType;}; // ok
        inline int getColSize()const {return colSize;}; //ok
        inline int getRowSize()const {return rowSize;}; //ok
        inline char getGameMode()const {return gameMode;};
        inline int getPlayerRank()const {return playerRank;};
        int getCommand(int choose); //position or save or load
        inline int getStatement()const {return boardStatement;};
        inline bool getStatementOfConstructor()const {return statementOfConstructor;};
        //other functions
        void clearBoard();
        void showBoard(); //  ok  
        virtual int play(); //for computer    
        virtual void play(int colVal); //for user    
        virtual int checkWin(); //check the game if an user is winner return 1 else 0    
        void playGame(); //get game type,rowSize,colSize    
        virtual void readFromFile(string fileName); //reader function
        virtual void writeToFile(string fileName); //writer function   
        virtual bool checkCommand(string command); //for save and load
        void runCommand(string command);
        void fillBoard(); //ok
        void fillBoard(string fName);
        int findBigCol(int a[], int size);
        char convertLetter(char in);
        //operator overloading
        ConnectFourAbstract& operator=(const ConnectFourAbstract& other);
        bool operator==(const ConnectFourAbstract& other);
        bool operator!=(const ConnectFourAbstract& other);
    protected:
        char gameMode; //bu değer ana  fonksiyon içerisinde en başta kullanılacak M : Multiple, S : Single
        char gameType; // p : PVP , c: PVC 
        Cell** board;
        int boardStatement = 0;
        int rowSize;
        int colSize;
        int playerRank = 1;
        bool statementOfConstructor = false;
        void resizeBoard();

    };


    void testMain();
}
#endif /* CONNECTFOURABSTRACT_H */


