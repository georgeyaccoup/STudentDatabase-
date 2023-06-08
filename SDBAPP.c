#include "SDB.h"
void SDB_APP (){
int option=0;
printf("\nList of operations :\n");
printf("To add entry, enter 1 \nTo get used size in database, enter 2 \nTo read student data, enter 3\nTo get the list of all student IDs, enter 4");
printf("\nTo check is ID is existed, enter 5 \nTo delete student data, enter 6\nTo check is database is full, enter 7\nTo print All the data, enter 8\nTo exit enter 0\n");
PrintLine();
printf("\nEnter the operation: ");
scanf("%u",&option);
SDB_action(option);
}
void SDB_action(uint8 choice){
switch(choice){
case 1:
    PrintLine();
    SDB_AddEntry();
    break;
case 2:
    PrintLine();
    printf("\nSize Of Data Base is %u",SDB_GetUsedSize());
    break;
case 3:
    PrintLine();
    uint32 id;
    printf("\nEnter the ID to search about: ");
    scanf("%u", &id);
    PrintLine();
    SDB_ReadEntry(id);
    break;
case 4:
    PrintLine();
    uint8 list_IDs[10]={0};
    printf("\nNumber of students : %u\n",SDB_GetUsedSize());
    SDB_GetList(list_IDs);
    for (int i=0;i<SDB_GetUsedSize();i++){
        printf("\nstudent number %d ID : %u",i+1,list_IDs[i]);
    }
    printf("\n");
    break;
case 5:
    PrintLine();
    uint32 ID;
    printf("\nEnter the ID to search about :");
    scanf("%u",&ID);
    if (SDB_IsIdExist(ID)){
        PrintLine();
        printf("\nThe ID (%d) is Exist",ID);
    }
    else{
        PrintLine();
        printf("\nThe ID (%d) is not Exist",ID);
    }
    break;
case 6:
    PrintLine();
    uint32 ID_DE;
    printf("\nEnter the ID to delete about :");
    scanf("%u",&ID_DE);
    if (SDB_IsIdExist(ID_DE) == 1) {
        SDB_DeletEntry(ID_DE);
    } else {
        PrintLine();
        printf("\nStudent with ID %u does not exist.....!", ID_DE);
    }
    break;
case 7:
    PrintLine();
    if (SDB_IsFull())
        printf("\nThe Database is full");
    else
        printf("\nThe Database is not full");
    break;
case 8:
    if(SDB_GetUsedSize()==0){
        PrintLine();
        printf("\nThe database is empty...!\n");
    }
    else {
        PrintLine();
        printf("\nAll Database :\n");
        uint8 Counter=SDB_GetUsedSize();
        SDB_PrintList(&Counter);
        printf("\n");
    }
    break;
case 0:
    PrintEndLine();
    return 0;
    break;
default:
    PrintLine();
    printf("\nInvalied input please try again....!\n");
    PrintLine();
    SDB_APP();
}
Another_operations();
}
