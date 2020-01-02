#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode{ 
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList CreatList(LNode*);
void Sort(LNode*);
void Print(LNode*);

int main(int argc, char* argv[])
{
    LNode *head;
    head=(LNode*)malloc(sizeof(LNode));
    head->next=NULL;

    head=CreatList(head);
    Print(head);
    Sort(head);
    Print(head);

    return 0;
}
//头插法创建单链表
LinkList CreatList(LNode* head)
{
    LNode *L;
    ElemType x;
    scanf("%d",&x);
    while(x!=999){
        L=(LNode*)malloc(sizeof(LNode));
        L->data=x;
        L->next=head->next;
        head->next=L;
        scanf("%d",&x);
    }
    return head;
}
//直接插入排序
void Sort(LNode *head)
{
    LNode *pre=head;
    LNode *p=pre->next;
    LNode *q=p->next;
    p->next=NULL;
    p=q;
    while(q){
        q=p->next;
        pre=head;
        while(pre->next!=NULL&&pre->next->data<p->data){
            pre=pre->next;
        }
        p->next=pre->next;
        pre->next=p;
        p=q;
    }
}
//打印全部结点
void Print(LNode *head)
{
    LNode *p=head->next;
    while(p){
        printf("%4d",p->data);
        p=p->next;
    }
    printf("\n");
}