/*
 ============================================================================
 Name        : Linked_list.c
 Author      : Abdelrahman_ElBadawy
 Version     : 1.0
 Created on  : Sep 22, 2023
 Copyright   : Your copyright notice
 Description : Linked_list c file , Ansi-style
 ============================================================================
 */

#include "Linked_list.h"
// Pointer to the first student in the list
struct StudentNode *gp_FirstStudent = NULL;

// Function to add a new student to the linked list
void addStudent() {
	struct StudentNode *pNewStudent;
	struct StudentNode *pLastStudent;
	char tempText[40];

	// Check if the list is empty
	if (gp_FirstStudent == NULL) {
		// Create a new record
		pNewStudent = (struct StudentNode*) malloc(sizeof(struct StudentNode));

		// Assign it to gp_FirstStudent
		gp_FirstStudent = pNewStudent;
	} else {
		pLastStudent = gp_FirstStudent;
		while (pLastStudent->p_NextStudent)
			pLastStudent = pLastStudent->p_NextStudent;

		// Create a new record
		pNewStudent = (struct StudentNode*) malloc(sizeof(struct StudentNode));
		pLastStudent->p_NextStudent = pNewStudent;
	}

	// Fill the new record
	DPRINTF("\nEnter The ID: ");
	gets(tempText);
	pNewStudent->student.ID = atoi(tempText);

	DPRINTF("\nEnter Student Full Name: ");
	gets(pNewStudent->student.Name);

	DPRINTF("\nEnter The Height: ");
	gets(tempText);
	pNewStudent->student.Height = atof(tempText);

	// Set the next pointer
	pNewStudent->p_NextStudent = NULL;
}

// Function to delete a student based on their ID
int deleteStudent() {
	char tempText[40];
	unsigned int selectedID;

	// Get the selected ID
	DPRINTF("\nEnter the student ID to be deleted: ");
	gets(tempText);
	selectedID = atoi(tempText);

	// List is not empty
	if (gp_FirstStudent) {
		struct StudentNode *pSelectedStudent = gp_FirstStudent;
		struct StudentNode *pPreviousStudent = NULL;

		// Loop through all records
		while (pSelectedStudent) {
			// Compare each node with the selected ID
			if (pSelectedStudent->student.ID == selectedID) {
				if (pPreviousStudent) {
					pPreviousStudent->p_NextStudent =
							pSelectedStudent->p_NextStudent;
				} else {
					gp_FirstStudent = pSelectedStudent->p_NextStudent;
				}
				free(pSelectedStudent);
				return 1;
			}
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->p_NextStudent;
		}
	}
	DPRINTF("\nCannot find student ID.");
	return 0;
}

// Function to view all students in the list
void view_students() {
	// Start with the first student in the list
	struct StudentNode *currentStudent = gp_FirstStudent;

	int count = 0;  // Counter to keep track of the student number

	if (gp_FirstStudent == NULL) {
		DPRINTF("\n Empty List");
	} else {
		// Loop through each student in the list
		while (currentStudent) {
			DPRINTF("\n---------------------------------\n");
			DPRINTF("\n Student number %d ", count + 1);
			DPRINTF("\n \t ID: %d ", currentStudent->student.ID);
			DPRINTF("\n \t Name: %s ", currentStudent->student.Name);
			DPRINTF("\n \t Height: %f ", currentStudent->student.Height);
			DPRINTF("\n---------------------------------\n");

			// Move to the next student in the list
			currentStudent = currentStudent->p_NextStudent;
			count++;
		}
	}
}

// Function to delete all students and free memory
void Delete_All_Students() {
	// Start with the first student in the list
	struct StudentNode *currentStudent = gp_FirstStudent;

	if (gp_FirstStudent == NULL) {
		DPRINTF("\n Empty List");
	} else {
		// Loop through each student in the list
		while (currentStudent) {
			// Temporarily store the current student
			struct StudentNode *tempStudent = currentStudent;

			// Move to the next student in the list
			currentStudent = currentStudent->p_NextStudent;

			// Free the memory associated with the current student
			free(tempStudent);
		}

		// Reset the pointer to the first student to NULL (empty list)
		gp_FirstStudent = NULL;
	}
}

