#ifndef NODOARBOLB_H
#define NODOARBOLB_H

#include <string>
#include <iostream>
#include "Persona.h"

struct stclave {
	std::string cedula;
	Persona persona;
};

class bnodo {
private:
	int clavesUsadas;
	stclave* clave;
	bnodo** puntero;
	bnodo* padre;

	friend class btree;
public:
	bnodo(int nClaves);
	~bnodo();
};

typedef bnodo* pbnodo;

#endif