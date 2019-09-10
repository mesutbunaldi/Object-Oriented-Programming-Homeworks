/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GTUSet.h
 * Author: mesut bunaldı
 * student id : 111044077
 *
 * Created on December 10, 2017, 12:31 AM
 */

#ifndef GTUSET_H
#define GTUSET_H
#include <memory>
#include "GTUSetBase.h"
using namespace std;


namespace hw6 {

    template <typename T>
    class GTUSet :public GTUSetBase<T>{
    public: 
        //typedef for ıterator
         typedef GTUIterator<T> Iterator;
         //no parameter constructor
        GTUSet();
        //overridde function empty
        bool empty()const;
        //override function  size
        int size()const;
        //override function max_size
        int max_size()const;
        //override function insert
        void insert(T item) throw ();
        //override function erase
        int erase(T tval);
        //override function clear
        void clear()noexcept;
        //override funvtion count
        int count(const T& tVal)const;
        //override function setSizeOfItem
        void setSizeOfItem(int val) {sizeOfItem = val;}
        //override function output
        void output(int i); 
        //override function begin
        const Iterator begin()const ;
        //override function end
        const Iterator end()const;
        //override function find
        const Iterator find(const T& val)const ;
        //destructor
        ~GTUSet(){};
    protected:
        //data member pointer for veriables 
        shared_ptr<T> items;
        //used
        int sizeOfItem;
        //capacity
        int maxSizeOfItem;
    };


  
}


#endif /* GTUSET_H */
