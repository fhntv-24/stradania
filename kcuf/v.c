#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "r.h"
int main(){
        int n;
        int sw;
        magaz*q;
        while (1){
                printf("выберите действие:\n");
                printf("добавление(1)!!!!\n");
                printf("вывод(2)\n");
                printf("поиск(3)\n");
                printf("изменение(4)\n");
                printf("издевательство(5)\n");
                printf("выход(6)\n");
                while (scanf("%i",&sw)!=1){
                        printf("может всётаки циферку введём?\n");
                        while(getchar() !='\n')
                                continue;
                }
                switch (sw){
                        case 1:
                                dob(&q,&n);
                                break;
                        case 2:
                                viv(&q,&n);
                                break;
                        case 3:
                                search(&q,&n);
                                 break;
                        case 4:
                                iz(&q,&n);
                                break;
                        case 5:
                                ud(&q,&n);
                                break;
                        case 6:
                                printf("ВНИМАНИЕ! ВНИМАНИЕ! спасибо за внимание :)\n");
                                return 0;
                                break;
                        default:
                                printf("ну куда больше и так до 5:15 делал это чудо, пощадите :(");
                                return 0;
                }
        }
        free(q);
        return 0;
}

