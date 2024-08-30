#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

typedef void* TElemento;

typedef struct NodoLista
{
    TElemento elemento;
    struct NodoLista* siguiente;
    struct NodoLista* anterior;
} *TNodoLista;

typedef struct Lista
{
    int cantidad;
    TNodoLista cabeza;
    TNodoLista cola;
} *TLista;

#endif // LISTADOBLE_H_INCLUDED
