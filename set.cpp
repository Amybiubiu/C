//
//  main.cpp
//  c++
//
//  Created by mac on 2020/2/21.
//  Copyright © 2020 mac. All rights reserved.
//  定义集合set类；重载操作符：<= 并| 交& 差- 增加+= 删除-= 这个六个操作

#include <iostream>
using namespace std;

template <class Type>
class Set {
private:
    Type items[100];
    int number;
public:
    Set(){
        this->number = 0;
        memset(this->items,0,sizeof(items));    //初始化为0，如果set中有0存在...
    }
    int isExist(Type item);
    bool addItem(Type item);
    bool removeItem(Type item);
    void display();
    
    //类成员函数重载，也可以作为友元函数重载
    bool operator<= (Set set2);
    Set operator| (Set set2);
    Set operator& (Set set2);
    Set operator- (Set set2);
    Set operator-= (Type item);
    Set operator+= (Type item);
};

template <class Type>
int Set<Type>::isExist(Type item){
    for(int i = 0;i < this->number;i++){
        if(this->items[i] == item)
            return i;
    }
    return -1;
}
template <class Type>
bool Set<Type>::addItem(Type item){
    if(isExist(item) == -1){
        items[this->number] = item;
        this->number++;
        return true;
    }else{
        return false;
    }
}
template <class Type>
bool Set<Type>::removeItem(Type item){
    if(isExist(item) != -1){
        for(int i = isExist(item); i < this->number-1 ;i++){
            this->items[i] = this->items[i+1];
        }
        this->number--;
        return true;
    }else{
        return false;
    }
}
template <class Type>
void Set<Type>::display(){
    for(int i=0; i < this->number ;i++){
        cout<<this->items[i]<<" ";
    }
    cout<<endl;
}
//交集
template <class Type>
Set<Type> Set<Type>::operator|(Set set2){
    Set result;
    for(int i=0; i<this->number; i++) {
        result.items[result.number] = this->items[i];
        result.number++;
    }
    for(int j=0; j<set2.number; j++) {
        if(result.isExist(set2.items[j]) == -1) {
            result.items[result.number] = set2.items[j];
            result.number++;
        }
    }
    return result;
}
//并集
template <class Type>
Set<Type> Set<Type>::operator& (Set set2)
{
    Set result;
    for(int i=0; i< this->number; i++) {
        if(set2.isExist(this->items[i]) >= 0) {
            result.items[result.number] = this->items[i];
            result.number++;
        }
    }
    return result;
}
// 差集
template <class Type>
Set<Type> Set<Type>::operator- (Set set2){
    Set result;
    for(int i=0; i<this->number; i++) {
        result.items[result.number] = this->items[i];
        result.number++;
    };
    for(int i = 0; i < set2.number; i++){
        result.removeItem(set2.items[i]);
    }
    return result;
}
//
template <class Type>
bool Set<Type>::operator <= (Set set2){
    if(this->number <= set2.number){
        return true;
    }else
        return false;
}
template <class Type>
Set<Type> Set<Type>::operator += (Type item){
    addItem(item);
    Set result;
    for(int i=0; i<this->number; i++) {
        result.items[result.number] = this->items[i];
        result.number++;
    }
    return result;
}
template <class Type>
Set<Type> Set<Type>::operator -= (Type item){
    removeItem(item);
    Set result;
    for(int i=0; i<this->number; i++) {
        result.items[result.number] = this->items[i];
        result.number++;
    }
    return result;
}
int main(){
    Set<int> set1;
    set1.addItem(1);
    set1.addItem(2);
    set1.addItem(2);
    set1.addItem(3);
    set1.display();
    set1.removeItem(3);
    set1.display();
    
    Set<int> set2;
    set2 += 1;
    set2 += 3;
    set2 += 5;
    set2.display();
    
    cout<<(set2<=set1)<<endl;
    (set1|set2).display();
    (set1&set2).display();
    (set1-set2).display();
    return 0;
}

