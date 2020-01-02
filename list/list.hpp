//
//  list.hpp
//  list
//
//  Created by mac on 2019/12/31.
//  Copyright © 2019 mac. All rights reserved.
//

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
void CreateList(SqList *&L, ElemType a[], int n);//用数组创建线性表
void InitList(SqList *&L);//初始化线性表InitList(L)
void DestroyList(SqList *&L);//销毁线性表DestroyList(L)
bool ListEmpty(SqList *L);//判定是否为空表ListEmpty(L)
int ListLength(SqList *L);//求线性表的长度ListLength(L)
void DispList(SqList *L);//输出线性表DispList(L)
bool GetElem(SqList *L,int i,ElemType &e);//求某个数据元素值GetElem(L,i,e)
int LocateElem(SqList *L, ElemType e);//按元素值查找LocateElem(L,e)
bool ListInsert(SqList *&L,int i,ElemType e);//插入数据元素ListInsert(L,i,e)
bool ListDelete(SqList *&L,int i,ElemType &e);//删除数据元素ListDelete(L,i,e)#endif // LIST_H_INCLUDED
#endif
