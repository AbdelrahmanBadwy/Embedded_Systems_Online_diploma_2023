/*
 ============================================================================
 Name        : Linked_List.c
 Author      : Abdelrahman_Badawy
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "Linked_list.h"

int main() {
	// Example usage of the provided functions
	addStudent();
	addStudent();
	addStudent();

	DPRINTF("Students in the list:\n");
	view_students();

	DPRINTF("\nDeleting student with ID :\n");
	deleteStudent();
	view_students();

	DPRINTF("\nGetting student at index :\n");
	Get_Nth();

	DPRINTF("\nReversing the list:\n");
	reverseList();
	view_students();

	// Free the memory allocated for the students and delete all students
	Delete_All_Students();

	return 0;
}
