# Gerenciador de Iluminação Inteligente com ESP32, LDR e Sensor IR

## Descrição do Projeto

Este projeto implementa um **sistema de iluminação inteligente** baseado em ESP32, capaz de ajustar a intensidade da luz de acordo com a luminosidade ambiente e detectar presença para otimizar o consumo energético.  
Além disso, o dispositivo se conecta ao **Arduino Cloud**, permitindo visualização em tempo real dos dados do sistema em um dashboard integrado.

---

## Funcionalidades principais

### Controle de iluminação
- Luz ambiente baixa → **LED_DIM ligado**  
- Luz baixa + presença → **LED_STRONG ligado**  
- Ambiente claro → **todos os LEDs desligados**

### Integração com Arduino Cloud
O dashboard exibe em tempo real:

- Estado do **LED_STRONG**
- Estado do **LED_DIM**
- Estado do **sensor de presença (IRS)**
- **Gráfico de linha** com o valor do LDR ao longo do tempo
- **Gauge** (indicador circular) com o valor atual do LDR
- Cálculo do **consumo energético** do sistema

---

## Cálculo de Consumo Energético

O sistema considera a quantidade de “nódulos” (lâmpadas LED simuladas) e multiplica pelo consumo em watts base configurado no código.

- Sem presença → **consumo = 10 × NODE_AMOUNT**  
- Com presença → **consumo = 20 × NODE_AMOUNT**  
- Ambiente claro → **consumo = 0**

Esse valor é enviado ao dashboard do Arduino Cloud para monitoramento.

---

## Componentes Utilizados

- ESP32 DevKit V1 (30 pinos)
- LDR + resistor (divisor de tensão)
- Sensor infravermelho digital (3 pinos – VCC, GND, OUT)
- LED forte (com resistor menor)
- LED fraco (com resistores em série)
- Jumpers e protoboard

---

## Requisitos do Projeto

### Hardware
- ESP32 compatível com Arduino IDE
- Fonte USB 5V
- LDR + resistor de pull-down
- Sensor IR digital (KY-032, TCRT5000 ou similar)
- 2 LEDs de 5mm
- Resistores adequados para os LEDs
- Acesso à internet WiFi

### Software
- **Arduino IDE** ou **Arduino Cloud Web Editor**
- Extensão/board do **ESP32** instalada
- Biblioteca do **Arduino Cloud**
- Credenciais configuradas no arquivo `thingProperties.h`

---

## Instruções de Instalação e Uso

### 1. Clonar o projeto
```bash
git clone https://github.com/VictorAGuerra/IoT-MQTT-Light-System.git
```

É necessário atualizar o arquivo "arduino_secrets.h" com a informação do WiFi que será utilizado, assim como o ID do Thing utilizado para que o código consiga se conectar com o Arduino Cloud.
