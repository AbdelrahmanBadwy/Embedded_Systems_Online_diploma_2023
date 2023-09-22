/*
 ============================================================================
 Name        : Linked_list.h
 Author      : Abdelrahman_ElBadawy
 Version     : 1.0
 Created on  : Sep 22, 2023
 Copyright   : Your copyright notice
 Description : Linked_list h file , Ansi-style
 ============================================================================
 */
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DPRINTF(...)    {fflush(stdout); \
						fflush(stdout); \
						printf(__VA_ARGS__); \
						fflush(stdout); \
						fflush(stdout);}

// Structure to represent a student
struct Student {
    int ID;
    char Name[50];
    float Height;
};

// Structure to represent a student node in a linked list
struct StudentNode {
    struct Student student;
    struct StudentNode* p_NextStudent;
};

void addStudent();
int deleteStudent();
void view_students();
void Delete_All_Students();
int Get_Nth();
void count();
int countRecursive(struct StudentNode *student);
int Get_Nth_From_End();
void getMiddle();
void reverseList();

#endif /* LINKED_LIST_H_ */
