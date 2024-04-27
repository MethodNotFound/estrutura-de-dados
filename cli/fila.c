void filaActions(struct ClientesLista* lista, struct Fila* fila){
  while(1) {
    system("clear");

    printf("total de fichas na fila: %d\n", fila->tamanho);
    printf("\n");

    printf("[0] chamar proxima ficha\n");
    printf("[1] adicinar ficha na fila\n");
    printf("[2] sair\n");

    int input;
    printf("selecionar ação: ");
    scanf("%d", &input);

    if(input == 2)
      return;
  }
}
