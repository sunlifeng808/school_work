#include <stdio.h>
#include "List.h"
int main(void)
{
    NUMBERLIST* p = NULL;
    p = CreateList();
    PrintList(p);
    int searchnumber;
    scanf("%d", &searchnumber);
    printf("%d", Find(p,searchnumber));
    return 0;
}