/*
 * twowiremasterv2.h
 *
 *  Created on: Dec 20, 2015
 *      Author: jacob
 */

#ifndef NEWLIB_TWOWIRELOWLEVEL_H_
#define NEWLIB_TWOWIRELOWLEVEL_H_
#include<stdint.h>
void twi_init_master();
void twi_send_start();
void twi_send_stop();
void twi_wait_int_flag_set();
void twi_check_start_ack();
void twi_slave_addr_write(uint8_t addr);
void twi_slave_addr_read(uint8_t addr);
void twi_mt_check_slave_ack();
void twi_mr_check_slave_ack();
void twi_format_data(uint8_t data);
void twi_send_data(uint8_t data);
uint8_t twi_recv_data();
void twi_check_data_ack();
uint8_t error();




#endif /* NEWLIB_TWOWIRELOWLEVEL_H_ */
