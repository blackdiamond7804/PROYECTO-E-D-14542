#include "NodoArbolB.h"

bnodo::bnodo(int nClaves) {
	clavesUsadas = 0;
	clave = new stclave[nClaves];
	puntero = new pbnodo[nClaves + 1];
	padre = NULL;
}

bnodo::~bnodo() {
	delete[] clave;
	delete[] puntero;
}


