#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	struct Node *lchild,*rchild;
}TreeNode,*pTreeNode;

pTreeNode createBTree(int i,int n)  //创建以i为根节点的子树,同时把树的根节点的地址返回出去
{
	if(i<=n)
	{
		pTreeNode p = new TreeNode;//创建根节点
		p->data = i;
		pTreeNode pl = createBTree(2*i,n);//递归创建左子树
		pTreeNode pr = createBTree(2*i+1,n);//递归创建右子树
		p->lchild = pl;
		p->rchild = pr;
		return p;
	}
	else
		return NULL;//递归结束的条件i<n
}

void preOrder (pTreeNode pt)
{
	if(pt)
	{
		cout<<pt->data<<" ";
		preOrder(pt->lchild);
		preOrder(pt->rchild);
	}
}


void inOrder(pTreeNode pt)
{
	if(pt)
	{
		inOrder(pt->lchild);
		cout<<pt->data<<" ";
		inOrder(pt->rchild);
	}
}

void postOrder(pTreeNode pt)
{
	if(pt)
	{
		postOrder(pt->lchild);
		postOrder(pt->rchild);
		cout<<pt->data<<" ";
	}
}

int main()
{
	pTreeNode pt = createBTree(1,6);
	preOrder(pt);
	cout<<endl;
	inOrder(pt);
	cout<<endl;
	postOrder(pt);
	cout<<endl;

    return 0;
}
