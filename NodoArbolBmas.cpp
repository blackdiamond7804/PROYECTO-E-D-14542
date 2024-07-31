#include "NodoArbolBmas.h"
#include "Lista.h"
#include <iostream>
#include <string>

NodoArbolBmas::NodoArbolBmas(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;
    llaves = new Lista();
    C = new NodoArbolBmas * [2 * t];
    n = 0;
    siguiente = nullptr;
}

void NodoArbolBmas::InsertarNodoLleno(Persona k) {
    int i = n - 1;
    if (leaf) {
        while (i >= 0 && llaves->datoEn(i + 1).cedula > k.cedula) {
            llaves->insertarEn(i + 2, llaves->datoEn(i + 1));
            i--;
        }
        llaves->insertarEn(i + 2, k);
        n = n + 1;
    }
    else {
        while (i >= 0 && llaves->datoEn(i + 1).cedula > k.cedula) i--;
        if (C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1]);
            if (llaves->datoEn(i + 2).cedula < k.cedula) i++;
        }
        C[i + 1]->InsertarNodoLleno(k);
    }
}

void NodoArbolBmas::splitChild(int i, NodoArbolBmas* y) {
    NodoArbolBmas* z = new NodoArbolBmas(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++) z->llaves->insertarEn(j + 1, y->llaves->datoEn(j + t + 1));
    if (!y->leaf) {
        for (int j = 0; j < t; j++) z->C[j] = y->C[j + t];
    }
    else {
        z->siguiente = y->siguiente;
        y->siguiente = z;
    }
    y->n = t - 1;
    for (int j = n; j >= i + 1; j--) C[j + 1] = C[j];
    C[i + 1] = z;
    for (int j = n - 1; j >= i; j--) llaves->insertarEn(j + 2, llaves->datoEn(j + 1));
    llaves->insertarEn(i + 1, y->llaves->datoEn(t));
    n = n + 1;
}

void NodoArbolBmas::imprimirArbolBmas(int indent) {
    for (int i = 0; i < n; i++) {
        if (!leaf) C[i]->imprimirArbolBmas(indent + 4);
        std::cout << std::string(indent, ' ') << llaves->datoEn(i + 1).cedula << std::endl;
    }
    if (!leaf) C[n]->imprimirArbolBmas(indent + 4);
}

bool NodoArbolBmas::buscar(std::string cedula) {
    int i = 0;
    while (i < n && cedula > llaves->datoEn(i + 1).cedula) i++;
    if (llaves->datoEn(i + 1).cedula == cedula) return true;
    return leaf ? false : C[i]->buscar(cedula);
}
