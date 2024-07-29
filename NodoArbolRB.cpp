#include "NodoArbolRB.h"

NodoArbolRB* NodoArbolRB::BSTInsert(NodoArbolRB* root, NodoArbolRB* pt) {
    if (root == nullptr)
        return pt;

    if (pt->dato.cedula < root->dato.cedula) {
        root->izquierda = BSTInsert(root->izquierda, pt);
        root->izquierda->padre = root;
    } else if (pt->dato.cedula > root->dato.cedula) {
        root->derecha = BSTInsert(root->derecha, pt);
        root->derecha->padre = root;
    }
    return root;
}

bool NodoArbolRB::buscar(const std::string& cedula) const {
    if (cedula == dato.cedula)
        return true;
    if (cedula < dato.cedula && izquierda != nullptr)
        return izquierda->buscar(cedula);
    if (cedula > dato.cedula && derecha != nullptr)
        return derecha->buscar(cedula);
    return false;
}

void NodoArbolRB::imprimirArbolRB(int indent) const {
    if (derecha != nullptr)
        derecha->imprimirArbolRB(indent + 4);
    if (indent)
        std::cout << std::string(indent, ' ');
    if (padre != nullptr)
        std::cout << " - ";
    std::cout << dato.cedula << "(" << (color == Rojo ? "R" : "N") << ")" << std::endl;
    if (izquierda != nullptr)
        izquierda->imprimirArbolRB(indent + 4);
}
