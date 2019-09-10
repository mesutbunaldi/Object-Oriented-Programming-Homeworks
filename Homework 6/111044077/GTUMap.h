/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GTUMap.h
 * Author: mesut bunaldı
 *student id : 111044077
 * Created on December 13, 2017, 2:21 PM
 */

#ifndef GTUMAP_H
#define GTUMAP_H
#include "GTUSet.h"


using namespace std;
namespace hw6 {

    template < typename K, typename V> 
    class GTUMap : public GTUSet<pair<K,V>> {
    public: 
        //print function for map
        void print(); 
        //index operator
        V& operator[](const K& key);      
    };


}


#endif /* GTUMAP_H */

