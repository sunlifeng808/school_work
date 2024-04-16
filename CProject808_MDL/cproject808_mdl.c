#include "cproject808_mdl.h"

int convertTimeToSeconds(char *timeStr)
{
    int hours, minutes, seconds;
    sscanf(timeStr, "%d:%d:%d", &hours, &minutes, &seconds);

    int totalSeconds = (hours-7) * 3600 + minutes * 60 + seconds;

    return totalSeconds;
}

void convertSeconds(int totalSeconds)
{
    int hours = totalSeconds / 3600;
    totalSeconds = totalSeconds % 3600;

    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    printf("%02d:%02d:%02d\n", hours+7, minutes, seconds);
}

Order *CreateList(void)
{
    Order *p = (Order *)malloc(sizeof(Order));
    p->next = NULL;
    Order *head = p;
    return head;
}

void addToList(Order *head, Order *p)
{
    p->next = NULL;
    for (Order *q = head; q != NULL; q = q->next)
    {
        if (q->next == NULL)
        {
            q->next = p;
            break;
        }
    }
}

int isFinish(int order[][2])
{
    int finish = 1;
    for (int i = 0; i < 5; i++)
    {
        if (order[i][1] == 1)
        {
            finish = 0;
            break;
        }
        
    }
    return finish;
    
}