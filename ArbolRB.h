#pragma once

#include <string>
#include "NodoArbolRB.h"
#include "Persona.h"

class ArbolRB {
public:
    NodoArbolRB* root;

    ArbolRB() : root(nullptr) {}
    void insertar(Persona k);
    bool buscar(std::string cedula) const;
    void mostrarConPausa() const;
    void rotarIzquierda(NodoArbolRB* &raiz, NodoArbolRB* &pt);
    void rotarDerecha(NodoArbolRB* &raiz, NodoArbolRB* &pt);
    void arreglarInsertarRB(NodoArbolRB* &raiz, NodoArbolRB* &pt);
};