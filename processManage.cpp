#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
struct jincheng_type
{ 
	int pid;
	int youxian;
	int daxiao;
};//进程模拟。
struct jincheng_type jiuxu[20];//就绪数组。

struct jincheng_type guaqi[20];//挂起数组。

struct jincheng_type cpu;//运行进程。

int shumu1=0,shumu2=0,first=0;

void create()
{
	if(shumu1>=20)
	{
		printf("\n就绪进程已满,请先删除或挂起进程\n");
	}
	else
	{
		if(first==0)
		{
			printf("\n这是你第一次输入进程信息,它将直接调入CPU运行!");
			printf("\n请输入新进程的pid\n");
			scanf("%d",&cpu.pid);
			printf("请输入新进程的优先级\n");
			scanf("%d",&cpu.youxian);
			printf("请输入新进程的大小\n");
			scanf("%d",&cpu.daxiao);
			first++;
		}
		else
		{
			printf("\n请输入新进程的pid\n");
			scanf("%d",&jiuxu[shumu1].pid);
			printf("请输入新进程的优先级\n");
			scanf("%d",&jiuxu[shumu1].youxian);
			printf("请输入新进程的大小\n");
			scanf("%d",&jiuxu[shumu1].daxiao);
			shumu1++;
		}
	}
}

//新建进程。

void run()
{
	printf("\n现在正在运行的进程的资料如下:\n");
	printf("PID码为:%d;\n优先级为:%d;\n大小为:%d.",cpu.pid,cpu.youxian,cpu.daxiao);
}

//查看运行进程。


void huanchua()
{
	int i,p,m,n,t;
	p=jiuxu[0].youxian;
	for(i=0;i<shumu1;i++)
	{
		if(p>jiuxu[i].youxian)
		{
			p=jiuxu[i].youxian;
		}
	}
	for(i=0;i<20;i++)
	{
		if(p==jiuxu[i].youxian)
		{
			m=cpu.daxiao;
			cpu.daxiao=jiuxu[i].daxiao;
			n=cpu.pid;
			cpu.pid=jiuxu[i].pid;
			t=cpu.youxian;
			cpu.youxian=jiuxu[i].youxian;
			break;
		}
		else continue;
	}
	for(i;i<shumu1-1;i++)
	{
		jiuxu[i].daxiao=jiuxu[i+1].daxiao;
		jiuxu[i].pid=jiuxu[i+1].pid;
		jiuxu[i].youxian=jiuxu[i+1].youxian;
	}
	jiuxu[i].daxiao=m;
	jiuxu[i].pid=n;
	jiuxu[i].youxian=t;
}

void huanchub()
{
	int i,p;
	printf("\n请输入想要挂起的进程的PID码:\n(在以下中选:");
	for(i=0;i<shumu1;i++)
	{
		printf("%d ",jiuxu[i].pid);
	}
	printf(")\n");
	scanf("%d",&p);
	for(i=0;i<shumu1;i++)
	{
		if(p==jiuxu[i].pid)
		{
			guaqi[shumu2].daxiao=jiuxu[i].daxiao;
			guaqi[shumu2].pid=jiuxu[i].pid;
			guaqi[shumu2].youxian=jiuxu[i].youxian;
			shumu2++;
			break;
		}
		else continue;
	}
	for(i;i<shumu1;i++)
	{
		jiuxu[i].daxiao=jiuxu[i+1].daxiao;
		jiuxu[i].pid=jiuxu[i+1].pid;
		jiuxu[i].youxian=jiuxu[i+1].youxian;
	}			
	shumu1--;
}


void huanchuc()
{
	int i;
	jiuxu[shumu1].daxiao=guaqi[0].daxiao;
	jiuxu[shumu1].pid=guaqi[0].pid;
	jiuxu[shumu1].youxian=guaqi[0].youxian;
	shumu1++;
	for(i=0;i<shumu2;i++)
	{
		guaqi[i].daxiao=guaqi[i+1].daxiao;
		guaqi[i].pid=guaqi[i+1].pid;
		guaqi[i].youxian=guaqi[i+1].youxian;
	}
	shumu2--;
}

