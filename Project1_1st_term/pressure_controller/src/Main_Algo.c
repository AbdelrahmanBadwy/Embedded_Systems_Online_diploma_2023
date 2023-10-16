/*
 ============================================================================
 Name        : Main_Algo.c
 Author      : Abdelrahman_ElBadawy
 Created on  : Oct 16, 2023
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : pressure_controller/Main_Algo.c , Ansi-style
 ============================================================================
 */
#include "Main_Algo.h"


static unsigned int pressure_value = 0;

void (*pMain_Algo)();

void sendPressureVal(int Pvalue){
	pressure_value = Pvalue;
}

STATE_DEFINE(Main_Algo_Waiting){
	Main_Algo_state_id = Main_Algo_Waiting_state;

	if (pressure_value > threeshold) {
		high_pressure_detected();
	}
	pMain_Algo = STATE(Main_Algo_Waiting);
}
