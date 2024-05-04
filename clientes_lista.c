typedef struct {
  char cpf[50];
  char nome[50];
  char numero[50];
} Cliente;

struct ClientesLista {
  int tamanho;
  Cliente* clientes; // lista dinamica
};

void inspectCliente(Cliente cliente) {
  printf("cpf: %s \n", cliente.cpf);
  printf("nome: %s \n", cliente.nome);
  printf("telefone: %s \n", cliente.numero);
}

void setClienteAttributes(Cliente* cliente){
  printf("cpf : ");
  fflush(stdin);
  scanf(" %50[^\n]c", cliente->cpf);
  printf("nome : ");
  scanf(" %50[^\n]c", cliente->nome);
  printf("telefone : ");
  scanf(" %50[^\n]c", cliente->numero);
}

void inicializarClientesLista(struct ClientesLista* lista) {
  lista->tamanho = 0;
}

int cadastrarClienteNaLista(struct ClientesLista* lista, Cliente* cliente) {
  lista->tamanho = lista->tamanho + 1;

  lista->clientes = (Cliente *)realloc(lista->clientes, lista->tamanho * sizeof(Cliente));

  Cliente novoCliente;
  strcpy(novoCliente.cpf, cliente->cpf);
  strcpy(novoCliente.nome, cliente->nome);
  strcpy(novoCliente.numero, cliente->numero);
  lista->clientes[lista->tamanho - 1] = novoCliente;

  return lista->tamanho - 1;
}

// poderia usar um index? poderia, maaaaaas, nesse projeto eXtreme GoHorse rules
int buscarClientePorCpf(struct ClientesLista* lista, char* cpf) {
  for(int i = 0; i < lista->tamanho; i++) {
    if(strcmp(lista->clientes[i].cpf, cpf) == 0) {
      return i;
    }
  }
  return -1;
}

// TODO deletar cliente.....
