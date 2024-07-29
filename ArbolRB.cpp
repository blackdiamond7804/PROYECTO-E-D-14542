#include "ArbolRB.h"
#include "NodoArbolRB.h"
#include "Lista.h"
#include <conio.h>
#include <iostream>

void ArbolRB::rotarIzquierda(NodoArbolRB* &raiz, NodoArbolRB* &pt) {
    NodoArbolRB* pt_right = pt->derecha;
    pt->derecha = pt_right->izquierda;

    if (pt->derecha != nullptr)
        pt->derecha->padre = pt;

    pt_right->padre = pt->padre;

    if (pt->padre == nullptr)
        raiz = pt_right;
    else if (pt == pt->padre->izquierda)
        pt->padre->izquierda = pt_right;
    else
        pt->padre->derecha = pt_right;

    pt_right->izquierda = pt;
    pt->padre = pt_right;
}

void ArbolRB::rotarDerecha(NodoArbolRB* &raiz, NodoArbolRB* &pt) {
    NodoArbolRB* pt_left = pt->izquierda;
    pt->izquierda = pt_left->derecha;

    if (pt->izquierda != nullptr)
        pt->izquierda->padre = pt;

    pt_left->padre = pt->padre;

    if (pt->padre == nullptr)
        raiz = pt_left;
    else if (pt == pt->padre->izquierda)
        pt->padre->izquierda = pt_left;
    else
        pt->padre->derecha = pt_left;

    pt_left->derecha = pt;
    pt->padre = pt_left;
}

void ArbolRB::arreglarInsertarRB(NodoArbolRB* &raiz, NodoArbolRB* &pt) {
    NodoArbolRB* padre_pt = nullptr;
    NodoArbolRB* abuelo_pt = nullptr;

    while ((pt != raiz) && (pt->color != Negro) &&
        (pt->padre->color == Rojo)) {
        
        padre_pt = pt->padre;
        abuelo_pt = pt->padre->padre;

        if (padre_pt == abuelo_pt->izquierda) {

            NodoArbolRB* tio_pt = abuelo_pt->derecha;

            if (tio_pt != nullptr && tio_pt->color == Rojo) {
                abuelo_pt->color = Rojo;
                padre_pt->color = Negro;
                tio_pt->color = Negro;
                pt = abuelo_pt;
            } else {
                if (pt == padre_pt->derecha) {
                    rotarIzquierda(raiz, padre_pt);
                    pt = padre_pt;
                    padre_pt = pt->padre;
                }

                rotarDerecha(raiz, abuelo_pt);
                std::swap(padre_pt->color, abuelo_pt->color);
                pt = padre_pt;
            }
        } else {
            NodoArbolRB* tio_pt = abuelo_pt->izquierda;

            if (tio_pt != nullptr && tio_pt->color == Rojo) {
                abuelo_pt->color = Rojo;
                padre_pt->color = Negro;
                tio_pt->color = Negro;
                pt = abuelo_pt;
            } else {
                if (pt == padre_pt->izquierda) {
                    rotarDerecha(raiz, padre_pt);
                    pt = padre_pt;
                    padre_pt = pt->padre;
                }

                rotarIzquierda(raiz, abuelo_pt);
                std::swap(padre_pt->color, abuelo_pt->color);
                pt = padre_pt;
            }
        }
    }

    raiz->color = Negro;
}

void ArbolRB::insertar(Persona k) {
    NodoArbolRB* pt = new NodoArbolRB(k);

    root = NodoArbolRB::BSTInsert(root, pt);

    arreglarInsertarRB(root, pt);
}

bool ArbolRB::buscar(std::string cedula) const {
    return root == nullptr ? false : root->buscar(cedula);
}

void ArbolRB::mostrarConPausa() const {
    if (root != nullptr) root->imprimirArbolRB();
    std::cout << "Presione cualquier tecla para continuar..." << std::endl;
    _getch();
}