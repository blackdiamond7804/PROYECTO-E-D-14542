#pragma once

#include "Persona.h"
enum Color { Rojo, Negro };

class NodoArbolRB {
public:
    Persona dato;
    bool color;
    NodoArbolRB *izquierda, *derecha, *padre;

    NodoArbolRB(Persona d) : dato(d) {
        padre = izquierda = derecha = nullptr;
        color = Rojo;
    }
    static NodoArbolRB* BSTInsert(NodoArbolRB* root, NodoArbolRB* pt);

    bool buscar(const std::string& cedula) const;
    void imprimirArbolRB(int indent = 0) const;
};