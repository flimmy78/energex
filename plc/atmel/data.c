/***************************************************************************
 *   Energex                                                               *
 *                                                                         *
 *   Copyright (C) 2008-2009 by Markus Walser                              *
 *   markus.walser@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*! 
 * @file 	data.h
 * @brief 	Stores and loads persistent data.
 * @author 	Markus Walser (markus.walser@gmail.com)
 * @date 	22.02.08
 */

#include <avr/eeprom.h>
#include "data.h"

// Declaration
//uint8_t eeI2CAddress EEMEM = DEFAULT_I2C_ADDRESS;
uint16_t eeCounter_10mAh   EEMEM = 0; // current battery charging level
uint16_t eeDischarged_Ah   EEMEM = 0; // current battery charging level
uint16_t eeCharged_Ah      EEMEM = 0; // current battery charging level

uint16_t eeCycles_over_110     EEMEM = 0; // > 110%
uint16_t eeCycles_over_100     EEMEM = 0; // > 100%
uint16_t eeCycles_over_90      EEMEM = 0; // >  90%
uint16_t eeCycles_over_80      EEMEM = 0; // >  80%
uint16_t eeCycles_over_70      EEMEM = 0; // >  70%
uint16_t eeCycles_over_60      EEMEM = 0; // >  60%
uint16_t eeCycles_over_50      EEMEM = 0; // >  50%
uint16_t eeCycles_over_40      EEMEM = 0; // >  40%
uint16_t eeCycles_over_30      EEMEM = 0; // >  30%
uint16_t eeCycles_over_20      EEMEM = 0; // >  20%
uint16_t eeCycles_over_10      EEMEM = 0; // >  10%
uint16_t eeCycles_under_10     EEMEM = 0; // <  10%

uint16_t eeChargeCycles        EEMEM = 0;
uint16_t eeDeepDischargeCycles EEMEM = 0;

uint16_t eeNominal_capacity    EEMEM = 2500; 
uint16_t eeMax_capacity        EEMEM = 0; 
uint16_t eeMin_capacity        EEMEM = 9999; 


// SRAM data pool
int16_t data_capacity;
uint16_t data_total_discharge;
uint16_t data_total_discharge;

data_stat_t data_stat;

uint16_t data_charge_cycles;
uint16_t data_deep_discharge_cycles;

uint16_t data_nominal_capacity;  
uint16_t data_max_capacity;  
uint16_t data_min_capacity;  



void data_save(void)
{
	eeprom_write_word( &eeCycles_over_110, data_stat.cycles_over_110 );
	eeprom_busy_wait();
	eeprom_write_word( &eeCycles_over_100, data_stat.cycles_over_100 );
	eeprom_busy_wait();
	eeprom_write_word( &eeCycles_over_90, data_stat.cycles_over_90 );
	eeprom_busy_wait();
	eeprom_write_word( &eeCycles_over_80, data_stat.cycles_over_80 );
	eeprom_busy_wait();
	eeprom_write_word( &eeCycles_over_70, data_stat.cycles_over_70 );
	eeprom_busy_wait();
	eeprom_write_word( &eeCycles_over_60, data_stat.cycles_over_60 );
	eeprom_busy_wait();
	eeprom_write_word( &eeCycles_over_50, data_stat.cycles_over_50 );
	eeprom_busy_wait();
	eeprom_write_word( &eeCycles_over_40, data_stat.cycles_over_40 );
	eeprom_busy_wait();
	eeprom_write_word( &eeCycles_over_30, data_stat.cycles_over_30 );
	eeprom_busy_wait();
	eeprom_write_word( &eeCycles_over_20, data_stat.cycles_over_20 );
	eeprom_busy_wait();
	eeprom_write_word( &eeCycles_over_10, data_stat.cycles_over_10 );
	eeprom_busy_wait();
	eeprom_write_word( &eeCycles_under_10, data_stat.cycles_under_10 );
	eeprom_busy_wait();

	eeprom_write_word( &eeChargeCycles, data_charge_cycles);
	eeprom_busy_wait();
	eeprom_write_word( &eeDeepDischargeCycles, data_deep_discharge_cycles);
	eeprom_busy_wait();

	eeprom_write_word( &eeNominal_capacity, data_nominal_capacity );
	eeprom_busy_wait();
	eeprom_write_word( &eeMax_capacity, data_max_capacity );
	eeprom_busy_wait();
	eeprom_write_word( &eeMin_capacity, data_min_capacity );
	eeprom_busy_wait();
}

void data_load(void)
{
	data_stat.cycles_over_110 = eeprom_read_word( &eeCycles_over_110);
	eeprom_busy_wait();
	data_stat.cycles_over_100 = eeprom_read_word( &eeCycles_over_100);
	eeprom_busy_wait();
	data_stat.cycles_over_90 = eeprom_read_word( &eeCycles_over_90);
	eeprom_busy_wait();
	data_stat.cycles_over_80 = eeprom_read_word( &eeCycles_over_80);
	eeprom_busy_wait();
	data_stat.cycles_over_70 = eeprom_read_word( &eeCycles_over_70);
	eeprom_busy_wait();
	data_stat.cycles_over_60 = eeprom_read_word( &eeCycles_over_60);
	eeprom_busy_wait();
	data_stat.cycles_over_50 = eeprom_read_word( &eeCycles_over_50);
	eeprom_busy_wait();
	data_stat.cycles_over_40 = eeprom_read_word( &eeCycles_over_40);
	eeprom_busy_wait();
	data_stat.cycles_over_30 = eeprom_read_word( &eeCycles_over_30);
	eeprom_busy_wait();
	data_stat.cycles_over_20 = eeprom_read_word( &eeCycles_over_20);
	eeprom_busy_wait();
	data_stat.cycles_over_10 = eeprom_read_word( &eeCycles_over_10);
	eeprom_busy_wait();
	data_stat.cycles_under_10 = eeprom_read_word( &eeCycles_under_10);

	eeprom_busy_wait();
	data_charge_cycles = eeprom_read_word( &eeChargeCycles);
	eeprom_busy_wait();
	data_deep_discharge_cycles = eeprom_read_word( &eeDeepDischargeCycles);

	eeprom_busy_wait();
	data_nominal_capacity = eeprom_read_word( &eeNominal_capacity);
	eeprom_busy_wait();
	data_max_capacity = eeprom_read_word( &eeMax_capacity);
	eeprom_busy_wait();
	data_min_capacity = eeprom_read_word( &eeMin_capacity);
}


#if 0


// read
eeprom_busy_wait();
callibration = eeprom_read_word( &eeCalibration );
eeprom_busy_wait();
address = eeprom_read_byte( &eeI2CAddress );





#endif
