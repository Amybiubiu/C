//
//  main.cpp
//  text
//
//  Created by mac on 2020/1/3.
//  Copyright © 2020 mac. All rights reserved.
//

#include <iostream>
using namespace std;

//定义一个Shape类，派生出Rectangle类和Circle类，计算各派生类对象的面积Area()
//Area函数定义为虚函数
class Point{
private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0){
        this->x = x;
        this->y = y;
    }
};
class Shape{
public:
    Shape(int x,int y){
        Point o(x,y);
    }
    virtual float getArea(){ return 0.0;};
};
class Rectangle:public Shape{
private:
    int w;
    int h;
public:
    Rectangle(int x, int y, int m, int n):Shape(x,y){
        this->w = m;
        this->h = n;
    };
    float getArea(){
        return w*h;
    };
};
class Circle:public Shape{
private:
    int r;
public:
    Circle(int x, int y, int z):Shape(x,y){
        this->r = z;
    };
    float getArea(){
        return 3.14*r*r;
    };
};
int main()
{
    Shape* ps[10];
    int i;
    
    for (i = 0; i < 10; i ++)  //
    {
        int t = i % 3;
        switch (t)
        {
            case 0: ps[i] = new Shape(1 + i, 1 + i); break;
            case 1: ps[i] = new Rectangle(1 + i, 1 + i, i, i); break;
            case 2: ps[i] = new Circle(1 + i, 1 + i, i); break;
        }
    }
    
    for (i = 0; i < 10; i ++)
    {
        cout << ps[i]->getArea() << endl;
    }
    
    for (i = 0; i < 10; i ++)
    {
        delete ps[i];
    }
    return 0;
}
