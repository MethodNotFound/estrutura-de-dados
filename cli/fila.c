void chamarProximo(struct ClientesLista* lista, struct Fila* fila, struct Fila* filaPri){
  system("clear");

  FichaCliente ficha;
  if(filaPri->tamanho > 0) {
    ficha = *dequeue(filaPri);
    printf("cliente chamado da fila de prioridade\n");
  } else {
    ficha = *dequeue(fila);
  }

  Cliente cliente = lista->clientes[ficha.clienteIndex];

  printf("\nficha: %s\n", ficha.id);
  inspectCliente(cliente);

  printf("\npressione qualquer tecla para voltar");
  getchar();
  getchar();
}

void adicinarFicha(struct ClientesLista* lista, struct Fila* fila, struct Fila* filaPri){
  system("clear");

  printf("Adicionar ficha\n");

  char prioritario[10];
  printf("o cliente é prioritário [S/N]: ");
  fflush(stdin);
  scanf("%s", &prioritario);
  if(strcmp(prioritario, "S") == 0 || strcmp(prioritario, "s") == 0) {
    printf("cadastrando ficha como prioritária\n");
  }

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
    fflush(stdin);
    printf("nome : ");
    scanf(" %50[^\n]c", &cliente.nome);
    printf("telefone : ");
    scanf(" %50[^\n]c", &cliente.numero);

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

  if(strcmp(prioritario, "S") == 0 || strcmp(prioritario, "s") == 0) {
    FichaCliente ficha = novaFicha(clienteIndex);
    enqueue(filaPri, &ficha);
    printf("adicionado na fila prioritária");
  } else {
    FichaCliente ficha = novaFicha(clienteIndex);
    enqueue(fila, &ficha);
    printf("adicionado na fila");
  }

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

void filaActions(struct ClientesLista* lista, struct Fila* fila, struct Fila* filaPri){
  while(1) {
    system("clear");

    printf("total de fichas na fila: %d\n", fila->tamanho + filaPri->tamanho);
    printf("\n");

    printf("[0] chamar proxima ficha\n");
    printf("[1] adicinar ficha na fila\n");
    /* printf("[2] listar fichas\n"); */
    printf("[2] sair\n");

    int input;
    printf("selecionar ação: ");
    scanf("%d", &input);

    if(input == 0){
      chamarProximo(lista, fila, filaPri);
    }
    else if(input == 1){
      adicinarFicha(lista, fila, filaPri);
    }
    /* else if(input == 2){ */
    /*   listarFichas(lista, fila); */
    /* } */
    else if(input == 2){
      return;
    }
    else {
      char t;
      scanf("%s", &t);
    }
  }
}
