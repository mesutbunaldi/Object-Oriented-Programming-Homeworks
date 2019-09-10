/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GTUSetBase.h
 * Author: mesut bunaldı
 * student id : 111044077
 *
 * Created on December 9, 2017, 11:30 PM
 */

#ifndef GTUSETBASE_H
#define GTUSETBASE_H
#include <iostream>
#include <cstdlib>
#include<ostream>
#include <memory>
#include "GTUIterator.h"
#include "GTUSet.h"
using namespace std;



    
namespace hw6{
   
    
    template<typename T>
    class GTUSetBase{
        
        public:
            //ıterator
            typedef GTUIterator<T> Iterator;
            //no parameter constructor
            GTUSetBase(){};
            //pure virtual function empty
            virtual bool empty()const=0;           
            //pure virtual function size
            virtual int size()const=0;
            //pure virtual function size
            virtual int  max_size()const=0;
            //pure virtual function insert
            virtual void insert(T tVal) throw() =0;
            //pure virtual function erase
            virtual int erase(T tVal)=0;
            //pure vrtual function clear
            virtual void clear()noexcept=0;
            //pure virtual function count
            virtual int count(const T& tVal)const=0;
            //pure virtual function find
            virtual const Iterator find(const T& val)const=0 ;
            //pure virtual function begin
            virtual const Iterator begin()const=0;
            //pure virtual function end
            virtual const Iterator end()const =0;
            //destructor
           ~GTUSetBase(){};
           

    };   
    
   
}
#endif /* GTUSETBASE_H */

