/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mesut bunaldı
 * student id : 111044077
 *
 * Created on December 10, 2017, 12:31 AM
 */

#include<iostream>
#include <cstdlib>
#include<string>
#include "GTUSet.h"
#include "GTUSet.cpp"
#include "GTUMap.h"
#include "GTUMap.cpp"
using namespace std;
using namespace hw6;

//global function intersection
template <class T>
shared_ptr<GTUSetBase<T>> setIntersection (const GTUSetBase<T>& t1,const GTUSetBase<T>& t2);

int main(int argc, char** argv) {
 
    
    
    GTUSet<int> b;
    b.insert(1);
    b.insert(4);
    b.insert(3);
    b.insert(120);
    
    
    GTUSet<int> a;
    a.insert(9);
    a.insert(4);
    a.insert(3);
    a.insert(1);
    
    

    auto temp=setIntersection(a,b);
  
    for(GTUSet<int>::Iterator i=a.begin();i!=a.end();i++)
        cout<<"a GTUSet Object : "<<*i<<" "<<endl;
    cout<<endl;
    for(GTUSet<int>::Iterator i=b.begin();i!=b.end();i++)
        cout<<"b GTUSetObject : "<<*i<<" "<<endl;
    cout<<endl;
   for(GTUSet<int> ::Iterator i=temp->begin();i!=temp->end();++i)
       cout<<"intersection element : "<<*i<<endl;
    
    cout<<"GTUSet max size : "<<temp->max_size()<<endl;
    
    GTUSet<string> str1;
    
    str1.insert("mesut");
    str1.insert("murat");
    str1.insert("kamil");
    for(GTUSet<string>::Iterator i=str1.begin();i!=str1.end();i++)
        cout<<"str1 GTUSet Object : "<<*i<<" "<<endl;
    cout<<endl; 
   
    
    
     GTUSet<string> str2;
    
    str2.insert("mesut");
    str2.insert("murtaza");
    str2.insert("kamile");
    for(GTUSet<string>::Iterator i=str2.begin();i!=str2.end();i++)
        cout<<"str2 GTUSet Object : "<<*i<<" "<<endl;
    cout<<endl;
    
    
    auto temp2=setIntersection(str1,str2);
  
    for(GTUSet<string> ::Iterator i=temp2->begin();i!=temp2->end();++i)
       cout<<"intersection element for str : "<<*i<<endl;
    
    str1.clear();
    str2.clear();
    
     auto temp4=setIntersection(str1,str2);
  
    for(GTUSet<string> ::Iterator i=temp4->begin();i!=temp4->end();++i)
       cout<<"intersection element for str : "<<*i<<endl;
    
    GTUMap<int,int> m;
    pair<int,int> p(1,100);
    pair<int,int> p2(2,200);
    m.insert(p);
    m.insert(p2); 
    
    m.print();
    
    GTUMap<string,string> m1;
    pair<string,string> p1("mesut","bunaldı");    
    m1.insert(p1);    
    m1.print();
    
    GTUMap<string,string> m2;   
    pair<string,string> p3("mesut","bunaldı");
    pair<string,string> p4("medfsut","busnaldı");    
    m2.insert(p3);
    m2.insert(p4);    
    m2.print();
    
    
    auto temp3=setIntersection(m1,m2);    
    cout<<"m1 and m2 intersection size : "<<temp3->size()<<endl;
    m1["mesut"]="naber";
    m1.print();
    
    
    cout<<"GTUMap index operator : "<<m1["mesut"]<<endl;
    
    
    m1.clear();
    m1.print();
    
   cout<<"GTUMap max size : "<< m1.max_size();
    
    
    return 0;
}


//global intersection function
template <class T>
    shared_ptr<GTUSetBase<T> > setIntersection (const GTUSetBase<T>& t1,const GTUSetBase<T>& t2){
        shared_ptr<GTUSet<T> > t(new GTUSet<T>);
        for(GTUIterator<T> i=t1.begin() ;i!=t1.end();++i){
            for(GTUIterator<T> j=t2.begin();j!=t2.end();++j){
                if(*i==*j){                    
                    t.get()[0].insert(*i);                    
                }                    
            }
        }     
        return t;       
}