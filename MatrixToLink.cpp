#include <iostream>
using namespace std;

typedef struct Node
{
    int col;
    int val;
    struct Node* next;
} node,*pNode;
typedef struct
{
    pNode* parray; //元素为链表表头节点(地址的地址)
    int NUMCol;
    int NUMRow;
} LinkMatrix;

void createLinkMatrix(LinkMatrix &L, void* matrix, int numrow, int numcol)
{
    int i, j, e;
    int* newMatrix = (int*)matrix;//将其强制转换为一维指针
    L.parray = new pNode[numrow]; //L.parray一共五条链表
    // 这样申请会导致parry[i]->next 为空，压根不可访问的问题，后面需用到flag处理。
    L.NUMCol = numcol;
    L.NUMRow = numrow;
    
    for (i = 0; i < L.NUMRow; i++){
        L.parray[i]=0; //链表表头初始化
    }
    
    for (i = 0; i < L.NUMRow; i++)
    {
        pNode tail=L.parray[i]; //头节点
        int flag = 1;
        for (j = 0; j < L.NUMCol; j++)
        {
            e =*(newMatrix+i*numcol+j);
            if (  e!= 0)//如何访问的问题
            {
                pNode np = new node;
                np->col = j + 1;
                np->val = e;
                np->next = 0;
                if(flag){
                    L.parray[i]= np;
                    flag = 0;
                }else{
                    tail->next = np;
                }
                tail = np;
            }
        }
    }
}

void displayLinkMatrix(LinkMatrix L)
{
    int i;
    for (i = 0; i < L.NUMRow; i++)
    {
        pNode p = L.parray[i];
        if (p)
        {
            while (p)
            {
                cout <<p->val <<"("<<p->col<<")"<< " ";
                p = p->next;
            }
        }
        cout <<endl;
    }
}

int main()
{
    
    int a[5][5] = {
        {3, 0, 0, 0, 7},
        {0, 0, -1, 0, 0},
        {-1, -2, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 2, 0}};
    LinkMatrix l;
    createLinkMatrix(l, a, 5, 5);
    displayLinkMatrix(l);
    
    return 0;
}
