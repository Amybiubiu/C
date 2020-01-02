/*  chenshu@mail.ccnu.edu.cn  */


#include <iostream>
#include <iomanip>

using namespace std;

#define NUM 12
#define MOD 13
#define HASHSIZE 16

void collision(int &p,int c)
{
	p = (p+1)%HASHSIZE;
}

int hashsearch(int ht[HASHSIZE],int key,int &p,int &c,void(*cp)(int &,int))
{
	p = key % MOD;//null不可转换为int型，那把null改为-1，为什么程序一直在while循环内出不来？
	while(ht[p]!= NULL && ht[p]!=key)//null 该地址为空，可储存，//哈希表中有一个相同的元素
	{
		cp(p,++c);
	}
	if(ht[p]==key)//如果是有一个相同元素
		return 1;
	else
		return 0;
}

int insertHash(int ht[HASHSIZE],int key)
{
	int p,c=0;
	if(hashsearch(ht,key,p,c,collision)==1)
		return 0;
	else if(c<=HASHSIZE/2)//找到一个合适的储存位置。且冲突次数少于哈希表长的一半。
	{
		ht[p] = key;//储存
		return 1;
	}
	else
		return -1;//冲突太大了不插入
}

int main()
{
	int i;
	int ht[HASHSIZE] = {NULL};//给第一个元素赋值，其他元素为空。
	int a[NUM] = {19,14,23,1,68,20,84,27,55,11,10,79};
	for(i=0;i<NUM;i++){
         insertHash(ht,a[i]);
    }
		
	for(i=0;i<HASHSIZE;i++)
		cout<<setw(3)<<left<<i;
	cout<<endl;
	for(i=0;i<HASHSIZE;i++)
		cout<<setw(3)<<left<<ht[i];
	cout<<endl;

    return 0;
}
