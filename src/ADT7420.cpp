/*
    ADT7420.cpp - Source Code for using the ADT7420 sensor via I2C
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

#include "ADT7420.h"

ADT7420::ADT7420(TwoWire *aWire) : i2caddr(I2C_ADT7420) {
	_Wire=aWire;
}

void ADT7420::setI2Caddr(char aAddr) {
	i2caddr=aAddr;
}

byte ADT7420::send_cmd(byte aCMD)
{
  _Wire->beginTransmission(i2caddr);
  _Wire->write(aCMD);
  uint8_t ret=_Wire->endTransmission(true);
  return ret;
}

uint8_t ADT7420::connect() {
	_Wire->begin();
	_Wire->beginTransmission(i2caddr);
	uint8_t ret=_Wire->endTransmission(true);
	return ret;
}

double ADT7420::GetTemp() {
	_Wire->beginTransmission(i2caddr);
	_Wire->write(ADT7420ConfigReg); //
	_Wire->write(B10100000); // Set 16-bit Mode
  _Wire->write(ADT7420TempReg);
  _Wire->endTransmission();

	Wire.requestFrom(I2C_ADT7420,2);
	MSB = Wire.read();
	LSB = Wire.read();

	// Assign global 'TEMPreading' the 16-bit signed value.
  TEMPreading = ((MSB << 8) | LSB);
  if (TEMPreading > 32768) {
		TEMPreading = TEMPreading - 65535;
  	TEMP = (TEMPreading/128.0)*-1;
	} else {
		TEMP = (TEMPreading/128.0);
	}

	return TEMP;
}
