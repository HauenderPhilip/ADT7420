/*
    ADT7420.h - Library for using the ADT7420 sensor via I2C
    Copyright (c) 2019 Philip Hauer

    ADT7420 is a free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ADT7420 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ADT7420.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ADT7420_h
#define ADT7420_h

#include "Arduino.h"
#include <Wire.h>

#define I2C_ADT7420	     0x48
#define ADT7420TempReg   0x00
#define ADT7420ConfigReg 0x03
#define SET16BITMODE     B10100000

class ADT7420
{
protected:
	TwoWire *_Wire;

	double TEMP;
	long TEMPreading;
	char i2caddr;

  byte MSB;
  byte LSB;

	byte send_cmd(byte aCMD);

public:
	ADT7420(TwoWire *aWire);

	uint8_t connect();
	double GetTemp();
	void setI2Caddr(char aAddr);
};
#endif
