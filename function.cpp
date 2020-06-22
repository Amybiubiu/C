#include <iostream>
#include <string>
using namespace std;

void reset(int &i){
    i = 0;
}

int main(){
    int i = 0;
    const int ci = i;
    reset(&i);
    reset(&ci);
    reset(i);
    reset(ci);  // error: can't bind a plain reference to the const object ci
    const string &i = "abcda";
}