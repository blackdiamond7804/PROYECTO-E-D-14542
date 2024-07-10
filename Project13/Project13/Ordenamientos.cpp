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
void bubbleSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio) {
    if (!cabeza || cabeza == cola) return;

    bool intercambiado;
    Nodo* actual;
    Nodo* fin = nullptr;

    do {
        intercambiado = false;
        actual = cabeza;

        while (actual->siguiente != fin) {
            Nodo* siguiente = actual->siguiente;
            bool debeIntercambiar = false;

            switch (criterio) {
                case 1:
                    debeIntercambiar = actual->dato.nombre > siguiente->dato.nombre;
                    break;
                case 2:
                    debeIntercambiar = actual->dato.apellido > siguiente->dato.apellido;
                    break;
                case 3:
                    debeIntercambiar = actual->dato.cedula > siguiente->dato.cedula;
                    break;
            }

            if (debeIntercambiar) {
                Persona tempDato = actual->dato;
                actual->dato = siguiente->dato;
                siguiente->dato = tempDato;
                intercambiado = true;
            }

            actual = siguiente;
        }

        fin = actual;
    } while (intercambiado);
}
void bubbleSort(std::string& str) {
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        int n = str.length();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (str[j] > str[j + 1]) {
                    std::swap(str[j], str[j + 1]);
                }
            }
        }
    }