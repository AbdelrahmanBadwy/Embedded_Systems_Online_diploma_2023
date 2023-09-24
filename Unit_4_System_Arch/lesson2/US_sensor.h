/*
 ============================================================================
 Name        : US_sensor.h
 Author      : Abdelrahman_ElBadawy
 Version     : 1.0
 Created on  : Sep 23, 2023
 Copyright   : Your copyright notice
 Description : US_sensor.h c file , Ansi-style
 ============================================================================
 */
#ifndef SRC_US_SENSOR_H_
#define SRC_US_SENSOR_H_

#include"state.h"


enum {
	US_busy,
} US_state_id;


STATE_define(US_busy);
int US_Get_distance_random(int l, int r, int count);
void US_init();
// State pointer to function
extern void (*US_state)();

#endif /* SRC_US_SENSOR_H_ */
