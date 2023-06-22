#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct fila{
    No *inicio;
    No *fim;
}Fila;

typedef struct no{
    void *info;
    No *prox;
    No *ant;
}No;

Fila *criaFila(){
    Fila *novaFila =  (Fila *)calloc(1, sizeof(Fila));
    if(!novaFila){
        printf("ERRO_AO_ALOCAR_MEMORIA");
        exit(1);
    }

    novaFila -> inicio = NULL;
    novaFila -> fim = NULL;
    return novaFila;
}

No *criaNo(void *valor){ // valor genérico
    No *novoNo = (No *)calloc(1, sizeof(No));
    if(!novoNo){
        printf("ERRO_AO_ALOCAR_MEMORIA");
        exit(1);
    }

    novoNo -> info = valor;
    novoNo -> ant = novoNo;
    novoNo -> prox = novoNo;
}

void enqueue(Fila *fila, void *v){
    No *novo = criaNo(v);

    if(fila -> inicio == NULL){
        fila -> inicio = novo;
        fila -> fim = novo;
    }else{
        fila -> inicio -> ant = novo;
        novo -> ant = fila -> fim;
        fila -> fim -> prox = novo;
        fila -> fim = novo;
        novo -> prox = fila -> inicio;
    }
}

void dequeue(Fila *fila){
    if(fila -> inicio != NULL){
        No *p = fila -> inicio;

        // apenas um elemento
        if(fila -> inicio == fila -> fim){
            fila -> inicio = NULL;
            fila -> fim = NULL;
        }
        // mais de um elemento
        p -> prox -> ant = fila -> fim;
        fila -> fim -> prox = fila -> inicio -> prox;
        fila -> inicio = fila -> fim -> prox;
        destroyNo(&p);
    }
}

void destroyNo(No **no_ref){
    No *no = *no_ref;
    free(no);
    *no_ref = NULL;
}

void percorreFila(Fila *fila, void (*cb)(Fila *f, void *)){
    No *aux = fila -> inicio; 
    No *pred = NULL;
    
    if(fila -> inicio != NULL){
        while(fila -> inicio != NULL){
            pred = aux;
            aux = aux -> prox;
            cb(fila, pred -> info);
        }
    }else{
        printf("Lista vazia");
    }
}
