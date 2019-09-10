/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GTUMap.cpp
 * Author: mesut bunaldı
 * student id : 111044077
 *
 * Created on December 10, 2017, 12:31 AM
 */

#include "GTUMap.h"
namespace hw6{
  //index operator overloading  
 template < typename K, typename V> 
 V& GTUMap<K,V>::operator[](const K& key){           
            
            for(int i=0;i<GTUSet<pair<K,V>>::size();i++)
                if(key==GTUSet<pair<K,V>>::items.get()[0].first)
                    return GTUSet<pair<K,V>>::items.get()[0].second;         
        }
 //print GTUMap object
 template < typename K, typename V> 
 void GTUMap<K,V>::print(){
            cout<<endl<<"key : "<<GTUSet<pair<K,V>>::items.get()[0].first<<endl;
            cout<<"value : "<<GTUSet<pair<K,V>>::items.get()[0].second<<endl;
        }
 
}