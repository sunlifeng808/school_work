#ifndef _LIST_H_
#define _LIST_H_

typedef struct List
{
    int number[10];
    int len;
} NUMBERLIST;

NUMBERLIST* CreateList(void);
void PrintList(NUMBERLIST* p);
int Find(NUMBERLIST* p, int searchnumber);

#endif