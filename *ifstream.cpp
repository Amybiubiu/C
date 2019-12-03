#include <fstream>
#include <iostream>
using namespace std;

int main(){
    char name1[8],name2[8];
    float score1,score2;
    int rec_num,rec_size,i;
    fstream binfile("/Users/mac/Desktop/rails/record.dat",ios::out|ios::in|ios::binary);
    if(!binfile){
        cout<<"open record.dat error"<<endl;
        exit(1);
    }
    rec_size = sizeof(float)+ 8*sizeof(char);
    binfile.seekg(0,ios::end);
    rec_num = binfile.tellg()/rec_size;
    for (int i = 0; i < rec_num / 2; i++) {
        binfile.seekg((long)i * rec_size, ios::beg);
        binfile.read((char*)name1, 8 * sizeof(char));
        binfile.read((char*)&score1, sizeof(float));//why?
        binfile.seekg(-(long)(i + 1) * rec_size, ios::end);
        binfile.read((char*)name2, 8 * sizeof(char));
        binfile.read((char*)&score2, sizeof(float));
        binfile.seekp((long)i * rec_size, ios::beg);
        binfile.write((char*)name2, 8 * sizeof(char));
        binfile.write((char*)&score2, sizeof(float));
        binfile.seekp(-(long)(i + 1) * rec_size, ios::end);
        binfile.write((char*)name1, 8 * sizeof(char));
        binfile.write((char*)&score1, sizeof(float));
    }
    binfile.seekg(rec_num, ios::end);
//    for (i = 0; i < rec_num; i++) {
//        binfile.read((char*)name1, 8 * sizeof(char));
//        binfile.read((char*)&score1, sizeof(float));
//        cout << name1 << '\t' << score1 << endl;
//    }
    while(!binfile.eof()){
        binfile.read((char*)name1, 8 * sizeof(char));
        binfile.read((char*)&score1, sizeof(float));//why?
        cout << name1 << '\t' << score1 << endl;
    }
    binfile.close();
    
    return 0;
}

//atony 85.5
//tom 60
//输出有问题 可是确实会翻转了顺序