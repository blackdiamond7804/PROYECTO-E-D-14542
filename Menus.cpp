
#include "Menus.h"

using namespace std;

enum Opciones {
    LISTA_SIMPLE,
    LISTA_DOBLE,
    LISTA_CIRCULAR,
    SALIR,
    NUM_OPCIONES
};

enum OpcionesSubMenu {
    INGRESAR_DATOS,
    ORDENAR_LISTA,
    IMPRIMIR_LISTA,
    ADICIONAL,
    REGRESAR,
    NUM_OPCIONES_SUBMENU
};

enum OpcionesSubMenu2 {
    INVERTIR_NOMBRE,
    INVERTIR_APELLIDO,
    INVERTIR_CEDULA,
    VOLVER,
    NUM_OPCIONES_SUBMENU2
};

enum OpcionesAdicionales {
    INVERTIR_CARACTERES,
    ENCRIPTAR_NOMBRE_APELLIDO,
    CONTAR_VOCALES_CONSONANTES,
    REEMPLAZAR_CEDULA,
    MEZCLA_NOMBRES,
    COMBINAR_LISTAS,
    BUSCAR,
    INSERTAR_DATOS_ARBOL, //Quitarlo y ponerlo en un menu con todos los tipos de arboles
    RETROCEDER,
    NUM_OPCIONES_ADICIONALES
};

enum OpcionesBusqueda {
    BUSQUEDA_SECUENCIAL,
    BUSQUEDA_BINARIA,
    BUSQUEDA_HASH,
    ATRAS,
    NUM_OPCIONES_BUSQUEDA
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
        "Adicional",
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

void mostrarSubMenu2(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Invertir nombre",
        "Invertir apellido",
        "Invertir cedula",
        "Volver"
    };

    cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES_SUBMENU2; ++i) {
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
        "Retroceder"
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

void mostrarAdicional(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Invertir caracteres",
        "Encriptar nombres y apellidos",
        "Contar vocales y consonantes",
        "Reemplazar cedula",
        "Mezclar nombres",
        "Combinar listas",
        "Buscar",
        "Insertar datos en un arbol e imprimirlos",//Quitarlo y ponerlo en un menu para los arboles
        "Volver"
    };

    cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES_ADICIONALES; ++i) {
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

void mostrarSubMenuCombinarListas(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Ordenadas por nombre",
        "Ordenadas por apellido",
        "Ordenadas por cedula",
        "Volver"
    };

    cout << "******************************" << endl;
    cout << "Seleccione el criterio por el cual estan ordenadas las listas:" << endl;
    for (int i = 0; i < NUM_OPCIONES_SUBMENU2; ++i) {
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

void mostrarMenuBusqueda(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Busqueda Secuencial",
        "Busqueda Binaria",
        "Busqueda Hash",
        "Atras"
    };

    cout << "******************************" << endl;
    cout << "Seleccione un criterio de busqueda:" << endl;
    cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES_BUSQUEDA; ++i) { // 4 opciones + "Regresar"
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
    else if (cedulaRegistradaEnArchivo(cedula)) {
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

bool cedulaRegistradaEnArchivo(const string& cedula) {
    ifstream archivo("Datos_Personas.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find("Cedula: ");
        if (pos != string::npos) {
            size_t start = pos + 8; // 8 es la longitud de "Cedula: "
            size_t end = linea.find('\n', start);
            string cedulaEnArchivo = linea.substr(start, end - start);
            if (cedula == cedulaEnArchivo) {
                return true;
            }
        }
    }
    return false;
}

void encriptador(Nodo* act, int nume) {
    if (act == nullptr) {
        return;
    }
    string pass = "", pass2 = "";
    string alfabetom = "abcdefghijklmnopqrstuvwxyz";
    bool mayuscula = true;
    for (char aux : act->dato.nombre) {
        char letra = alfabetom[(tolower(aux) - 'a' + nume) % 26];
        pass += mayuscula ? toupper(letra) : tolower(letra);
        mayuscula = !mayuscula;
    }
    mayuscula = true;
    for (char aux : act->dato.apellido) {
        char letra = alfabetom[(tolower(aux) - 'a' + nume) % 26];
        pass2 += mayuscula ? toupper(letra) : tolower(letra);
        mayuscula = !mayuscula;
    }
    pass2.pop_back();
    std::cout << "Encriptado: " << pass << " " << pass2 << std::endl;

    act = act->siguiente;
    encriptador(act, nume);
}

void encriptado(Lista& lista, int num) {
    Nodo* actual = lista.getCabeza();
    encriptador(actual, num);
}

void contarVocalesYConsonantes(Lista& lista) {
    int vocales = 0;
    int consonantes = 0;
    lista.contarVocalesYConsonantes(vocales, consonantes);
    cout << "En la lista hay " << vocales << " vocales y " << consonantes << " consonantes en total." << endl;

    system("pause");
}

void reemplazarEnCedula() {
    string cedula = ingresarCedula();
    if (!validarCedula(cedula)) {
        cout << "Cedula invalida:" << endl;
        return;
    }

    Pila pila = convertirCedulaAPila(cedula);
    int viejo, nuevo;

    cout << "Ingrese el valor a reemplazar: ";
    cin >> viejo;
    cout << "Ingrese el nuevo valor: ";
    cin >> nuevo;

    pila.reemplazar(viejo, nuevo);

    cout << "Cedula modificada: ";
    pila.imprimir();
}

void menuBusqueda(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;
    while (continuar) {
        mostrarMenuBusqueda(subopcion);
        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + NUM_OPCIONES_BUSQUEDA) % NUM_OPCIONES_BUSQUEDA;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % NUM_OPCIONES_BUSQUEDA;
            break;
        case 13: // Enter
            switch (subopcion) {
            case BUSQUEDA_SECUENCIAL: {
                Busquedas busquedas;
                string cedula;
                cout << "Ingrese la cedula a buscar: ";
                cin >> cedula;
                Persona* persona = busquedas.busquedaSecuencial("Datos_Personas.txt", cedula);
                busquedas.imprimirPersona(persona);
                _getch();
            }  
                break;
            case BUSQUEDA_BINARIA:
                cout << "Busqueda binaria" << endl;
                break;
            case BUSQUEDA_HASH:
                cout << "Busqueda hash" << endl;
                break;
            case ATRAS:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
            break;
        default:
            break;
        }
    }
}

void menuAdicional(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;
    while (continuar) {
        mostrarAdicional(subopcion);
        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + NUM_OPCIONES_ADICIONALES) % NUM_OPCIONES_ADICIONALES;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % NUM_OPCIONES_ADICIONALES;
            break;
        case 13: // Enter
            switch (subopcion) {
            case INVERTIR_CARACTERES: {
                int criteri = 0;
                bool continuarOrden = true;
                while (continuarOrden) {
                    mostrarSubMenu2(criteri);
                    int teclaOrden = _getch();
                    switch (teclaOrden) {
                    case 72: // Flecha arriba
                        criteri = (criteri - 1 + 4) % 4; // 4 opciones en el menú de ordenación
                        break;
                    case 80: // Flecha abajo
                        criteri = (criteri + 1) % 4;
                        break;
                    case 13: // Enter
                        if (criteri == 3) {
                            continuarOrden = false;
                        }
                        else {
                            lista.InertirPersonas(criteri + 1); // Ajustar criterio según implementación
                        }
                        break;
                    }
                }
                break;
            }
            case ENCRIPTAR_NOMBRE_APELLIDO: {
                int num;
                cout << "Ingrese el valor de desplazamiento: ";
                num = ingresarEntero();
                encriptado(lista, num);
                cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            }
            case CONTAR_VOCALES_CONSONANTES:
                contarVocalesYConsonantes(lista);
                break;
            case REEMPLAZAR_CEDULA:
                reemplazarEnCedula();
                _getch();
                break;
            case MEZCLA_NOMBRES:
                lista.MezclaPares();
                cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            case COMBINAR_LISTAS: {
                int criter = 0;
                bool continuarOrde = true;
                while (continuarOrde) {
                    mostrarSubMenuCombinarListas(criter);
                    int teclaOrde = _getch();
                    switch (teclaOrde) {
                    case 72: // Flecha arriba
                        criter = (criter - 1 + 4) % 4; // 4 opciones en el menú de ordenación
                        break;
                    case 80: // Flecha abajo
                        criter = (criter + 1) % 4;
                        break;
                    case 13: // Enter
                        if (criter == 3) {
                            continuarOrde = false;
                        }
                        else {
                            Lista lista2(false, "Datos_Personas.txt");
                            Lista listaCombinada(false);
                            listaCombinada.setCabeza(lista.combinarListas(lista.getCabeza(), lista2.getCabeza(), criter + 1));
                            cout << "Lista combinada: " << endl;
                            listaCombinada.imprimir();
                            cout << "Presione cualquier tecla para continuar...";
                            _getch(); // Espera una tecla antes de continuar
                            
                        }
                        break;
                    }
                }
                break;
            }
            case BUSCAR:
                menuBusqueda(lista);
                break;
            case INSERTAR_DATOS_ARBOL: { //Esto hay que quitarlo
                int arbolopcion;
                cout << "Seleccione el tipo de arbol: " << endl;
                cout << "1. Arbol B" << endl;
                cout << "2. Arbol Rojo-Negro" << endl;
                cin >> arbolopcion;

                switch (arbolopcion) {
                    case 1: {
                        int t;
                        cout << "Digite el grado del arbol: " << endl;
                        cin >> t;
                        ArbolB arbol(t);
                        lista.leerArchivoEInsertarEnArbolB(arbol);
                        arbol.mostrarConPausa();
                        break;
                    };
                    case 2: {
                        ArbolRB arbol;
                        lista.leerArchivoEInsertarEnArbolRB(arbol);
                        arbol.mostrarConPausa();
                    }
                    default: {
                        cout << "Opción inválida" << endl;
                    }
                }
                break;
            }
            case RETROCEDER:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
            break; 
        default:
            break;
        }
    }
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
            case ADICIONAL:
                menuAdicional(lista);
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
            case LISTA_SIMPLE:
                subMenuListaShell(listaSimple);
                break;
            case LISTA_DOBLE:
                subMenuListaShell(listaDoble);
                break;
            case LISTA_CIRCULAR:
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
                menuAdicional(lista);
                break;
            case 4:
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
            case ADICIONAL:
                menuAdicional(lista);
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
            case LISTA_SIMPLE:
                subMenuListaIntercambio(listaSimple);
                break;
            case LISTA_DOBLE:
                subMenuListaIntercambio(listaDoble);
                break;
            case LISTA_CIRCULAR:
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
            case ADICIONAL:
                menuAdicional(lista);
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
            case LISTA_SIMPLE:
                subMenuListaQuicksort(listaSimple);
                break;
            case LISTA_DOBLE:
                subMenuListaQuicksort(listaDoble);
                break;
            case LISTA_CIRCULAR:
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
            case ADICIONAL:
                menuAdicional(lista);
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
            case ADICIONAL:
                menuAdicional(lista);
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
            case LISTA_SIMPLE:
                subMenuListaBurbuja(listaSimple);
                break;
            case LISTA_DOBLE:
                subMenuListaBurbuja(listaDoble);
                break;
            case LISTA_CIRCULAR:
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