// Function to get information of the student at a specified index
int Get_Nth() {
	int selected_index, count = 1;
	char index[40];

	// Start with the first student in the list
	struct StudentNode *currentStudent = gp_FirstStudent;

	if (gp_FirstStudent == NULL) {
		DPRINTF("\n Empty List");
	} else {
		DPRINTF("\n Enter The Index :");
		gets(index);
		selected_index = atoi(index);

		// Loop through each student in the list
		while (currentStudent) {
			if (selected_index == count) {
				DPRINTF("\n---------------------------------\n");
				DPRINTF("\n Student (%d)", count);
				DPRINTF("\n ID : %d", currentStudent->student.ID);
				DPRINTF(" \nNAME : %s", currentStudent->student.Name);
				DPRINTF(" \nHEIGHT : %f", currentStudent->student.Height);
				DPRINTF("\n---------------------------------\n");

				return 1;
			} else {
				currentStudent = currentStudent->p_NextStudent;
				count++;
			}
		}
	}
	DPRINTF("\n === Invalid pointer ===");

	return 0;
}

// Function to count the number of students in the linked list
void count() {
	int count = 0;
	struct StudentNode *currentStudent = gp_FirstStudent;

	if (gp_FirstStudent == NULL) {
		DPRINTF("\n Empty List");
	} else {
		// Navigate through all records
		while (currentStudent) {
			currentStudent = currentStudent->p_NextStudent;
			count++;
		}
		DPRINTF("\n #Number Of Students: %d", count);
	}
}

// Recursive function to count the number of students in the linked list
int countRecursive(struct StudentNode *student) {
	// Base case: reached the end of the list
	if (student == NULL)
		return 0;

	// Recursive call: count the rest of the list and add 1 for this student
	return 1 + countRecursive(student->p_NextStudent);
}

// Function to get the Nth student from the end of the linked list
int Get_Nth_From_End() {
	if (gp_FirstStudent == NULL) {
		DPRINTF("\n Empty List");
	} else {
		struct StudentNode *main_ptr = gp_FirstStudent;
		struct StudentNode *ref_ptr = gp_FirstStudent;

		char temp_text[40];
		int selected_index, i, count = 0;
		DPRINTF("\n Enter student index: ");
		gets(temp_text);
		selected_index = atoi(temp_text);

		// Move the ref_ptr to the Nth node from the start
		for (i = 0; i < selected_index; i++) {
			if (ref_ptr == NULL) {
				DPRINTF("\n Invalid index.");
				return 1;
			}
			ref_ptr = ref_ptr->p_NextStudent;
		}

		// Move both pointers to find the Nth node from the end
		while (ref_ptr) {
			ref_ptr = ref_ptr->p_NextStudent;
			if (ref_ptr == NULL)
				break;
			main_ptr = main_ptr->p_NextStudent;
			count++;
		}

		// Display the Nth node from the end
		DPRINTF("\n---------------------------------\n");
		DPRINTF("\n Student (%d)", count);
		DPRINTF("\n ID : %d", main_ptr->student.ID);
		DPRINTF(" \nNAME : %s", main_ptr->student.Name);
		DPRINTF(" \nHEIGHT : %f", main_ptr->student.Height);
		DPRINTF("\n---------------------------------\n");
		return 0;
	}
	return 1;
}

// Function to find and print the middle student of the linked list
void getMiddle() {
	int count = 1;
	struct StudentNode *p_FastStudent = gp_FirstStudent;
	struct StudentNode *p_SlowStudent = gp_FirstStudent;

	while (p_FastStudent->p_NextStudent) {
		p_FastStudent = p_FastStudent->p_NextStudent->p_NextStudent;
		p_SlowStudent = p_SlowStudent->p_NextStudent;
		count++;
	}

	// Print the middle student
	DPRINTF("\n---------------------------------\n");
	DPRINTF("\n Student (%d)", count);
	DPRINTF("\n ID : %d", p_SlowStudent->student.ID);
	DPRINTF(" \nNAME : %s", p_SlowStudent->student.Name);
	DPRINTF(" \nHEIGHT : %f", p_SlowStudent->student.Height);
	DPRINTF("\n---------------------------------\n");
}

// Function to reverse the linked list
void reverseList() {
	// Check if the list is empty
	if (gp_FirstStudent == NULL) {
		DPRINTF("\n Empty List");
	} else {
		struct StudentNode *pCurrentStudent = gp_FirstStudent;
		struct StudentNode *pPreviousStudent = NULL;
		struct StudentNode *p_NextStudent = NULL;

		// Traverse the linked list and reverse the pointers
		while (pCurrentStudent != NULL) {
			p_NextStudent = pCurrentStudent->p_NextStudent;
			pCurrentStudent->p_NextStudent = pPreviousStudent;
			pPreviousStudent = pCurrentStudent;
			pCurrentStudent = p_NextStudent;
		}

		// Update the pointer to the first student for the reversed list
		gp_FirstStudent = pPreviousStudent;
	}
	DPRINTF("====Reverse is done===="); // Print a message indicating the reversal is complete
}
