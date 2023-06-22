typedef struct fila Fila;
typedef struct no No;
Fila *criaFila();
No *criaNo(void *valor);
void enqueue(Fila *fila, void *v);
void dequeue(Fila *fila);
void destroyNo(No **no_ref);
void percorreFila(Fila *fila, void (*cb)(Fila *f, void *));
