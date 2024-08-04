#include "ArbolB.h"
#include <fstream>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

btree::btree(int nClv) :nClaves(nClv) {
	if (nClv <= 0) {
		std::cerr << "El grado del árbol debe ser mayor que 0" << std::endl;
		std::exit(1); // Salir del programa con un mensaje de error
	}
	lista = new stclave[nClaves + 1];
	if (!lista) {
		std::cerr << "Error al asignar memoria para lista" << std::endl;
		std::exit(1);
	}
	listapunt = new pbnodo[nClaves + 2];
	if (!listapunt) {
		std::cerr << "Error al asignar memoria para listapunt" << std::endl;
		std::exit(1);
	}
	nodosMinimos = nClaves / 2;
	Entrada = NULL;
}

btree::~btree()
{
	delete[] lista;
	delete[] listapunt;
	// Destruir árbol, algoritmo recursivo:
	BorrarNodo(Entrada);
}

void btree::BorrarNodo(pbnodo nodo)
{
	int i;

	if (!nodo) return;
	for (i = 0; i <= nodo->clavesUsadas; i++) BorrarNodo(*(nodo->puntero + i));
	delete nodo;
}
void btree::Ver(pbnodo nodo) {
	if (!nodo) return;

	queue<pbnodo> nodesQueue;  
	nodesQueue.push(nodo);

	while (!nodesQueue.empty()) {
		int levelSize = nodesQueue.size();  

		for (int i = 0; i < levelSize; ++i) {
			pbnodo currentNode = nodesQueue.front();
			nodesQueue.pop();

			
			cout << "[";
			for (int j = 0; j < currentNode->clavesUsadas; ++j) {
				cout << (*(currentNode->clave + j)).cedula;
				if (j < currentNode->clavesUsadas - 1) cout << "|";  // Separador entre claves
			}
			cout << "] ";

			
			for (int j = 0; j <= currentNode->clavesUsadas; ++j) {
				if (*(currentNode->puntero + j)) {
					nodesQueue.push(*(currentNode->puntero + j));
				}
			}
		}

		cout << endl;  
	}
}

void btree::Mostrar()
{
	cout << "Arbol B:" << endl;
	Ver(Entrada); // Llama a la función Ver empezando desde la raíz
	cout << "-----" << endl;
	system("pause");
}

bool btree::InsertarA(stclave clave)
{
	pbnodo nodo, padre;
	int i;

	// Se asegura de que la clave no está en el árbol
	padre = nodo = Entrada;
	while (nodo) {
		padre = nodo;
		i = 0;
		while (i < nodo->clavesUsadas && ((*(nodo->clave + i)).cedula < clave.cedula)) i++;
		if ((*(nodo->clave + i)).cedula == clave.cedula && i < nodo->clavesUsadas) return false;
		else nodo = *(nodo->puntero + i);
	}
	nodo = padre;
	Inserta(clave, nodo, NULL, NULL);
	return true;
}

