void clientesActions(struct ClientesLista* lista){
  while(1) {
    system("clear");

    printf("[0] cadastrar cliente\n");
    printf("[1] listar clientes\n");
    printf("[2] consultar cliente\n");
    printf("[3] editar cliente\n");
    printf("[4] sair\n");

    int input;
    printf("selecionar ação: ");
    scanf("%d", &input);

    if(input == 4)
      return;
  }
}

void listarClientes(struct ClientesLista* lista) {
  for(int i = 0; i < lista->tamanho; i++) {
    printf("\n");
    printf("cpf: %s \n", lista->clientes[i]->cpf);
    printf("nome: %s \n", lista->clientes[i]->nome);
    printf("numero: %s \n", lista->clientes[i]->numero);
  }
}
