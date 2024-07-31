#include "NodoArbolAA.h"
#include <iostream>

bool NodoArbolAA::buscar(const std::string& cedula) const {
    if (cedula == dato.cedula)
        return true;
    if (cedula < dato.cedula && izquierda != nullptr)
        return izquierda->buscar(cedula);
    if (cedula > dato.cedula && derecha != nullptr)
        return derecha->buscar(cedula);
    return false;
}

void NodoArbolAA::imprimirArbolAA(int indent) const {
    if (derecha != nullptr)
        derecha->imprimirArbolAA(indent + 4);
    if (indent)
        std::cout << std::string(indent, ' ');
    std::cout << dato.cedula << "(" << nivel << ")" << std::endl;
    if (izquierda != nullptr)
        izquierda->imprimirArbolAA(indent + 4);
}