void mainActions(struct ClientesLista* lista, struct Fila* fila){
  while(1) {
    system("clear");

    printf("[0] clientes\n");
    printf("[1] fila\n");
    printf("[2] sair\n");

    int input;
    printf("selecionar ação: ");
    scanf("%d", &input);

    if(input == 0){
      clientesActions(lista);
    }
    else if(input == 1) {
      filaActions(lista, fila);
    }
    else if(input == 2) {
      return;
    }
    else {
      char t;
      scanf("%s", &t);
    }
  }
}
