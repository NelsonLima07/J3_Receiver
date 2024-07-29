/*
 *
 *
 *
 *      Author: Nelson Lima
 */

#ifndef INC_USR_J3_TRECEIVER_H_
#define INC_USR_J3_TRECEIVER_H_


#include <stdbool.h>
#include <stdint.h>


#define BTN_INPUT_PORT  BTN_INPUT_GPIO_Port
#define BTN_INPUT  BTN_INPUT_Pin


enum receiverInput {rsOptico1, rsOptico2, rsCoaxial, rsAux };
typedef enum receiverInput receiverInput_t;

enum receiverTipoAudio {ta21, ta51 };
typedef enum receiverTipoAudio receiverTipoAudio_t;


typedef void(*btnInput)(void);
typedef uint8_t(*inputInterface)(void);

typedef struct {
  bool ligado;
  receiverTipoAudio_t audioTipo;  /* 2.1 ou 5.1 */
  receiverInput_t  audioEntrada;
  btnInput onBtnInput;
  inputInterface onInputOptico;
  inputInterface onInputOptico2;
  inputInterface onInputCoaxial;

  int8_t volume_fl;  /* Front Left       */
  int8_t volume_fr;  /* Front Right      */
  int8_t volume_fc;  /* Front Center     */
  int8_t volume_sl;  /* SoundRound Left  */
  int8_t volume_sr;  /* SoundRound Right */
  int8_t volume_sw;  /* Subwoofer        */
  int8_t volume_master;

} receiver_t;



receiver_t* j3_tReceiver_new(btnInput _funcBtnInput);  /* Instancia receiver_t */
void j3_tReceiver_OnInterfaceOptico(receiver_t *_receiver, inputInterface _interface);
void j3_tReceiver_OnInterfaceOptico2(receiver_t *_receiver, inputInterface _interface);
void j3_tReceiver_OnInterfaceCoaxial(receiver_t *_receiver, inputInterface _interface);
void j3_tReceiver_init(receiver_t *_receiver);  /* Inicia o receiver */

void j3_receiver_setEntrada(receiver_t *_receiver, receiverInput_t _entrada);  /* Seta a entrada de audio selecionada */
receiverInput_t j3_receiver_getEntrada(receiver_t *_receiver);  /* Verifica a entrada selecionada  */
void j3_receiver_ProxEntrada(receiver_t *_receiver); /* Seleciona a proxima Entrada */

#endif /* INC_USR_J3_TRECEIVER_H_ */
