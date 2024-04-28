void chamarProximo(struct ClientesLista* lista, struct Fila* fila){
  system("clear");

  FichaCliente ficha =  *dequeue(fila);

  Cliente cliente = lista->clientes[ficha.clienteIndex];


  printf("\nproximo ficha: %s\n", ficha.id);
  inspectCliente(cliente);

  printf("\npressione qualquer tecla para voltar");
  getchar();
  getchar();
}

void adicinarFicha(struct ClientesLista* lista, struct Fila* fila){
  system("clear");

  printf("Adicionar ficha\n");

  char cpf[50];
  printf("digite o cpf : ");
  scanf("%s", &cpf);

  int clienteIndex = buscarClientePorCpf(lista, cpf);

  // macarrão, muito bom
  if(clienteIndex == -1) {
    printf("cliente com cpf %s não encontrado\n", cpf);

    Cliente cliente;
    printf("cadastrando novo cliente cliente\n");

    strcpy(cliente.cpf, cpf);
    printf("nome : ");
    scanf("%s", &cliente.nome);
    printf("numero : ");
    scanf("%s", &cliente.numero);

    clienteIndex = cadastrarClienteNaLista(lista, &cliente);
    printf("\ncliente cadastrado\n");
  } else {
    if(clienteNaFila(fila, clienteIndex)) {
      printf("cliente ja foi adicionado na fila");

      printf("\npressione qualquer tecla para voltar");
      getchar();
      getchar();
      return;
    }
  }

  FichaCliente ficha = novaFicha(clienteIndex);
  enqueue(fila, &ficha);
  printf("adicionado na fila");

  printf("\npressione qualquer tecla para voltar");
  getchar();
  getchar();
}


void listarFichas(struct ClientesLista* lista, struct Fila* fila){
  system("clear");

  printf("Listar fichas\n");

  for(int i = 0; i < fila->tamanho; i++){
    printf("\nficha %s\n", fila->elementos[i].id);
    inspectCliente(lista->clientes[fila->elementos[i].clienteIndex]);
  }

  printf("\npressione qualquer tecla para voltar");
  getchar();
  getchar();
}

void filaActions(struct ClientesLista* lista, struct Fila* fila){
  while(1) {
    system("clear");

    printf("total de fichas na fila: %d\n", fila->tamanho);
    printf("\n");

    printf("[0] chamar proxima ficha\n");
    printf("[1] adicinar ficha na fila\n");
    printf("[2] listar fichas\n");
    printf("[3] sair\n");

    int input;
    printf("selecionar ação: ");
    scanf("%d", &input);

    if(input == 0){
      chamarProximo(lista, fila);
    }
    else if(input == 1){
      adicinarFicha(lista, fila);
    }
    else if(input == 2){
      listarFichas(lista, fila);
    }
    else if(input == 3){
      return;
    }
    else {
      char t;
      scanf("%s", &t);
    }
  }
}
