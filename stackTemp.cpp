//
//  stack.h
//  text
//
//  Created by mac on 2020/3/22.
//  Copyright © 2020 mac. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <iostream>
using namespace std;

template <typename Type>
class Stack
{
private:
    enum {MAX = 10};    // 栈长度
    Type items[MAX];    // 用数组申请栈
    int top;            // 指向栈顶(栈中最后一个元素的上一个空间)
public:
    Stack();        // 初始化栈
    bool isempty();        // 是否栈空
    bool isfull();        // 是否栈满
    bool push(const Type & item); // 进栈
    bool pop(Type & item);        // 出栈
};

template <typename Type>
Stack<Type>::Stack()
{
    top = 0;
}

template <typename Type>
bool Stack<Type>::isempty()
{
    return top == 0;
}

template <typename Type>
bool Stack<Type>::isfull()
{
    return top == MAX;
}

template <typename Type>
bool Stack<Type>::push(const Type & item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <typename Type>
bool Stack<Type>::pop(Type & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}


#endif /* stack_h */
