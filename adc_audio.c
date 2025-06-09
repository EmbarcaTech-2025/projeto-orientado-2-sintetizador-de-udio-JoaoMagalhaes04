// adc_audio.c
// Inclui o cabeçalho deste módulo, onde estão definidos o tamanho do buffer e o protótipo da função
#include "adc_audio.h"

// Biblioteca da Raspberry Pi Pico para lidar com o ADC (Conversor Analógico-Digital)
#include "hardware/adc.h"

// Biblioteca para controle de temporização (usado para delay entre amostras)
#include "hardware/timer.h"

// Biblioteca padrão da Pico (inclui funções como sleep_us, etc)
#include "pico/stdlib.h"

// Buffer onde o áudio digitalizado será armazenado.
// Cada posição do buffer armazena uma amostra de 8 bits (0 a 255).
uint8_t audio_buffer[AUDIO_BUFFER_SIZE];


// Função de inicialização do ADC
void init_adc() {
    adc_init();                  // Inicializa o sistema ADC do RP2040
    adc_gpio_init(28);          // Configura o pino GP28 como entrada analógica
    adc_select_input(2);        // Seleciona o canal 2 do ADC (correspondente ao GP28)
}


// Função para gravar áudio do microfone
void record_audio() {
    // Percorre o buffer para preenchê-lo com amostras de áudio
    for (int i = 0; i < AUDIO_BUFFER_SIZE; i++) {
        uint16_t raw = adc_read();        // Lê uma amostra do ADC (valor de 12 bits: 0 a 4095)
        
        // Reduz a resolução de 12 bits para 8 bits, descartando os 4 bits menos significativos
        // Isso é uma forma simples de "quantização", reduzindo o tamanho dos dados para economizar memória
        audio_buffer[i] = raw >> 4;
        
        // Aguarda 125 microssegundos antes de fazer a próxima leitura
        // Isso define a taxa de amostragem em 8000 Hz (8 mil amostras por segundo)
        sleep_us(125);
    }
}
