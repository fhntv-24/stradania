//realize function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "r.h"

void dob(magaz**ar,int*n){
        FILE*f=fopen("b.bin","rb");
        if(!f)
                return;
        fseek(f,0,SEEK_END);
        size_t size=ftell(f);
        rewind(f);
        int tk=size/sizeof(magaz);
        *ar=(magaz*)calloc(tk,sizeof(magaz));
        magaz*temp=*ar;
        fread(*ar,sizeof(magaz),tk,f);
        fclose(f);
        printf("сколько позиций добавить:\n");
        while(scanf("%i",n)!=1){
                printf("может всётаки циферку введём?\n\n");
                while(getchar() !='\n');
        }
        f=fopen("b.bin","wb");
        if(!f)
                return;
        int s=*n;
        int kk=s+tk;
        *ar=(magaz*)realloc(*ar,kk*sizeof(magaz));
        for(int i=tk; i<kk;i++){
                printf("%i введите:название производителя и цену товара\n",i+1);
                scanf("%s %s %i",temp[i].t,temp[i].p,&temp[i].cen);
        }
        fwrite(*ar,kk,sizeof(magaz),f);
        fclose(f);
}
void viv(magaz* *ar,int *n){
        FILE*f=fopen("b.bin","rb");
        if(!f)
                return;
        fseek(f,0,SEEK_END);
        size_t size=ftell(f);
        rewind(f);
        int s=size/sizeof(magaz);
        *ar=(magaz*)calloc(s,sizeof(magaz));
        magaz*temp=*ar;
        fread(*ar,sizeof(magaz),s,f);
        printf("великолепная не один раз проклятая база данных:\n");
        for(int i=0;i<s;i++)
                printf("%i)\t %s\t %s\t %i\t\n",i+1,temp[i].t,temp[i].p,temp[i].cen);
        fclose(f);
}
void search(magaz* *ar,int *n){
        FILE*f=fopen("b.bin","rb");
        if(!f)
                return;
        int s=*n;
        fseek(f,0,SEEK_END);
        size_t size=ftell(f);
        rewind(f);
        s=size/sizeof(magaz);
        *ar=(magaz*)calloc(s,sizeof(magaz));
        magaz*temp=*ar;
        fread(*ar,sizeof(magaz),s,f);
        int t,u;
        char e[50];
        printf("по какому признаку ищем?\n 1-название\n 2-производитель\n 3-цена\n(ОЖИДАЕТСЯ ЧИСЛО)\n");
        while (scanf("%i",&t)!=1){
                printf("может всётаки циферку введём?\n");
                while(getchar() !='\n');
        }
        printf("что ищем?\n");
        if (t!=3)
                scanf("%s",e);
        else
                while(scanf("%i",&u)!=1){
                        printf("может всётаки циферку введём?\n");
                        while(getchar() !='\n');
                }
        int o=0;
        switch(t){
                case 1:
                        for(int i=0; i<s;i++){
                                if(strcmp(e,temp[i].t) == 0){
                                        printf("строка удовлетворяющие условиям поиска:\n");
                                        printf("%i)\t %s\t %s\t %i\t\n",i+1,temp[i].t,temp[i].p,temp[i].cen);
                                        o=1;
                                }
                        }
                break;
                case 2:
                        for(int i=0; i<s;i++){
                                if(strcmp(e,temp[i].p) == 0){
                                        printf("строка удовлетворяющие условиям поиска:\n");
                                        printf("%i)\t %s\t %s\t %i\t\n",i+1,temp[i].t,temp[i].p,temp[i].cen);
                                        o=1;
                                }
                        }
                break;
                case 3:
                        for(int i=0; i<s;i++){
                                if(u==temp[i].cen){
                                        printf("строка удовлетворяющие условиям поиска:\n");
                                        printf("%i)\t %s\t %s\t %i\t\n",i+1,temp[i].t,temp[i].p,temp[i].cen);
                                        o=1;
                                }
                        }
                break;
        }
        if (o==0)
                printf("совпадений не найдено\n\n");
        fclose(f);
}
void iz(magaz* *ar,int *n){
        FILE*f=fopen("b.bin","rb");
        if(!f)
                return;
        int s=*n;
        fseek(f,0,SEEK_END);
        size_t size=ftell(f);
        rewind(f);
        s=size/sizeof(magaz);
        *ar=(magaz*)calloc(s,sizeof(magaz));
        magaz*temp=*ar;
        fread(*ar,sizeof(magaz),s,f);
        int e,j;
        printf("какую строку меняем?\n");
        while (scanf("%i",&j)!=1 || j<1 || j>s){
                printf("что-то тут не так, подумай лучше и введи правильно\n");
                while(getchar() !='\n');
        }
        printf("что меняем?\n 1-название\n 2-производитель\n 3-цена\n(ЧИСЛО)\n");
        while (scanf("%i",&e)!=1){
                printf("может всётаки циферку введём?\n");
                while(getchar() !='\n');
        }
        switch (e){
                case 1:
                        printf("на что меняем?\n");
                        scanf("%s",temp[j-1].t);
                        printf("ну красавец:\n");
                        printf("%i)\t %s\t %s\t %i\t\n",j,temp[j-1].t,temp[j-1].p,temp[j-1].cen);
                break;
                case 2:
                        printf("на что меняем?\n");
                        scanf("%s",temp[j-1].p);
                        printf("ну красавец:\n");
                        printf("%i)\t %s\t %s\t %i\t\n",j,temp[j-1].t,temp[j-1].p,temp[j-1].cen);
                break;
                case 3:
                        printf("на что меняем?\n");
                        if (scanf("%i",&temp[j-1].cen)!=1){
                                printf("может всётаки циферку введём?\n");
                                while(getchar() !='\n')
                                        continue;
                        }
                        printf("ну красавец:\n");
                        printf("%i)\t %s\t %s\t %i\t\n",j,temp[j-1].t,temp[j-1].p,temp[j-1].cen);
                break;
                default:
                        printf("мне лень больше добавлять)))\n");
        }
        fclose(f);
        f=fopen("b.bin","wb");
        if(!f)
                return;
        fwrite(*ar,s,sizeof(magaz),f);
        fclose(f);
}
void ud(magaz* *ar,int *n){
        FILE*f=fopen("b.bin","rb");
        if(!f)
        return;
        int s=*n;
        fseek(f,0,SEEK_END);
        size_t size=ftell(f);
        rewind(f);
        s=size/sizeof(magaz);
        *ar=(magaz*)calloc(s,sizeof(magaz));
        magaz*temp=*ar;
        fread(*ar,sizeof(magaz),s,f);
        fclose(f);
        int j;
        printf("кого казним? кто провинился?\n");
        while (scanf("%i",&j)!=1){
                printf("может всётаки циферку введём?\n");
                while(getchar() !='\n');
        }
        if (j<=s && j>0){
                        for(int y=j-1;y<s-1;y++){
                                temp[y]=temp[y+1];
                        }
                f=fopen("b.bin","wb");
                if(!f)
                        return;
                fwrite(*ar,s-1,sizeof(magaz),f);
                fclose(f);
                *ar=(magaz*)calloc(s-1,sizeof(magaz));
        }
        else{
                printf("нет такой строки!\n");
                return;
        }
}

