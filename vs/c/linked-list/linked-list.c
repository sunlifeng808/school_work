#include "node.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
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
    Print(A);
    Print(B);
    return 0;
}