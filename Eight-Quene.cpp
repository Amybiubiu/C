#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define NUM 8

typedef struct
{
   char *elem;
   int top;
   int stacksize;
}stack,*pstack;

void initiStack(pstack s)
{
   s->elem = (char*)malloc(sizeof(char)*NUM);
   s->top = -1;
   s->stacksize = NUM;
}

void push (pstack s,char e)
{
   if(s->top==s->stacksize-1)
   {
   printf("stack full\n");
   return;
   }
   s->elem[++s->top]=e;
}

void pop(pstack s,char *e)
{
   if(s->top==-1)
   {
      printf("stack empty\n");
	  return;
   }
   *e=s->elem[s->top--];
}

int stackEmpty(pstack s)
{
    if(s->top==-1)
		return 1;
    return 0;
}

int stackFull(pstack s)
{
   if(s->top== s->stacksize-1)
	   return 1;
   return 0;
}

int canPut(pstack s, int e)//在第top+1行的第e列放置皇后是否会冲突
{
    int i=0;
	for(i=0;i<=s->top;i++)
	{
	   if(s->elem[i]==e||abs(s->elem[i]-e)==abs(i-(s->top+1)))//列和行是否有冲突
		   return 0;
	}
	return 1;
}

void displayResult(pstack s)
{
   int i;
   for(i=0;i<=s->top;i++)
   {
      printf("%d",s->elem[i]);
   }
   printf("\n");
}

int main()
{
	stack s;
	char col=-1;//定义列下标
	initiStack(&s);
	while(1)//无限循环，在运行过程中判断是否要退出循环
	{
	   col++;
	   while(col<NUM && !canPut(&s,col))//存在可以放置的列，同时判断是否可以放
	   {
	      col++;
	   }
	   if(col<NUM && !stackFull(&s))
	   {
	      push(&s,col);//如果top+1行可以在第col列放置，则入栈
	      if(stackFull(&s))//栈满说明找到解
		  {
		    displayResult(&s);
			return 0;
		  }
		  col=-1;//重置列下标，在下一行找
	   }
        if(col>=NUM)//如果第top+1行已经没有可以放置的列，需要回溯
		{
		  if(stackEmpty(&s))//栈空，无路可退
		  {
		    printf("no solution\n");
			return 0;
		  }
		  pop(&s,&col);
		}
	}
    return 0;

}