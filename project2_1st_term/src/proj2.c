/*
 ============================================================================
 Name        : proj2.c
 Author      : Abdelrahman_ElBadawy
 Version     :  1.0
 Copyright   : Your copyright notice
 Description : Student Management System in C, Ansi-style
 ============================================================================
 */

#include "Student.h"
#include "FIFO.h"
const int NUMBER_OF_STUDENTS = 55;
// Creator:  Abdelrahman El-Badawy
FIFO_BUF_t FIFO;
int main()
{

    Student_t students[NUMBER_OF_STUDENTS];

    FIFO_init(&FIFO, students, NUMBER_OF_STUDENTS);

    // Your code here
    DPRINTF("Welcome To Student Management System\n");
    while (1)
    {
        DPRINTF("Please choose the task\n");
        DPRINTF("1. Add Student\n");
        DPRINTF("2. Add Student From File\n");
        DPRINTF("3. Find Student By roll Number\n");
        DPRINTF("4. Find Student By First Name\n");
        DPRINTF("5. Find Student By Course Id\n");
        DPRINTF("6. Find Total Number Of Students\n");
        DPRINTF("7. Delete Student By Roll Number\n");
        DPRINTF("8. Update Student By Roll Number\n");
        DPRINTF("9. Show All Students\n");
        DPRINTF("10. Exit\n");
        DPRINTF("Your Choice: ");
        char choice;
        scanf("%u", &choice);

        switch (choice)
        {
        case 1:
            AddStudent(&FIFO);
            break;
        case 2:
            AddStudentFromFile(&FIFO);
            break;
        case 3:
            searchByRollNumber(&FIFO);
            break;
        case 4:
            FindStudentByFirstName(&FIFO);
            break;
        case 5:
            FindStudentByCourseId(&FIFO);
            break;
        case 6:
            FindTotalNumberOfStudents(&FIFO);
            break;
        case 7:
            DeleteStudentByRollNumber(&FIFO);
            break;
        case 8:
            UpdateStudentByRollNumber(&FIFO);
            break;
        case 9:
            ShowAllStudents(&FIFO);
            break;
        case 10:
            return 0;
            break;
        default:
            DPRINTF("Invalid Choice\n");
            break;
        }
    }

    return 0;
}
