/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GTUIterator.h
 * Author: mesut bunaldı
 * student id : 111044077
 *
 * Created on December 10, 2017, 12:31 AM
 */
  
#include<iostream>
using namespace std;

namespace hw6{

    
    template<typename T>
    class GTUIterator{  
        public:
            //one parameter constructor
            GTUIterator(T* x) : p(x) {};
            //copy constructor
            GTUIterator(const GTUIterator& mit) : p(mit.p) {}
            //operator overloading 
            T& operator=(const GTUIterator& tVal) {*this = tVal;return this;};
            T* operator->() {return p; }
            T& operator*() {return *p;} 
            GTUIterator& operator++() {++p; return *this;} //post increment
            GTUIterator operator++(int) {GTUIterator tmp(*this);p++;return tmp;} //pre increment
            GTUIterator& operator--() {--p;return *this;}//pre decrement
            GTUIterator operator--(int) {GTUIterator tmp(*this);operator--();return tmp;} //post decrement
            bool operator==(const GTUIterator& tVal)const {return p == tVal.p;}
            bool operator!=(const GTUIterator& tVal)const {return p != tVal.p;}
            
        protected:
            //data member
            T* p;
        };
        
        
        
}