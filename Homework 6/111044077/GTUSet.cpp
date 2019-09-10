/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GTUSet.cpp
 * Author: mesut bunaldı
 * student id : 111044077
 *
 * Created on December 10, 2017, 12:31 AM
 */


#include "GTUSet.h"
using namespace std;


namespace hw6{
    
    
    //no parameter constructor
    template<class T>
    GTUSet<T>::GTUSet() {
        shared_ptr<T> tmp(new T[10],default_delete<T[]>());
        items = tmp;
        setSizeOfItem(0);
        maxSizeOfItem = 10;
    }
    //output function
    template<class T>
    void GTUSet<T>::output(int i) {
        cout << items.get()[i];
    }
    //size function
    template<class T>
    int GTUSet<T>::size()const {
        return sizeOfItem;
    }
    //empty class
    template<class T>
    bool GTUSet<T>::empty() const {
        if (size() == 0)
            return true;
        else
            return false;
    }
    //max_size function
    template<class T>
    int GTUSet<T>::max_size()const {
        return maxSizeOfItem;
    }
    //insert function
    template<class T>
    void GTUSet<T>::insert(T item) throw () {

        try {
            for (int i = 0; i < size(); i++) {
                if (items.get()[i] == item)
                    throw;
            }
            if (size() == max_size()) {
                maxSizeOfItem += 10;
                shared_ptr<T> tmp(new T[max_size()]);
                for (int i = 0; i < size(); ++i)
                    tmp.get()[i] = items.get()[i];

                items = tmp;
            }
            items.get()[size()] = item;
            setSizeOfItem(sizeOfItem + 1);
        } catch (...) {
            cout << "Default exception." << endl;
        }
    }
    //erase function
    template<class T>
    int GTUSet<T>::erase(T tVal) {

        for (int i = 0; i < size(); i++) {
            if (items.get()[i] == tVal) {
                items.get()[i] = items.get()[size() - 1];
                setSizeOfItem(size() - 1);
                return 1;
            } else
                return 0;
        }
    }
    //clear function
    template<class T>
    void GTUSet<T>::clear()noexcept {
        items.reset(new T);
        setSizeOfItem(0);
    }

    template<class T>
    int GTUSet<T>::count(const T& tVal)const {

        for (int j = 0; j < size(); j++) {
            if (items.get()[j] == tVal) {
                return 1;
            }
        }
        return 0;
    }
    //begin function
    template<class T>
    const GTUIterator<T> GTUSet<T>::begin() const{
        return GTUIterator<T>(&*items);
    }
    //end function
    template<class T>
    const GTUIterator<T> GTUSet<T>::end()const {
        return GTUIterator<T>(&*items + sizeOfItem);
    }
    //fnd function
    template<class T>
    const GTUIterator<T> GTUSet<T>::find(const T& val)const {

            for (int i = 0; i < size(); i++) {
                if (items.get()[i] == val)
                    return GTUIterator<T>(&*items + i);
            }
        }
  
}