/*
 ============================================================================
 Name        : Alarm_Monitor.h
 Author      : Abdelrahman_ElBadawy
 Created on  : Oct 16, 2023
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : pressure_controller/Alarm_Monitor.h , Ansi-style
 ============================================================================
 */
#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_


#include "state.h"
#include "driver.h"
#define Alarm_timer 60
//define states id
enum {
	Alarm_Monitor_AlarmON_state,
	Alarm_Monitor_Waiting_state
}Alarm_Monitor_state_id;

//States
STATE_DEFINE(Alarm_Monitor_AlarmON);
STATE_DEFINE(Alarm_Monitor_Waiting);


#endif /* ALARM_MONITOR_H_ */
