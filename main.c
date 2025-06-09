#include <stdio.h>               // Biblioteca padrão para entrada e saída (não usada diretamente aqui)
#include "pico/stdlib.h"         // Funções padrão da Raspberry Pi Pico (GPIO, delays, etc.)
#include "adc_audio.h"           // Interface para gravação de áudio (ADC)
#include "pwm_audio.h"           // Interface para reprodução de áudio (PWM)
#include "controls.h"            // Interface para controle dos botões e LEDs


int main() {
    stdio_init_all();         // Inicializa a entrada/saída padrão (geralmente para debug via USB)
    
    init_adc();               // Inicializa o ADC (configura GP28 para leitura do microfone)
    init_pwm();               // Inicializa o PWM (configura GP10 para saída de áudio)
    init_controls();          // Inicializa botões e LEDs (GP5, GP6 e LEDs nos GPIOs 11, 12 e 13)


    while (true) {
            if (is_button_pressed(BTN_RECORD)) {
            set_led(LED_GREEN, true);    // Acende o LED verde indicando início da gravação
            set_led(LED_RED, false);     // Garante que o LED vermelho está apagado
            record_audio();              // Executa a função de gravação (leitura do ADC para o buffer)
            set_led(LED_GREEN, false);   // Apaga o LED verde ao fim da gravação
            set_led(LED_RED, true);      // Acende o LED vermelho indicando que a gravação terminou
        }


            if (is_button_pressed(BTN_PLAY)) {
            set_led(LED_BLUE, true);     // Acende o LED azul indicando início da reprodução
            play_audio(audio_buffer, AUDIO_BUFFER_SIZE); // Reproduz o buffer de áudio via PWM
            set_led(LED_BLUE, false);    // Apaga o LED azul ao fim da reprodução
        }


            sleep_ms(100); // Pequeno atraso (100 ms) para evitar leitura múltipla dos botões
    

    }

    return 0;
}
