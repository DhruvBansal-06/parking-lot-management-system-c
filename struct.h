#ifndef STRUCT_H
#define STRUCT_H
struct parking
{
    char vehiclemodel[20];
    char ownerName[20];
    char vehicleNumber[20];
    char intime[5];
    char outtime[5];
    int free;
};
#endif