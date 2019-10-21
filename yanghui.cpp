#include <iostream>
using namespace std;

const int QUEUE_INIT_SIZE = 100;
const int QUEUEINITCREMENT= 10;

typedef int QElemType;
typedef struct {
    QElemType *elem;
    int front;
    int rear;
    int queuesize;
    int incrementsize;
}SqQueue;
//为什么传的是地址，之后再想一想！
void InitQueue_Sq(SqQueue &Q,int maxsize=QUEUE_INIT_SIZE,int incresize=QUEUEINITCREMENT){
    Q.elem=new QElemType[maxsize+1];

    Q.queuesize=maxsize+1;
    Q.incrementsize=incresize;
    Q.front=Q.rear=0;//对rear和front设置一个初始值，这个值会被覆盖么，还是指向下一个
    //这仅仅是一个索引，该位置储存的为有效值
}
int QueueLength_Sq(SqQueue Q){
    return (Q.rear-Q.front+Q.queuesize)%Q.queuesize;
}
bool DeQueue_Sq(SqQueue &Q,QElemType &e){//有点神奇，效果好像和return是一样的
    if(Q.front==Q.rear) return false;
    e=Q.elem[Q.front];
    Q.front = (Q.front+1)%Q.queuesize;
    return true;
}
//扩容操作；
void incrementQueuesize(SqQueue &Q){
    QElemType *a;//指针与数组的关系。书中用的数组，但此处有报错，类型不完整
    a = new QElemType[Q.queuesize+Q.incrementsize];
    for(int k=0;k<Q.queuesize-1;k++){
        a[k]=Q.elem[(Q.front+k)%Q.queuesize];
    }//beacuse索引值和原先不一样了，front和原来的指向已经不一样了，为了保持一致。。。
    delete[] Q.elem;
    Q.elem = a;
    Q.front = 0;//设置新的头指针//这个必须么？增添元素是在尾部增加的，头部不是没影响么，why
    Q.rear = Q.queuesize-1;//设置新的尾指针
    Q.queuesize += Q.incrementsize;
}
void EnQueue_Sq(SqQueue &Q,QElemType e){
    if((Q.rear+1)%Q.queuesize==Q.front) incrementQueuesize(Q);
    Q.elem[Q.rear]=e;
    Q.rear=(Q.rear+1)%Q.queuesize;
}

void GetHead_Sq(SqQueue &Q,QElemType &e){
    e = Q.elem[Q.front];
}
bool QueueEmpty(SqQueue &Q){
     Q.front == QueueLength_Sq(Q);
}
void Yanghui(int n){
    SqQueue Q;
    QElemType e,s;
    for(int i=1;i<=n;i++) cout<<' ';
    cout<<'1'<<endl;
    InitQueue_Sq(Q,n+2);
    EnQueue_Sq(Q,0);
    EnQueue_Sq(Q,1);
    EnQueue_Sq(Q,1);
    int k=1;
    while(k<n){
        for(int i=1;i<n-k;i++) cout<<' ';
        EnQueue_Sq(Q,0);
        do{
            DeQueue_Sq(Q,s);
            GetHead_Sq(Q,e);
            if(e) cout<<e<<' ';
            else cout<<endl;
            EnQueue_Sq(Q,s+e);
        }while(e!=0);
        k++;
    }
    DeQueue_Sq(Q,e);//把标志符号0出队不输出
    while(!QueueEmpty(Q)){      //单独处理第n行的输出
        DeQueue_Sq(Q,e);
        cout<<e<<' ';
    }
}
int main(){
    Yanghui(10);
    return 0;
}