// Ajuste en la redistribución de claves y punteros
void btree::Inserta(stclave clave, pbnodo nodo, pbnodo hijo1, pbnodo hijo2) {
	pbnodo padre, nuevo;
	int i, j;
	bool salir = false;

	do {
		if (!nodo) {
			nodo = new bnodo(nClaves);
			nodo->clavesUsadas = 0;
			nodo->padre = NULL;
			Entrada = nodo;
		}
		padre = nodo->padre;

		if (nodo->clavesUsadas == nClaves) { // Desbordamiento
			nuevo = new bnodo(nClaves);

			// Construir la lista ordenada con la nueva clave
			i = 0;
			while (i < nClaves && (*(nodo->clave + i)).cedula < clave.cedula) {
				*(lista + i) = *(nodo->clave + i);
				*(listapunt + i) = *(nodo->puntero + i);
				i++;
			}
			*(lista + i) = clave;
			*(listapunt + i) = hijo1;
			*(listapunt + i + 1) = hijo2;

			// Copiar las claves restantes
			while (i < nClaves) {
				*(lista + i + 1) = *(nodo->clave + i);
				*(listapunt + i + 2) = *(nodo->puntero + i + 1);
				i++;
			}

			// Redistribuir claves y punteros en los nodos izquierdo y derecho
			nodo->clavesUsadas = (nClaves + 1) / 2;
			for (j = 0; j < nodo->clavesUsadas; j++) {
				*(nodo->clave + j) = *(lista + j);
				*(nodo->puntero + j) = *(listapunt + j);
			}
			*(nodo->puntero + nodo->clavesUsadas) = *(listapunt + nodo->clavesUsadas);

			nuevo->clavesUsadas = nClaves - nodo->clavesUsadas;
			for (j = 0; j < nuevo->clavesUsadas; j++) {
				*(nuevo->clave + j) = *(lista + j + nodo->clavesUsadas + 1);
				*(nuevo->puntero + j) = *(listapunt + j + nodo->clavesUsadas + 1);
			}
			*(nuevo->puntero + nuevo->clavesUsadas) = *(listapunt + nClaves + 1);

			for (j = 0; j <= nodo->clavesUsadas; j++) {
				if (*(nodo->puntero + j)) (*(nodo->puntero + j))->padre = nodo;
			}
			for (j = 0; j <= nuevo->clavesUsadas; j++) {
				if (*(nuevo->puntero + j)) (*(nuevo->puntero + j))->padre = nuevo;
			}

			clave = *(lista + nodo->clavesUsadas);
			hijo1 = nodo;
			hijo2 = nuevo;
			nodo = padre;

			if (!nodo) {
				nodo = new bnodo(nClaves);
				nodo->clave[0] = clave;
				nodo->puntero[0] = hijo1;
				nodo->puntero[1] = hijo2;
				nodo->clavesUsadas = 1;
				hijo1->padre = nodo;
				hijo2->padre = nodo;
				Entrada = nodo;
				salir = true;
			}
		}
		else {
			i = 0;
			if (nodo->clavesUsadas > 0) {
				while (i < nodo->clavesUsadas && (*(nodo->clave + i)).cedula < clave.cedula) i++;
				for (j = nodo->clavesUsadas; j > i; j--) {
					*(nodo->clave + j) = *(nodo->clave + j - 1);
					*(nodo->puntero + j + 1) = *(nodo->puntero + j);
				}
			}
			nodo->clavesUsadas++;
			*(nodo->clave + i) = clave;
			*(nodo->puntero + i) = hijo1;
			*(nodo->puntero + i + 1) = hijo2;
			if (hijo1) hijo1->padre = nodo;
			if (hijo2) hijo2->padre = nodo;
			salir = true;
		}
	} while (!salir);
}









void btree::InsertarEnArbolBDesdeArchivo() {
	std::ifstream archivo("Datos_Personas.txt");

	if (!archivo) {
		std::cerr << "No se pudo abrir el archivo " << std::endl;
		return;
	}

	std::string nombre, segundoNombre, apellido, cedula, correo, contrasenaInicial, contrasena;
	std::string dummy;
	while (archivo >> dummy >> nombre >> segundoNombre >> dummy >> apellido >> dummy >> cedula) {
		archivo >> dummy >> correo >> dummy >> dummy >> contrasenaInicial >> dummy >> contrasena;

		// Crear un objeto Persona solo con el primer nombre (o nombre completo si así lo prefieres)
		Persona persona(nombre, segundoNombre == "null" ? "" : segundoNombre, apellido, cedula);

		// Insertar el objeto Persona en el árbol 
        std::cout << "Intentando insertar: " << nombre << " " << segundoNombre << apellido << std::endl;
        stclave clave;
		clave.cedula = cedula;
		clave.persona = persona;
			if (!InsertarA(clave)) {
				cerr << "Error al insertar clave: " << cedula << endl;
			}

		
	}

	archivo.close();
}


