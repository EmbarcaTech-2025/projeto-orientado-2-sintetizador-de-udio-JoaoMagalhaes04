// Prevenção contra inclusões múltiplas do mesmo cabeçalho
#ifndef CONTROLS_H
#define CONTROLS_H

// Inclusão de bibliotecas padrão para tipos básicos
#include <stdbool.h> // Permite o uso de 'bool' (true/false)
#include <stdint.h>  // Permite o uso de tipos como uint32_t

// Biblioteca padrão do ambiente Pico SDK, já inclui funcionalidades GPIO, delays, etc.
// Também já inclui stdbool.h e stdint.h por padrão
#include "pico/stdlib.h"


// Protótipo da função de inicialização dos botões e LEDs
void init_controls();

// Protótipo da função que verifica se um botão está pressionado
bool is_button_pressed(uint32_t pin);

// Protótipo da função que acende ou apaga um LED
void set_led(uint32_t pin, bool on);

// Definições dos pinos usados para os botões
#define BTN_RECORD 5  // Botão A: Gravar áudio (ligado ao pino GPIO 5)
#define BTN_PLAY   6  // Botão B: Reproduzir áudio (ligado ao pino GPIO 6)

// Definições dos pinos usados para os LEDs
#define LED_GREEN  11 // LED Verde: Indica que a gravação está em andamento
#define LED_BLUE   12 // LED Azul: Indica que a reprodução está em andamento
#define LED_RED    13 // LED Vermelho: Indica que a memória está cheia ou fim da gravação


#endif
