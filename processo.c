#include <stdio.h>
#include <string.h>
#include "fila.h"
#define SEQUENCIA 10

// Adotarei neste exercício que o tempo que a CPU irá demorar para realizar um processo será de 1 segundo.
// Logo, se um processo demora 5 segundos para ser realizado, a CPU irá ler esse processo por 5 vezes
// até completá-lo. O valor de 1 segundo é decrescido do processo e será o último da fila até que chegue 
// sua vez novamente.

typedef struct dados{
    int id;
    int tempo;
    char bits[SEQUENCIA];
}Dados;

Dados criaProcesso(int id, int t, char *bits){
    
    Dados processo;

    processo.id = id;
    strcpy(processo.bits, bits);
    processo.tempo = t;

    return processo;
}

void realizaProcesso(Fila *f, void *info){
    // A função percorreFila vai utilizar o callback para chamar esta função. Aqui, as informações do andamento
    // do processo serão passadas para o usuário. Além disso, nesta função o tempo é decrementado em 1 segundo e,
    // se o processo for finalizado, o Nó é retirado através da função dequeue na linha 41.
    
    Dados *processo = (Dados *)info;

    printf("Processo de identificacao '%d'.\n", processo -> id);
    printf("Informacao: %s\n", processo -> bits);
    
    if(processo -> tempo <= 0){
        printf("----------------------------------------\n");
        printf("Processo '%d' concluido com sucesso.\n", processo -> id);
        printf("----------------------------------------\n\n");
        dequeue(f);
    }else{
        printf("Tempo necessario para ser executado: %d seg\n", processo -> tempo);
        processo -> tempo--;
        printf("\n");
    }
}


