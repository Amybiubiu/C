#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector> 

using namespace std;
const int block_time=10; //定义时间片的长度为10秒
const int MAXPCB=10; //定义最大进程数
 
 
//定义进程结构体
typedef struct node {
    char name[20];
    int status;
    int time;
    int privilege;
 
    int finished;
    int wait_time;
} pcb;
 
pcb pcbs[MAXPCB];
int number = 0;  // 输入进程的数量
 
//初始化函数
void initial() {
    int i;
 
    for ( i=0; i<MAXPCB; i++ ) {
        strcpy ( pcbs[i].name,"" );
        pcbs[i].status=0;
        pcbs[i].time=0;
        pcbs[i].privilege=0;
 
        pcbs[i].finished=0;
        pcbs[i].wait_time=0;
    }
 
    number=0;
}
 
//读数据函数
int readData() {
    FILE *fp;
    // char fname[20];
    int i;
 
    // cout<<"请输入进程流文件名:";
    // cin>>fname;
    if ( ( fp=fopen ("process.dat" ,"r" ) ) ==NULL ) {
        cout<<"错误,文件打不开,请检查文件名"<<endl;
    } else {
        while ( !feof ( fp ) ) {
            fscanf ( fp,"%s %d %d %d",pcbs[number].name,&pcbs[number].status,&pcbs[number].time,&pcbs[number].privilege );
            number++;
        }
 
//输出所读入的数据
        cout<<"输出所读入的数据"<<endl;
        cout<<"进程名 进程状态 所需时间 优先数"<<endl;
        for ( i=0; i<number; i++ ) {
            cout<<" "<<pcbs[i].name<<"     "<<pcbs[i].status<<"     "<<pcbs[i].time<<"       "<<pcbs[i].privilege<<endl;
        }
        return ( 1 );
    }
    return ( 0 );
 
}
 
//重置数据,以供另一个算法使用
void reset() {
    int i;
 
    for ( i=0; i<MAXPCB; i++ ) {
 
        pcbs[i].finished=0;
        pcbs[i].wait_time=0;
    }
}
 
 
//先进先出算法
void FIFO() {
    int i,j;
    int total;
 
//输出FIFO算法执行流
    cout<<endl<<"---------------------------------------------------------------"<<endl;
    cout<<"FIFO算法执行流:"<<endl;
    cout<<"进程名 等待时间"<<endl;
    for ( i=0; i<number; i++ ) {
        cout<<" "<<pcbs[i].name<<" "<<pcbs[i].wait_time<<endl;
        if(i+1 < number)
            pcbs[i+1].wait_time = pcbs[i].wait_time + pcbs[i].time;
    }
    total=0;
    for ( i=0; i<number; i++ ) {
        total+=pcbs[i].wait_time;
    }
    cout<<"总等待时间:"<<total<<" 平均等待时间:"<<total/number<<endl;
 
}
 
//优先数调度算法
void privilege() {
    int i,j,p;
    int passed_time=0;
    int total;
 
    
    int current_privilege=1000;
 
    cout<<endl<<"---------------------------------------------------------------"<<endl;
    cout<<"优先数调度执行流:"<<endl;
    cout<<"进程名 等待时间"<<endl;
    for ( i=0; i<number; i++ ) {
        current_privilege=1000;
        for ( j=0; j<number; j++ ) {
            if ( ( pcbs[j].finished==0 ) && ( pcbs[j].privilege<current_privilege ) ) {
                p=j;
                current_privilege=pcbs[j].privilege;
            }
        }
        pcbs[p].finished=1;
        pcbs[p].wait_time+=passed_time;
        passed_time+=pcbs[p].time;
        cout<<" "<<pcbs[p].name<<" "<<pcbs[p].wait_time<<endl;  //输出优先数调度执行流

    }

 
    total=0;
    for ( i=0; i<number; i++ ) {
        total+=pcbs[i].wait_time;
    }
    cout<<"总等待时间:"<<total<<" 平均等待时间:"<<total/number<<endl;
 
}
 
//时间片轮转调度算法
void timer(){
    int round = 0; // process上cpu的最多次数
    vector<int> remain_time(number, 0);  // 记录还需执行的时间长度
    // vector<char*> record(number);
    int max_time = pcbs[0].time;
    int passed_time = 0;
    for(int i = 0; i < number; i++){
        remain_time[i] = pcbs[i].time;
        if(pcbs[i].time > max_time)
            max_time = pcbs[i].time;
    }
    // 如果最大值非常大 后面的几个循环没有必要 怎么处理
    // 建立一个queue，执行完毕后移出
    // 每次遍历queue而不是 pcbs。这样也可以把pcbs[i].finished flag去除
    round = max_time / block_time + 1;
    for(int i = 0; i < round; i++){
        for(int j = 0; j < number; j++){
            if(!pcbs[j].finished){
                // record.push_back(pcbs[i].name);
                cout<<pcbs[j].name<<" ";
                if(remain_time[j] <= 10){
                    // to be finished
                    pcbs[j].finished = 1;
                    passed_time += remain_time[j];
                    remain_time[j] = 0; 
                    pcbs[j].wait_time = passed_time - pcbs[j].time;
                }else{
                    passed_time += 10;
                    remain_time[j] -= 10;
                }
            }
        }
    }
    cout << "\n进程名 等待时间" << endl;
    int total = 0;
    for (int i = 0; i < number; i++)
    {
        cout << " " << pcbs[i].name << " " << pcbs[i].wait_time << endl;
        total += pcbs[i].wait_time;
    }
    cout << "总等待时间:" << total << " 平均等待时间:" << total / number << endl;
}

//主函数
int main() {
    initial();
    if ( readData() ) {
        FIFO();
        reset();
 
        privilege();
        reset();
 
        timer();
    }
    return 0;
}
