typedef struct {
  char cpf[50];
  char nome[50];
  char numero[50];
} Cliente;

struct ClientesLista {
  int tamanho;
  Cliente* *clientes; // lista dinamica
};

void inicializarClientesLista(struct ClientesLista* lista) {
  lista->tamanho = 0;
}

int cadastrarClienteNaLista(struct ClientesLista* lista, Cliente* cliente) {
  lista->tamanho = lista->tamanho + 1;

  if (lista->tamanho == 1)
    lista->clientes = (Cliente **)malloc(lista->tamanho * sizeof(Cliente));
  else
    lista->clientes = (Cliente **)realloc(lista->clientes, lista->tamanho * sizeof(Cliente));

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
