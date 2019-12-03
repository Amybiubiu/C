#include <iostream>
using namespace std;
template <class TYPE>
class ListNode{
private:
    TYPE data;
    ListNode * next;
    static ListNode * CurNode;
    static ListNode * head;
public:
    ListNode(){
        next = NULL;
        head = CurNode = this;
    }
    ListNode(TYPE NewData){
        data = NewData;
        next = NULL;
    }
    void AppendNode(TYPE NewNode);
    void DispList();
    void DelList();
};
template <class TYPE>
ListNode<TYPE>* ListNode<TYPE>::CurNode;
template <class TYPE>
ListNode<TYPE> *ListNode<TYPE>::head;
template <class TYPE>
void ListNode<TYPE>::AppendNode(TYPE NewNode){
    CurNode->next = new ListNode(NewNode);
    CurNode = CurNode->next;
}
template <class TYPE>
void ListNode<TYPE>::DispList(){
    CurNode = head->next;
    while(CurNode != NULL){
        cout<<CurNode->data<<endl;
        CurNode = CurNode->next;
    }
}
template <class TYPE>
void ListNode<TYPE>::DelList(){
    ListNode *q;
    CurNode = head->next;
    while(CurNode!= NULL){
        q = CurNode->next;
        delete CurNode;
        CurNode = q;
    }
    head=head->next;
}
int main(){
    ListNode <char> Clist;
    Clist.AppendNode('a');
    Clist.AppendNode('b');
    Clist.AppendNode('c');
    Clist.AppendNode('d');
    Clist.DispList();
    Clist.DelList();
    cout<<"after delet"<<endl;
    Clist.DispList();
    return 0;
}
