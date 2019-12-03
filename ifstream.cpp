#include <fstream>
#include <iostream>

using namespace std;
int main(){
    char * name[3] ={"Antony","John","Tom"};
    float score[3] = {85.5,90,60};
    fstream txtfile,binfile;
//    outee.open("/Users/slfanta/Documents/123.txt");
    txtfile.open("/Users/mac/Desktop/rails/record.txt",ios::out|ios::trunc);
    binfile.open("/Users/mac/Desktop/rails/record.dat",ios::binary|ios::out|ios::trunc);
    if(!txtfile){
        cerr<<"record.txt open failed"<<endl;
        exit(1);
    }
    if(!binfile){
        cerr<<"record.dat open failed"<<endl;
    }
    for(int i=0;i<3;i++){
        txtfile<<name[i]<<'\t'<<score[i]<<endl;
        binfile.write(name[i],8*sizeof(char));
        binfile.write((char *)&score[i],sizeof(float));//why?
    }
    txtfile.close();
    binfile.close();
    return 0;
}