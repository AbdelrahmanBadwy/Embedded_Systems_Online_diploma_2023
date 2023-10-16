/*
 ============================================================================
 Name        : Main_Algo.h
 Author      : Abdelrahman_ElBadawy
 Created on  : Oct 16, 2023
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : pressure_controller/Main_Algo.h , Ansi-style
 ============================================================================
 */
#ifndef MAIN_ALGO_H_
#define MAIN_ALGO_H_


#include "state.h"
#include "driver.h"

#define threeshold 20


//define states id
enum {
    Main_Algo_Waiting_state
}Main_Algo_state_id;

//States
STATE_DEFINE(Main_Algo_Waiting);



#endif /* MAIN_ALGO_H_ */
