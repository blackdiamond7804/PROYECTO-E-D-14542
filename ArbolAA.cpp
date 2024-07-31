#include "ArbolAA.h"
#include <conio.h>
#include <iostream>

void ArbolAA::insertar(Persona k) {
    root = insertarRec(root, k);
}

NodoArbolAA* ArbolAA::insertarRec(NodoArbolAA* nodo, Persona k) {
    if (nodo == nullptr)
        return new NodoArbolAA(k);

    if (k.cedula < nodo->dato.cedula)
        nodo->izquierda = insertarRec(nodo->izquierda, k);
    else if (k.cedula > nodo->dato.cedula)
        nodo->derecha = insertarRec(nodo->derecha, k);

    nodo = skew(nodo);
    nodo = split(nodo);

    return nodo;
}

NodoArbolAA* ArbolAA::skew(NodoArbolAA* nodo) {
    if (nodo == nullptr || nodo->izquierda == nullptr)
        return nodo;

    if (nodo->izquierda->nivel == nodo->nivel) {
        NodoArbolAA* izquierda = nodo->izquierda;
        nodo->izquierda = izquierda->derecha;
        izquierda->derecha = nodo;
        return izquierda;
    }
    return nodo;
}

NodoArbolAA* ArbolAA::split(NodoArbolAA* nodo) {
    if (nodo == nullptr || nodo->derecha == nullptr || nodo->derecha->derecha == nullptr)
        return nodo;

    if (nodo->nivel == nodo->derecha->derecha->nivel) {
        NodoArbolAA* derecha = nodo->derecha;
        nodo->derecha = derecha->izquierda;
        derecha->izquierda = nodo;
        derecha->nivel++;
        return derecha;
    }
    return nodo;
}

bool ArbolAA::buscar(std::string cedula) const {
    return root == nullptr ? false : root->buscar(cedula);
}

void ArbolAA::mostrarConPausa() const {
    if (root != nullptr) root->imprimirArbolAA();
    std::cout << "Presione cualquier tecla para continuar..." << std::endl;
    _getch();
}