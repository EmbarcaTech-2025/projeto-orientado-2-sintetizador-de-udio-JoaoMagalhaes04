// Inclui o cabeçalho deste módulo (declarações das funções e pino)
#include "pwm_audio.h"

// Biblioteca de controle de PWM da Raspberry Pi Pico
#include "hardware/pwm.h"

// Biblioteca padrão do Pico (delays, controle de GPIO, etc)
#include "pico/stdlib.h"


// Define o pino utilizado para saída de áudio (buzzer)
// O buzzer está conectado ao GPIO 10
#define AUDIO_PIN 10


void init_pwm() {
    gpio_set_function(AUDIO_PIN, GPIO_FUNC_PWM);  // Configura o GPIO 10 para função PWM

    uint slice = pwm_gpio_to_slice_num(AUDIO_PIN); // Obtém o "slice" PWM correspondente ao pino

    pwm_config config = pwm_get_default_config();  // Carrega a configuração padrão do PWM

    pwm_config_set_wrap(&config, 255);             // Define o valor máximo (TOP) do contador como 255 → PWM de 8 bits

    pwm_init(slice, &config, true);                // Inicializa o slice com a configuração e já ativa
}


void play_audio(const uint8_t *buffer, int size) {
    uint slice = pwm_gpio_to_slice_num(AUDIO_PIN); // Obtém o slice do PWM novamente

    // Percorre o buffer com as amostras de áudio
    for (int i = 0; i < size; i++) {
        pwm_set_gpio_level(AUDIO_PIN, buffer[i]); // Define o nível PWM conforme a amostra (volume/intensidade)
        sleep_us(125); // Espera 125 µs = 8000 Hz → mesma taxa da gravação
    }

    // Após terminar a reprodução, define nível 0 para "silenciar" o buzzer
    pwm_set_gpio_level(AUDIO_PIN, 0);
}
