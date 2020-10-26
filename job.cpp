#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

struct work
{
    char name[30];
    int Ctime;    // 进入
    int Rtime;    // 运行
    int Stime;    // 开始
    int Etime;    // 结束
    int Ttime;    // 周转时间
    double Qtime; // 带权周转时间
};
void FCFS(vector<work> list);
void SJF(vector<work> list);
void HRN(vector<work> list);
void chooseAlgorithm(vector<work>& list);
void inputJobData(){
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
    vector<work> list(n);
    for (int i = 0; i < n; i++)
    {
        printf("输入作业的名字\n");
        scanf("%s", list[i].name);
        printf("输入作业进入的时间\n");
        scanf("%d:%d", &h, &m);
        list[i].Ctime = h * 60 + m;
        printf("输入作业运行的时间\n");
        scanf("%d", &list[i].Rtime);
        file.write((char *)&list[i], sizeof(list[i]));
    }
    // save data
    file.close();
    chooseAlgorithm(list);
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
void chooseAlgorithm(vector<work>& list){
    bool flag = true;
    int op2;
    while (flag)
    {
        printf("选择调度算法(输入数字):1.FCFS, 2.SJF, 3.HRN 4.exit\n");
        scanf("%d", &op2);

        switch (op2)
        {
        case 1:
            FCFS(list);
            break;
        case 2:
            SJF(list);
            break;
        case 3:
            HRN(list);
            break;
        case 4:
            flag = false;
            break;
        default:
            printf("错误输入\n");
            flag = false;
            break;
        }
    }
}

void show(vector<work> list)
{
    printf("\n作业   进入时间  估计运行时间  开始时间 结束时间 周转时间 带权周转时间\n");
    for (int i = 0; i < list.size(); i++)
    {
        printf("%s   ", list[i].name);
        printf("%2d:%02d        ", list[i].Ctime / 60, list[i].Ctime % 60);
        printf("%3d     ", list[i].Rtime);
        printf("%2d:%02d    ", list[i].Stime / 60, list[i].Stime % 60);
        printf("%2d:%02d      ", list[i].Etime / 60, list[i].Etime % 60);
        printf("%3d      ", list[i].Ttime);
        printf("%.2f\n", list[i].Qtime);
    }
}

bool cmp(work a, work b)
{
    return a.Ctime < b.Ctime;
}
void FCFS(vector<work> list)
{
    sort(list.begin(), list.end(), cmp);
    int lastEtime = list[0].Ctime;
    for (int i = 0; i < list.size(); i++)
    {
        list[i].Stime = max(lastEtime, list[i].Ctime);
        list[i].Etime = list[i].Stime + list[i].Rtime;
        list[i].Ttime = list[i].Etime - list[i].Ctime;
        list[i].Qtime = (double)list[i].Ttime / list[i].Rtime;
        lastEtime = list[i].Etime;
    }
    show(list);
}
void SJF(vector<work> list)
{
    sort(list.begin(), list.end(), cmp);
    int lastEtime = list[0].Ctime;
    int n = list.size();
    bool vis[10] = {0};
    for(int i = 0; i < n; i++){
        int cur = 0;
        for(int j = 0; j < n; j++){
            if(vis[j])
                continue;
            if(list[j].Ctime > lastEtime)
                continue;
            if(list[j].Rtime < list[cur].Rtime)
                cur = j;
        }
        list[cur].Stime = lastEtime;
        list[cur].Etime = list[cur].Stime + list[cur].Rtime;
        list[cur].Ttime = list[cur].Etime - list[cur].Ctime;
        list[cur].Qtime = (double)list[cur].Ttime / list[cur].Rtime;
        lastEtime = list[cur].Etime;
        vis[cur] = 1;
    }
    show(list);
}
void HRN(vector<work> list)
{
    sort(list.begin(), list.end(), cmp);
    int lastEtime = list[0].Ctime;
    int n = list.size();
    bool vis[10] = {0};
    for(int i = 0; i < n; i++){
        // 每次都以0进入的原因 除了0有更好的值吗
        int cur = 0;
        for(int j = 0; j < n; j++){
            if(vis[j])
                continue;
            if(list[j].Ctime > lastEtime)
                continue;
            double jR = 1 + (lastEtime - list[j].Ctime)/(double)list[j].Rtime;
            double curR = 1 + (lastEtime - list[cur].Ctime)/(double)list[cur].Rtime;
            if(jR > curR)
                cur = j;
        }
        list[cur].Stime = lastEtime;
        list[cur].Etime = list[cur].Stime + list[cur].Rtime;
        list[cur].Ttime = list[cur].Etime - list[cur].Ctime;
        list[cur].Qtime = (double)list[cur].Ttime / list[cur].Rtime;
        lastEtime = list[cur].Etime;
        vis[cur] = 1;
    }
    show(list);
}


int main()
{
    int op1;
    printf("选择数据的来源:1.文件 2.输入\n");
    scanf("%d", &op1);
    switch (op1)
    {
    case 1:
        readFromFile();
        break;
    case 2:
        inputJobData();
        break;
    default:
        printf("输入不合法\n");
        break;
    }
      
    return 0;
}
