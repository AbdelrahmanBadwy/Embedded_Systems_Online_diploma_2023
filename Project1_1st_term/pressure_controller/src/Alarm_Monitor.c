/*
 ============================================================================
 Name        : Alarm_Monitor.c
 Author      : Abdelrahman_ElBadawy
 Created on  : Oct 16, 2023
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : pressure_controller/Alarm_Monitor.c , Ansi-style
 ============================================================================
 */

#include "Alarm_Monitor.h"

void (*pAlarm_Monitor)();

int high_pressure_detected(){
	pAlarm_Monitor=STATE(Alarm_Monitor_AlarmON);
	return Alarm_Monitor_AlarmON_state;
}

STATE_DEFINE(Alarm_Monitor_AlarmON){
	Alarm_Monitor_state_id = Alarm_Monitor_AlarmON_state;
	Start_alarm();
	Delay(Alarm_timer);
	pAlarm_Monitor=STATE(Alarm_Monitor_Waiting);
}


STATE_DEFINE(Alarm_Monitor_Waiting){
	Alarm_Monitor_state_id = Alarm_Monitor_Waiting_state;
	Stop_alarm();
}
