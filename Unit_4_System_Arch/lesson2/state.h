/*
 ============================================================================
 Name        : state.h
 Author      : Abdelrahman_ElBadawy
 Version     : 1.0
 Created on  : Sep 23, 2023
 Copyright   : Your copyright notice
 Description : state.h c file , Ansi-style
 ============================================================================
 */
#ifndef SRC_STATE_H_
#define SRC_STATE_H_

// Automatic State Function generate

#define STATE_define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_

//states connection
void US_Set_distance(int distance);
void DC_Motor_Set_speed(int speed);

#endif /* SRC_STATE_H_ */
