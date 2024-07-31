#pragma once

#include "NodoArbolAA.h"
#include "Persona.h"

class ArbolAA {
public:
    NodoArbolAA* root;

    ArbolAA() : root(nullptr) {}
    void insertar(Persona k);
    bool buscar(std::string cedula) const;
    void mostrarConPausa() const;

private:
    NodoArbolAA* insertarRec(NodoArbolAA* nodo, Persona k);
    NodoArbolAA* skew(NodoArbolAA* nodo);
    NodoArbolAA* split(NodoArbolAA* nodo);
};