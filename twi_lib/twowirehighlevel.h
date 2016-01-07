/*
 * twowirehighlevel.h
 *
 *  Created on: Dec 22, 2015
 *      Author: jacob
 */

#ifndef NEWLIB_TWOWIREHIGHLEVEL_H_
#define NEWLIB_TWOWIREHIGHLEVEL_H_
#include<stdint.h>

void twi_start();
void twi_stop();
void twi_send_data(uint8_t data);
void twi_addr_write(uint8_t addr);
void twi_addr_read(uint8_t addr);
uint8_t twi_read_data();

#endif /* NEWLIB_TWOWIREHIGHLEVEL_H_ */
