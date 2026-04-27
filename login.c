#include<stdio.h>
#include<string.h>
int login()
{
    char str1[20],str2[20];
    printf("Enter the username:\n");
    scanf("%s",str1);
    printf("Enter the password:\n");
    scanf("%s",str2);
    if(strcmp(str1,"admin")==0 && strcmp(str2,"Messi@2022")==0 )
    {
        FILE *fp = fopen("parking.txt","a");
        if(fp!=NULL)
        {
            fprintf(fp,"Login Success\n");
            fclose(fp);
        }
        return 1;
    }
    printf("Either USERNAME or PASSWORD is WRONG!!!\n");
    printf("Enter username again:\n");
    scanf("%s",str1);
    printf("Enter password:\n");
    scanf("%s",str2);
    if(strcmp(str1,"admin")==0 && strcmp(str2,"Messi@2022")==0 )
    {
        FILE *fp = fopen("parking.txt","a");
        if(fp!=NULL)
        {
            fprintf(fp,"Login Success\n");
            fclose(fp);
        }
        return 1;
    }
    printf("LAST ATTEMPT\n");
    printf("Enter username:\n");
    scanf("%s",str1);
    printf("Enter password:\n");
    scanf("%s",str2);
    if(strcmp(str1,"admin")==0 && strcmp(str2,"Messi@2022")==0 )
    {
        FILE *fp = fopen("parking.txt","a");
        if(fp!=NULL)
        {
            fprintf(fp,"Login Success\n");
            fclose(fp);
        }
        return 1;
    }
    FILE *fp = fopen("parking.txt","a");
    if(fp!=NULL)
    {
        fprintf(fp,"Login Failed\n");
        fclose(fp);
    }
    return 0;
}