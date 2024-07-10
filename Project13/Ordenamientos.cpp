#include "Ordenamientos.h"
#include <vector>
using namespace std;

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

void radixSort(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    int n = str.length();
    int maxVal = *std::max_element(str.begin(), str.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        std::vector<char> bucket(26, 0);
        std::vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            int index = str[i] - 'a';
            count[index]++;
        }

        for (int i = 1; i < 26; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int index = str[i] - 'a';
            bucket[count[index] - 1] = str[i];
            count[index]--;
        }

        for (int i = 0; i < n; i++) {
            str[i] = bucket[i];
        }
    }
}


/*void radixSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio) {
    if (!cabeza || cabeza == cola) return;

    int n = 0;
    Nodo* actual = cabeza;
    do {
        n++;
        actual = actual->siguiente;
    } while (actual != (esCircular ? cabeza : nullptr));

    int maxVal = 0;
    switch (criterio) {
    case 1:
        for (actual = cabeza; actual != (esCircular ? cabeza : nullptr); actual = actual->siguiente) {
            if (actual->dato.nombre.length() > maxVal) {
                maxVal = actual->dato.nombre.length();
            }
        }
        break;
    case 2:
        for (actual = cabeza; actual != (esCircular ? cabeza : nullptr); actual = actual->siguiente) {
            if (actual->dato.apellido.length() > maxVal) {
                maxVal = actual->dato.apellido.length();
            }
        }
        break;
    case 3:
        for (actual = cabeza; actual != (esCircular ? cabeza : nullptr); actual = actual->siguiente) {
            if (actual->dato.cedula.length() > maxVal) {
                maxVal = actual->dato.cedula.length();
            }
        }
        break;
    }

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        Nodo* bucket[10];
        for (int i = 0; i < 10; i++) {
            bucket[i] = nullptr;
        }

        Nodo* last[10] = { nullptr };

        actual = cabeza;
        do {
            int digito;
            switch (criterio) {
            case 1:
                digito = (actual->dato.nombre[(maxVal - 1) - (exp / 10)] - '0');
                break;
            case 2:
                digito = (actual->dato.apellido[(maxVal - 1) - (exp / 10)] - '0');
                break;
            case 3:
                digito = (actual->dato.cedula[(maxVal - 1) - (exp / 10)] - '0');
                break;
            }

            if (bucket[digito] == nullptr) {
                bucket[digito] = actual;
            }
            else {
                last[digito]->siguiente = actual;
            }
            last[digito] = actual;

            Nodo* siguiente = actual->siguiente;
            if (esCircular && siguiente == cabeza) {
                siguiente = nullptr;
            }
            actual = siguiente;
        } while (actual != (esCircular ? cabeza : nullptr));

        cabeza = nullptr;
        cola = nullptr;
        for (int i = 0; i < 10; i++) {
            if (bucket[i] != nullptr) {
                if (cabeza == nullptr) {
                    cabeza = bucket[i];
                    cola = last[i];
                }
                else {
                    cola->siguiente = bucket[i];
                    cola = last[i];
                }
                if (esCircular) {
                    cola->siguiente = cabeza;
                }
                else {
                    cola->siguiente = nullptr;
                }
            }
        }
    }
}*/

bool compareNodos(Nodo* a, Nodo* b, int criterio) {
    switch (criterio) {
    case 1:
        return a->dato.nombre.length() < b->dato.nombre.length();
    case 2:
        return a->dato.apellido.length() < b->dato.apellido.length();
    case 3:
        return a->dato.cedula < b->dato.cedula;
    default:
        return false;
    }
}

void radixSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio) {
    if (!cabeza || cabeza == cola) return;

    int n = 0;
    Nodo* actual = cabeza;
    std::vector<Nodo*> nodos;
    do {
        n++;
        nodos.push_back(actual);
        actual = actual->siguiente;
    } while (actual != (esCircular ? cabeza : nullptr));

    auto maxVal = *std::max_element(nodos.begin(), nodos.end(), [&](Nodo* a, Nodo* b) {
        return compareNodos(a, b, criterio);
        });

    for (int exp = 1; maxVal->dato.nombre.length() / exp > 0 || maxVal->dato.apellido.length() / exp > 0 || maxVal->dato.cedula.length() / exp > 0; exp *= 10) {
        std::vector<std::vector<Nodo*>> bucket(10, std::vector<Nodo*>());
        std::vector<int> count(10, 0);

        actual = cabeza;
        do {
            int index;
            switch (criterio) {
            case 1:
                index = (actual->dato.nombre.length() / exp) % 10;
                break;
            case 2:
                index = (actual->dato.apellido.length() / exp) % 10;
                break;
            case 3:
                index = (actual->dato.cedula.length() / exp) % 10;
                break;
            }
            bucket[index].push_back(actual);
            count[index]++;
            actual = actual->siguiente;
        } while (actual != (esCircular ? cabeza : nullptr));

        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < count[i]; j++) {
                actual = bucket[i][j];
                cabeza = (index == 0 ? actual : cabeza);
                cola = (index == n - 1 ? actual : cola);
                index++;
            }
        }

        actual = cabeza;
        do {
            actual = actual->siguiente;
        } while (actual != (esCircular ? cabeza : nullptr));
    }
}
