#pragma once

#include <string>
#include "NodoArbolBmas.h"
#include "Persona.h"

class ArbolBmas {
public:
    NodoArbolBmas* root;
    int t;

    ArbolBmas(int _t) :root(nullptr), t(_t) {}

    void insertar(Persona k);
    bool buscar(std::string cedula);
    void mostrarConPausa() const;
  
};
