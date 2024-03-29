/*
 ============================================================================
 Name        : FIFO.h
 Author      : Abdelrahman_ElBadawy
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : FIFO (Queue) h file , Ansi-style
 ============================================================================
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include <stdint.h>
#include <string.h>
typedef struct
{
    char first_name[50];
    char last_name[50];
    unsigned int roll_number;
    unsigned int course_id[5];
    float GPA;
} Student_t;

#define element_type Student_t // Define the type of elements in the FIFO as uint8_t
#define DPRINTF(...)         \
    {                        \
        fflush(stdout);      \
        fflush(stdout);      \
        printf(__VA_ARGS__); \
        fflush(stdout);      \
        fflush(stdout);      \
    }
typedef struct
{
    unsigned int length; // Length of the FIFO buffer
    unsigned int count;  // Current count of elements in the FIFO
    element_type *head;  // Pointer to the head of the FIFO
    element_type *base;  // Pointer to the base of the FIFO (start of the buffer)
    element_type *tail;  // Pointer to the tail of the FIFO
} FIFO_BUF_t;            // Define a structure to represent a FIFO buffer

typedef enum
{
    FIFO_no_error,  // No error status
    FIFO_full,      // FIFO is full
    FIFO_not_full,  // FIFO is not full
    FIFO_empty,     // FIFO is empty
    FIFO_not_empty, // FIFO is not empty
    FIFO_Null       // FIFO is null (invalid)
} BUFFER_Status;    // Define an enumeration for buffer status

// Initialize the FIFO buffer
BUFFER_Status FIFO_init(FIFO_BUF_t *buf, element_type bufArr[], unsigned int length);

// Check if the FIFO buffer is full
BUFFER_Status FIFO_isFull(FIFO_BUF_t *buf);

// Check if the FIFO buffer is empty
BUFFER_Status FIFO_isEmpty(FIFO_BUF_t *buf);

// Enqueue an item into the FIFO buffer
BUFFER_Status FIFO_enqueue(FIFO_BUF_t *buf, element_type item);

// Dequeue an item from the FIFO buffer
BUFFER_Status FIFO_dequeue(FIFO_BUF_t *buf, element_type *item);

// Print the elements in the FIFO buffer
void print_FIFO(FIFO_BUF_t *buf);

// Find Student By Roll Number
// BUFFER_Status searchByRollNumber(FIFO_BUF_t* buf);

// Find Student By First Name
BUFFER_Status search_by_first_name(FIFO_BUF_t *buf, char *first_name);

// Find Student By Course Id
BUFFER_Status search_by_course_id(FIFO_BUF_t *buf, int course_id);

// Find Total Number Of Students
BUFFER_Status find_total_number_of_students(FIFO_BUF_t *buf);

// Delete Student By Roll Number
BUFFER_Status delete_by_roll_number(FIFO_BUF_t *buf, int roll_number);

#endif /* FIFO_H_ */
