// Inclui o cabeçalho correspondente a este módulo (onde estão definidos os pinos dos botões e LEDs)
#include "controls.h"

// Biblioteca padrão da Raspberry Pi Pico (manipulação de GPIO, delays, etc.)
#include "pico/stdlib.h"


// Função que inicializa os botões e LEDs
void init_controls() {
    // Inicializa o pino do botão de gravação (BTN_RECORD)
    gpio_init(BTN_RECORD);
    gpio_set_dir(BTN_RECORD, GPIO_IN);   // Configura como entrada
    gpio_pull_up(BTN_RECORD);            // Ativa resistor pull-up (botão ativo em nível baixo)

    // Inicializa o pino do botão de reprodução (BTN_PLAY)
    gpio_init(BTN_PLAY);
    gpio_set_dir(BTN_PLAY, GPIO_IN);     // Configura como entrada
    gpio_pull_up(BTN_PLAY);              // Ativa resistor pull-up (botão ativo em nível baixo)

    // Inicializa os pinos dos LEDs (verde, azul, vermelho)
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);

    // Configura os LEDs como saída
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
}

// Função que verifica se um botão está pressionado
bool is_button_pressed(uint32_t pin) {
    return !gpio_get(pin); // Retorna true se o botão estiver pressionado (nível lógico baixo)
}


// Função que acende ou apaga um LED
void set_led(uint32_t pin, bool on) {
    gpio_put(pin, on); // Liga (true) ou desliga (false) o LED correspondente
}
