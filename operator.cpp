#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double image;
public:
    Complex(double real = 0.0,double image = 0.0)
    {
        this->real = real;
        this->image = image;
    }
    void display(){
        cout<<"("<<real<<","<<image<<")"<<endl;
    }
    Complex operator + (Complex B);
    Complex operator - (Complex B);
    Complex operator - ();
    Complex operator ++ ();
    Complex operator ++(int);
};

Complex Complex::operator+(Complex B){
    return Complex(real +B.real,image + B.image);
}
Complex Complex::operator-(Complex B){
    return Complex(real -B.real,image - B.image);
}
Complex Complex::operator - ()
{
    return Complex(-real,-image);
}
Complex Complex::operator ++()
{
    return Complex(++real,image);
}
Complex Complex::operator ++(int)
{
    return Complex(real++,image);
}
int main()
{
    Complex A(100.0,200.0);
    Complex B(-10.0,20.0);
    Complex C;
    cout<<"A=";
    A.display();
    cout<<"B=";
    B.display();
    C = A+B;
    cout<<"C = A+B";
    C.display();
    C = A - B;
    cout<<"C=A-B";
    C.display();
    C = -A+B;
    cout<<"C = -A+B=";
    C.display();
    C = A++;
    cout<<"C=A++=";
    C.display();
    C = ++A;
    cout<<"C=++A=";
    C.display();
    C = A+5;
    cout<<"C=A+5";
    C.display();
    return 0;
    
}
