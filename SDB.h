#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include "STD.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct SimpleDb // the main linked list
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;
 struct SimpleDb *next;
} student;


bool SDB_IsFull ();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry (uint32 id);
bool SDB_ReadEntry (uint32 id);
void SDB_GetList(uint8 List[]);// count and list is reserved words so i made them with cabital liters
void SDB_PrintList (uint8 *Count);
bool SDB_IsIdExist (uint32 id);
void SDB_APP (); //program start
void SDB_action (uint8 choice);
bool SDB_IsSubjectIdExist(uint8 id);// function to make sure their are not indentical Id
void Get_Data(student *New_Student);// function that take the data from the user
void PrintLine();//function print line of - for more organization
void Another_operations();// function to reopen the seclection operation
void PrintEndLine();
#endif // SDB_H_INCLUDED
