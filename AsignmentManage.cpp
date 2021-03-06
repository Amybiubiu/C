#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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

void input(int n, vector<work>& list){
    fstream file;
    int h, m;
    for (int i = 0; i < n; i++)
    {
        printf("输入作业的名字\n");
        scanf("%s", list[i].name);
        printf("输入作业进入的时间\n");
        scanf("%d:%d", &h, &m);
        list[i].Ctime = h * 60 + m;
        printf("输入作业运行的时间\n");
        scanf("%d", &list[i].Rtime);
    }
    // save data
    file.open("job.dat", ios::out | ios::binary | ios::trunc );
    file.write((char *)&list, sizeof(list));
    file.close();
}

int main()
{
    int n = 0;
    printf("输入作业数量\n");
    scanf("%d", &n);

    vector<work> list(n);
    int op1,op2;
    fstream file;
    int length =  0;
    // 逻辑混乱 如果先前的n和文件中的空间不匹配呢？？
    printf("选择数据的来源:1.文件 2.输入\n");
    scanf("%d", &op1);
    switch (op1)
    {
    case 1:
        file.open("job.dat", ios::in | ios::binary);
        // get length of file
        file.seekg(0, file.end);
        length = file.tellg();
        file.seekg(0, file.beg);
        // (char *) ?? vector<work>*
        file.read((char *)&list2, length);
        file.close();
        break;
    case 2:
        input(n, list);
        break;
    default:
        printf("输入不合法\n");
        break;
    }
    
    bool flag = true;
    while (flag)
    {
        printf("选择调度算法(输入数字):1.FCFS, 2.SJF, 3.HRN 4.exit\n");
        scanf("%d", &op2);

        switch (op2)
        {
        case 1:
            FCFS(list2);
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
            break;
        }
    }
    return 0;
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
        int cur = 0;
        for(int j = 0; j < n; j++){
            if(vis[j])
                continue;
            if(list[j].Ctime > lastEtime)
                continue;
            double rCur = 1 + (lastEtime - list[cur].Ctime)/list[cur].Rtime;
            double rJ = 1 + (lastEtime - list[j].Ctime)/list[j].Rtime;
            if(rJ < rCur)
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