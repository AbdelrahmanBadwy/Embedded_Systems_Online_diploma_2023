/*
 ============================================================================
 Name        : Alarm_actuator.h
 Author      : Abdelrahman_ElBadawy
 Created on  : Oct 16, 2023
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : pressure_controller/Alarm_actuator.h , Ansi-style
 ============================================================================
 */
#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_


#include "state.h"
#include "driver.h"


//define states id
enum {
    Alarm_actuator_AlarmON_state,
	Alarm_actuator_AlarmOFF_state,
	Alarm_actuator_Waiting_state
}Alarm_actuator_state_id;

//States
STATE_DEFINE(Alarm_actuator_AlarmON);
STATE_DEFINE(Alarm_actuator_AlarmOFF);
STATE_DEFINE(Alarm_actuator_Waiting);

#endif /* ALARM_ACTUATOR_H_ */
