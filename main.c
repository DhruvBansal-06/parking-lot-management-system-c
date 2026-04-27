#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
int login();
int freeslot(struct parking a[], int x);
float revenue(char[], char[], int);
struct parking a[20];
int main()
{
    int totalslots,choice,fred,i,removeslot,charge;
    float fare;
    i=login();
    if (i!=1)
    {
        printf("Access denied");
        return 0;
    }
    printf("Access granted\n");
    printf("Enter total number of slots:\n");
    scanf("%d",&totalslots);
    printf("Enter parking charge per hour:\n");
    scanf("%d",&charge);
    for(i=0;i<totalslots;i++)
    {
        a[i].free=0;
    }
    while(1)
    {
        printf("\n\n====== PARKING MENU ======\n");
        printf("1.Add Car\n");
        printf("2.Remove Car\n");
        printf("3.View Parking Details\n");
        printf("4.View Total Revenue\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case(1):
            fred=freeslot(a,totalslots);
            if (fred==-93)
            {
                printf("No free slots available\n");
                break;
            }
            printf("\nEnter vehicle details:\n");
            printf("Vehicle model:");
            scanf("%s",a[fred].vehiclemodel);
            printf("Owner name:");
            scanf("%s",a[fred].ownerName);
            char tempNumber[20];
            int duplicate = 0;
            printf("Vehicle number:");
            scanf("%s", tempNumber);
            for(int j = 0; j < totalslots; j++)
            {
                if(a[j].free == 1 && strcmp(a[j].vehicleNumber, tempNumber) == 0)
                {
                    duplicate = 1;
                    break;
                }
            }
            if(duplicate)
            {
                printf("Car number already exists!\n");
                break;
            }
            else
            {
                strcpy(a[fred].vehicleNumber, tempNumber);
            }
            getchar();
            printf("Enter intime (HH:MM):");
            gets(a[fred].intime);
            printf("Slot %d assigned\n",fred);
            a[fred].free=1;
            FILE *fp = fopen("parking.txt","a");
            fprintf(fp,"ENTRY: %s %s %s IN:%s\n",
                a[fred].vehiclemodel,
                a[fred].ownerName,
                a[fred].vehicleNumber,
                a[fred].intime);
            fclose(fp);
            break;
        case(2):
            printf("Enter slot number to remove:");
            scanf("%d",&removeslot);
            if(removeslot>=totalslots || removeslot<0)
            {
                printf("Invalid slot number\n");
                break;
            }
            if(a[removeslot].free==0)
            {
                printf("Slot already empty\n");
                break;
            }
            getchar();
            printf("Enter outtime (HH:MM):");
            gets(a[removeslot].outtime);
            fare=revenue(a[removeslot].outtime,a[removeslot].intime,charge);
            printf("Fare: %f\n",fare);
            fp = fopen("parking.txt","a");
            fprintf(fp,
            "EXIT: %s %s %s IN:%s OUT:%s FARE:%f\n",
            a[removeslot].vehiclemodel,
            a[removeslot].ownerName,
            a[removeslot].vehicleNumber,
            a[removeslot].intime,
            a[removeslot].outtime,
            fare);
            fclose(fp);
            a[removeslot].free=0;
            break;
        case(3):
            for(i=0;i<totalslots;i++)
            {
                if(a[i].free!=0)
                {
                    printf("\nSlot %d\n",i);
                    printf("Vehicle: %s\n",a[i].vehiclemodel);
                    printf("Owner: %s\n",a[i].ownerName);
                    printf("Number: %s\n",a[i].vehicleNumber);
                    printf("Intime: %s\n",a[i].intime);
                }
            }
            break;
        case(4):
        {
            FILE *fp2 = fopen("parking.txt","r");
            float total = 0, f;
            char line[200];
            if(fp2 != NULL)
            {
                while(fgets(line, sizeof(line), fp2))
                {
                    if(strstr(line,"FARE:") != NULL)
                    {
                        sscanf(line,"%*[^F]FARE:%f",&f);
                        total += f;
                    }
                }
                fclose(fp2);
            }
            printf("\nTotal Revenue = %f\n", total);
            break;
        }
        case(5):
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}