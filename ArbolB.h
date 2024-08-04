#pragma once

#include <string>
#include "NodoArbolB.h"
#include "Persona.h" 

class btree {
private:
	stclave* lista;
	pbnodo* listapunt;
	void Inserta(stclave clave, pbnodo nodo, pbnodo hijo1, pbnodo hijo2);
	//void BorrarClave(pbnodo nodo, int valor);
	void BorrarNodo(pbnodo nodo);
	//void PasarClaveDerecha(pbnodo derecha, pbnodo padre, pbnodo nodo, int posClavePadre);
	//void PasarClaveIzquierda(pbnodo izquierda, pbnodo padre, pbnodo nodo, int posClavePadre);
	//void FundirNodo(pbnodo izquierda, pbnodo& padre, pbnodo derecha, int posClavePadre);
	void Ver(pbnodo nodo);
	
	int nClaves, nodosMinimos;
	pbnodo Entrada;
public:
	btree(int nClv);
	~btree();
	//Persona Buscar(std::string cedula);
	bool InsertarA(stclave clave);
	//void Borrar(std::string cedula);
	void Mostrar();
	void InsertarEnArbolBDesdeArchivo();
};