#include <string>
#include <iostream>
#include <fstream>
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
int count;  // 输入进程的数量
 
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
 
    count=0;
}
 

void inputData(){
    int n = 0;
    printf("输入作业数量\n");
    scanf("%d", &n);

    fstream file;
    file.open("job.dat", ios::out | ios::binary | ios::trunc );
    if (!file)
    {
        //handle the error
        printf("something went wrong: %s", strerror(errno));
        exit(1);
    }
    int h, m;
    for (int i = 0; i < n; i++)
    {
        printf("输入作业的名字\n");
        scanf("%s", pcds[i].name);
        printf("输入作业进入的时间\n");
        scanf("%d:%d", &h, &m);
        list[i].Ctime = h * 60 + m;
        printf("输入作业运行的时间\n");
        scanf("%d", &list[i].Rtime);
        file.write((char *)&list[i], sizeof(list[i]));
    }
    // save data
    file.close();
}

void readFromFile(){
    fstream file;
    file.open("job.dat", ios::in | ios::binary);
    // get length of file
    file.seekg(0, file.end);
    int length = file.tellg();
    // printf("%d\n", length);
    file.seekg(0, file.beg);

    int n = length/sizeof(work);
    // printf("%d\n", n);
    vector<work> list;
    for(int i = 0; i < n; i++){
        work item;
        file.read((char*)&item, sizeof(item));
        list.push_back(item);
    }

    file.close();

    chooseAlgorithm(list);
}

int main(){

}