/*
 ============================================================================
 Name        : main.c
 Author      : Abdelrahman_ElBadawy
 Created on  : Oct 16, 2023
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : pressure_controller/main.c , Ansi-style
 ============================================================================
 */

#include <stdint.h>
#include "Pressure_sensor.h"
#include "Main_Algo.h"
#include "Alarm_Monitor.h"
#include "Alarm_actuator.h"


extern void (*pMain_Algo)();
extern void (*pAlarm_Monitor)();
extern void (*pAlarm_actuator)();
extern void (*pPressure_sensor)();

void init(){
	GPIO_INITIALIZATION();

	pMain_Algo = STATE(Main_Algo_Waiting);
	pAlarm_Monitor=STATE(Alarm_Monitor_Waiting);
	pAlarm_actuator = STATE(Alarm_actuator_Waiting);
	pPressure_sensor = STATE(pressure_sensor_Reading);

}
int main (){
	init();

	while (1)
	{
		//Implement your Design
		pPressure_sensor();
		pMain_Algo();
		pAlarm_Monitor();
		pAlarm_actuator();
	}

}
