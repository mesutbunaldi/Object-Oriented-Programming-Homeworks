/* 
 * File:   Cell.h
 * Author: mesut bunaldı 111044077

        HW05
 *
 * Created on november 15, 2017, 8:16 PM
 */

#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

namespace CellSpace {

    class Cell {
    public:
        //no parameter constructor
        Cell();
        //copy constructor 
        Cell(const Cell& other);        
        //destructor
        ~Cell();
        
        //getters
        inline char getColumnName()const {return columnName;};
        inline int getRowNumber()const {return rowNumber;};
        inline char getCellType()const {return pointType;};
        inline int getPlayerType()const{return playerType;};
        inline int getLivingCells()const{return livingCells;};
        
        //setters
        inline void setColumnName(char col) {columnName = col;};
        inline void setRowNumber(int row) {rowNumber = row;};
        inline void setCellType(char type) {pointType = type;};
        inline void setPlayerType(int typeVal) {playerType = typeVal;};
        //operator overloading
        bool operator==(const Cell& otherCell);
        Cell& operator++(); //pre increment
        Cell operator++(int); //post increment
        friend istream& operator>>(istream& input, Cell& cellObject);
        friend ostream& operator<<(ostream& output, const Cell& cellObject);

        static int countLivingCells() {
            livingCells++;
        };

    protected:
        char columnName;
        int rowNumber;
        char pointType = '.'; // "." "x" "o"
        int playerType = 0; //0 is empty, 1 user1,2 user2,3 computer 
        static int livingCells;
    };

    istream& operator>>(istream& input, Cell& cellObject);
    ostream& operator<<(ostream& output, const Cell& cellObject);
}
#endif /* CELL_H */

