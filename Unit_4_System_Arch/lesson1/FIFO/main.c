/*
 ============================================================================
 Name        : FIFO.c
 Author      : Abdelrahman_Badawy
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include "FIFO.h"

int main() {
    // Define a FIFO buffer with a capacity of 5 elements
    element_type buffer[5];
    FIFO_BUF_t fifo;
    BUFFER_Status status;

    // Initialize the FIFO buffer
    status = FIFO_init(&fifo, buffer, 5);
    if (status != FIFO_no_error) {
        printf("FIFO initialization failed with status %d\n", status);
        return 1;
    }

    // Enqueue elements into the FIFO
    for (int i = 0; i < 6; i++) {
        status = FIFO_enqueue(&fifo, (element_type)i);
        if (status == FIFO_full) {
            printf("FIFO is full. Cannot enqueue more elements.\n");
        } else if (status == FIFO_no_error) {
            printf("Enqueued: %d\n", i);
        } else {
            printf("Enqueue failed with status %d\n", status);
        }
    }

    // Print the elements in the FIFO
    printf("\n");
    print_FIFO(&fifo);

    // Dequeue elements from the FIFO
    element_type item;
    for (int i = 0; i < 6; i++) {
        status = FIFO_dequeue(&fifo, &item);
        if (status == FIFO_empty) {
            printf("FIFO is empty. Cannot dequeue more elements.\n");
        } else if (status == FIFO_no_error) {
            printf("Dequeued: %d\n", item);
        } else {
            printf("Dequeue failed with status %d\n", status);
        }
    }

    // Print the elements in the FIFO
    printf("\n");
    print_FIFO(&fifo);

    return 0;
}
