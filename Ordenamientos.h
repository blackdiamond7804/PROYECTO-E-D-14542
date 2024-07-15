
#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

#include <algorithm>
#include <string>
#include <cctype>
#include "Nodo.h"
#include "Lista.h"
#include "Persona.h"

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
void inversoString(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio);
#endif // ORDENAMIENTOS_H