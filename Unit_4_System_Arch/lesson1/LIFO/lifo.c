/*
 ============================================================================
 Name        : lifo.c
 Author      : Abdelrahman_ElBadawy
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : LIFO (stack) c file , Ansi-style
 ============================================================================
 */
#include "lifo.h"
BUFFER_Status LIFO_init(LIFO_BUF_t* buf, unsigned int* bufArr, unsigned int length ){
    if (bufArr == NULL)
    {
        return LIFO_Null;
    }
    buf->base = bufArr;
    buf->head = bufArr;
    buf->length = length;
    buf->count = 0;
    return LIFO_no_error;
}
BUFFER_Status LIFO_isFull(LIFO_BUF_t* buf){
    if (buf->count == buf->length)
    {
        return LIFO_full;
    }
    return LIFO_not_full;
}
BUFFER_Status LIFO_isEmpty(LIFO_BUF_t* buf){
    if (buf->count == 0)
    {
        return LIFO_empty;
    }
    return LIFO_not_empty;
}
BUFFER_Status LIFO_add(LIFO_BUF_t* buf, unsigned int item){
    if (!buf->base || !buf->head)
    {
        return LIFO_Null;
    }
    if (LIFO_isFull(buf) == LIFO_full)
    {
        return LIFO_full;
    }
    *(buf->head) = item;
    buf->head ++ ;
    buf->count ++ ;
    return LIFO_no_error;
}
BUFFER_Status LIFO_pop(LIFO_BUF_t* buf, unsigned int* item){
    if (!buf->base || !buf->head)
    {
        return LIFO_Null;
    }
    if (LIFO_isEmpty(buf) == LIFO_empty)
    {
        return LIFO_empty;
    }
    buf->head --;
    buf->count --;
    *(item) = *(buf->head);
    return LIFO_no_error ;
}