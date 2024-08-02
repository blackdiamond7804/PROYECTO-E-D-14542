
#ifndef NODO_H
#define NODO_H

#include "Persona.h"
#include <cstring>

class Nodo {
public:
    Persona dato;
    char key[20];
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(const Persona& p) : dato(p), siguiente(nullptr), anterior(nullptr) {}

    Nodo(const char* key, Persona& dato) : dato(dato), siguiente(nullptr) {
        strncpy(this->key, key, sizeof(this->key) - 1);
        this->key[sizeof(this->key) - 1] = '\0'; // Asegurar que la cadena esté terminada en null
    }

    //Metodos para la creacion del nodo de arbol
    //Nodos para el arbol
    /*Nodo* derecha;
    Nodo* izquierda;
    Nodo* padre;
    Nodo(const Persona& p, Nodo* pad) : dato(p), izquierda(nullptr), derecha(nullptr), padre(pad) {}
    void setDerecha(Nodo* derecha) {
        this->derecha = derecha;
    }

    Nodo*& getDerecha() {
        return derecha;
    }

    void setIzquierda(Nodo* izquierda) {
        this->izquierda = izquierda;
    }

    Nodo*& getIzquierda() {
        return izquierda;
    }

    Nodo*& getPadre() {
        return padre;
    }

    void setPadre(Nodo* padre) {
        this->padre = padre;
    }*/
};

#endif