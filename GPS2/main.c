//
//  main.c
//  GPS2
//
//  Created by 20161104588 on 17/6/26.
//  Copyright © 2017年 20161104588. All rights reserved.
//
#include<stdio.h>
int main(int argc,const char *argv[])
{
    FILE *fp;
    char gps1[70];
    char gps2[70];
    char lat[10];//纬度
    char lng[10];//经度
    char alt[10];//海拔
    char time[10];//时间
    int a,b,i,j;
    fp=fopen("//Users//a20161104588//Desktop//GPS//GPS170510.log","r+");
    fscanf(fp,"%s%s",gps1,gps2);
    printf("输出：%s\n%s\n",gps1,gps2);
    for(a=0;a<8;a++)
        lat[a]=gps1[a+16];
    lat[8]='\0';
    printf("纬度：%s\n",lat);
    for(b=0;b<9;b++)
        lng[b]=gps1[b+27];
    lng[9]='\0';
    printf("经度:%s\n",lng);
    for(i=0;i<4;i++)
        alt[i]=gps2[i+43];
    lng[4]='\0';
    printf("海拔:%s\n",alt);
    for(j=0;j<6;j++)
        time[j]=gps1[j+7];
    time[6]='\0';
    printf("时间:%s\n",time);
    fclose(fp);
    return 0;
}
