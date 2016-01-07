/*
 * twowirehighlevel.c

 *
 *  Created on: Dec 22, 2015
 *      Author: jacob
 */

#include"twowirehighlevel.h"
#include"twowirelowlevel.h"

//Start up i2c
void twi_start(){
	twi_send_start();
	twi_wait_int_flag_set();
	twi_check_start_ack();
}

//Send a piece of data over i2c
void twi_send_data(uint8_t data){
	twi_send_data(data);
	twi_wait_int_flag_set();
	twi_mt_check_slave_ack();
}

//Set up slave addr to write to
void twi_addr_write(uint8_t addr){
	twi_slave_addr_write(addr);
	twi_wait_int_flag_set();
	twi_mt_check_slave_ack();
}

//Set up slave addr to read from
void twi_addr_read(uint8_t addr){
	twi_slave_addr_read(addr);
	twi_wait_int_flag_set();
	twi_mr_check_slave_ack();
}

uint8_t twi_read_data(){
	uint8_t thing = twi_recv_data();
	twi_wait_int_flag_set();
	twi_check_data_ack();
	return thing;
}

void twi_stop(){
	twi_send_stop();
}



