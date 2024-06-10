/*
 * tEnconder.h
 *
 *  Created on: Nov 11, 2023
 *      Author: Nelson Lima
 */

#include "usr/tEncoder.h"

int16_t tEnconder_getValor(enconder_t *_encoder)
{
  return _encoder->valor;
}

void tEnconder_setValor(enconder_t *_encoder, int16_t _valor)
{
  _encoder->valor = _valor;
  return ;
}
