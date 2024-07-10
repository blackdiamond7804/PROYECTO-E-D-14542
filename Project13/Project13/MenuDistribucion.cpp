#include "MenuDistribucion.h"
#include "Lista.h"
#include "Persona.h"
#include "Validacion.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

void mostrarMenu(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Lista Simple",
        "Lista Doble",
        "Lista Circular",
        "Salir"
    };

    cout << "******************************" << endl;
    cout << "En que lista deseas trabajar?" << endl;
    cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            cout << "     " << opciones[i] << "\n";
        }
    }
    cout << "******************************" << endl;
}

void subMenuListaDistribucion(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarSubMenu(subopcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + NUM_OPCIONES_SUBMENU) % NUM_OPCIONES_SUBMENU;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % NUM_OPCIONES_SUBMENU;
            break;
        case 13: // Enter
            switch (subopcion) {
            case INGRESAR_DATOS:
                ingresarDatos(lista);
                break;
            case ORDENAR_LISTA: {
                int criterio = 0;
                bool continuarOrden = true;
                while (continuarOrden) {
                    mostrarMenuOrden(criterio);

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
                            lista.ordenarDistribucion(criterio + 1); // Ajustar criterio según implementación
                        }
                        break;
                    }
                }
                break;
            }
            case IMPRIMIR_LISTA:
                lista.imprimir();
                cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            case REGRESAR:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    }
}

void MenuDistribucion() {
    Lista listaSimple(false, "lista_simple.txt");
    Lista listaDoble(false, "lista_doble.txt");
    Lista listaCircular(true, "lista_circular.txt");
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenu(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + NUM_OPCIONES) % NUM_OPCIONES;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % NUM_OPCIONES;
            break;
        case 13: // Enter
            switch (opcion) {
            case LISTA_SIMPLE:
                subMenuListaDistribucion(listaSimple);
                break;
            case LISTA_DOBLE:
                subMenuListaDistribucion(listaDoble);
                break;
            case LISTA_CIRCULAR:
                subMenuListaDistribucion(listaCircular);
                break;
            case SALIR:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
            }
        }
    }
}