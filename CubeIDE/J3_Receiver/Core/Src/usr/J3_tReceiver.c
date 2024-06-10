/*
 * main_J3_Receiver.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Nelson Lima
 */

#include <stdlib.h>

//#include "main.h"
#include "usr/J3_tReceiver.h"

receiver_t* j3_tReceiver_new(btnInput _funcBtnInput)
{
  receiver_t*  auxReceiver;

  auxReceiver = malloc(sizeof(receiver_t));
  auxReceiver->onBtnInput = _funcBtnInput;
  return auxReceiver;
}

void j3_tReceiver_OnInterfaceOptico(receiver_t *_receiver, inputInterface _interface)
{
  _receiver->onInputOptico = _interface;
}
void j3_tReceiver_OnInterfaceOptico2(receiver_t *_receiver, inputInterface _interface)
{
  _receiver->onInputOptico2 = _interface;
}
void j3_tReceiver_OnInterfaceCoaxial(receiver_t *_receiver, inputInterface _interface)
{
  _receiver->onInputCoaxial = _interface;
}


/* Seleciona a proxima Entrada */
void j3_receiver_ProxEntrada(receiver_t *_receiver)
{
   _receiver->onBtnInput();
}

void j3_receiver_setEntrada(receiver_t *_receiver, receiverInput_t _entrada)  /* Seta a entrada de audio selecionada */
{
  while(_receiver->audio_entrada != _entrada)
  {
      j3_receiver_ProxEntrada(_receiver);
      j3_receiver_getEntrada(_receiver);
  }
}

/* Verifica a Entrada  */

receiverInput_t j3_receiver_getEntrada(receiver_t *_receiver)
{
  if(!_receiver->onInputOptico()) /* O pinto em GND é o ATIVO, ou seja se não for 1 então ligado */
  {
    _receiver->audio_entrada = rsOptico1;
    return rsOptico1;
  }
  else if (!_receiver->onInputOptico2()) /* O pinto em GND é o ATIVO, ou seja se não for 1 então ligado */
  {
    _receiver->audio_entrada = rsOptico2;
    return rsOptico2;
  }
  else if (!_receiver->onInputCoaxial()) /* O pinto em GND é o ATIVO, ou seja se não for 1 então ligado */
  {
    _receiver->audio_entrada = rsCoaxial;
    return rsCoaxial;
  }
  else
  {
    _receiver->audio_entrada = rsAux;
    return rsAux;
  }
}
