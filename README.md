### TIMESLICE

Exercício que simula escalonamento de processos utilizando o algoritmo Time Slice (Round Robin) em linguagem C.

### Sobre o exercício

Este projeto foi desenvolvido como atividade da disciplina de Estrutura de Dados com o objetivo de simular o funcionamento básico de um escalonador de processos de sistemas operacionais.

A implementação utiliza:

fila circular duplamente encadeada
nós genéricos com void *
callbacks para processamento
gerenciamento dinâmico de memória
simulação de quantum de CPU

### Conceitos aplicados
Estruturas de Dados
Filas
Lista circular
Escalonamento Round Robin
Ponteiros genéricos em C
Modularização
Callbacks
Como funciona

**Cada processo possui**:

ID, tempo restante de execução e sequência binária representando dados do processo.

A CPU executa um “time slice” de cada processo por vez.

**Após cada execução**:

o tempo restante é decrementado, o processo retorna ao fim da fila e quando o tempo chega a zero, o processo é removido.
