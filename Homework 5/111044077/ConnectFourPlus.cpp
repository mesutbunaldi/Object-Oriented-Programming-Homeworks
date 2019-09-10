#include "ConnectFourPlus.h"
#include "ConnectFourPlusUndo.h"
#include "ConnectFourDiag.h"
namespace CellSpace {

    ConnectFourPlus::ConnectFourPlus() : ConnectFourAbstract(), name("") {
        //no parameter constructor
    }

    ConnectFourPlus::~ConnectFourPlus() {
        //destructor
    }
    //check win function for check winner
    // vertical and horizontal check

    int ConnectFourPlus::checkWin() {
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
            }
        }
        if (counter == 0) {
            cerr << "Board is full. You can not move. You can start new game..." << endl;
            return -1;
        }
        return 0;
    }
    //test function for different objects

    void testMain() {
        string gameMode, fileName, command;
        int objectNumber = 0;

        do {
            cout << "Oyun Tipini Girin :" << endl;
            getline(cin, gameMode);
            if (gameMode == "P" || gameMode=="p") {
                objectNumber = 1;
                ConnectFourPlus obj;
                obj.playGame();
            } else if (gameMode == "D" || gameMode=="d") {
                objectNumber = 1;
                ConnectFourDiag obj1;
                obj1.playGame();

            } else if (gameMode == "U" || gameMode=="u") {
                objectNumber = 1;
                ConnectFourPlusUndo obj;
                obj.playGame();
            }
        } while (objectNumber == 0);
    }

}