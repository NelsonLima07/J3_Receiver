/*
 * tEnconder.h
 *
 *  Created on: Nov 11, 2023
 *      Author: Nelson Lima
 */

#ifndef INC_USR_TENCODER_H_
#define INC_USR_TENCODER_H_

#include <stdint.h>
#include <stdbool.h>

enum encoder_sentido {esHorario, esAntihorario, esParado };
typedef enum encoder_sentido encoder_sentido_t;

typedef struct {
  bool btnOn;
  encoder_sentido_t sentido;
  int16_t valor;  /* Front Left       */
} enconder_t;


int16_t tEnconder_getValor(enconder_t *_encoder);
void tEnconder_setValor(enconder_t *_encoder, int16_t _valor);

#endif /* INC_USR_TENCODER_H_ */
