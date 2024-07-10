#include "Ordenamientos.h"



void shellSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio) {
    if (!cabeza || cabeza == cola) return;

    int n = 0;
    Nodo* actual = cabeza;
    do {
        n++;
        actual = actual->siguiente;
    } while (actual != (esCircular ? cabeza : nullptr));

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Nodo* temp = cabeza;
            for (int k = 0; k < i; k++) temp = temp->siguiente;

            Persona tempDato = temp->dato;
            Nodo* jNodo = temp;
            for (int j = i; j >= gap; j -= gap) {
                Nodo* jGapNodo = cabeza;
                for (int k = 0; k < j - gap; k++) jGapNodo = jGapNodo->siguiente;

                bool debeIntercambiar = false;
                switch (criterio) {
                case 1:
                    debeIntercambiar = jGapNodo->dato.nombre > tempDato.nombre;
                    break;
                case 2:
                    debeIntercambiar = jGapNodo->dato.apellido > tempDato.apellido;
                    break;
                case 3:
                    debeIntercambiar = jGapNodo->dato.cedula > tempDato.cedula;
                    break;
                }

                if (!debeIntercambiar) break;

                jNodo->dato = jGapNodo->dato;
                jNodo = jGapNodo;
            }
            jNodo->dato = tempDato;
        }
    }
}

void shellSort(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    int n = str.length();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = str[i];
            int j;
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap) {
                str[j] = str[j - gap];
            }
            str[j] = temp;
        }
    }
}

void BucketSort(Nodo*& cabeza, Nodo*& cola, bool esCircular, int n) {
    if (!cabeza) return;

    int cant = 0;
    Nodo* actual = cabeza;
    do {
        cant++;
        actual = actual->siguiente;
    } while (actual != (esCircular ? cabeza : nullptr));

    Lista** listaB = new Lista * [cant];

    for (int i = 0; i < cant; i++) {
        listaB[i] = new Lista();
    }

    actual = cabeza;
    do {
        Persona valor = actual->dato;
        int indB;
        switch (n) {
        case 1:
            indB = calcularIndice(valor.cedula, cant);
            break;
        case 2:
            indB = calcularIndice(valor.nombre, cant);
            break;
        case 3:
            indB = calcularIndice(valor.apellido, cant);
            break;
        default:
            indB = 0; // Asignar a un bucket predeterminado en caso de valor inválido
            break;
        }
        listaB[indB]->insertarOrdenado(valor, n);
        actual = actual->siguiente;
    } while (actual != (esCircular ? cabeza : nullptr));

    while (cabeza != cola) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    cabeza = nullptr;
    cola = nullptr;

    for (int i = 0; i < cant; i++) {
        while (listaB[i]->cantidad() > 0) {
            Persona valor = listaB[i]->eliminarPrimero();
            Nodo* nuevo = new Nodo(valor);
            if (!cabeza) {
                cabeza = nuevo;
                cola = nuevo;
                if (esCircular) {
                    cabeza->siguiente = cabeza;
                    cabeza->anterior = cabeza;
                }
            }
            else {
                cola->siguiente = nuevo;
                nuevo->anterior = cola;
                if (esCircular) {
                    nuevo->siguiente = cabeza;
                    cabeza->anterior = nuevo;
                }
                cola = nuevo;
            }
        }
        delete listaB[i];
    }
    delete[] listaB;
}
