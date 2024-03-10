#ifndef _NODE_H
#define _NODE_H
 
typedef struct _node {
    int value;
    struct _node* next;
} Node;

Node* CreateList(void);
void Print(Node* head);
void rPrint(Node* head);//反向打印，需输入head->next
void Free(Node* head);
void Sort(Node* head);
int SizeOf(Node* head);
void Swap(Node* p, Node* q);
void InsertNumber(Node* head, int number);//按顺序将一个数插入链表
void InsertNode( Node* head, Node* p);//按顺序将一个节点插入链表
void Delete(Node* head, int delnumber);
int isSub(Node* A, Node* B);//判断B是否为A的子序列
int isElement(Node* head, int a);//判断p的值是否为A中元素
int Sum(Node* head);
Node* SearchNode(Node* head, int n);//返回第n个节点的指针
Node* SwapList( Node* head, int s1, int t1, int s2, int t2);//交换部分链表
int Max( Node* head);
int Min( Node* head);


#endif