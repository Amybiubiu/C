#include <string>
#include <iostream>
#include <fstream>

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
}
 

void inputData(){
    int n = 0;
    printf("输入作业数量\n");
    scanf("%d", &n);

    fstream file;
    file.open("process.dat", ios::out | ios::binary | ios::trunc );
    if (!file)
    {
        //handle the error
        printf("something went wrong: %s", strerror(errno));
        exit(1);
    }
    int h, m;
    for (int i = 0; i < n; i++)
    {
        printf("输入进程的名字\n");
        scanf("%s", pcbs[i].name);
        file<<pcbs[i].name<<" "<<pcbs[i].status<<" ";
        // printf("输入作业进入的时间\n");
        // scanf("%d:%d", &h, &m);
        // pcbs[i].time = h * 60 + m;
        // file<<pcbs[i].time;
        printf("输入进程运行的时间\n");
        scanf("%d", &pcbs[i].time);
        file<<pcbs[i].time<<" ";
        
        printf("输入进程的优先级\n");
        scanf("%d", &pcbs[i].privilege);
        file<<pcbs[i].privilege;
    }
    // save data
    file.close();
}

int main(){
    initial();
    inputData();
    return 0;
}