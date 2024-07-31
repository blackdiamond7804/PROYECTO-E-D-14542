#include "ArbolRadix.h"
#include <iostream>
#include <iomanip>

using namespace std;

ArbolRadix::ArbolRadix() : raizNombre(new NodoArbolRadix()), raizApellido(new NodoArbolRadix()), raizNombre2(new NodoArbolRadix()) {}

ArbolRadix::~ArbolRadix() {
    limpiar(raizNombre);
    limpiar(raizApellido);
    limpiar(raizNombre2);
    delete raizNombre;
    delete raizApellido;
    delete raizNombre2;
}

void ArbolRadix::insertar(const Persona& persona) {
    insertar(raizNombre, persona.nombre);
    insertar(raizApellido, persona.apellido);
    insertar(raizNombre2, persona.segundoNombre);
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
                    actual->hijo = nuevoHijo;
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
    return buscar(raizNombre, nombre);
}


bool ArbolRadix::buscarNombre2(const std::string& segundoNombre) {
    return buscar(raizNombre2, segundoNombre);
}

bool ArbolRadix::buscarApellido(const std::string& apellido) {
    return buscar(raizApellido, apellido);
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

void ArbolRadix::mostrarNombres() const {
    std::cout << "===========NOMBRES==============" << std::endl;
    mostrar(raizNombre, "", 0);
    std::cout << std::endl;
}

void ArbolRadix::mostrarNombre2() const {
    std::cout << "===========SEGUNDO NOMBRE==============" << std::endl;
    mostrar(raizNombre2, "", 0);
    std::cout << std::endl;
}

void ArbolRadix::mostrarApellidos() const {
    std::cout << "===========APELLIDOS=============" << std::endl;
    mostrar(raizApellido, "", 0);
    std::cout << std::endl;
}

void ArbolRadix::mostrar(NodoArbolRadix* nodo, const std::string& prefijo, int nivel) const {
    if (!nodo) return;

    NodoArbolRadix* actual = nodo->hijo;
    while (actual) {
        std::string nuevoPrefijo = prefijo + actual->clave;
        std::cout << std::setw(nivel * 4) << "" << actual->clave;
        if (actual->finPalabra) {
            std::cout << " (Fin)";
        }
        std::cout << std::endl;

        mostrar(actual, nuevoPrefijo, nivel + 1); 
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

