#pragma once
#include "NodoArbolRadix.h"
#include "Persona.h"

class ArbolRadix {
    NodoArbolRadix* raizNombre;
    NodoArbolRadix* raizApellido;
    NodoArbolRadix* raizNombre2;

    void insertar(NodoArbolRadix* nodo, const std::string& palabra);
    bool buscar(NodoArbolRadix* nodo, const std::string& palabra);
    void mostrar(NodoArbolRadix* nodo, const std::string& prefijo, int nivel) const;
    void limpiar(NodoArbolRadix* nodo);

public:
    ArbolRadix();
    ~ArbolRadix();
    void insertar(const Persona& persona);
    bool buscar(const std::string& nombre);
    bool buscarApellido(const std::string& apellido);
    bool buscarNombre2(const std::string& segundoNombre);   
    void mostrarApellidos() const;
    void mostrarNombres() const ;
    void mostrarNombre2() const;
};
