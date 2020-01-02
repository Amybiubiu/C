//
//  main.cpp
//  list
//
//  Created by mac on 2019/12/31.
//  Copyright © 2019 mac. All rights reserved.
//


#include "list.hpp"
#include <stdio.h>

void unionList(SqList *LA, SqList *LB, SqList *&LC)
{
    int lena,i;
    ElemType e;
    InitList(LC);
    for (i=1; i<=ListLength(LA); i++) //将LA的所有元素插入到Lc中
    {
        GetElem(LA,i,e);
        ListInsert(LC,i,e);
    }
    lena=ListLength(LA);         //求线性表LA的长度
    for (i=1; i<=ListLength(LB); i++)
    {
        GetElem(LB,i,e);         //取LB中第i个数据元素赋给e
        if (!LocateElem(LA,e)) //LA中不存在和e相同者,插入到LC中
            ListInsert(LC,++lena,e);
    }
}

//用main写测试代码
int main()
{
    SqList *sq_a, *sq_b, *sq_c;
    ElemType a[6]= {5,8,7,2,4,9};
    CreateList(sq_a, a, 6);
    printf("LA: ");
    DispList(sq_a);
    
    ElemType b[6]= {2,3,8,6,0};
    CreateList(sq_b, b, 5);
    printf("LB: ");
    DispList(sq_b);
    unionList(sq_a, sq_b, sq_c);
    printf("LC: ");
    DispList(sq_c);
    return 0;
}
