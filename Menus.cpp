
#include "Menus.h"

using namespace std;

enum Opciones {
    Datos_Personas,
    Datos_Personas,
    Datos_Personas,
    SALIR,
    NUM_OPCIONES
};

enum OpcionesSubMenu {
    INGRESAR_DATOS,
    ORDENAR_LISTA,
    IMPRIMIR_LISTA,
    REGRESAR,
    NUM_OPCIONES_SUBMENU
};

void setConsoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

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

void mostrarSubMenu(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Ingresar datos",
        "Ordenar lista",
        "Imprimir lista",
        "Regresar"
    };

    cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES_SUBMENU; ++i) {
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

void mostrarMenuOrden(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Ordenar por Nombre",
        "Ordenar por Apellido",
        "Ordenar por Cedula",
        "Ordenar por Caracteres de Nombre",
        "Regresar"
    };

    cout << "******************************" << endl;
    cout << "Seleccione un criterio de ordenacion:" << endl;
    cout << "******************************" << endl;
    for (int i = 0; i < 5; ++i) { // 4 opciones + "Regresar"
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

void ingresarDatos(Lista& lista) {
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

void subMenuListaShell(Lista& lista) {
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
                            lista.ordenar(criterio + 1); // Ajustar criterio según implementación
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

void MenuShellMain() {
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
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
            case Datos_Personas:
                subMenuListaShell(listaSimple);
                break;
            case Datos_Personas:
                subMenuListaShell(listaDoble);
                break;
            case Datos_Personas:
                subMenuListaShell(listaCircular);
                break;
            case SALIR:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
            }
        }
    }
}

void subMenuListaRadix(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarSubMenu(subopcion);

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
                ingresarDatos(lista);
                break;
            case 1: {
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
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenu(opcion);

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


void subMenuListaIntercambio(Lista& lista) {
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
                            lista.ordenarIntercambio(criterio + 1); // Ajustar criterio según implementación
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

void MenuIntercambio() {
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
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
            case Datos_Personas:
                subMenuListaIntercambio(listaSimple);
                break;
            case Datos_Personas:
                subMenuListaIntercambio(listaDoble);
                break;
            case Datos_Personas:
                subMenuListaIntercambio(listaCircular);
                break;
            case SALIR:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
            }
        }
    }
}

void subMenuListaQuicksort(Lista& lista) {
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
                        criterio = (criterio - 1 + 5) % 5; // 5 opciones en el men� de ordenaci�n
                        break;
                    case 80: // Flecha abajo
                        criterio = (criterio + 1) % 5;
                        break;
                    case 13: // Enter
                        if (criterio == 4) {
                            continuarOrden = false;
                        }
                        else {
                            lista.ordenarQuicksort(criterio + 1); // Ajustar criterio seg�n implementaci�n
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

void MenuQuicksortMain() {
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
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
            case Datos_Personas:
                subMenuListaQuicksort(listaSimple);
                break;
            case Datos_Personas:
                subMenuListaQuicksort(listaDoble);
                break;
            case Datos_Personas:
                subMenuListaQuicksort(listaCircular);
                break;
            case SALIR:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
            }
        }
    }
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
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
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
            case Datos_Personas:
                subMenuListaDistribucion(listaSimple);
                break;
            case Datos_Personas:
                subMenuListaDistribucion(listaDoble);
                break;
            case Datos_Personas:
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

void subMenuListaBurbuja(Lista& lista) {
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
                        criterio = (criterio - 1 + 5) % 5; // 5 opciones en el men? de ordenaci?n
                        break;
                    case 80: // Flecha abajo
                        criterio = (criterio + 1) % 5;
                        break;
                    case 13: // Enter
                        if (criterio == 4) {
                            continuarOrden = false;
                        }
                        else {
                            lista.ordenarBurbuja(criterio + 1); // Ajustar criterio seg?n implementaci?n
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

void MenuBurbujaMain() {
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
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
            case Datos_Personas:
                subMenuListaBurbuja(listaSimple);
                break;
            case Datos_Personas:
                subMenuListaBurbuja(listaDoble);
                break;
            case Datos_Personas:
                subMenuListaBurbuja(listaCircular);
                break;
            case SALIR:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
            }
        }
    }
}