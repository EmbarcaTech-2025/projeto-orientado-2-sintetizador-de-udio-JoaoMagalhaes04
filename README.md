
# Projetos de Sistemas Embarcados - EmbarcaTech 2025

Autor: **João Fernandes**

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Campinas, junho de 2025

---
Este projeto implementa um sistema simples de gravação e reprodução de áudio usando a placa Raspberry Pi Pico com a placa BitDogLab. O áudio é capturado via ADC a partir de um microfone analógico, armazenado em um buffer, e reproduzido por um buzzer utilizando PWM.

Os controles são realizados por dois botões:

- Botão A (GPIO 5) para iniciar a gravação.

- Botão B (GPIO 6) para iniciar a reprodução.

LEDs indicam os estados do sistema:

- LED Verde (GPIO 11): gravação em andamento.

- LED Vermelho (GPIO 13): gravação finalizada/memória cheia.

- LED Azul (GPIO 12): reprodução em andamento.

Hardware Utilizado

- BitDogLab (placa de expansão com botões, LEDs, buzzer, microfone analógico)

- Microfone analógico conectado ao GPIO 28 (ADC2)

- Buzzer conectado ao GPIO 10 (PWM)

- Botão de gravação no GPIO 5

- Botão de reprodução no GPIO 6

- LEDs conectados aos GPIOs 11 (verde), 12 (azul) e 13 (vermelho)

Funcionalidades

- Gravação de áudio digital com taxa de amostragem de 8 kHz e resolução de 8 bits.

- Armazenamento do áudio em buffer de 40.000 amostras na RAM.

- Reprodução do áudio via PWM, com a mesma taxa de amostragem.

- Controle simples via botões para iniciar gravação e reprodução.

- Indicação visual via LEDs para diferentes estados.

Estrutura do Código
| Arquivo       | Descrição                                                     |
| ------------- | ------------------------------------------------------------- |
| `adc_audio.c` | Captura o áudio via ADC e armazena no buffer.                 |
| `adc_audio.h` | Declaração das funções e variáveis de áudio.                  |
| `pwm_audio.c` | Inicializa o PWM e reproduz o áudio.                          |
| `pwm_audio.h` | Protótipos das funções PWM.                                   |
| `controls.c`  | Inicializa e gerencia botões e LEDs.                          |
| `controls.h`  | Protótipos e definições de pinos para botões e LEDs.          |
| `main.c`      | Loop principal: gerencia botões, LEDs, gravação e reprodução. |

Como Usar

- Compile o projeto usando o SDK do Raspberry Pi Pico.

- Carregue o firmware na placa Raspberry Pi Pico.

- Pressione o Botão A (GPIO 5) para iniciar a gravação — LED verde acende durante a gravação.

- Após a gravação (buffer cheio), o LED vermelho acende.

- Pressione o Botão B (GPIO 6) para reproduzir o áudio gravado — LED azul acende durante a reprodução.

- O áudio é reproduzido no buzzer conectado ao GPIO 10.
---

## 📜 Licença
GNU GPL-3.0.

