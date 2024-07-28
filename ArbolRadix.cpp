#include "ArbolRadix.h"
#include <iostream>
#include <iomanip>

using namespace std;

ArbolRadix::ArbolRadix() : raiz(new NodoArbolRadix()) {}

ArbolRadix::~ArbolRadix() {
    limpiar(raiz);
    delete raiz;
}

void ArbolRadix::insertar(const Persona& persona) {
    insertar(raiz, persona.nombre);
}

void ArbolRadix::insertar(NodoArbolRadix* nodo, const std::string& palabra) {
    if (palabra.empty()) {
        nodo->finPalabra = true;
        return;
    }

    NodoArbolRadix* actual = nodo->hijo;
    NodoArbolRadix* anterior = nullptr;

    while (actual) {
        size_t pos = 0;
        while (pos < actual->clave.size() && pos < palabra.size() && actual->clave[pos] == palabra[pos]) {
            ++pos;
        }

        if (pos > 0) {
            std::string prefijoComun = actual->clave.substr(0, pos);
            std::string hijoRestante = actual->clave.substr(pos);
            std::string palabraRestante = palabra.substr(pos);

            if (hijoRestante.empty()) {
                if (palabraRestante.empty()) {
                    actual->finPalabra = true;
                } else {
                    NodoArbolRadix* nuevoHijo = new NodoArbolRadix(palabraRestante, true);
                    nuevoHijo->hijo = actual->hijo;
                    actual->clave = prefijoComun;
                    actual->hijo = nuevoHijo;
                    actual->finPalabra = false;
                }
                return;
            } else {
                NodoArbolRadix* nuevoHijo = new NodoArbolRadix(hijoRestante, actual->finPalabra);
                nuevoHijo->hijo = actual->hijo;
                actual->clave = prefijoComun;
                actual->hijo = nuevoHijo;
                actual->finPalabra = false;
                insertar(nuevoHijo, palabraRestante);
                return;
            }
        }

        anterior = actual;
        actual = actual->siguiente;
    }

    NodoArbolRadix* nuevoNodo = new NodoArbolRadix(palabra, true);
    if (anterior) {
        anterior->siguiente = nuevoNodo;
    } else {
        nodo->hijo = nuevoNodo;
    }
}

bool ArbolRadix::buscar(const std::string& nombre) {
    return buscar(raiz, nombre);
}

bool ArbolRadix::buscar(NodoArbolRadix* nodo, const std::string& palabra) {
    if (palabra.empty()) {
        return nodo->finPalabra;
    }

    NodoArbolRadix* actual = nodo->hijo;
    while (actual) {
        if (palabra.find(actual->clave) == 0) {
            return buscar(actual, palabra.substr(actual->clave.size()));
        }
        actual = actual->siguiente;
    }

    return false;
}

void ArbolRadix::mostrar() {
    mostrar(raiz, "", 0);
}

void ArbolRadix::mostrar(NodoArbolRadix* nodo, const std::string& prefijo, int nivel) {
     if (!nodo) return;

    if (nodo->finPalabra) {
        std::cout << std::setw(nivel * 4) << "" << prefijo << " (Fin)" << std::endl;
    }

    NodoArbolRadix* actual = nodo->hijo;
    while (actual) {
        std::cout << std::setw(nivel * 4) << "" << actual->clave << std::endl;
        mostrar(actual->hijo, prefijo + actual->clave, nivel + 1);
        actual = actual->siguiente;
    }
}


void ArbolRadix::limpiar(NodoArbolRadix* nodo) {
    NodoArbolRadix* actual = nodo->hijo;
    while (actual) {
        NodoArbolRadix* siguiente = actual->siguiente;
        limpiar(actual);
        delete actual;
        actual = siguiente;
    }
}
