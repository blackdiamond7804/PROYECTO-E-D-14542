#pragma once
#include <string>

class NodoArbolRadix {
public:
    std::string clave;
    NodoArbolRadix* siguiente;
    NodoArbolRadix* hijo;
    bool finPalabra;
    NodoArbolRadix(const std::string& clave = "", bool finPalabra = false)
        : clave(clave), siguiente(nullptr), hijo(nullptr), finPalabra(finPalabra) {}
};
