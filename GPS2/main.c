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
    char lat[9];//纬度
    char lng[10];//经度
    char alt[10];//海拔
    char time[10];//时间
    char day[10];//日期
    int a,b,i,j,t1,t2,d;
    fp=fopen("//Users//a20161104588//Desktop//GPS2//GPS170510.log","r+");
    fr=fopen("//Users//a20161104588//Desktop//GPS2//gpsout.csv","w" );
    
    //$GPRMC,013238,A,4047.533,N,11141.856,E,012.2,253.6,100517,,*1A
    //$GPGGA,013238,4047.533,N,11141.856,E,1,05,,1108,M,,M,,*57
    if(fp==NULL)
        printf("打开文件错误\n");
    else
        fprintf(fr,"纬度,  经度,   海拔,   时间,   日期\n");
    
    
    while(fscanf(fp,"%s %s",gps1,gps2)!=EOF)
    {
    fscanf(fp,"%s%s",gps1,gps2);
    printf("输出：%s\n%s\n",gps1,gps2);
        
        
    for(a=0;a<8;a++)
        lat[a]=gps1[a+16];
    lat[8]='\0';
        printf("纬度:%c%c.%c%c%c%c%c\n",lat[0],lat[1],lat[2],lat[3],lat[5],lat[6],lat[7]);
        fprintf(fr,"%c%c.%c%c%c%c%c,",lat[0],lat[1],lat[2],lat[3],lat[5],lat[6],lat[7]);
        
        
    for(b=0;b<9;b++)
        lng[b]=gps1[b+27];
    lng[9]='\0';
     
        printf("%c%c%c.%c%c%c%c%c\n",lng[0],lng[1],lng[2],lng[3],lng[4],lng[6],lng[7],lng[8]);
     fprintf(fr,"%c%c%c.%c%c%c%c%c,",lng[0],lng[1],lng[2],lng[3],lng[4],lng[6],lng[7],lng[8]);
        
        
        
    for(i=0;i<4;i++)
        alt[i]=gps2[i+43];
    alt[4]='\0';
     printf("海拔:%sm,\n",alt);
     fprintf(fr,"%sm, ",alt);
        
        
    for(j=0;j<2;j++)
        time[j]=gps1[j+7];
    time[2]='\0';
    t1=(time[0]-'0')*10;
    t2=(time[1]-'0')*1+t1+8;
     printf("时间:%d时",t2);
     fprintf(fr,"%d时",t2);
        
        
    for(j=0;j<2;j++)
        time[j]=gps1[j+9];
    time[2]='\0';
     printf("%s分",time);
     fprintf(fr,"%s分",time);
        
        
    for(j=0;j<2;j++)
        time[j]=gps1[j+11];
    time[2]='\0';
    printf("%s秒,\n",time);
    fprintf(fr,"%s秒, ",time);
        
        
    for(d=0;d<2;d++)
            day[d]=gps1[d+55];
        day[2]='\0';
        printf("日期:20%s年",day);
    fprintf(fr,"20%s年",day);
        
        
    for(d=0;d<2;d++)
        day[d]=gps1[d+53];
    day[2]='\0';
    printf("%s月",day);
    fprintf(fr,"%s月",day);
        
        
    for(d=0;d<6;d++)
        day[d]=gps1[d+51];
    day[2]='\0';
    printf("%s日,\n",day);
    fprintf(fr,"%s日,\n",day);
        
        
    }
    fclose(fp);
    fclose(fr);
    return 0;
}
