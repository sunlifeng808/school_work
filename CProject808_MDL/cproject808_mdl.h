#ifndef CPROJECT_MDL_H
#define CPROJECT_MDL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FOOD
{
    char name[30];
    int proTime;
    int maxStor;
    int stor;
    int process;
} Food;

typedef struct COMBO
{
    char name[30];
    int foodNumList[5];
} Combo;

typedef struct ORDER
{
    int orderTime;
    int orderFoodNumList[5][2];
    struct ORDER *next;
} Order;



extern Food foodArray[18];
extern Combo comboArray[7];
extern Order orderArray[54000];

int time;
int n;
int W1;
int W2;
int accept;
int orderNum;
int wait;

Order* waitList;
int convertTimeToSeconds(char *timeStr);
void convertSeconds(int totalSeconds);
Order *CreateList(void);
void addToList(Order *head, Order* p);
int isFinish(int order[][2]);

#endif