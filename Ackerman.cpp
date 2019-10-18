#include <iostream>
using namespace std;

typedef struct {
	int nval;
	int xval;
	int yval;
}ElemType;
typedef struct LNode 
{
	ElemType data;
	struct LNode *next;
}LNode,* LinkList;
typedef LinkList LinkStack;

void InitStack(LinkStack &S){
     S = NULL;
}
void Push(LinkStack &S,ElemType e){
	LinkStack p;
	p = new LNode;
	p->data = e;
	p->next = S;//前插
	S = p;
}

bool Pop(LinkStack &S,ElemType &e){
	if(S){
		LinkStack p;
		p = S;
		S = S->next;//结合P89的图看，你就能明白为什么是next；
		e = p->data;
		delete p;
		return true;
	}else
	return false;
}

int value(int n,int x,int y){
	if(n == 0)
	return x+1;
	else{
		switch(n){
			case 1: return x;
			case 2: return 0;
			case 3: return 1;
			default: return 2;
		}
	}
}
int Ackerman(int n,int x,int y){
	LinkStack S;
	InitStack(S);
	ElemType e;
	e.nval = n;
	e.xval = x;
	e.yval = y;
	int u;
	Push(S,e);
	do{
		while(e.yval != 0 && e.nval != 0){
			e.yval -= 1;
			Push(S,e);
		}
		Pop(S,e);
		u = value(e.nval,e.xval,e.yval);
		if(S){
			Pop(S,e);
			e.nval -= 1;
			e.yval = e.xval;
			e.xval = u;
			Push(S,e);
		}

	}while((S));
	cout<<u<<endl;
	return u;
}
int main(){
	Ackerman(3,2,1);
	return 0;
}