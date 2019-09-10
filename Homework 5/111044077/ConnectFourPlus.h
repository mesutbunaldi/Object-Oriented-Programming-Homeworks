/* 
 * File:   ConnectFourPlus.h
 * Author: mesut bunaldı 111044077

        HW05
 *
 * Created on november 15, 2017, 8:16 PM
 */
#ifndef CONNECTFOURPLUS_H
#define CONNECTFOURPLUS_H
#include "ConnectFourAbstract.h"
namespace CellSpace {

    class ConnectFourPlus : public ConnectFourAbstract {
    public:
        //constructor
        ConnectFourPlus();
        //destructor
        ~ConnectFourPlus();
        inline string getName()const;
        int checkWin(); //virtual function
        inline void setName(string nameVal) {name = nameVal;};
    protected:
        string name;

    };
}
#endif 