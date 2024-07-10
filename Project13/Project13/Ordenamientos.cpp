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

void intercambioPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio) {
    if (!cabeza) return;
    bool swapped;
    Nodo* actual;
    Nodo* lastPtr = nullptr;

    if (esCircular) {
        do {
            swapped = false;
            actual = cabeza;

            do {
                Nodo* siguiente = actual->siguiente;
                if (siguiente == cabeza) break;

                bool condition = false;
                switch (criterio) {
                case 1:
                    condition = actual->dato.nombre > siguiente->dato.nombre;
                    break;
                case 2:
                    condition = actual->dato.segundoNombre > siguiente->dato.segundoNombre;
                    break;
                case 3:
                    condition = actual->dato.apellido > siguiente->dato.apellido;
                    break;
                }

                if (condition) {
                    std::swap(actual->dato, siguiente->dato);
                    swapped = true;
                }
                actual = siguiente;
            } while (actual != lastPtr);

            lastPtr = actual;
        } while (swapped);
    }
    else {
        do {
            swapped = false;
            actual = cabeza;

            while (actual->siguiente != lastPtr) {
                Nodo* siguiente = actual->siguiente;

                bool condition = false;
                switch (criterio) {
                case 1:
                    condition = actual->dato.nombre > siguiente->dato.nombre;
                    break;
                case 2:
                    condition = actual->dato.segundoNombre > siguiente->dato.segundoNombre;
                    break;
                case 3:
                    condition = actual->dato.apellido > siguiente->dato.apellido;
                    break;
                }

                if (condition) {
                    std::swap(actual->dato, siguiente->dato);
                    swapped = true;
                }
                actual = siguiente;
            }
            lastPtr = actual;
        } while (swapped);
    }
}

void intercambio(std::string& str) {
    bool swapped;
    for (size_t i = 0; i < str.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < str.size() - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                std::swap(str[j], str[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}