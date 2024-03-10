#include <stdio.h>
#include <stdlib.h>
 
typedef struct _node {
    int value;
    struct _node* next;
} Node;
 
Node* CreateList(void);
int isElement(Node* head, int a);
void InsertNode( Node* head, Node* p);
void Print(Node* head);

int main(void)
{
    Node* A = CreateList();
    Node* B = CreateList();
    Node* p = B;
    while (  p->next!=NULL)
    {
        if ( isElement( A, p->next->value))
        {
            p = p->next;
        }else {
            Node* t = p->next;
            p->next = p->next->next;
            InsertNode( A, t);
        }
    }
    if ( A->next == NULL)
    {
        printf("There is no item in A list.\n");
    }else {
        printf("The new list A:");
        Print(A);
    }
    if ( B->next == NULL)
    {
        printf("There is no item in B list.\n");
    }else {
        printf("The new list B:");
        Print(B);
    }
    return 0;
}

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

void Print(Node* head)
{
    Node* p;
    for ( p=head->next; p!=NULL; p=p->next)
    {
        printf("%d ", p->value);
    }
    printf("\n");
}