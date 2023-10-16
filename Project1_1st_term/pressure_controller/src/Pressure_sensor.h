/*
 ============================================================================
 Name        : Pressure_sensor.h
 Author      : Abdelrahman_ElBadawy
 Created on  : Oct 16, 2023
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : pressure_controller/Pressure_sensor.h , Ansi-style
 ============================================================================
 */
#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"
#include "driver.h"

#define sensorPullTime 100

//define states id
enum {
    pressure_sensor_Reading_state,
    pressure_sensor_Waiting_state
}pressure_sensor_state_id;

//States
STATE_DEFINE(pressure_sensor_Reading);
STATE_DEFINE(pressure_sensor_Waiting);


#endif /* PRESSURE_SENSOR_H_ */
