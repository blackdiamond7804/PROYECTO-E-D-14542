
#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

#include "Nodo.h"
#include "Lista.h"
#include "Persona.h"
#include <algorithm>
#include <string>
#include <cctype>

void shellSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio);
void shellSort(std::string& str);

int obtenerDigito(const std::string& str, int index);
void radixSortPersonas(Nodo*& cabeza, bool esCircular, int criterio);
void radixSort(std::string& str);

void bubbleSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio);
void bubbleSort(std::string& str);

void quickSortPersonas(Nodo*& cabeza, Nodo*& cola, bool esCircular, int criterio);
void quickSort(std::string& str);

void intercambioPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio);
void intercambio(std::string& str);

void BucketSort(Nodo*& cabeza, Nodo*& cola, bool esCircular, int n);
#endif // ORDENAMIENTOS_H