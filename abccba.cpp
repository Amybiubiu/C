/*
判断回文字符串：将字符串的一般入栈，然后将栈顶元素和后一半的字符串的字符相比较
若相同，则将栈顶元素出栈。当栈最后为空时，说明该字符串是回文字符串。 
*/
#include <stdio.h>
#include <string.h>
#define MAX 100
//定义一个栈
typedef struct
{
    char *base;
    char *top;
    int stacksize;
} SqStack;

//初始化栈
int InitStack(SqStack &S)
{
    S.base = new char[MAX];
    if (!S.base)
    {
        return 0;
    }
    S.top = S.base;
    S.stacksize = MAX;
    return 1;
}

//判断栈是否为空
int IsEmpty(SqStack &S)
{
    if (S.top == S.base)
    {
        return 1; //栈空
    }
    else
    {
        return 0; //栈非空
    }
}

//判断栈是否满
int IsFull(SqStack &S)
{
    if (S.top - S.base == S.stacksize)
    {
        return 1; //栈满
    }
    else
    {
        return 0; //栈空
    }
}

//进栈
int Push(SqStack &S, char e)
{
    if (IsFull(S))
    {
        return 0; //栈满，无法入栈
    }
    *S.top++ = e;
    return 1;
}

int Pop(SqStack &S, char &e)
{
    if (IsEmpty(S))
    {
        return 0; //栈空，无法出栈
    }
    e = *--S.top;
    return 1;
}

/*
算法思想：
1.当字符串的长度是偶数时，入栈的字符个数正好是整个字符串的一半；
则在栈非空的情况下，依次将栈顶元素出栈，并和字符串后半段的元素比较，
当栈顶元素和当前字符串不相同，说明不是回文串，返回false；反之，
将新的栈顶元素和下一个字符比较，直到栈为空时，说明是回文串。
 
2.当字符串的长度是奇数时，需要将中间的字符跳过；入栈的是中间字符前面的字符，
并将栈中的元素和中间字符后面的字符一次比较。操作同上。 
*/
int IsHuiWen2(SqStack &S, char str[])
{
    int len = strlen(str);
    int m = len / 2;
    int i;
    char temp;
    for (i = 0; i < m; i++)
    {
        Push(S, str[i]);
    }
    //	char e;
    //	Pop(S,e);
    //	printf("%c",e);
    if (len % 2 == 0)
    {
        while (!IsEmpty(S))
        {
            char e;
            Pop(S, e);
            temp = e;
            if (temp != str[i])
            {
                return 0;
            }
            else
            {
                i++;
            }
        }
    }
    else if (len % 2 != 0)
    {
        i = i + 1;
        while (!IsEmpty(S))
        {
            char e;
            Pop(S, e);
            temp = e;
            if (temp != str[i])
            {
                return 0;
            }
            else
            {
                i++;
            }
        }
    }
    return 1;
}

int main()
{
    SqStack S;

    if (InitStack(S))
    {
        printf("初始化成功!\n");
    }
    else
    {
        printf("初始化失败!\n");
    }

    printf("请输入字符串:");
    char str[20];
    scanf("%s", str);
    if (IsHuiWen2(S, str))
    {
        printf("是回文串!\n");
    }
    else
    {
        printf("不是回文串!\n");
    }
}