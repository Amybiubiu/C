#include <iostream>
using namespace std;

class Point{
protected:
    int x;
    int y;
public:
    Point(int x=1,int y=0){
        this->x=x;
        this->y=y;
    }
    void SetState(int x,int y){
        this->x =x;
        this->y =y;
    }
    void showXY(){
        Point p;
        cout<<p.x<<endl;//right!
        cout<<x<<y<<endl;
    }
};
class Circle:protected Point{
private:
    double radius;
protected:
//    Point p;
public:
    void showX(){
        Point p;
        cout<<p.x<<endl;//err: x is a protected member of point
        cout<<x<<endl;//两种情况不一样，没有道理可讲，自己记住就好了，只有第一种情况才能访问成功
    }
};
int main(){
    Point p;
//    p.SetState(3,2);
    p.showXY();
    return 0;
}
