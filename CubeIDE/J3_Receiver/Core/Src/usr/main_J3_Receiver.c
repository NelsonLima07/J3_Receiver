/*
 * main_J3_Receiver.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Nelson Lima
 */

#include "main.h"
#include "usr/main_J3_Receiver.h"


receiver_t receiver;


void DoBtnInput(void)
{
  HAL_GPIO_WritePin(BTN_INPUT_GPIO_Port, BTN_INPUT_Pin, GPIO_PIN_RESET);
  HAL_Delay(200);   /* Espera o debounce  */
  HAL_GPIO_WritePin(BTN_INPUT_GPIO_Port, BTN_INPUT_Pin, GPIO_PIN_SET);
  HAL_Delay(1200);   /*  */
}

uint8_t DoInterfaceOptica(void)
{
  return HAL_GPIO_ReadPin(ENT_D1_GPIO_Port, ENT_D1_Pin);
}

uint8_t DoInterfaceOprtica2(void)
{
  return HAL_GPIO_ReadPin(ENT_D2_GPIO_Port, ENT_D2_Pin);
}

uint8_t DoInterfaceCoaxial(void)
{
  return HAL_GPIO_ReadPin(ENT_D3_GPIO_Port, ENT_D3_Pin);
}


void main_j3_receiver()
{

  receiver_t* receiver;

  int8_t volume_fl;  /* Front Left       */
  int8_t volume_fr;  /* Front Right      */
  int8_t volume_fc;  /* Front Center     */
  int8_t volume_sl;  /* SoundRound Left  */
  int8_t volume_sr;  /* SoundRound Right */
  int8_t volume_sw;  /* Subwoofer        */
  int8_t volume_master;


  receiver = j3_tReceiver_new(DoBtnInput);
  j3_tReceiver_OnInterfaceOptico(receiver, DoInterfaceOptica);
  j3_tReceiver_OnInterfaceOptico2(receiver, DoInterfaceOprtica2);
  j3_tReceiver_OnInterfaceCoaxial(receiver, DoInterfaceCoaxial);


  while(1)
  {

      //DoBtnInput();
  //    j3_receiver_ProxEntrada(receiver);

    j3_receiver_setEntrada(receiver, rsOptico1);
    HAL_Delay(5000);
    j3_receiver_setEntrada(receiver, rsAux);
    HAL_Delay(5000);
    j3_receiver_setEntrada(receiver, rsOptico2);
  }

}
