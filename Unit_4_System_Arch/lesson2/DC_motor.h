/*
 ============================================================================
 Name        : DC_motor.h
 Author      : Abdelrahman_ElBadawy
 Version     : 1.0
 Created on  : Sep 23, 2023
 Copyright   : Your copyright notice
 Description : DC_motor.h c file , Ansi-style
 ============================================================================
 */
#ifndef SRC_DC_MOTOR_H_
#define SRC_DC_MOTOR_H_

#include"state.h"

enum {
	DC_idle, DC_busy
} DC_state_id;

// declare states functions of DC
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

// State pointer to function
extern void (*DC_state)();

#endif /* SRC_DC_MOTOR_H_ */
