#pragma once
#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

#include "Nodo.h"
#include "Persona.h"
#include "Lista.h"
#include <algorithm>
#include <string>
#include <cctype>
#include "Hash.h"

void shellSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio);
void shellSort(std::string& str);
void BucketSort(Nodo* cabeza, Nodo* cola, bool esCircular, int n);
#endif // ORDENAMIENTOS_H