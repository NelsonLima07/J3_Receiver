/*
 * J3_SH1106.h
 *
 *  Created on: May 31, 2021
 *      Author: Nelson Lima
 */

#include "usr/J3_PT2258.h"
#include <stdlib.h>




struct TPT2258{
	I2C_HandleTypeDef* i2c;
  uint8_t address;
};

typedef struct TPT2258 TPT2258;

/* Canal 0 é o master */
uint8_t aCanais[7] = {MASTER, CANAL1, CANAL2, CANAL3, CANAL4, CANAL5, CANAL6};


/* Enviar comando para o PT2258 */
/*
void j3_PT2258_sendCmd(TPT2258* _pt2258, uint8_t _b1, uint8_t _b2){
  if (_pt2258->i2c != NULL){
    HAL_StatusTypeDef ret;
    uint8_t buf[2];

    buf[0] = _b1;
    buf[1] = _b2;
    ret = HAL_I2C_Master_Transmit(_pt2258->i2c, _pt2258->address, buf, 2, HAL_MAX_DELAY);
    if (ret == HAL_OK) {
    }
    else {
    }
  }
}
*/

/* Enviar comando para o PT2258 */
void j3_PT2258_sendCmd2(TPT2258* _pt2258, uint8_t _buf[], uint8_t _tambuf){
  if (_pt2258->i2c != NULL){
    HAL_StatusTypeDef ret;
    ret = HAL_I2C_Master_Transmit(_pt2258->i2c, _pt2258->address, _buf, _tambuf, HAL_MAX_DELAY);
    if (ret == HAL_OK) {
    }
    else {
    }
  }
}

TPT2258* J3_PT2258_new(I2C_HandleTypeDef* _i2c, uint8_t _i2c_address){ /* Retorna um ponteiro para o CI PT2258 */
	TPT2258* auxPT2258;

	auxPT2258 = malloc(sizeof(TPT2258));
	auxPT2258->address = _i2c_address;
	auxPT2258->i2c = _i2c;

	return auxPT2258;
}


void J3_PT2258_setVolumeCanal(TPT2258* _pt2258, uint8_t _canal, uint8_t _vol){
	if (_canal > 6){
		return;
	}
	uint8_t auxBuf[2];

	if (_vol > VOL_MAX)
	{
		_vol = VOL_MAX;
	}

    if (_vol < VOL_MIN)
    {
        _vol = VOL_MIN;
    }


	auxBuf[0] = ( aCanais[_canal]  | (_vol % 10) ); // Byte da Unidade
	auxBuf[1] = ( (aCanais[_canal] - 0x10)  | (_vol / 10) ); // Byte da Dezeza

	j3_PT2258_sendCmd2(_pt2258, auxBuf, 2);
}

void J3_PT2258_setMuteOn(TPT2258* _pt2258){
	uint8_t auxBuf[1] = {MUTE_ON};

	j3_PT2258_sendCmd2(_pt2258, auxBuf, 1);
}

void J3_PT2258_setMuteOff(TPT2258* _pt2258){
	uint8_t auxBuf[1] = {MUTE_OFF};

	j3_PT2258_sendCmd2(_pt2258, auxBuf, 1);
}

void J3_PT2258_reset(TPT2258* _pt2258){
	uint8_t auxBuf[1] = {CLEAR_RESET};

	j3_PT2258_sendCmd2(_pt2258, auxBuf, 1);
}

