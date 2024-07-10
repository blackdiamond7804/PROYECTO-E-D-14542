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

void quickSortPersonas(Nodo*& cabeza, Nodo*& cola, bool esCircular, int criterio) {
    if (cabeza == nullptr || cabeza == cola) return;

    Nodo *pivot = cola;
    Nodo *i = cabeza->anterior;
    for (Nodo *j = cabeza; j != cola; j = j->siguiente) {
        bool menor = false;
        switch (criterio) {
            case 1: menor = j->dato.nombre < pivot->dato.nombre; break;
            case 2: menor = j->dato.apellido < pivot->dato.apellido; break;
            case 3: menor = j->dato.cedula < pivot->dato.cedula; break;
        }
        if (menor) {
            if (i == nullptr) i = cabeza;
            else i = i->siguiente;
            std::swap(i->dato, j->dato);
        }
    }
    if (i == nullptr) i = cabeza;
    else i = i->siguiente;
    std::swap(i->dato, pivot->dato);

    Nodo *pi = (i == nullptr) ? cabeza : i;
    Nodo *ni = (i == nullptr || i->siguiente == nullptr) ? cola : i->siguiente;

    if (pi != cabeza) quickSortPersonas(cabeza, pi->anterior, esCircular, criterio);
    if (ni != cola) quickSortPersonas(ni, cola, esCircular, criterio);
}

void quickSort(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    int n = str.length();

    if (n <= 1) return;

    char pivot = str[n / 2];
    str[n / 2] = str[0];
    str[0] = pivot;

    int i = 1;
    for (int j = 1; j < n; j++) {
        if (str[j] < pivot) {
            char temp = str[j];
            str[j] = str[i];
            str[i] = temp;
            i++;
        }
    }

    str[0] = str[i - 1];
    str[i - 1] = pivot;

    std::string left = str.substr(0, i - 1);
    std::string right = str.substr(i);

    quickSort(left);
    quickSort(right);

    str = left + pivot + right;
}
