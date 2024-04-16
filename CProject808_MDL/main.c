#include "cproject808_mdl.h"

Food foodArray[18] = {
    {"BigMac"},
    {"Fries"},
    {"Coke"},
    {"McChicken"},
    {"Sprite"},
    {"SpicyMcChicken"},
    {"Fanta"},
    {"McWings"},
    {"Coca-Cola"},
    {"CaesarSalad"},
    {"GrilledChickenPieces"},
    {"Croutons"},
    {"SpecialDressing"},
    {"IceCream"},
    {"ChocolateSauce"},
    {"CrushedNuts"},
    {"MiniBurger"},
    {"Juice"}

};

Order orderArray[54000] = {0};

int main()
{   //初始化
    Combo comboArray[7] = {
        {"BigMacCombo", {0, 1, 2}},
        {"McChickenCombo", {3, 1, 4}},
        {"SpicyMcChickenCombo", {5, 1, 6}},
        {"McWingsCombo", {7, 1, 8}},
        {"CaesarSaladCombo", {9, 10, 11, 12}},
        {"IceCreamCombo", {13, 14, 15}},
        {"LittleTreasureCombo", {16, 1, 17}}

    };
    FILE* fp;
    fp = fopen("./input.txt", "r");
    int time = 0;
    int accept = 1;
    // char timeStr[10];
    // scanf("%s", timeStr);
    // int timeInSecond = convertTimeToSeconds(timeStr);
    // printf("%d", timeInSecond);
    // convertSeconds(timeInSecond);
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d %d", &W1, &W2);
    for (int i = 0; i < 18; i++)
    {
        fscanf(fp, "%d", &foodArray[i].proTime);
    }
    for (int i = 0; i < 18; i++)
    {
        fscanf(fp, "%d", &foodArray[i].maxStor);
    }
    // for (int i = 0; i < 18; i++)
    // {
    //     printf("%d %d\n", foodArray[i].proTime, foodArray[i].maxStor);
    // }

    
    // for (int i = 0; i < 7; i++)
    // {
    //     printf("%s: ", comboArray[i].name);
    //     for (int j = 0; j < 5; j++)
    //     {
    //         if (comboArray[i].foodList[j].name[0] == '\0')
    //         {
    //             break;
    //         }
    //         printf("%s ", comboArray[i].foodList[j].name);
    //     }
    //     printf("\n");
    // }
    
    //读取订单
    for (int i = 0; i < n; i++)
    {
        char timeStr[10];
        char foodStr[30];
        fscanf(fp, "%s %s", timeStr, foodStr);
        orderArray[i].orderTime = convertTimeToSeconds(timeStr);
        for (int j = 0; j < 18; j++)
        {
            if (strcmp(foodStr, foodArray[j].name) == 0)
            {
                orderArray[i].orderFoodNumList[0][0] = j;
                orderArray[i].orderFoodNumList[0][1] = 1;
                break;
            }else if (j < 7 && strcmp(foodStr, comboArray[j].name) == 0)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (comboArray[j].foodNumList[k] == 0)
                    {
                        break;
                    }
                    
                    orderArray[i].orderFoodNumList[k][0] = comboArray[j].foodNumList[k];
                    orderArray[i].orderFoodNumList[k][1] = 1;
                }
                break;
            }
        }
    }
    int orderNum = 0;
    int wait = 0;
    Order* waitList = CreateList();
    while (time >= 0 && time < 61200)
    {
        if (wait > W1)
        {
            accept = 0;
        }
        if (wait < W2)
        {
            accept = 1;
        }
        
        
        //接受订单
        if (time >= 0 && time <= 54001)
        {
            if (orderArray[orderNum].orderTime == time && accept == 1)
            {
                wait ++;
                Order* order = &orderArray[orderNum];
                addToList(waitList, order);
                orderNum ++;
            }else if (orderArray[orderNum].orderTime == time && accept == 0 )
            {
                printf("Fail\n");
            }
            
            
            
        }
        // 分配
        for (Order *order = waitList->next; order != NULL; order = order->next)
        {
            for (int i = 0; i < 5; i++)
            {
                if (order->orderFoodNumList[i][0] == 0)
                {
                    break;
                }
                if (foodArray[order->orderFoodNumList[i][0]].stor > 0 && order->orderFoodNumList[i][1] == 1)
                {
                    foodArray[order->orderFoodNumList[i][0]].stor--;
                    order->orderFoodNumList[i][1] = 0;
                }
            }
        }

        // 结算
        for (Order *order = waitList; order != NULL; order = order->next)
        {
            if (order->next == NULL)
            {
                continue;
            }

            if (isFinish(order->next->orderFoodNumList))
            {
                // printf("%d ", order->next->orderTime);
                convertSeconds(time);
                order->next = order->next->next;
                wait --;
            }
        }
        //食物制作
        for (int i = 0; i < 18; i++)
        {
            if (foodArray[i].stor < foodArray[i].maxStor)
            {
                foodArray[i].process ++;
            }
            if (foodArray[i].process == foodArray[i].proTime)
            {
                foodArray[i].stor ++;
                foodArray[i].process = 0;
            }
        }
        //一秒过去
        time++;
    }
        
    // printf("###\n");
    // for (Order* p = waitList->next; p != NULL; p = p->next)
    // {
    //     printf("%d ", p->orderTime);
    //     for (int j = 0; j < 5; j++)
    //     {
    //         if (p->orderFoodNumList[j][0] == 0)
    //         {
    //             break;
    //         }
    //         printf("%s ", foodArray[p->orderFoodNumList[j][0]]);
    //     }
    //     printf("\n");
    // }

    return 0;
}