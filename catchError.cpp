#include <cmath>
#include <iostream>
using namespace std;

struct Res{
    float x1;
    float x2;
};
Res resolution(int a,int b,int c) throw(int);
int main(){
    int a;
    int b;
    int c;
    Res r;
    cout<<"Input a,b,c: ";
    cin>>a>>b>>c;
    try{
        r = resolution(a,b,c);
        cout<<"x1= "<<r.x1<<"\tx2= "<<r.x2<<endl;//?x1 x2 ? error
    }
    catch(int){
        cerr<<"Sqrt Negative Exception";
    }
    catch(...){
        cerr<<"unexpected or rethrow expecption"<<endl;
    }
    return 0;
}
float quotient(int a,int b) throw(char *){
    if(b == 0)
        throw("Divide 0!");
    else
    {
        return a/(float)b;
    }
}
Res resolution(int a,int b,int c) throw(int){
    Res tmpr;
    try{
        if(a == 0&& b!=0){
            tmpr.x1 = tmpr.x2 = quotient(-c,b);
            return tmpr;
        }
        if(b*b - 4*a*c < 0)
            throw(b);
        tmpr.x1 = quotient(-b + sqrt(b*b-4.0*a*c),2*a);
        tmpr.x2 = quotient(-b - sqrt(b*b-4.0*a*c),2*a);
        return tmpr;
    }
    catch(char  * Errs){
        cerr<<Errs<<endl;
        exit(0);
    }
}
