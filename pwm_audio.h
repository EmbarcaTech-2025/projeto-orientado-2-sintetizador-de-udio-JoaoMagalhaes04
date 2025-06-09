// Evita inclusões múltiplas deste cabeçalho durante a compilação
#ifndef PWM_AUDIO_H
#define PWM_AUDIO_H

// Biblioteca padrão para tipos de dados inteiros com tamanho fixo, como uint8_t
#include <stdint.h>


// Protótipo da função que inicializa o módulo PWM no pino de áudio
void init_pwm();

// Protótipo da função que reproduz o áudio armazenado no buffer, usando PWM
// - buffer: ponteiro para os dados de áudio (uint8_t, 8 bits)
// - size: número de amostras no buffer
void play_audio(const uint8_t *buffer, int size);

#endif
