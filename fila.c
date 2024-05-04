#define MAX_SIZE 100


// TODO adicionar uma fila com prioridade
// TODO mostrar o programa para o cliente
typedef struct {
  char id[50];
  int clienteIndex;
} FichaCliente;

struct Fila {
  int tamanho, fim, inicio;
  FichaCliente elementos[MAX_SIZE]; // fila
};

int GLOBAL_ID_COUNT = 0;

FichaCliente novaFicha(int clienteIndex) {
  char id[50];
  sprintf(id, "%d", GLOBAL_ID_COUNT);
  FichaCliente ficha = { "" };
  strcpy(ficha.id, id);
  ficha.clienteIndex = clienteIndex;
  GLOBAL_ID_COUNT++;
  return ficha;
}

void inicializarFila(struct Fila* fila) {
  fila->inicio = 0;
  fila->fim = -1;
  fila->tamanho = 0;
}

int estaVazia(struct Fila* fila) {
  return fila->tamanho == 0;
}

int estaCheia(struct Fila* fila) {
  return fila->tamanho == MAX_SIZE;
}

void enqueue(struct Fila* fila, FichaCliente* ficha) {
  if (!estaCheia(fila)) {
    fila->fim = (fila->fim + 1) % MAX_SIZE;
    fila->elementos[fila->fim] = *ficha;
    fila->tamanho++;
  } else {
    printf("Erro: Fila cheia.\n");
  }
}

FichaCliente* dequeue(struct Fila* fila) {
  if (!estaVazia(fila)) {
    FichaCliente ficha = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_SIZE;
    fila->tamanho--;
    return &ficha;
  } else {
    printf("Erro: Fila vazia.\n");
    return NULL;
  }
}

FichaCliente* peek(struct Fila* fila) {
  if (!estaVazia(fila)) {
    return &fila->elementos[fila->inicio];
  } else {
    printf("Erro: Fila vazia.\n");
    return NULL;
  }
}

int clienteNaFila(struct Fila* fila, int clienteIndex){
  // outra busca nao optimizada
  for(int i = 0; i < fila->tamanho; i++){
    if(fila->elementos[i].clienteIndex == clienteIndex) {
      return 1;
    }
  }
  return 0;
}
