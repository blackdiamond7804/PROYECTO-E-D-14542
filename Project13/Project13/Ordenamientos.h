#pragma once
#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

#include "Nodo.h"
#include "Persona.h"
#include <algorithm>
#include <string>
#include <cctype>

void shellSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio);
void shellSort(std::string& str);
void bubbleSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio);
void bubbleSort(std::string& str);

#endif // ORDENAMIENTOS_H