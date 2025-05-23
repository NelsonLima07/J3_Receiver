/*
 * J3_SH1106.h
 *
 *  Created on: May 31, 2021
 *      Author: Nelson Lima
 */


#ifndef INC_J3_PT2258_H_
#define INC_J3_PT2258_H_

#include "i2c.h"

/* U = Unidade D = Dezena */
/* Sistema deve enviar sempre atenuacao com 2 bytes */
/* Os 4 bits de endereco e 4 bits do valor */
/* Primeiro byte da dezena e segundo byte da unidade
 * Dezena sempre e o */

#define MASTER 0xE0
#define CANAL1 0x90
#define CANAL2 0x50
#define CANAL3 0x10
#define CANAL4 0x30
#define CANAL5 0x70
#define CANAL6 0xB0

#define MUTE_ON  0xF9
#define MUTE_OFF 0xF8

#define CLEAR_RESET 0xC0

/* Endereco
 * CODE1 CODE2  Endereco
 *   1     1      0x8C
 *   1     0      0x88
 *   0     1      0x84
 *   0     0      0x80
 */

#define VOL_MAX 79
#define VOL_MIN 0

typedef struct TPT2258 TPT2258;

TPT2258* J3_PT2258_new(I2C_HandleTypeDef* _i2c, uint8_t _i2c_address); /* Retorna um ponteiro para o CI PT2258 */

/*_canal -> 1 a 6 ou 0 para Master */
void J3_PT2258_setVolumeCanal(TPT2258* _pt2258, uint8_t _canal, uint8_t _vol);
void J3_PT2258_setMuteOn(TPT2258* _pt2258);
void J3_PT2258_setMuteOff(TPT2258* _pt2258);
void J3_PT2258_reset(TPT2258* _pt2258);

#endif /* INC_J3_PT2258_H_ */
