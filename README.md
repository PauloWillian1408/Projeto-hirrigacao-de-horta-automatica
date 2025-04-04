# Projeto AutoIrriga tech
O sistema de autoirrigação funciona por meio de um sensor de umidade do solo que através da
condutibilidade do solo capta a porcentagem de umidade, o sensor envia um sinal de 5v (CC), o
sensor possui duas “pernas” um cátodo (positivo) e um ânodo (negativo) o nível de umidade é
definido através da porcentagem de tensão que chega do cátodo ao ânodo. Exemplo: Se chegar
menos de 5v ao cátodo o nível de umidade será menor que 100%.
O nível de umidade captado pelo sensor será enviado para o microcontrolador (Arduino) que
terá o papel de processar a informação recebida, o código que está armazenado no Arduino
definirá como esta informação deverá ser tratada, em nosso código nós definimos o nível de
umidade em 65% deste modo se a informação que chegar ao Arduino for que o nível de umidade
do solo está a baixo de 65% ele executará uma ação, ação esta que será de ligar a bomba que
controla o fluxo de água para a irrigação. O sensor capta a umidade do solo a cada 500ms
(milissegundo) ou seja, meio segundo, durante e após a irrigação o sensor continuará captando
a umidade do solo, então no momento em que ele captar uma umidade maior ou igual a 65%
será enviada uma nova informação para o Arduino que irá recebê-lo e efetuará o desligamento
da bomba. O ato de ligar e desligar a bomba é controlado por um módulo relé que recebe a
informação enviada pelo Arduino e ativa e desativa a passagem de corrente para a bomba. O
sistema conta com um sistema de LCD para facilitar a visualização do nível de umidade, nesta
tela será impressa o nível de umidade do solo seja ela menor ou maior de 65% esta tela LCD é
controla pelo código armazenado no Arduino, que no momento que recebe a informação do
sensor, processa e envia esta informação para que a tela LCD a imprima, o código define um
delay de 500ms para a limpeza da tela onde uma informação é impressa e após meio segundo
aquela informação é apagada da tela e uma nova informação é impressa desta forma tendo uma
maior precisão é sincronia com o sensor.
O sistema é alimentado por um sistema de painel solar Off-Grid no qual não possui nenhuma
conexão com a rede de distribuição elétrica, o painel solar capta os raios do sol por meio de
células fotovoltaicas transformando estes raios em energia elétrica (CC) que irá para um
regulador de tensão no qual controlará a forma de carregamento de uma bateria e onde será
feita a conexão entre o painel solar, a bateria e o sistema que será alimentado.

