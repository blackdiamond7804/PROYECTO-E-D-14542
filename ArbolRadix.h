#pragma once
#include "NodoArbolRadix.h"
#include "Persona.h"

class ArbolRadix {
    NodoArbolRadix* raiz;

    void insertar(NodoArbolRadix* nodo, const std::string& palabra);
    bool buscar(NodoArbolRadix* nodo, const std::string& palabra);
    void mostrar(NodoArbolRadix* nodo, const std::string& prefijo, int nivel);
    void limpiar(NodoArbolRadix* nodo);

public:
    ArbolRadix();
    ~ArbolRadix();
    void insertar(const Persona& persona);
    bool buscar(const std::string& nombre);
    void mostrar();
};
