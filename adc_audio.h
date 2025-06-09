// adc_audio.h
// Evita inclusões múltiplas deste cabeçalho durante a compilação
#ifndef ADC_AUDIO_H
#define ADC_AUDIO_H

// Inclui tipos de dados padrão (uint8_t, bool, etc)
#include <stdint.h>
#include <stdbool.h>

// Define o tamanho do buffer de áudio em bytes (40.000 amostras de 8 bits)
// Isso equivale a 5 segundos de gravação com taxa de amostragem de 8000 Hz
#define AUDIO_BUFFER_SIZE 40000

// Declaração externa do buffer de áudio
// O buffer é definido no arquivo .c, mas pode ser acessado por outros arquivos que incluam este .h
extern uint8_t audio_buffer[AUDIO_BUFFER_SIZE];

// Protótipo da função que inicializa o ADC
void init_adc();

// Protótipo da função que grava áudio e preenche o buffer
void record_audio();

#endif
