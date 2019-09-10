

#include "ConnectFourDiag.h"
#include "ConnectFourPlus.h"
namespace CellSpace {

    ConnectFourDiag::ConnectFourDiag() {
        //no parameter constructor
    }

    ConnectFourDiag::~ConnectFourDiag() {
        //destructor
    }
    //check win function
    //diagonal check

    int ConnectFourDiag::checkWin() {
        int counter = 0;
        for (int row = 0; row < getRowSize(); ++row) {
            for (int col = 0; col < getColSize(); ++col) {
                if (board[row][col].getCellType() == '.')
                    ++counter;

                if ((col >= 3 && row < getRowSize() - 3) && (board[row][col].getCellType() == 'X' && board[row + 1][col - 1].getCellType() == 'X' && board[row + 2][col - 2].getCellType() == 'X') && board[row + 3][col - 3].getCellType() == 'X') {
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


}

