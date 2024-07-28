#ifndef NODOARBOLB_H
#define NODOARBOLB_H

#include <string>
#include "Persona.h"
class Lista;

class NodoArbolB {
public:
	Lista* llaves;//son las claves
	int t;//grado minimo
	NodoArbolB** C;
	int n;
	bool leaf;

	NodoArbolB(int t1, bool leaf1);

	bool buscar(string k);
	void InsertarNodoLleno(Persona k);
	void splitChild(int i, NodoArbolB* y);
	void imprimirArbolB(int indent = 0);

};

#endif