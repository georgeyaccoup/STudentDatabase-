#include "SDB.h"
student *head=NULL;//main linked list

bool SDB_IsFull() {
    return SDB_GetUsedSize() == 10;
}
uint8 SDB_GetUsedSize() {
    uint8 counter = 0;
    student *current = head;
    while (current != NULL) {
        counter++;
        current = current->next;
    }
    return counter;
}

bool SDB_AddEntry() {
    if (SDB_GetUsedSize() == 0) { // condition check if the data is empty (create the head)
        student *New_Student = malloc(sizeof(student));
        Get_Data(New_Student);
        head = New_Student;
        New_Student->next = NULL;
        if (SDB_GetUsedSize()<3)//condtion that let the user enter the minimum required data which mean the data at list have 3 students
            SDB_AddEntry();
        return true;
    } else if (SDB_IsFull()) { // if the data is full (ask the user to remove something)
        printf("\nThe data is full. You need to remove someone...\n");
        printf("To remove, enter 'Y'. To select another option, enter 'O': ");
        char Option;
        scanf(" %c", &Option);
        if (Option == 'Y') {
            uint32 ID;
            printf("Enter the ID to remove: ");
            scanf("%u", &ID);
            SDB_DeletEntry(ID);
            return true;
        } else {
            SDB_APP(); // Assuming SDB_APP() is defined to handle other options
        }
    } else { // if the data isn't full, the new data will be added successfully
        student *current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = malloc(sizeof(student));
        Get_Data(current->next);
        current->next->next = NULL;
        if (SDB_GetUsedSize()<3)
            SDB_AddEntry();
        return true;
    }
    return false;
}

bool SDB_ReadEntry(uint32 id) {
    if (SDB_GetUsedSize()==0){
        printf("\nThe list is Empty please fill it first \nFor Data Entry pass 1:");
        int Option;
        scanf("%u",&Option);
        PrintLine();
        if (Option==1)
            SDB_AddEntry();
        else {
            PrintLine();
            printf("\nThen you can choose from the ");
            SDB_APP();
        }
    }else if(SDB_IsIdExist(id)==1){
    student* current = head;
    while (current != NULL) {
        if (current->Student_ID == id) {
            printf("\nStudent ID: %u\n", current->Student_ID);
            printf("Subject ID (%u)\tGrade (%u)\n", current->Course1_ID, current->Course1_grade);
            printf("Subject ID (%u)\tGrade (%u)\n", current->Course2_ID, current->Course2_grade);
            printf("Subject ID (%u)\tGrade (%u)\n", current->Course3_ID, current->Course3_grade);
            return true;
        }
        current = current->next;
    }
    }else{
        PrintLine();
        printf("\nThe ID is not Exist\n");
        PrintLine();
        printf("\nPlease Enter the ID again :");
        SDB_action(3);
        return false;
}
}
void SDB_PrintList(uint8 *Count) {
    while (*Count > 0) {
        PrintLine();
        printf("\n");
        SDB_ReadEntry(head->Student_ID);
        head = head->next;
        (*Count)--;
    }
}
void SDB_GetList(uint8 List[10]) {
    student *NEW=head;
    for (int i=0; i<SDB_GetUsedSize();i++){
        List[i]=NEW->Student_ID;
        NEW=NEW->next;
    }
}

bool SDB_IsIdExist(uint32 id) {
    student* current = head;
    while (current != NULL) {
        if (current->Student_ID == id) {
            return true; // Found the student with the given id
        }
        current = current->next;
    }
    return false; // Student with the given id was not found
}

void Get_Data(student *New_Student) {
    printf("\nEnter Student ID: ");
    scanf("%u", &New_Student->Student_ID);

    printf("Enter Subject ID 1: ");
    scanf("%u", &New_Student->Course1_ID);
    printf("Enter Subject grade of %u: ", New_Student->Course1_ID);
    scanf("%u", &New_Student->Course1_grade);

    printf("Enter Subject ID 2: ");
    scanf("%u", &New_Student->Course2_ID);

    while (New_Student->Course2_ID == New_Student->Course1_ID) {
        printf("This ID already exists. Please re-enter it: ");
        scanf("%u", &New_Student->Course2_ID);
    }

    printf("Enter Subject grade of %u: ", New_Student->Course2_ID);
    scanf("%u", &New_Student->Course2_grade);

    printf("Enter Subject ID 3: ");
    scanf("%u", &New_Student->Course3_ID);

    while (New_Student->Course3_ID == New_Student->Course1_ID || New_Student->Course3_ID == New_Student->Course2_ID) {
        printf("This ID already exists. Please re-enter it: ");
        scanf("%u", &New_Student->Course3_ID);
    }

    printf("Enter Subject grade of %u: ", New_Student->Course3_ID);
    scanf("%u", &New_Student->Course3_grade);

    PrintLine();
}


void SDB_DeletEntry(uint32 ID) {
    if (head == NULL) { // Empty list
        printf("\nThe list is empty.\n");
        return;
    } else if (head->Student_ID == ID) { // Delete the first node
        student* temp = head;
        head = head->next;
        free(temp);
        printf("\nStudent with ID %u deleted successfully.\n", ID);
        return;
    } else { // General case
        student* current = head;
        while (current->next != NULL && current->next->Student_ID != ID) {
            current = current->next;
        }
        if (current->next == NULL) { // ID not found
            printf("\nStudent with ID %u not found.\n", ID);
            return;
        }
        student* temp = current->next;
        current->next = current->next->next;
        free(temp);
        PrintLine();
        printf("Student with ID %u deleted successfully.", ID);
        PrintLine();
    }

    if (SDB_GetUsedSize() < 3) {
        printf("\nThe size is less than 3. You need to fill %d students:\n", 3 - SDB_GetUsedSize());
        SDB_AddEntry();
    }

}
void Another_operations() {
    char Again;
    printf("\n");
    PrintLine();
    printf("\nEnter Y for more operations and N for End : ");
    scanf(" %c", &Again);
    PrintLine();
    if (Again == 'Y') {
        SDB_APP();
    }else if (Again=='N'){
        PrintEndLine();
        return 0;
    }else {
        printf("\n");
        PrintLine();
        printf("\ninvalied input Please make sure of that");
        Another_operations();
    }
}

void PrintEndLine(){
    printf("\n");
    PrintLine();
    printf("\n");
    for (int i=0;i<45;i++)
       printf("-");
    printf("Thank You");
    for (int i=0;i<=45;i++)
       printf("-");
    printf("\n");
    PrintLine();
    printf("\n");
}
void PrintLine(){
for (int i=0;i<100;i++)
        printf("-");
}
