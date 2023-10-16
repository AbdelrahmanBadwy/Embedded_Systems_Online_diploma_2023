/*
 ============================================================================
 Name        : Alarm_actuator.c
 Author      : Abdelrahman_ElBadawy
 Created on  : Oct 16, 2023
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : pressure_controller/Alarm_actuator.c , Ansi-style
 ============================================================================
 */

#include "Alarm_actuator.h"

void (*pAlarm_actuator)();

void Start_alarm(){
	Set_Alarm_actuator(0);
}

void Stop_alarm(){
	Set_Alarm_actuator(1);
}

STATE_DEFINE(Alarm_actuator_AlarmON){
	Alarm_actuator_state_id = Alarm_actuator_AlarmON_state;
	pAlarm_actuator = STATE(Alarm_actuator_Waiting);
}
STATE_DEFINE(Alarm_actuator_AlarmOFF){
	Alarm_actuator_state_id = Alarm_actuator_AlarmOFF_state;
	pAlarm_actuator = STATE(Alarm_actuator_Waiting);

}
STATE_DEFINE(Alarm_actuator_Waiting){
	Alarm_actuator_state_id = Alarm_actuator_Waiting_state;
}
