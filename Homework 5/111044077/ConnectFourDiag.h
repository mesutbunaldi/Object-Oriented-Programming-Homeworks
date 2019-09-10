

/* 
 * File:   ConnectFourDiag.h
 * Author: mesut bunaldı 111044077

        HW05
 *
 * Created on november 15, 2017, 8:16 PM
 */
#ifndef CONNECTFOURDIAG_H
#define CONNECTFOURDIAG_H
#include "ConnectFourAbstract.h"
namespace CellSpace {

    class ConnectFourDiag : public ConnectFourAbstract {
    public:
        //constructor
        ConnectFourDiag();
        //destructor
        ~ConnectFourDiag();
        //getter
        string getName()const;
        
        int checkWin(); //virtual function        
        //setter
        void setName(string nameVal) {
            name = nameVal;
        };

    private:
        string name;
    };
}
#endif 