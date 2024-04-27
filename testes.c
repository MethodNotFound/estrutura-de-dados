void test() {
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
}
