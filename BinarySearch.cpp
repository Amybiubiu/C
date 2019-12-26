#include <iostream>
using namespace std;
#define NUM 10

void heappass(int st[NUM],int i,int m)
{

    int tmp = st[i];//先取出当前元素i
    for(int k=i*2+1;k<m+1;k=k*2+1){//从i结点的左子结点开始，也就是2i+1处开始
        if(k+1<m+1 && st[k]<st[k+1]){//如果左子结点小于右子结点，k指向右子结点
            k++;
        }
        if(st[k] >tmp){//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
            st[i] = st[k];
            i = k;
        }else{
            break;
        }
    }
    st[i] = tmp;//将temp值放到最终的位置
}

void heapsort(int st[NUM],int n)//n = NUM-1 从调用情况来看！
{
	int i,tmp;
	for(i=n/2;i>=0;i--)// //从第一个非叶子结点从下至上，从右至左调整结构
		heappass(st,i,n);
	for(i=n;i>=0;i--)
	{
		tmp = st[0];
		st[0] = st[i];
		st[i] = tmp;
		heappass(st,0,i-1);
	}
}

int BSearch1(int st[NUM],int n,int key)
{
	int mid,low,high;
	low = 0;
	high = n;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(st[mid]==key) return mid;
		if(key<st[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

int BSearch2(int st[NUM],int low,int high,int key)
{
	int mid;
	if(low>high) return 0;
	mid = (low+high)/2;
	if(st[mid] == key) return mid;
	if(key<st[mid])
		return BSearch2(st,low,mid-1,key);
	else
		return BSearch2(st,mid+1,high,key);
}

int main()
{
	int i;
	int st[NUM+1] = {-1,5,7,3,2,8,9,0,4,1,6};
	heapsort(st,NUM);
	for(i=0;i<=NUM;i++)
		cout<<st[i]<<" ";
	cout<<endl;

	i = BSearch1(st,NUM,9);
	cout<<i<<endl;
	i = BSearch2(st,0,NUM,9);
	cout<<i<<endl;

    return 0;
}
