/*
 ============================================================================
 Name        : Pressure_sensor.c
 Author      : Abdelrahman_ElBadawy
 Created on  : Oct 16, 2023
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : pressure_controller/Pressure_sensor.c , Ansi-style
 ============================================================================
 */

#include "Pressure_sensor.h"

static unsigned int pressure_value = 0;

void (*pPressure_sensor)();

STATE_DEFINE(pressure_sensor_Reading){

	pressure_sensor_state_id = pressure_sensor_Reading_state;

	pressure_value = getPressureVal();
	sendPressureVal(pressure_value);

	pPressure_sensor = STATE(pressure_sensor_Waiting);

}

STATE_DEFINE(pressure_sensor_Waiting){

	pressure_sensor_state_id = pressure_sensor_Waiting_state;

	Delay(sensorPullTime);

	pPressure_sensor = STATE(pressure_sensor_Reading);
}
