#include "Student.h"
Student_t *temp;
// Function To Add Student
void AddStudent(FIFO_BUF_t *FIFO)
{
    Student_t s;

    getRollNumber(&s);
    getFirstName(&s);
    getLastName(&s);
    s.GPA = getGPA();
    getCourseId(&s);

    // if (search_by_roll_number(FIFO, (*temp).roll_number) == FIFO_no_error)
    // {
    //     DPRINTF("Student Roll Number Already Exists\n");
    //     return;
    // }
    if (FIFO_enqueue(FIFO, s) == FIFO_no_error)
    {
        DPRINTF("Students Added Successfully\n");
    }
    else
    {
        DPRINTF("Data filled failed\n");
    }
}
void getRollNumber(Student_t *s)
{
    char temp_text[40];
    DPRINTF("Enter the student's Roll number:\n");
    scanf("%s", temp_text);
    s->roll_number = atoi(temp_text);
}
void getFirstName(Student_t *s)
{
    char temp_text[40];
    DPRINTF("Enter the student's first Name:\n");
    scanf("%s", temp_text);
    strcpy(s->first_name, temp_text);
}
void getLastName(Student_t *s)
{
    char temp_text[40];
    DPRINTF("Enter the student's last Name:\n");
    scanf("%s", temp_text);
    strcpy(s->last_name, temp_text);
}
float getGPA()
{
    float temp_text;
    DPRINTF("Enter the student's GPA: \n");
    scanf("%f", &temp_text);
    return temp_text;
}
void getCourseId(Student_t *s)
{
    char temp_text[40];
    for (int i = 0; i < 5; i++)
    {
        DPRINTF("Enter the student's registered course number %d:\n", i + 1);
        scanf("%s", temp_text);

        s->course_id[i] = atoi(temp_text);
    }
}

// Function To Add Student From File
void AddStudentFromFile(FIFO_BUF_t *FIFO)
{
    Student_t student;
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    if (fptr == NULL)
    {
        DPRINTF("Error Opening File\n");
        return;
    }
    // Read data from file using fscanf
    fscanf(fptr, "%u %49s %49s %f %u %u %u %u %u",
           &student.roll_number,
           student.first_name,
           student.last_name,
           &student.GPA,
           &student.course_id[0],
           &student.course_id[1],
           &student.course_id[2],
           &student.course_id[3],
           &student.course_id[4]);
    fclose(fptr);
    FIFO_enqueue(FIFO, student);
    DPRINTF("Student Roll Number: %d\n", student.roll_number);
    DPRINTF("Students Added Successfully\n");
}
// Function To Find Student By Roll Number
BUFFER_Status searchByRollNumber(FIFO_BUF_t *buf)
{
    char roll_number[10];
    DPRINTF("Please Enter Student Roll Number: \n");
    scanf(" %s", roll_number);

    if (!buf->base || !buf->head || !buf->tail)
    {
        return FIFO_Null; // Return null status if pointers are invalid
    }

    if (FIFO_isFull(buf) == FIFO_full)
    {
        return FIFO_full; // Return full status if buffer is full
    }

    element_type *current = buf->tail;
    int count = buf->count;

    // Iterate through the elements and print them
    while (count > 0)
    {
        if (buf->base->roll_number == atoi(roll_number))
        {
            DPRINTF("Student Found\n");
            DPRINTF("Student Roll Number: %d\n", buf->base->roll_number);
            DPRINTF("Student First Name: %s\n", buf->base->first_name);
            DPRINTF("Student Last Name: %s\n", buf->base->last_name);
            DPRINTF("Student GPA: %f\n", buf->base->GPA);
            for (int j = 0; j < 5; j++)
            {
                DPRINTF("Student Course %d ID: %d\n", j + 1, buf->base->course_id[j]);
            }
            return FIFO_no_error;
        }

        if (current == (buf->base + (buf->length * sizeof(element_type))))
        {
            current = buf->base;
        }
        else
        {
            current++;
        }

        count--;
    }
    //    DPRINTF("Student Not Found\n");
    return FIFO_empty;
}

