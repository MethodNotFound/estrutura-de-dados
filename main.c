#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.c"
#include "clientes_lista.c"

//cli
#include "cli/clientes.c"
#include "cli/fila.c"
#include "cli/main.c"

#include "testes.c"

int main(void) {
  /* test(); */
  struct ClientesLista listaClientes;
  inicializarClientesLista(&listaClientes);
  struct Fila fila;
  inicializarFila(&fila);
  struct Fila filaPri;
  inicializarFila(&filaPri);

  mainActions(&listaClientes, &fila, &filaPri);

  return 0;
}