void huanchud()
{
	int i,p,m,n,t;
	printf("\n请输入想要运行的进程的PID码:\n(在以下中选:");
	for(i=0;i<shumu1;i++)
	{
		printf("%d ",jiuxu[i].pid);
	}
	printf(")\n");
	scanf("%d",&p);
	for(i=0;i<shumu1;i++)
	{
		if(p==jiuxu[i].pid)
		{
			m=cpu.daxiao;
			cpu.daxiao=jiuxu[i].daxiao;
			jiuxu[i].daxiao=m;
			n=cpu.pid;
			cpu.pid=jiuxu[i].pid;
			jiuxu[i].pid=n;
			t=cpu.youxian;
			cpu.youxian=jiuxu[i].youxian;
			jiuxu[i].youxian=t;
			break;
		}
		else continue;
	}
}


void huanchue()
{
	int i,p;
	printf("\n请输入想要调入就绪的进程的PID码:\n(在以下中选:");
	for(i=0;i<shumu2;i++)
	{
		printf("%d ",guaqi[i].pid);
	}
	printf(")\n");
	scanf("%d",&p);
	for(i=0;i<shumu2;i++)
	{
		if(p==guaqi[i].pid)
		{
			jiuxu[shumu1].daxiao=guaqi[i].daxiao;
			jiuxu[shumu1].pid=guaqi[i].pid;
			jiuxu[shumu1].youxian=guaqi[i].youxian;
			break;
		}
		else continue;
	}
	shumu1++;
	for(i;i<shumu2;i++)
	{
		guaqi[i].daxiao=guaqi[i+1].daxiao;
		guaqi[i].pid=guaqi[i+1].pid;
		guaqi[i].youxian=guaqi[i+1].youxian;
	}
	shumu2--;
}

//交换进程的原码。


void huanchu()
{
	int a;
	printf("请你选择需要的交换方式:\n");
	printf("1.将优先级高的进程调入CPU执行.\n");
	printf("2.手动将进程挂起.\n");
	printf("3.将挂起的进程按先如先出的方式调入就绪队列.\n");
	printf("4.手动将就绪进程调入CPU执行.\n");
	printf("5.手动将挂起的进程调入就绪队列.\n");
	scanf("%d",&a);
	switch(a)
	{
	case 1: huanchua();break;
	case 2: huanchub();break;
	case 3: huanchuc();break;
	case 4: huanchud();break;
	case 5: huanchue();break;
	default:break;
	}
}

//换入换出实现函数。

void del()
{
	int i,p;
	printf("\n请输入想要删除的进程的PID码:\n(在以下中选:");
	for(i=0;i<shumu2;i++)
	{
		printf("%d ",guaqi[i].pid);
	}
	printf(")\n");
	scanf("%d",&p);
	for(i=0;i<shumu2;i++)
	{
		if(p==guaqi[i].pid)
		{
			for(i;i<shumu2;i++)
			{
				guaqi[i].daxiao=guaqi[i+1].daxiao;
				guaqi[i].pid=guaqi[i+1].pid;
				guaqi[i].youxian=guaqi[i+1].youxian;
			}			
			shumu1--;
			break;
		}
		else continue;
	}
}

//删除进程。



void main()
{
    int n;
    char a;
    n=1;
    while(n==1)
	{
		printf("\n********************************************");
		printf("\n*               进程演示系统               *");
		printf("\n*    1.创建新的进程      2.查看运行进程    *");
		printf("\n*    3.换出某个进程      4.删除某个进程    *");
		printf("\n*    5.退出演示系统                        *");
		printf("\n********************************************");
		printf("\n请选择（1～5）");
		a=getche();
		switch(a)
		{
		case'1':create();break;
		case'2':run();break;
	    case'3':huanchu();break;
	    case'4':del();break;
	    case'5':exit(0);
	    default:printf("输入有错!\n");break;
		}
		printf("\n********************************************");
	}
}

//主实现函数。