#include <iostream>
using namespace std;
class Point{
private:
    int X;
    int Y;
public:
    Point(int x=0,int y=0){
        this->X = x;
        this->Y = y;
        cout<<"construtor"<<"Point("<<X<<","<<Y<<")"<<endl;
    }
    ~Point(){
        cout<<"destructor"<<"Point("<<X<<","<<Y<<")"<<endl;
    }
};
class Circle :protected Point{
private:
    double radius;
public:
    Circle(double R = 0,int X = 0,int Y = 0):Point(X,Y){
        radius = R;
        cout<<"circle constructor radius:"<<R<<endl;
    };
    ~Circle(){
        cout<<"circle destructor radius:"<<radius<<endl;
    };
};
class tube :protected Circle{
private:
    double Height;
    Circle Incircle;
public:
    tube(double H,double R1,double R2,int X=0,int Y=0):Incircle(R2,X,Y),Circle(R1,X,Y){
        Height = H;
        cout<<"tube constructor H:"<<Height<<endl;
    }
    ~tube(){
        cout<<"tube destructor H:"<<Height<<endl;
    }
};
int main(){
    tube TU(100,20,5);
    return 0;
}
