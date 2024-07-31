#pragma once


#include "Persona.h"
class Lista;

class NodoArbolBmas {
public:
    Lista* llaves;
    NodoArbolBmas** C;
    int t;
    bool leaf;
    
    NodoArbolBmas* siguiente;
    int n;

    NodoArbolBmas(int _t, bool _leaf);

    void InsertarNodoLleno(Persona k);
    void splitChild(int i, NodoArbolBmas* y);
    void imprimirArbolBmas(int indent);
    bool buscar(std::string cedula);

    
 
    friend class ArbolBmas;
};

