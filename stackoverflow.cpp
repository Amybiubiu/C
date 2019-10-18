//
//  main.cpp
//  cpp_test
//
//  Created by mac on 2019/9/29.
//  Copyright © 2019 mac. All rights reserved.
//

# include <iostream>
using namespace std;

class Student {
private:
    char *Name;
    int No;
    static int countS;
public:
    static int GetCount(){
        return countS;
    }
    Student(char * ="",int = 0);
    Student(Student &);
    ~Student();
};
Student::Student(char *Name,int No){
    this->Name = new char [strlen(Name)+1];
    strcpy(this->Name,Name);
    this->No= No;
    ++countS;
    cout<<"constructing:"<<Name<<endl;
}
Student::Student(Student &r){
    Name = new char[strlen(r.Name)+1];
    strcpy(Name,r.Name);
    No=r.No;
    ++countS;
    cout<<"copy constructing:"<<r.Name<<endl;
}
Student::~Student(){
    cout<<"destructing:"<<Name<<endl;
    delete [] Name;
    --countS;
}
int Student::countS=0;
int main(){
    cout<<Student::GetCount()<<endl;
    Student s1("Antony");
    cout<<s1.GetCount()<<endl;
    Student s2(s1);
    cout<<s1.GetCount()<<endl;
    Student S3[2];
    cout<<Student::GetCount()<<endl;
    Student *s4 = new Student[3];
    cout<<Student::GetCount()<<endl;
    delete [] s4;
    cout<<Student::GetCount()<<endl;
    return 0;
}
