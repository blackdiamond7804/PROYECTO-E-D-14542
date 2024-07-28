#pragma once

#include <string>
#include "NodoArbolB.h"
#include "Persona.h" 

class ArbolB {
public:
	NodoArbolB* root;//puntero a a raiz
	int t;

	ArbolB(int _t) : root(nullptr), t(_t){}
	bool buscar(std::string cedula);
	void insertar(Persona k);
	void imprimirArbolB() const { if (root != nullptr) root->imprimirArbolB(); }
	void mostrarConPausa() const;
};