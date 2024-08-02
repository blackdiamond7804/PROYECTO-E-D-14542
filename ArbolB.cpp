#include "ArbolB.h"
#include "Lista.h"
#include <conio.h>

void ArbolB::insertar(Persona k) {
    
    if (root != nullptr && buscar(k.cedula)) {
        //std::cout << "La cedula ya esta registrada" << std::endl;
        return;
    }

    if (root == nullptr) {
        root = new NodoArbolB(t, true);
        root->llaves->insertar(k);
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            NodoArbolB* s = new NodoArbolB(t, false);
            *(s->C) = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->llaves->datoEn(i + 1).cedula < k.cedula) i++;
            (*(s->C + i))->InsertarNodoLleno(k);
            root = s;
        }
        else {
            root->InsertarNodoLleno(k);
        }
    }
}

bool ArbolB::buscar(std::string cedula) {
    return (root == nullptr) ? false : root->buscar(cedula);
}


void ArbolB::mostrarConPausa() const {
	imprimirArbolB();
	std::cout << "Presione cualquier tecla para continuar..." << std::endl;
	_getch(); // Pausar para que el usuario vea la salida
}
