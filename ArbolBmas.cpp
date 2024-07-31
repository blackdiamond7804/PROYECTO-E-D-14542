#include "ArbolBmas.h"
#include "Lista.h"
#include <conio.h>
#include <iostream>

void ArbolBmas::insertar(Persona k) {
    if (root == nullptr) {
        root = new NodoArbolBmas(t, true);
        root->llaves->insertar(k);
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            NodoArbolBmas* s = new NodoArbolBmas(t, false);
            s->C[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->llaves->datoEn(i + 1).cedula < k.cedula) i++;
            s->C[i]->InsertarNodoLleno(k);
            root = s;
        }
        else {
            root->InsertarNodoLleno(k);
        }
    }
}

bool ArbolBmas::buscar(std::string cedula) {
    return root == nullptr ? false : root->buscar(cedula);
}

void ArbolBmas::mostrarConPausa() const {
    NodoArbolBmas* current = root;
    while (current && !current->leaf) {
        current = current->C[0];
    }
    while (current) {
        current->imprimirArbolBmas(0);
        current = current->siguiente;
    }
    std::cout << "Presione cualquier tecla para continuar..." << std::endl;
    _getch(); 
}
