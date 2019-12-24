//              0, 1, 1, 1, 0, 0,
//              1, 0, 0, 0, 1, 0,
//              1, 0, 0, 0, 1, 0,
//              1, 0, 0, 0, 0, 1,
//              0, 1, 1, 0, 0, 0,
//              0, 0, 0, 1, 0, 0
// DFS 1-2-5-3-4-6   2-1-3-5-4-6   3-1-2-5-4-6   4-1-2-5-3-6

#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 100
#define NUM 6
typedef struct {
	int* elem;   
	int top;    
	int stacksize;  
}stack, * pstack;

void initStack(stack& s) {
	s.elem = new int[STACK_INIT_SIZE];   
	s.top = -1;
	s.stacksize = STACK_INIT_SIZE;
}

void push(stack& s, int e) {
	if (s.top == s.stacksize - 1) {
		printf("stack full\n");
		return;
	}
	s.elem[++s.top] = e;
}

void pop(stack& s, int& e) {
	if (s.top == -1) {
		printf("stack empty\n");
		return;
	}
	e = s.elem[s.top--];
}

int stackEmpty(stack& s) {
	if (s.top == -1)
		return 1;
	return 0;
}

//构成矩阵的单元，adj 1 相接，否则 不想接。
typedef struct ArcCell 
{
	int adj;
	char* info;
}ArcCell, AdjMatrix[NUM][NUM];

//图 有储存元素的数组vexs和表示元素关系矩阵arcs；
typedef struct
{
	char vexs[NUM];
	AdjMatrix arcs;
}Mgraph;

void DFS(Mgraph& mg, int n, int* output)  
{
	int visited[NUM] = { 0 };
	int i, j, p = n - 1;
	stack st;
	initStack(st);
	push(st, p);   
	output[0] = p;
	visited[p] = 1;
	i = 1;
    //mg.vexs[output[i]] vexs为储存元素的数组，output[i]对应索引
	while (i < NUM)
	{
		for (j = 0; j < NUM; j++)  
		{
			if (!visited[j] && mg.arcs[p][j].adj == 1)//找 p为5第五行与第五号元素临接且未被访问 的
				break;
		}
		if (j < NUM)   
		{
			p = j;
			push(st, p);
			output[i++] = p;//找到了 为第j号元素，将临接元素的j这个索引入栈
			visited[p] = 1;//并更改为该j号元素已被访问
		}//找完第一个临接元素，跳入下一层while循环继续寻找写一个临接元素。
		else  
		{
			if (!stackEmpty(st))
				pop(st, p);//栈的作用在于回溯，例如在此例中，遍历到3的时候就要不断回退到1，找1第二个相邻点。
			else
				return;//结束标志。
		}

	}
	return;
}

int main()
{
	int matrix[NUM][NUM] = { 0,1,1,1,0,0,
							1,0,0,0,1,0,
							1,0,0,0,1,0,
							1,0,0,0,0,1,
							0,1,1,0,0,0,
							0,0,0,1,0,0 };
	Mgraph mg;
	int output[NUM];
	int i, j;
	for (i = 0; i < NUM; i++)
	{
		for (j = 0; j < NUM; j++)
		{
			mg.arcs[i][j].adj = matrix[i][j];
		}
	}
	for (i = 0; i < NUM; i++)
		mg.vexs[i] = '1' + i;
	for (i = 0; i < NUM; i++)
		output[i] = -1;
	DFS(mg, 1, output);
	for (i = 0; i < NUM && output[i] != -1; i++)
		cout << mg.vexs[output[i]] << " ";
	cout << endl;

	return 0;
}
