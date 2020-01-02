#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct LinkNode
{
    char data;
    struct LinkNode *next, *prior;
} LNode, *PNode;

void CreateList(PNode *PL)
{
    int i;
    PNode p, q;
    *PL = NULL;
    p = (PNode)malloc(sizeof(LNode));
    p->data = 'Z';
    *PL = p;
    for (i = 1; i < 26; i++)
    {
        q = (PNode)malloc(sizeof(LNode));
        q->data = 'Z' - i;
        q->next = p;
        p->prior = q;
        p = q;
    }
    (*PL)->next = q;
    q->prior = (*PL);
}

int main()
{
    int n, i;
    PNode p, q, PL;
    CreateList(&PL);
    printf("Please input an integer\n");
    scanf("%d", &n);
    p = PL->next;
    if (n > 0)
    {
        for (i = 0; i < n; i++)
        {
            p = p->next;
        }
    }
    else
    {
        for (i = n; i < 0; i++)
        {
            p = p->prior;
        }
    }
    q = p;
    do
    {
        printf("%c", p->data);
        p = p->next;
    } while (p != q);

    return 0;
}
