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
    FILE *fr;
    char gps1[70];
    char gps2[70];
    char lat[10];//纬度
    char lng[10];//经度
    char alt[10];//海拔
    char time[10];//时间
    char day[10];//日期
    int a,b,i,j,t1,t2,d;
    fp=fopen("//Users//a20161104588//Desktop//GPS2//GPS170510.log","r+");
    fr=fopen("//Users//a20161104588//Desktop//GPS2//gpsout.csv","w" );
    if(fp==NULL)
        printf("打开文件错误\n");
    else
        fprintf(fr,"纬度 ，经度 ，海拔 ，时间 ，日期 \n");
    while(fscanf(fp,"%s %s",gps1,gps2)!=EOF)
    {
    fscanf(fp,"%s%s",gps1,gps2);
    printf("输出：%s\n%s\n",gps1,gps2);
    for(a=0;a<8;a++)
        lat[a]=gps1[a+16];
    lat[8]='\0';
     printf("纬度：%s\n",lat);
     fprintf(fr,"纬度:%s",lat);
    for(b=0;b<9;b++)
        lng[b]=gps1[b+27];
    lng[9]='\0';
     printf("经度:%s\n",lng);
     fprintf(fr,"经度:%s",lng);
    for(i=0;i<4;i++)
        alt[i]=gps2[i+43];
    alt[5]='\0';
     printf("海拔:%sm\n",alt);
     fprintf(fr,"海拔:%sm",alt);
    for(j=0;j<2;j++)
        time[j]=gps1[j+7];
    time[2]='\0';
    t1=(time[0]-'0')*10;
    t2=(time[1]-'0')*1+t1+8;
     printf("时间:%d时",t2);
     fprintf(fr,"时间:%d时",t2);
    for(j=0;j<2;j++)
        time[j]=gps1[j+9];
    time[2]='\0';
     printf("%s分",time);
     fprintf(fr,"%s分",time);
    for(j=0;j<2;j++)
        time[j]=gps1[j+11];
    time[2]='\0';
    printf("%s秒\n",time);
    fprintf(fr,"%s秒",time);
    for(d=0;d<2;d++)
            day[d]=gps1[d+55];
        day[2]='\0';
        printf("日期:20%s年",day);
    fprintf(fr,"日期:20%s年",day);
    for(d=0;d<2;d++)
        day[d]=gps1[d+53];
    day[2]='\0';
    printf("%s月",day);
    fprintf(fr,"%s月",day);
    for(d=0;d<6;d++)
        day[d]=gps1[d+51];
    day[2]='\0';
    printf("%s日\n",day);
    fprintf(fr,"%s日\n",day);
    }
    fclose(fp);
    fclose(fr);
    return 0;
}
