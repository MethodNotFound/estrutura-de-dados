void listarClientes(struct ClientesLista* lista) {
  system("clear");

  for(int i = 0; i < lista->tamanho; i++) {
    inspectCliente(lista->clientes[i]);
    printf("\n");
  }

  printf("pressione qualquer tecla para voltar");
  getchar();
  getchar();
}

void cadastrarCliente(struct ClientesLista* lista){
  system("clear");

  Cliente cliente;
  printf("Novo cliente\n");
  setClienteAttributes(&cliente);

  cadastrarClienteNaLista(lista, &cliente);
  printf("\ncliente cadastrado ");

  printf("\npressione qualquer tecla para voltar");
  getchar();
  getchar();
}

void consultarCliente(struct ClientesLista* lista){
  system("clear");

  printf("Consultar cliente\n");

  char cpf[50];
  printf("digite o cpf : ");
  scanf("%s", &cpf);

  int clienteIndex = buscarClientePorCpf(lista, cpf);

  if(clienteIndex == -1) {
    printf("cliente com cpf %s não encontrado", cpf);
  } else {
    inspectCliente(lista->clientes[clienteIndex]);
  }

  printf("\npressione qualquer tecla para voltar");
  getchar();
  getchar();
}

void editarCliente(struct ClientesLista* lista){
  system("clear");

  printf("Editar cliente\n");


  char cpf[50];
  printf("digite o cpf : ");
  scanf("%s", &cpf);

  int clienteIndex = buscarClientePorCpf(lista, cpf);

  if(clienteIndex == -1) {
    printf("cliente com cpf %s não encontrado", cpf);

    printf("\npressione qualquer tecla para voltar");
    getchar();
    getchar();
    return;
  }

  setClienteAttributes(&lista->clientes[clienteIndex]);


  printf("\ndados do cliente editado");

  printf("\npressione qualquer tecla para voltar");
  getchar();
  getchar();
}

void clientesActions(struct ClientesLista* lista){
  while(1){
    system("clear");

    printf("[0] cadastrar cliente\n");
    printf("[1] listar clientes\n");
    printf("[2] consultar cliente\n");
    printf("[3] editar cliente\n");
    printf("[4] sair\n");

    int input;
    printf("selecionar ação: ");
    scanf("%d", &input);

    if(input == 0){
      cadastrarCliente(lista);
    }
    else if(input == 1) {
      listarClientes(lista);
    }
    else if(input == 2) {
      consultarCliente(lista);
    }
    else if(input == 3) {
      editarCliente(lista);
    }
    else if(input == 4) {
      return;
    }
    else {
      char t;
      scanf("%s", &t);
    }
  }
}
