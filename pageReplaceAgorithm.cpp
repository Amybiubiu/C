/*功能描述：输入可用内存页面数和一个作业访问逻辑页号的序列
*给出FIFO、LRU、OPT算法的缺页中断率
*本程序中设初始页框里的页号与实际页号都不同
*在VC6.0里测试通过
*/
#include<iostream.h>
#define  M  40
int N;
struct Pro
{
	int num,time;
};
int Input(int m,Pro p[M])
{   
	cout<<"请输入实际页数：";
	do
	{
		cin>>m;
		if(m>M)cout<<"数目太多，请重试"<<endl;
		else break;
	}while(1);
    cout<<endl<<"请输入各页面号"<<endl;
   	for(int i=0;i<m;i++)
	{
		cin>>p[i].num;
		p[i].time=0;
	}
	return m;
}

void print(Pro *page1)//打印当前的页面
{
	Pro *page=new Pro[N];
	page=page1;
	for(int i=0;i<N;i++)cout<<page[i].num<<"  ";
	cout<<endl;
}


int  Search(int e,Pro *page1  )
{
	Pro *page=new Pro[N];
	page=page1;
	for(int i=0;i<N;i++)if(e==page[i].num)return i;
	return -1;
}

int Max(Pro *page1)
{
	Pro *page=new Pro[N];
	page=page1;
	int e=page[0].time,i=0;
	while(i<N)//找出离现在时间最长的页面
	{
		if(e<page[i].time)e=page[i].time;
		i++;
	}
    for( i=0;i<N;i++)if(e==page[i].time)return i;
	
	return -1;
}

int Compfu(Pro *page1,int i,int t,Pro p[M])
{
	Pro *page=new Pro[N];
	page=page1;
	
	int count=0;
	for(int j=i;j<M;j++)
	{
		if(page[t].num==p[j].num )break;
		else count++;
	}
	return count;
	
}

int main()
{
    
	cout<<"可用内存页面数"<<endl;
	cin>>N;	
	Pro p[M];
	Pro *page=new Pro[N];
	char c;
	int m=0,t=0;
	float n=0;
	m=Input(m,p);	
	
	do{
		
		for(int i=0;i<N;i++)//初始化页面基本情况
		{
			page[i].num=0;
			page[i].time=2-i;
		}
		/*int j=0,count=1;
		page[0].num=p[0].num;
		int i=1,k=1;
		while(i<N)
		{
		int flag=1;
		for(j=0;j<i;j++)
		if(p[k].num==page[i].num)
		{n++;flag=0;break;}
		if(flag==1){page[i].num=p[k].num;i++;}
		count++;k++;
	}*/
        i=0;		
        cout<<"f:FIFO页面置换"<<endl;
		cout<<"l:LRU页面置换"<<endl;
		cout<<"o:OPT页面置换"<<endl;
		cout<<"按其它键结束"<<endl;
		cin>>c;
		
		if(c=='f')//FIFO页面置换
		{
			n=0;
			cout<<"页面置换情况:   "<<endl;
			while(i<m)
			{
				if(Search(p[i].num,page)>=0)i++;//找到相同的页面
				else 
				{  
					if(t==N)t=0;
					else 
					{
						n++;//
						page[t].num=p[i].num;
						print(page);
						t++;
					}
				}
			}
			cout<<"缺页次数："<<n<<"    缺页率："<<n/m<<endl;      
			
		}
		if(c=='l')//LRU页面置换
		{   

//这里自己写 
		}
		cout<<"缺页次数："<<n<<"    缺页率："<<n/m<<endl; 
		}
		if(c=='o')//OPT页面置换
		{
			n=0;
			while(i<m)
			{
				if(Search(p[i].num,page)>=0)i++;
				else
				{
					int temp=0,cn;
					for(t=0;t<N;t++)
					{
						if(temp<Compfu(page,i,t,p))
						{
							temp=Compfu(page,i,t,p);
							cn=t;
						}
					}
					page[cn]=p[i];
					n++;
					print(page);
					i++;
				}
			}
			cout<<"缺页次数："<<n<<"    缺页率："<<n/m<<endl; 
		}
		
	}while(c=='f'||c=='l'||c=='o');
	
	
	
	return 0;
}


