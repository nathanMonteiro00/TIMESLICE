#include <stdio.h>
#include <string.h>
#include "fila.h"
#include "fila.c"
#include "processo.c"

void main(){

    Fila *filaProcess = criaFila();
    Dados proc1 = criaProcesso(20007, 1, "1001010");
    Dados proc2 = criaProcesso(20008, 1, "0010111");
    Dados proc3 = criaProcesso(20009, 2, "1110101");
    Dados proc4 = criaProcesso(20010, 5, "1110101");
    enqueue(filaProcess, &proc1);
    enqueue(filaProcess, &proc2);
    enqueue(filaProcess, &proc3);
    enqueue(filaProcess, &proc4);
    percorreFila(filaProcess, realizaProcesso);
}