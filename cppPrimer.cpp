#include <iostream>
using namespace std;

//pointer
void pointer(void){
    int i = 42;
    int *p = &i;
    *p = 2;
    cout<<i<<endl;  //2
}
//reference
void ref(){
    int i = 54;
    int &r = i;
    int i2 = 24;
    r = i2;
    // i = 23; r->23
    i2 = 33;
    cout<<r<<endl;  // 24
    const int &i3 = 2;
}
//const reference
void const_ref(){
    int i = 54;
    int &r = i;
    const int &r1 = i;
    i = 23;
    cout<<r<<endl;
    cout<<r1<<endl;    //23 r1 is const reference to r1;
    //r1 = 0; error, can't change be used to change i
    //这种设计真的绕的人晕
}
void const_ptr(){
    int i = 34;
    const int *p = &i;
    //*p = 2; error, can't change be used to change i
}
int main(){
    pointer();  //为什么会引用不了？？函数顺序问题++
    int i = 54;
    int &r = i;
    int i2 = 24;
    r = i2;
    // i = 23;
    i2 = 33;
    cout<<r<<endl; 
    cout<<i<<endl; //23
    return 0;
}