// Function To Find Student By First Name
void FindStudentByFirstName(FIFO_BUF_t *FIFO)
{
    char first_name[50];
    DPRINTF("Please Enter Student First Name: ");
    scanf(" %s", first_name);
    search_by_first_name(FIFO, first_name);
}
// Function To Find Student By Course Id
void FindStudentByCourseId(FIFO_BUF_t *FIFO)
{
    char course_id[10];
    DPRINTF("Please Enter Student Course ID: \n");
    scanf(" %s", course_id);
    search_by_course_id(FIFO, atoi(course_id));
}
// Function To Find Total Number Of Students
void FindTotalNumberOfStudents(FIFO_BUF_t *FIFO)
{
    find_total_number_of_students(FIFO);
}
// Function To Delete Student By Roll Number
BUFFER_Status DeleteStudentByRollNumber(FIFO_BUF_t *buf)
{
    int roll_number;
    DPRINTF("Please Enter Student Roll Number: \n");
    scanf(" %d", &roll_number);
    if (!buf->base || !buf->head || !buf->tail)
    {
        return FIFO_Null; // Return null status if pointers are invalid
    }

    if (FIFO_isFull(buf) == FIFO_full)
    {
        return FIFO_full; // Return full status if buffer is full
    }

    element_type *current = buf->tail;
    int count = buf->count;

    // Iterate through the elements and print them
    while (count > 0)
    {
        if (buf->base->roll_number == roll_number)
        {
            buf->base->roll_number = 0;
            strcpy(buf->base->first_name, "");
            strcpy(buf->base->last_name, "");
            buf->base->GPA = 0;
            for (int j = 0; j < 5; j++)
            {
                buf->base->course_id[j] = 0;
            }
            DPRINTF("Student Deleted Successfully\n");
            (buf->count)--;
            DPRINTF("Total Number Of Students: %d\n", buf->count);
            return FIFO_no_error;
        }

        if (current == (buf->base + (buf->length * sizeof(element_type))))
        {
            current = buf->base;
        }
        else
        {
            current++;
        }

        count--;
    }
    return FIFO_empty;
}
// Function To Update Student By Roll Number
BUFFER_Status UpdateStudentByRollNumber(FIFO_BUF_t *buf)
{
    int roll_number;
    DPRINTF("Please Enter Student Roll Number: \n");
    scanf("%d", &roll_number);
    if (!buf->base || !buf->head || !buf->tail)
    {
        return FIFO_Null; // Return null status if pointers are invalid
    }

    if (FIFO_isFull(buf) == FIFO_full)
    {
        return FIFO_full; // Return full status if buffer is full
    }

    element_type *current = buf->tail;
    int count = buf->count;

    // Iterate through the elements and print them
    while (count > 0)
    {
        if (buf->base->roll_number == roll_number)
        {
            DPRINTF("Student Found\n");
            DPRINTF("Student Roll Number: %d\n", buf->base->roll_number);
            DPRINTF("Student First Name: %s\n", buf->base->first_name);
            DPRINTF("Student Last Name: %s\n", buf->base->last_name);
            DPRINTF("Student GPA: %f\n", buf->base->GPA);

            DPRINTF("______________________________________________________\n");
            for (int j = 0; j < 5; j++)
            {
                DPRINTF("Student Course %d ID: %d\n", j + 1, buf->base->course_id[j]);
            }
            DPRINTF("______________________________________________________\n");

            getFirstName(buf->base);
            getLastName(buf->base);
            buf->base->GPA = getGPA();
            for (int j = 0; j < 5; j++)
            {
                DPRINTF("Please Enter Student Course %d ID: ", j + 1);
                scanf(" %d", &buf->base->course_id[j]);
            }
            DPRINTF("Student Updated Successfully\n");
            return FIFO_no_error;
        }

        if (current == (buf->base + (buf->length * sizeof(element_type))))
        {
            current = buf->base;
        }
        else
        {
            current++;
        }

        count--;
    }
    return FIFO_empty;
}
// Function To Show All Students
void ShowAllStudents(FIFO_BUF_t *FIFO)
{
    print_FIFO(FIFO);
}
