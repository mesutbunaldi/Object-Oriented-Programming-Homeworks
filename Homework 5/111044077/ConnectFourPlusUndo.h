/* 
 * File:   ConnectFourPlusUndo.h
 * Author: mesut bunaldı 111044077

        HW05
 *
 * Created on november 15, 2017, 8:16 PM
 */
#ifndef CONNECTFOURPLUSUNDO_H
#define CONNECTFOURPLUSUNDO_H
#include "ConnectFourPlus.h"
#include <vector>
namespace CellSpace {

    class ConnectFourPlusUndo : public ConnectFourPlus {
    public:
        //constructor
        ConnectFourPlusUndo();
        //destructor
        ~ConnectFourPlusUndo();
        //getter
        inline vector<int> getMoves() {return moves;};
        int play(); //for computer    override
        void play(int colVal); //for user  override
        bool checkCommand(string command); //for save and load
        void readFromFile(string fileName); //reader function override
        void writeToFile(string fileName); //writer function override
    private:
       
        vector<int> moves;

    };
}
#endif 