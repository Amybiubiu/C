//
//  DBase.cpp
//  c++
//
//  Created by mac on 2020/3/22.
//  Copyright © 2020 mac. All rights reserved.
//

#include "DBase.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class Type>
class DBase {
private:
    vector<Type> items;
    string path;
    fstream datfile;
public:
    DBase(string path){
        this->path = path;
    }
    bool create();
    void insert(Type item);
    void remove(int no);
    int getCount();
    void load(int no,Type& s);
    vector<Type> loadAll();
    void close();
    
};

template <class Type>
bool DBase<Type>::create(){
    datfile.open(path.c_str(),ios::binary|ios::trunc|ios::out);
    if(!datfile){
        cerr<<"open failed"<<endl;
        return false;
    }else
        return true;
}

template <class Type>
void DBase<Type>::insert(Type item){
    items.push_back(item);
    datfile.write((char *)& item,sizeof(item));
}

template <class Type>
void DBase<Type>::remove(int id){
    for(unsigned i=0; i < items.size(); i++){
        if(items[i].getNo() == id){
            items.erase(items.begin()+i);
            cout<<"删除成功"<<endl;
        }
    }
    datfile.close();
    datfile.open(path,ios::binary|ios::trunc|ios::out);
    if(datfile)
        cout<<"再次打开成功"<<endl;
    for(unsigned i=0;i < items.size(); i++){
        datfile.write((char *)& items[i],sizeof(items[i]));
    }
}

template <class Type>
int DBase<Type>::getCount(){
    return items.size();
}

template <class Type>
void DBase<Type>::load(int id,Type& s){
    for(int i = 0; i<items.size(); i++){
        if(items[i].getNo() == id){
            s = items[i];
            break;
        }
    }
}

template <class Type>
vector<Type> DBase<Type>::loadAll(){
    return items;
}

template <class Type>
void DBase<Type>::close(){
    datfile.close();
}
