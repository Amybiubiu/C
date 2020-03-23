//
//  Student.h
//  text
//
//  Created by mac on 2020/3/22.
//  Copyright © 2020 mac. All rights reserved.
//

#ifndef Student_h
#define Student_h
#include <iostream>
#include <string>
using namespace std;
class Student{
private:
    int No;
    string Name;
    int Score;
public:
    Student(){ };
    Student(int no,string name,int score){
        this->No = no;
        this->Name = name;
        this->Score = score;
    }
    int getNo(){
        return this->No;
    }
    string getName(){
        return this->Name;
    }
    int getScore(){
        return this->Score;
    }
};

#endif /* Student_h */
