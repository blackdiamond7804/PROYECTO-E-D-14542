#pragma once

#include "Persona.h"

class NodoArbolAA {
public:
    Persona dato;
    NodoArbolAA* izquierda;
    NodoArbolAA* derecha;
    int nivel;

    NodoArbolAA(Persona d) : dato(d), izquierda(nullptr), derecha(nullptr), nivel(1) {}

    bool buscar(const std::string& cedula) const;
    void imprimirArbolAA(int indent = 0) const;
};