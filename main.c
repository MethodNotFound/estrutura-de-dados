#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
  char id[50];
  int clienteIndex;
} FichaCliente;

typedef struct {
  char cpf[50];
  char nome[50];
  char numero[50];
} Cliente;

struct ClientesLista {
  int tamanho;
  Cliente* *clientes; // lista dinamica
};

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

void inicializarClientesLista(struct ClientesLista* lista) {
  lista->tamanho = 0;
}

int cadastrarClienteNaLista(struct ClientesLista* lista, Cliente* cliente) {
  lista->tamanho = lista->tamanho + 1;
  if(lista->tamanho == 1) {
    lista->clientes = (Cliente **)malloc(lista->tamanho * sizeof(Cliente));
  }  else {
    lista->clientes = (Cliente **) realloc(lista->clientes, lista->tamanho * sizeof(Cliente));
  }
  lista->clientes[lista->tamanho - 1] = cliente;
  
  return lista->tamanho - 1;
}

void listarClientes(struct ClientesLista* lista) {
  for(int i = 0; i < lista->tamanho; i++) {
    printf("\n");
    printf("cpf: %s \n", lista->clientes[i]->cpf);
    printf("nome: %s \n", lista->clientes[i]->nome);
    printf("numero: %s \n", lista->clientes[i]->numero);
  }
}

// poderia usar um index? poderia, maaaaaas, nesse projeto eXtreme GoHorse rules
int buscarClientePorCpf(struct ClientesLista* lista, char* cpf) {
  for(int i = 0; i < lista->tamanho; i++) {
    if(lista->clientes[i]->cpf == cpf) {
      return i;
    }
  }
  return -1;
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

int main(void) {
  struct ClientesLista listaClientes;
  inicializarClientesLista(&listaClientes);
  struct Fila fila;
  inicializarFila(&fila);

  Cliente cliente = {"3232323223223", "Turkyilmaz Rana", "5511942042069"};
  int clienteIndex = cadastrarClienteNaLista(&listaClientes, &cliente);
  Cliente cliente2 = {"3232323223222", "Swift Taylor", "5511942042068"};
  int cliente2Index = cadastrarClienteNaLista(&listaClientes, &cliente2);
  
  FichaCliente ficha = novaFicha(clienteIndex);
  FichaCliente ficha2 = novaFicha(cliente2Index);

  enqueue(&fila, &ficha);
  enqueue(&fila, &ficha2);

  listarClientes(&listaClientes);
  return 0;
}
