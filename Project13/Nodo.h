#pragma once
#ifndef NODO_H
#define NODO_H

#include "Persona.h"

class Nodo {
public:
    Persona dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(const Persona& p) : dato(p), siguiente(nullptr), anterior(nullptr) {}
};

#endif