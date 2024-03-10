#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node* CreateList(void)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    Node* head = p;
    Node* last = p;
    int number;
    scanf("%d", &number);
    while ( number!=-1)
    {
        p = (Node*)malloc(sizeof(Node));
        p->value = number;
        p->next = NULL;
        last->next = p;
        last = p;
        scanf("%d", &number);
    }
    return head;
}

void Print(Node* head)
{
    Node* p;
    for ( p=head->next; p!=NULL; p=p->next)
    {
        printf("%d ", p->value);
    }
    printf("\n");
}

void rPrint(Node* head)
{
    if (head == NULL)
    {
        return;
    }else {
        rPrint(head->next);
        printf("%d ", head->value);
    }
}

void Free(Node* head)
{
    Node* p = head;
    while ( p!=NULL)
    {
        Node* t = p;
        p = p->next;
        free(t);
    }
}

void Sort(Node* head)
{
    Node* p = head->next;
    while (p != NULL)
    {
        Node* q = p;
        while (q != NULL)
        {
            int t = 0;
            if (q->value < p->value)
            {
                Swap(p,q);
            }
            q = q->next;
        }

        p = p->next;
    }
    
}

int SizeOf(Node* head)
{
    int i = 0;
    Node* p;
    for ( p=head->next; p!=NULL; p=p->next)
    {
        i ++;
    }
    return i;
}

void Swap(Node* p, Node* q)
{
    int t = q->value;
    q->value = p->value;
    p->value = t;
}

void InsertNumber(Node* head, int number)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    for (Node* q = head; q != NULL; q=q->next)
    {
        if (q->next == NULL)
        {
            q->next = p;
            break;
        }else if (p->value < q->next->value)
        {
            p->next = q->next;
            q->next = p;
            break;
        }
    }
}

void InsertNode( Node* head, Node* p)
{
    p->next = NULL;
    for (Node* q = head; q != NULL; q=q->next)
    {
        if (q->next == NULL)
        {
            q->next = p;
            break;
        }else if (p->value < q->next->value)
        {
            p->next = q->next;
            q->next = p;
            break;
        }
    }
}

void Delete(Node* head, int delnumber)
{
    Node* p;
    for ( p=head; p!=NULL; p=p->next)
    {
        if ( p->next->value == delnumber)
        {
            Node* t = p->next;
            p->next = p->next->next;
            free(t);
            break;
        }
    }
}

int isSub(Node* A, Node* B)
{
    Node* p = NULL;
    Node* q = NULL;
    int out;
    for (p=A->next; p!=NULL; p=p->next)
    {
        out = 1;
        for (q=B->next; q!=NULL; q=q->next, p=p->next)
        {
            if (q->value != p->value)
            {
                out = 0;
                break;
            }
        }
        if (out ==1)
        {
            break;
        }
    }
    return out ;
}

int isElement(Node* head, int a)
{
    int out = 0;
    Node* p;
    for ( p=head->next; p!=NULL; p=p->next)
    {
        if ( p->value == a)
        {
            out = 1;
            break;
        }
    }
    return out;
}

int Sum(Node* head)
{
    int sum = 0;
    Node* p = NULL;
    for (p=head->next; p!=NULL; p=p->next)
    {
        sum += p->value;
    }
    return sum;
}

Node* SearchNode(Node* head, int n)
{
    int i = 0;
    Node* p = NULL;
    for ( p=head; p!=NULL; p=p->next)
    {
        if ( n == i)
        {
            break;
        }
        i ++;
    }
    return p;
}

Node* SwapList( Node* head, int s1, int t1, int s2, int t2)
{
    Node* fS1 = SearchNode( head, s1-1);
    Node* S1 = SearchNode( head, s1);
    Node* T1 = SearchNode( head, t1);
    Node* fS2 = SearchNode( head, s2-1);
    Node* S2 = SearchNode( head, s2);
    Node* T2 = SearchNode( head, t2);
    fS1->next = S2;
    fS2->next = S1;
    Node* t = T2->next;
    T2->next = T1->next;
    T1->next = t;
    return head;
}

int Max( Node*head)
{
    int max = head->next->value;
    Node* p = NULL;
    for ( p=head->next; p!=NULL; p=p->next)
    {
        if ( p->value > max)
        {
            max = p->value;
        }
    }
    return max;
}

int Min( Node*head)
{
    int min = head->next->value;
    Node* p = NULL;
    for ( p=head->next; p!=NULL; p=p->next)
    {
        if ( p->value < min)
        {
            min = p->value;
        }
    }
    return min;
}