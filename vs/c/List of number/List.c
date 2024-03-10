#include <stdio.h>
#include "List.h"
#include <stdlib.h>
#define maxlen 10

NUMBERLIST* CreateList(void)
{
    NUMBERLIST* p = NULL;
    p = (NUMBERLIST*)malloc(sizeof(NUMBERLIST));
    p->len = 0;
    int i;
    for (i=0; i<maxlen; i++ )
    {
        int number;
        scanf("%d", &number);
        if (number == -1)
        {
            break;
        }else {
            p->number[i] = number;
            p->len ++;
        }
    }
    return p;
}

void PrintList(NUMBERLIST* p)
{
    printf("%d\n",p->len);
    int i;
    for (i=0; i<p->len; i ++ )
    {
        printf("%d ", p->number[i]);
    }
}

int Find(NUMBERLIST* p, int searchnumber)
{
    int i;
    int out = -1;
    for (i=0; i<p->len; i++ )
    {
        if (searchnumber == p->number[i])
        {
            out = i+1;
            break;
        }

    }
    return out;
}