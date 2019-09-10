#include "Cell.h"
namespace CellSpace {
    int Cell::livingCells = 0;
    //no parameter constructor
    Cell::Cell() {
        countLivingCells();
        setCellType('.');
    }
    //copy constructor
    Cell::Cell(const Cell& other) {
        countLivingCells();
        setCellType(other.getCellType());
        setPlayerType(other.playerType);
        setRowNumber(other.getRowNumber());
        setColumnName(other.getColumnName());
    }
    //destructor
    Cell::~Cell() {

    }
    //compare operator overloading
    bool Cell::operator==(const Cell& otherCell) {
        if (getColumnName() == otherCell.getColumnName() &&
                getRowNumber() == otherCell.getRowNumber() &&
                getCellType() == otherCell.getCellType())
            return true;
        else
            return false;
    }
    //post increment operator overloading
    Cell& Cell::operator++() {
        if (getPlayerType() == 0)
            playerType = 1;
        else if (getPlayerType() == 1)
            playerType = 2;
        else if (getPlayerType() == 2)
            playerType = 3;
        else if (getPlayerType() == 3)
            playerType = 0;
        return *this;
    }
    //pre increment operator overloading
    Cell Cell::operator++(int) {
        Cell temp = *this;
        ++(*this);

        return temp;
    }
    //stream insertion operator overloading
    istream& operator>>(istream& input, Cell& cellObject) {
        cout << "Column Name : ";
        input >> cellObject.columnName;
        cout << "Row number  : ";
        input >> cellObject.rowNumber;
        cout << "Player type ?(0:empty , 1:user1 , 2:user2, 3:computer):";
        input >> cellObject.playerType;
        cout << "Point type ? ('x','o','.') :";
        input >> cellObject.pointType;
        return input;
    }
    //stream extraction operator
    ostream& operator<<(ostream& output, const Cell& cellObject) {
        output << "Column Name :" << cellObject.columnName << endl;
        output << "Row number  :" << cellObject.rowNumber << endl;
        output << "Player type ?(0:empty , 1:user1 , 2:user2, 3:computer):" << cellObject.playerType << endl;
        output << "Point type ? ('x','o','.') :" << cellObject.pointType << endl;
        return output;
    }
}