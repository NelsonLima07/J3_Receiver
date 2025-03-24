/*
 * main_J3_Receiver.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Nelson Lima
 */


#include "main.h"
#include "usr/main_J3_Receiver.h"
#include "usr/J3_PT2258.h"


#define TEMPO_LENTO 2000
#define TEMPO_NORMAL 1000
#define TEMPO_RAPIDO 500

#define DEBOUNCE_DELAY 100

uint16_t tempoLED = TEMPO_NORMAL;

volatile bool btnEncoder_presFlag = false;
volatile uint32_t btnEncoder_lastTime = 0;

volatile bool clkEncoder_presFlag = false;
volatile uint32_t clkEncoder_lastTime = 0;

volatile bool dtEncoder_presFlag = false;
volatile uint32_t dtEncoder_lastTime = 0;



/* funcao altera o input do Decodificador */
void btnSelecEntAudio(void)
{
  HAL_GPIO_WritePin(SELEC_ENT_AUDIO_GPIO_Port, SELEC_ENT_AUDIO_Pin, GPIO_PIN_RESET);
  HAL_Delay(20);   /* 30ms Espera o debounce  */
  HAL_GPIO_WritePin(SELEC_ENT_AUDIO_GPIO_Port, SELEC_ENT_AUDIO_Pin, GPIO_PIN_SET);
}


/* D1 D2 e D3 sao inerface para inticar qual entrada de audio está ativa  */
/*
 D1 = On => Optical 1
 D2 = On => Optical 2
 D3 = On => Coaxial
 D1, D2 e D3 = Off => Analogico

*/

uint8_t lerD1(void)
{
  return HAL_GPIO_ReadPin(ENT_D1_GPIO_Port, ENT_D1_Pin);
}

uint8_t lerD2(void)
{
  return HAL_GPIO_ReadPin(ENT_D2_GPIO_Port, ENT_D2_Pin);
}

uint8_t lerD3(void)
{
  return HAL_GPIO_ReadPin(ENT_D3_GPIO_Port, ENT_D3_Pin);
}


/*   */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if( (GPIO_Pin == ENCODER_SW_Pin) && (btnEncoder_presFlag == false) ) {
      btnEncoder_presFlag = true;
      tempoLED = TEMPO_RAPIDO;
      btnEncoder_lastTime = HAL_GetTick();
  }
  else if( (GPIO_Pin == ENCODER_CLK_Pin) && (clkEncoder_presFlag == false) && (HAL_GPIO_ReadPin(ENCODER_CLK_GPIO_Port,ENCODER_CLK_Pin) == GPIO_PIN_RESET) ) {
      clkEncoder_presFlag = true;
      clkEncoder_lastTime = HAL_GetTick();
  }
  else if( (GPIO_Pin == ENCODER_DT_Pin) && (dtEncoder_presFlag == false) && (HAL_GPIO_ReadPin(ENCODER_DT_GPIO_Port,ENCODER_DT_Pin) == GPIO_PIN_RESET) ) {
      dtEncoder_presFlag = true;
      dtEncoder_lastTime = HAL_GetTick();
  }
}



void main_j3_receiver()
{
  HAL_Delay(50); /* Delay de estabilização das tensões e dos sistemas */

  TPT2258* controleVolume;
  receiver_t* receiver;

  uint32_t tmrLED_old = 0;
  uint32_t auxSystickNow = 0;
  //uint16_t tempoLED = TEMPO_LENTO;


  controleVolume = J3_PT2258_new(&hi2c1,  0x88);
  receiver = j3_tReceiver_new();

  //receiver = j3_tReceiver_new(DoBtnInput);
  //j3_tReceiver_OnInterfaceOptico(receiver, DoInterfaceOptica);
  //j3_tReceiver_OnInterfaceOptico2(receiver, DoInterfaceOprtica2);
  //j3_tReceiver_OnInterfaceCoaxial(receiver, DoInterfaceCoaxial);

  uint8_t ch1_vol = 35;

  J3_PT2258_reset(controleVolume);
  HAL_Delay(500);
  J3_PT2258_setVolumeCanal(controleVolume, 1, ch1_vol);
  J3_PT2258_setVolumeCanal(controleVolume, 2, ch1_vol);
  J3_PT2258_setVolumeCanal(controleVolume, 3, ch1_vol);
  J3_PT2258_setVolumeCanal(controleVolume, 4, ch1_vol);
  J3_PT2258_setVolumeCanal(controleVolume, 5, ch1_vol);
  J3_PT2258_setVolumeCanal(controleVolume, 6, ch1_vol);
  J3_PT2258_setMuteOff(controleVolume);
  HAL_Delay(500);

  while(1)
  {
      auxSystickNow = HAL_GetTick();

      if((auxSystickNow - tmrLED_old) >= tempoLED)
      {
        HAL_GPIO_TogglePin(LED_PLACA_GPIO_Port, LED_PLACA_Pin);
        tmrLED_old = auxSystickNow;
      }

      if( ((auxSystickNow - btnEncoder_lastTime) >= DEBOUNCE_DELAY)  && btnEncoder_presFlag ) {

          if (receiver->volume_master_mute){
            J3_PT2258_setMuteOn(controleVolume);
          }
          else{
            J3_PT2258_setMuteOff(controleVolume);
          }
          receiver->volume_master_mute = !receiver->volume_master_mute;
          btnEncoder_presFlag = false;
      }


      if(clkEncoder_presFlag && dtEncoder_presFlag)
      {
        if (clkEncoder_lastTime >= dtEncoder_lastTime)
        {
            tempoLED = TEMPO_LENTO;

            if(ch1_vol > 0){
              ch1_vol--;
            }

            J3_PT2258_setVolumeCanal(controleVolume, 3, ch1_vol);
            J3_PT2258_setVolumeCanal(controleVolume, 4, ch1_vol);

        }
        else
        {
            tempoLED = TEMPO_RAPIDO;

            if(ch1_vol < 79){
              ch1_vol++;
            }

            J3_PT2258_setVolumeCanal(controleVolume, 3, ch1_vol);
            J3_PT2258_setVolumeCanal(controleVolume, 4, ch1_vol);
        }

        HAL_Delay(DEBOUNCE_DELAY);

        clkEncoder_presFlag = false;
        dtEncoder_presFlag = false;
      }


  }

}
