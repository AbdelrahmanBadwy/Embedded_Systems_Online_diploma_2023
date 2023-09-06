/*
 ============================================================================
 Name        : lifo.h
 Author      : Abdelrahman_ElBadawy
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : LIFO (stack) h file , Ansi-style
 ============================================================================
 */
#ifndef LIFO_H_
#define LIFO_H_

#include<stdio.h>

#define LIFO_buffer_length 5

typedef struct 
{   
    unsigned int length ;
    unsigned int count ;
    unsigned int* head ;
    unsigned int* base ;
    
} LIFO_BUF_t;

typedef enum {
    LIFO_no_error,
    LIFO_full,
    LIFO_not_full,
    LIFO_empty,
    LIFO_not_empty,
    LIFO_Null
    
}BUFFER_Status;

BUFFER_Status LIFO_isFull(LIFO_BUF_t* buf);
BUFFER_Status LIFO_add(LIFO_BUF_t* buf, unsigned int item);
BUFFER_Status LIFO_pop(LIFO_BUF_t* buf, unsigned int* item);

#endif