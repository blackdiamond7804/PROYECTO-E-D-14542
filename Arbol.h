#pragma once

#include <iostream>
#include <conio.h>
#include "Nodo.h"
#include "Persona.h"

class Arbol {

public:
	Nodo* raiz;

	Arbol() : raiz(nullptr) {
	}

	Nodo*& getRaiz() {
		return raiz;
	}

	void Insertar(Nodo*& nodo, const Persona& persona, Nodo* padre) {
		if (nodo == NULL) {
			Nodo* nuevo = new Nodo(persona, padre);
			nodo = nuevo;
		}
		else {
			if (persona.cedula < nodo->dato.cedula) {
				Insertar(nodo->getIzquierda(), persona, nodo);
			}
			else {
				Insertar(nodo->getDerecha(), persona, nodo);
			}
		}
	}

	void mostrar(Nodo* nodo, int espacio) const {
		if (nodo == nullptr) {
			return;
		}
		espacio += 2;
		mostrar(nodo->getDerecha(), espacio);
		for (int i = 2; i < espacio; i++) {
			std::cout << "  ";
		}
		std::cout << nodo->dato << std::endl;
		mostrar(nodo->getIzquierda(), espacio);
	}

	void mostrarConPausa() const {
		mostrar(raiz, 0);
		std::cout << "Presione cualquier tecla para continuar..." << std::endl;
		_getch(); // Pausar para que el usuario vea la salida
	}
};