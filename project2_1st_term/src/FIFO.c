/*
 ============================================================================
 Name        : FIFO.c
 Author      : Abdelrahman_ElBadawy
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : FIFO (Queue) c file , Ansi-style
 ============================================================================
 */
#include "FIFO.h"

// Initialize the FIFO buffer
BUFFER_Status FIFO_init(FIFO_BUF_t *buf, element_type bufArr[], unsigned int length)
{
    // Check if bufArr is NULL
    if (bufArr == NULL)
    {
        return FIFO_Null;
    }

    // Initialize FIFO buffer members
    buf->base = bufArr;
    buf->head = bufArr;
    buf->tail = bufArr;
    buf->length = length;
    buf->count = 0;

    // Check if base, head, and tail pointers are valid
    if (!buf->base || !buf->head || !buf->tail)
    {
        return FIFO_Null;
    }

    return FIFO_no_error; // Return no error status
}

// Check if the FIFO buffer is full
BUFFER_Status FIFO_isFull(FIFO_BUF_t *buf)
{
    if (!buf->base || !buf->head || !buf->tail)
    {
        return FIFO_Null; // Return null status if pointers are invalid
    }

    if (buf->count == buf->length)
    {
        return FIFO_full; // Return full status if buffer is full
    }

    return FIFO_not_full; // Return not full status if buffer is not full
}

// Check if the FIFO buffer is empty
BUFFER_Status FIFO_isEmpty(FIFO_BUF_t *buf)
{
    if (!buf->base || !buf->head || !buf->tail)
    {
        return FIFO_Null; // Return null status if pointers are invalid
    }

    if (buf->count == 0)
    {
        return FIFO_empty; // Return empty status if buffer is empty
    }

    return FIFO_not_empty; // Return not empty status if buffer is not empty
}

// Enqueue an item into the FIFO buffer
BUFFER_Status FIFO_enqueue(FIFO_BUF_t *buf, element_type item)
{
    if (!buf->base || !buf->head || !buf->tail)
    {
        return FIFO_Null; // Return null status if pointers are invalid
    }

    if (FIFO_isFull(buf) == FIFO_full)
    {
        return FIFO_full; // Return full status if buffer is full
    }

    *(buf->head) = item; // Store the item at head
    buf->count++;        // Increment count

    // Update head (considering circular buffer)
    if (buf->head == (buf->base + (buf->length * sizeof(element_type))))
    {
        buf->head = buf->base;
    }
    else
    {
        buf->head++;
    }

    return FIFO_no_error; // Return no error status
}

// Dequeue an item from the FIFO buffer
BUFFER_Status FIFO_dequeue(FIFO_BUF_t *buf, element_type *item)
{
    if (!buf->base || !buf->head || !buf->tail)
    {
        return FIFO_Null; // Return null status if pointers are invalid
    }

    if (FIFO_isEmpty(buf) == FIFO_empty)
    {
        return FIFO_empty; // Return empty status if buffer is empty
    }

    *item = *(buf->tail); // Retrieve item from tail
    buf->count--;         // Decrement count

    // Update tail (considering circular buffer)
    if (buf->tail == (buf->base + (buf->length * sizeof(element_type))))
    {
        buf->tail = buf->base;
    }
    else
    {
        buf->tail++;
    }

    return FIFO_no_error; // Return no error status
}

// search for student by first name and print all students with the same first name
BUFFER_Status search_by_first_name(FIFO_BUF_t *buf, char *first_name)
{
    // strcmp(buf->base[i].first_name, first_name) == 0
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
        if (strcmp(current->first_name, first_name) == 0)
        {
            DPRINTF("Student Found\n");
            DPRINTF("Student Roll Number: %d\n", current->roll_number);
            DPRINTF("Student First Name: %s\n", current->first_name);
            DPRINTF("Student Last Name: %s\n", current->last_name);
            DPRINTF("Student GPA: %f\n", current->GPA);
            for (int j = 0; j < 5; j++)
            {
                DPRINTF("Student Course %d ID: %d\n", j + 1, current->course_id[j]);
            }
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

// search for student by course id and print all students with the same course id
BUFFER_Status search_by_course_id(FIFO_BUF_t *buf, int course_id)
{
    char Exists = 0;
    // strcmp(buf->base[i].first_name, first_name) == 0
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
        for (int j = 0; j < 5; j++)
        {
            if (current->course_id[j] == course_id)
            {
                DPRINTF("Student Found\n");
                DPRINTF("Student Roll Number: %d\n", current->roll_number);
                DPRINTF("Student First Name: %s\n", current->first_name);
                DPRINTF("Student Last Name: %s\n", current->last_name);
                DPRINTF("Student GPA: %f\n", current->GPA);
                for (int j = 0; j < 5; j++)
                {
                    DPRINTF("Student Course %d ID: %d\n", j + 1, current->course_id[j]);
                }
                Exists = 1;
            }
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
    if (Exists == 1)
    {
        return FIFO_no_error;
    }
    return FIFO_empty;
}

// search for student by roll number and delete it
BUFFER_Status delete_by_roll_number(FIFO_BUF_t *buf, int roll_number)
{
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
            // DPRINTF("Student Found\n");
            // DPRINTF("Student Roll Number: %d\n", buf->base->roll_number);
            // DPRINTF("Student First Name: %s\n", buf->base->first_name);
            // DPRINTF("Student Last Name: %s\n", buf->base->last_name);
            // DPRINTF("Student GPA: %d\n", buf->base->GPA);
            // for (int j = 0; j < 5; j++)
            // {
            //     DPRINTF("Student Course %d ID: %d\n", j + 1, buf->base->course_id[j]);
            // }
            buf->base->roll_number = 0;
            strcpy(buf->base->first_name, "");
            strcpy(buf->base->last_name, "");
            buf->base->GPA = 0;
            for (int j = 0; j < 5; j++)
            {
                buf->base->course_id[j] = 0;
            }
            return FIFO_no_error;
        }
        buf->count--;
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

// Find Total Number Of Students
BUFFER_Status find_total_number_of_students(FIFO_BUF_t *buf)
{
    DPRINTF("Total Number Of Students: %d\n", buf->count);
    return FIFO_no_error;
}

// Print the elements in the FIFO buffer
void print_FIFO(FIFO_BUF_t *buf)
{
    if (!buf->base || !buf->head || !buf->tail)
    {
        printf("FIFO_Null\n");
        return;
    }

    if (FIFO_isEmpty(buf) == FIFO_empty)
    {
        printf("FIFO is empty\n");
        return;
    }

    printf("FIFO elements: \n");
    element_type *current = buf->tail;
    int count = buf->count;

    // Iterate through the elements and print them
    while (count > 0)
    {
        DPRINTF("Roll Number :%d ", current->roll_number);
        DPRINTF("||First Name :%s ", current->first_name);
        DPRINTF("||Last Name :%s ", current->last_name);
        DPRINTF("||GPA :%f ", current->GPA);
        for (int i = 0; i < 5; i++)
        {
            DPRINTF("||Course %d ID :%d ", i + 1, current->course_id[i]);
        }
        DPRINTF("\n");
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

    printf("\n");
}
