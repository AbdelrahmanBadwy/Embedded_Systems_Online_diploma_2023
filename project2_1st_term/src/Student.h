/*
 ============================================================================
 Name        : FIFO.h
 Author      : Abdelrahman_ElBadawy
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Student h file , Ansi-style
 ============================================================================
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FIFO.h"

void getRollNumber(Student_t *s);

void getFirstName(Student_t *s);

void getLastName(Student_t *s);

float getGPA();

void getCourseId(Student_t *s);
// Function To Add Student
void AddStudent(FIFO_BUF_t *FIFO);

// Function To Add Student From File
void AddStudentFromFile(FIFO_BUF_t *FIFO);

// Function To Find Student By Roll Number
void FindStudentByRollNumber(FIFO_BUF_t *FIFO);

// Function To Find Student By First Name
void FindStudentByFirstName(FIFO_BUF_t *FIFO);

// Function To Find Student By Course Id
void FindStudentByCourseId(FIFO_BUF_t *FIFO);

// Function To Find Total Number Of Students
void FindTotalNumberOfStudents(FIFO_BUF_t *FIFO);

// Function To Delete Student By Roll Number
BUFFER_Status DeleteStudentByRollNumber(FIFO_BUF_t *buf);

BUFFER_Status searchByRollNumber(FIFO_BUF_t *buf);

// Function To Update Student By Roll Number
BUFFER_Status UpdateStudentByRollNumber(FIFO_BUF_t *buf);

// Function To Show All Students
void ShowAllStudents(FIFO_BUF_t *FIFO);

#endif
