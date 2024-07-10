//#include "MenuShell.h"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MenuShell.h"
#include "MenuRadix.h"
#include <conio.h>
#include <windows.h>
#include "Lista.h"
#include "Validacion.h"
#include "Persona.h"

using namespace std;


void Color(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenuRadix(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Lista Simple",
        "Lista Doble",
        "Lista Circular",
        "Salir"
    };

    std::cout << "******************************" << endl;
    std::cout << "En que lista deseas trabajar?" << endl;
    std::cout << "******************************" << endl;
    for (int i = 0; i < 4; ++i) {
        if (i == opcion) {
            Color(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            Color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
    std::cout << "******************************" << endl;
}

void mostrarSubMenuRadix(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Ingresar datos",
        "Ordenar lista",
        "Imprimir lista",
        "Regresar"
    };

    std::cout << "******************************" << endl;
    for (int i = 0; i < 4; ++i) {
        if (i == opcion) {
            Color(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            Color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
    std::cout << "******************************" << endl;
}

void mostrarMenuOrdenRadix(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Ordenar por Nombre",
        "Ordenar por Apellido",
        "Ordenar por Cedula",
        "Ordenar por Caracteres de Nombre",
        "Regresar"
    };

    std::cout << "******************************" << endl;
    std::cout << "Seleccione un criterio de ordenacion:" << endl;
    std::cout << "******************************" << endl;
    for (int i = 0; i < 5; ++i) { // 4 opciones + "Regresar"
        if (i == opcion) {
            Color(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            Color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
    std::cout << "******************************" << endl;
}

void ingresarDatosRadix(Lista& lista) {
    string cedula = ingresarCedula();

    if (lista.verificarCedula(cedula)) {
        cout << "La cedula ya esta registrada. Intente con otra. " << endl;
        return;
    }

    string nombre, segundoNombre, apellido;
    cout << "Ingrese el primer nombre: ";
    nombre = ingresarLetra();
    cout << "Ingrese el segundo nombre: ";
    segundoNombre = ingresarStringValidado();
    cout << "Ingrese el apellido: ";
    apellido = ingresarLetra();

    Persona p(nombre, segundoNombre, apellido, cedula);
    lista.insertar(p);
}

void subMenuListaRadix(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarSubMenuRadix(subopcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + 4) % 4;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % 4;
            break;
        case 13: // Enter
            switch (subopcion) {
            case 0:
                ingresarDatosRadix(lista);
                break;
            case 1: {
                int criterio = 0;
                bool continuarOrden = true;
                while (continuarOrden) {
                    mostrarMenuOrdenRadix(criterio);

                    int teclaOrden = _getch();
                    switch (teclaOrden) {
                    case 72: // Flecha arriba
                        criterio = (criterio - 1 + 5) % 5; // 5 opciones en el menú de ordenación
                        break;
                    case 80: // Flecha abajo
                        criterio = (criterio + 1) % 5;
                        break;
                    case 13: // Enter
                        if (criterio == 4) {
                            continuarOrden = false;
                        }
                        else {
                            lista.ordenarRadix(criterio + 1); // Ajustar criterio según implementación
                        }
                        break;
                    }
                }
                break;
            }
            case 2:
                lista.imprimir();
                std::cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            case 3:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    }
}

void MenuRadixMain() {
    Lista listaSimple(false, "lista_simple.txt");
    Lista listaDoble(false, "lista_doble.txt");
    Lista listaCircular(true, "lista_circular.txt");
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenuRadix(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + 4) % 4;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % 4;
            break;
        case 13: // Enter
            switch (opcion) {
            case 0:
                subMenuListaRadix(listaSimple);
                break;
            case 1:
                subMenuListaRadix(listaDoble);
                break;
            case 2:
                subMenuListaRadix(listaCircular);
                break;
            case 3:
                continuar = false;
                std::cout << "Saliendo..." << endl;
                break;
            }
        }
    }
}


