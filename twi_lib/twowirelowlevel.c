/*
 * twowiremasterv2.c
 *
 *  Created on: Dec 20, 2015
 *      Author: jacob
 */
#include "twowirelowlevel.h"

#include<stdint.h>
#include<avr/io.h>
#include<util/twi.h>

void twi_init_master(){
	TWBR = 17; //Setting the bit rate to 17 since this is running at 16 MHz
	TWSR &= !(3); //Clearing the bottom two bits
	//This will give us 100kHz on the I2C Bus
}

//This is a function to send a TWI start condition
void twi_send_start(){
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
}

//This is a function to send a TWI stop condition
void twi_send_stop(){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

//This is a function to wait for the TWINT flag to be set, meaning something has happened correctly
void twi_wait_int_flag_set(){
	while(!(TWCR & (1<<TWINT))); //Just waits until it is set
}

//This is a function to check if the Start condition was acknowledged by the slave
void twi_check_start_ack(){
	if ((TWSR & 0xF8) != TW_START) //If the start condition wasn't met
		error(); //Throw an error
}

//This is a function to choose the address of the slave as well as choose to write to it
void twi_slave_addr_write(uint8_t addr){
	TWDR = (addr<<1) | TW_WRITE;
	TWCR = _BV(TWINT) | (1<<TWEN);
}

//This is a function to choose the address of the slave as well as choose to read from it
void twi_slave_addr_read(uint8_t addr){
	TWDR = (addr<<1) | TW_READ;
	TWCR = _BV(TWINT) | _BV(TWEN);
}

//This is a function to check if the slave acknowledged the read/write request
void twi_mt_check_slave_ack(){
	if ((TWSR & 0xF8) != TW_MT_SLA_ACK) //If the slave did not acknowledge
		error(); //Throw error
}

void twi_mr_check_slave_ack(){
	if((TWSR & 0xF8) != TW_MR_SLA_ACK || (TWSR & 0xF8) != TW_MR_SLA_NACK ) //If the slave did not acknowledge
		error(); //Throw error

	if((TWSR & 0xF8) != TW_MR_SLA_NACK)
	{
		twi_send_stop(); //The end of the data has been reached
	}
}

//This is a function to send data to the slave as the Master Transmitter
void twi_format_data(uint8_t data){
	TWDR = data; //Load data into the shift register
	TWCR = (1<TWINT) | (1<<TWEN); //Get it transmitted
}

//This is a function to receive data from a slave as a Master Reader
uint8_t twi_recv_data(){
	return TWDR; //This is where the data is supposed to me
	//TODO: Figure out how to know when the last data byte was received
}

//This is a function to check if the slave acknowledges the data write
void twi_check_data_ack(){
	if((TWSR & 0xF8) != TW_MT_DATA_ACK)
		error();
}

//This is a placeholder function to throw an error, TODO: Actually use error codes
uint8_t error(){
	return 1;
}
