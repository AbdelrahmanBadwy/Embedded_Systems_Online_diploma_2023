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
BUFFER_Status FIFO_init(FIFO_BUF_t* buf, element_type* bufArr, unsigned int length) {
    // Check if bufArr is NULL
    if (bufArr == NULL) {
        return FIFO_Null;
    }

    // Initialize FIFO buffer members
    buf->base = bufArr;
    buf->head = bufArr;
    buf->tail = bufArr;
    buf->length = length;
    buf->count = 0;

    // Check if base, head, and tail pointers are valid
    if (!buf->base || !buf->head || !buf->tail) {
        return FIFO_Null;
    }

    return FIFO_no_error;  // Return no error status
}

// Check if the FIFO buffer is full
BUFFER_Status FIFO_isFull(FIFO_BUF_t* buf) {
    if (!buf->base || !buf->head || !buf->tail) {
        return FIFO_Null;  // Return null status if pointers are invalid
    }

    if (buf->count == buf->length) {
        return FIFO_full;  // Return full status if buffer is full
    }

    return FIFO_not_full;  // Return not full status if buffer is not full
}

// Check if the FIFO buffer is empty
BUFFER_Status FIFO_isEmpty(FIFO_BUF_t* buf) {
    if (!buf->base || !buf->head || !buf->tail) {
        return FIFO_Null;  // Return null status if pointers are invalid
    }

    if (buf->count == 0) {
        return FIFO_empty;  // Return empty status if buffer is empty
    }

    return FIFO_not_empty;  // Return not empty status if buffer is not empty
}

// Enqueue an item into the FIFO buffer
BUFFER_Status FIFO_enqueue(FIFO_BUF_t* buf, element_type item) {
    if (!buf->base || !buf->head || !buf->tail) {
        return FIFO_Null;  // Return null status if pointers are invalid
    }

    if (FIFO_isFull(buf) == FIFO_full) {
        return FIFO_full;  // Return full status if buffer is full
    }

    *(buf->head) = item;  // Store the item at head
    buf->count++;  // Increment count

    // Update head (considering circular buffer)
    if (buf->head == (buf->base + (buf->length * sizeof(element_type)))) {
        buf->head = buf->base;
    } else {
        buf->head++;
    }

    return FIFO_no_error;  // Return no error status
}

// Dequeue an item from the FIFO buffer
BUFFER_Status FIFO_dequeue(FIFO_BUF_t* buf, element_type* item) {
    if (!buf->base || !buf->head || !buf->tail) {
        return FIFO_Null;  // Return null status if pointers are invalid
    }

    if (FIFO_isEmpty(buf) == FIFO_empty) {
        return FIFO_empty;  // Return empty status if buffer is empty
    }

    *item = *(buf->tail);  // Retrieve item from tail
    buf->count--;  // Decrement count

    // Update tail (considering circular buffer)
    if (buf->tail == (buf->base + (buf->length * sizeof(element_type)))) {
        buf->tail = buf->base;
    } else {
        buf->tail++;
    }

    return FIFO_no_error;  // Return no error status
}

// Print the elements in the FIFO buffer
void print_FIFO(FIFO_BUF_t* buf) {
    if (!buf->base || !buf->head || !buf->tail) {
        printf("FIFO_Null\n");
        return;
    }

    if (FIFO_isEmpty(buf) == FIFO_empty) {
        printf("FIFO is empty\n");
        return;
    }

    printf("FIFO elements: ");
    element_type* current = buf->tail;
    int count = buf->count;

    // Iterate through the elements and print them
    while (count > 0) {
        printf("%d ", *current);

        if (current == (buf->base + (buf->length * sizeof(element_type)))) {
            current = buf->base;
        } else {
            current++;
        }

        count--;
    }

    printf("\n");
}
