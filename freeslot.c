#include<stdio.h>
#include"struct.h"

int freeslot(struct parking a[],int x)
{
    FILE *fp = fopen("parking.txt","r");
    if(fp!=NULL)
    {
        fclose(fp);
    }

    int i;
    for(i=0;i<x;i++)
    {
        if(a[i].free==0)
        {
            return (i);
        }
    }
    return(-93);
}