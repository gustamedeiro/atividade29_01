# Atividade de Semáforo e One Shot, ambas estão neste repositório.
Cada atividade tem sua pasta, com os componentes necessários para sua utilização.

# Como acessar cada atividade?
É bem simples, se tiver interesse em acessar a atividade que pede para fazer algo parecido com um semáforo (especificações completas das atividades no próximo paragrafo), basta entrar na pasta com nome de "semaforo"; caso for na outra atividade do dia 29/02 basta entrar na pasta "one_shot".

# ESPECIFICAÇÕES DAS ATIVIDADES

# Atividade Semáforo

Com o emprego da função add_repeating_timer_ms(), presente na ferramenta Pico SDK, projete um semáforo com temporização de 3 segundos para cada alteração de sinal. O fluxograma simplificado de atuação do semáforo pode ser visualizado na Figura 1. Nesta prática, será necessário simular os seguintes componentes:

1) Microcontrolador Raspberry Pi Pico W.

2) 03 LEDs (vermelho, amarelo e verde).

3) 03 Resistores de 330 Ω.

OS REQUISITOS PARA A REALIZAÇÃO DESTA ATIVIDADE:

1) O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha, conforme orientação presente na Figura 1, alterando para amarela e, em seguida, verde.

2) O temporizador deve ser ajustado para um atraso de 3 segundos (3.000ms).

3) A mudança de estado dos LEDs deve ser implementa na função de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona - repeating_timer_callback().

4) A rotina principal, presente no interior da estrutura de repetição while, deve imprimir algum tipo de informação a cada segundo (1.000 ms) - a mensagem enviada pela porta serial fica a critério do discente.

5) Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIOs 11, 12 e 13.


# Atividade One Shot

Com o emprego da função add_alarm_in_ms(), presente na ferramenta Pico SDK, projete um sistema de temporização para o acionamento de LEDs, que atua a partir do clique em um botão (pushbutton). Nesta prática, será necessário simular os seguintes componentes:

1) Microcontrolador Raspberry Pi Pico W.

2) 03 LEDs (azul, vermelho e verde).

3) 03 Resistores de 330 Ω.

4) Botão (Pushbutton).

OS REQUISITOS PARA A REALIZAÇÃO DESTA ATIVIDADE:

1) Caso o usuário clique no botão (pushbutton), os três LEDs serão ligados (todos em nível alto). A partir da primeira rotina de atraso, ocorrerá uma mudança de estado para dois LEDs ligados e, em seguida, apenas um. Obs.: veja o vídeo associado a esta prática no link presente na Figura 3.

2) O temporizador do alarme deve ser ajustado para um atraso de 3 segundos (3.000ms), entre os estados de acionamento dos LEDs.

3) A mudança de estado dos LEDs deve ser implementa em funções de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona - turn_off_callback().
