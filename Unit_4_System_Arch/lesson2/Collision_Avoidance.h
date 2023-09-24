/*
 ============================================================================
 Name        : Collision_Avoidance.h
 Author      : Abdelrahman_ElBadawy
 Version     : 1.0
 Created on  : Sep 23, 2023
 Copyright   : Your copyright notice
 Description : Collision_Avoidance.h c file , Ansi-style
 ============================================================================
 */
#ifndef SRC_COLLISION_AVOIDANCE_H_
#define SRC_COLLISION_AVOIDANCE_H_

#include"state.h"
#include"state.h"
#include"stdio.h"
#include"stdlib.h"
// define states

enum {
	CA_waiting, CA_driving
} CA_state_Id;

// declare states functions of DC
STATE_define(CA_waiting);
STATE_define(CA_driving);

// State pointer to function
extern void (*CA_state)();

#endif /* SRC_COLLISION_AVOIDANCE_H_ */
