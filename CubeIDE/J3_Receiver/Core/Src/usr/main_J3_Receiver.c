/*
 * main_J3_Receiver.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Nelson Lima
 */


#include "main.h"
#include "usr/main_J3_Receiver.h"
#include "usr/J3_PT2258.h"


receiver_t receiver;

/* Btn q muda o input do decodificador */
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



void HAL_GPIO_EXIT_Falling_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == ENCODER_BTN_Pin)
  {

  }

  if(GPIO_Pin == ENCODER_CLK_Pin)
  {

  }
  if(GPIO_Pin == ENCODER_DT_Pin)
  {

  }
}



void main_j3_receiver()
{

//  receiver_t* receiver;
  TPT2258* controleVolume;
/*
  int8_t volume_fl;  // Front Left
  int8_t volume_fr;   // Front Right
  int8_t volume_fc;  // Front Center
  int8_t volume_sl;  // SoundRound Left
  int8_t volume_sr;  // SoundRound Right
  int8_t volume_sw;  // Subwoofer
  int8_t volume_master;
*/

  controleVolume = J3_PT2258_new(&hi2c1,  0x88);

  //receiver = j3_tReceiver_new(DoBtnInput);
  //j3_tReceiver_OnInterfaceOptico(receiver, DoInterfaceOptica);
  //j3_tReceiver_OnInterfaceOptico2(receiver, DoInterfaceOprtica2);
  //j3_tReceiver_OnInterfaceCoaxial(receiver, DoInterfaceCoaxial);

  uint8_t ch1_vol = 70;
  HAL_Delay(500);
  J3_PT2258_reset(controleVolume);
  HAL_Delay(500);
  J3_PT2258_setMuteOff(controleVolume);
  HAL_Delay(500);
  //J3_PT2258_setVolumeCanal(controleVolume, 1, ch1_vol);

  J3_PT2258_setVolumeCanal(controleVolume, 0, 1);
  while(1)
  {

      J3_PT2258_setVolumeCanal(controleVolume, 1, 5);
      J3_PT2258_setVolumeCanal(controleVolume, 2, 10);
      J3_PT2258_setVolumeCanal(controleVolume, 3, 10);
      J3_PT2258_setVolumeCanal(controleVolume, 4, 10);
      J3_PT2258_setVolumeCanal(controleVolume, 5, 10);
      J3_PT2258_setVolumeCanal(controleVolume, 6, 1);
      //J3_PT2258_setVolumeCanal(controleVolume, 2, 10);
     // J3_PT2258_setVolumeCanal(controleVolume, 3, 750);
      HAL_Delay(3000);
      HAL_GPIO_TogglePin(LED_PLACA_GPIO_Port, LED_PLACA_Pin);
      //J3_PT2258_setVolumeCanal(controleVolume, 3, 20);
      J3_PT2258_setVolumeCanal(controleVolume, 6, 10);
      HAL_Delay(3000);
      J3_PT2258_setVolumeCanal(controleVolume, 6, 30);
      //DoBtnInput();
      HAL_GPIO_TogglePin(LED_PLACA_GPIO_Port, LED_PLACA_Pin);
     // J3_PT2258_setVolumeCanal(controleVolume, 3, 70);
      HAL_Delay(3000);
      J3_PT2258_setVolumeCanal(controleVolume, 6, 60);
      //DoBtnInput();
      HAL_GPIO_TogglePin(LED_PLACA_GPIO_Port, LED_PLACA_Pin);


  //    j3_receiver_ProxEntrada(receiver);

    //j3_receiver_setEntrada(receiver, rsOptico1);
    //HAL_Delay(5000);
    //j3_receiver_setEntrada(receiver, rsAux);
    //HAL_Delay(5000);
    //j3_receiver_setEntrada(receiver, rsOptico2);
  }

}
