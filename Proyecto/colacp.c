#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include "colacp.h"

TColaCP crear_cola_cp(int (*f)(TEntrada, TEntrada))
{
    TColaCP cola = (TColaCP) malloc(sizeof(TNodo));
    cola->cantidad_elementos= 0;
    cola->raiz= NULL;
    cola->comparador = f;

    return cola;
}

int cp_insertar(TColaCP cola, TEntrada entr) {
  return 0;
}
/*
TEntrada cp_eliminar(TColaCP cola) {

}*/

int cp_cantidad(TColaCP cola)
{
    if (cola == NULL) exit(CCP_NO_INI);
    return cola->cantidad_elementos;
}

/*void cp_destruir(TColaCP cola, void(*fEliminar) (TEntrada)) {
    while (cola->cantidad_elementos > 0) {
        fEliminar(cp_eliminar(cola));
    }
}*/

