/*
 * See header file for details
 *
 *  This program is free software: you can redistribute it and/or modify\n
 *  it under the terms of the GNU General Public License as published by\n
 *  the Free Software Foundation, either version 3 of the License, or\n
 *  (at your option) any later version.\n
 * 
 *  This program is distributed in the hope that it will be useful,\n
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of\n
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n
 *  GNU General Public License for more details.\n
 * 
 *  You should have received a copy of the GNU General Public License\n
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.\n
 */

/* Dependencies */
#include <Wire.h>
#include "ADG2128.h"

PatchBay::PatchBay()
{
}


void PatchBay::begin(uint8_t address) {

	/* Store the I2C address and init the Wire library */
	_address = address;
	Wire.begin();
}

void PatchBay::set(uint8_t input, uint8_t output, bool state, bool immediate) {

  uint8_t port;
  
  if(state) {
    port = input|output|ON;
  } else {
    port = input|output|OFF;
  }
  Wire.beginTransmission(_address);  // Start transmission
  I2CWRITE((uint8_t)port);
  if(immediate) {
    I2CWRITE((uint8_t)0x01);
  } else {
    I2CWRITE((uint8_t)0x00);
  }	
  Wire.endTransmission();           // Stop transmission
}


void PatchBay::set(uint8_t input, uint8_t output, bool state) {
  set(input, output, state, 1);
}

uint8_t PatchBay::read(uint8_t input) {

  uint8_t output, port;
  
  switch(input) {
    case X0:	port = RBX0;
				break;
	case X1:	port = RBX1;
				break;
	case X2:	port = RBX2;
				break;
	case X3:	port = RBX3;
				break;
	case X4:	port = RBX4;
				break;
	case X5:	port = RBX5;
				break;
	case X6:	port = RBX6;
				break;	
    case X7:	port = RBX7;
				break;
	case X8:	port = RBX8;
				break;
	case X9:	port = RBX9;
				break;
	case X10:	port = RBX10;
				break;
	case X11:	port = RBX11;
				break;
	default:	return((uint8_t)0);
				break;		
  }	
				
  Wire.beginTransmission(_address);  // Start transmission
  I2CWRITE((uint8_t)port);		//Address of input port in question
  I2CWRITE((uint8_t)0x00);		//2nd byte is required but value is don't care
  Wire.endTransmission();           // Stop transmission
  
  Wire.beginTransmission(_address);  // Start transmission
  I2CWRITE((uint8_t)0x00);
  Wire.requestFrom((uint8_t)_address, (uint8_t)2);
  I2CREAD(); 	// disregard first byte
  output = (uint8_t)I2CREAD();	// Bits for outputs connected.
  Wire.endTransmission();           // Stop transmission
  
  return((uint8_t)output);
}


void PatchBay::clear(void) {

}