#include "Lista.h"

Lista::Lista(bool circular, const std::string& nombreArchivo)
    : cabeza(nullptr), cola(nullptr), esCircular(circular), nombreArchivo(nombreArchivo) {
    cargarDesdeArchivo(nombreArchivo);
}

Lista::~Lista() {
    if (!esCircular) {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
    else {
        Nodo* actual = cabeza;
        if (actual) {
            do {
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;
            } while (actual != cabeza);
        }
    }
}

bool Lista::verificarCedula(const std::string& cedula) {
    return cedulasRegistradas.find(cedula) != cedulasRegistradas.end();
}

void Lista::insertar(Persona dato) {
    if (verificarCedula(dato.cedula)) {
        std::cout << "La cedula ya esta registrada" << std::endl;
        return;
    }

    dato.setCorreo(generarCorreo(cabeza, dato, esCircular));
    generarContrasena(dato);
    Nodo* nuevo = new Nodo(dato);
    if (!cabeza) {
        cabeza = nuevo;
        cola = nuevo;
        if (esCircular) {
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        }
    }
    else {
        if (esCircular) {
            nuevo->siguiente = cabeza;
            nuevo->anterior = cola;
            cola->siguiente = nuevo;
            cabeza->anterior = nuevo;
            cola = nuevo;
        }
        else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
    }

    cedulasRegistradas.insert(dato.cedula);

    // Agregar al archivo después de insertar
    agregarAlArchivo(dato);
}

void Lista::ordenar(int criterio) {
    if (criterio >= 1 && criterio <= 3) {
        shellSortPersonas(cabeza, cola, esCircular, criterio);
        guardarEnArchivo(nombreArchivo); // Guardar en el archivo original
    }
    else if (criterio == 4) {
        ordenarCaracteres();
    }
}

void Lista::ordenarCaracteres() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        shellSort(actual->dato.nombre);
        shellSort(actual->dato.apellido);
        actual = actual->siguiente;
        if (esCircular && actual == cabeza) break;
    }

    std::string contenidoOrdenado = obtenerContenidoOrdenado();
    crearBackup(nombreArchivo, contenidoOrdenado); // Crear un backup con los datos ordenados
}

std::string Lista::obtenerContenidoOrdenado() const {
    std::stringstream ss;
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        ss << "Nombre: " << actual->dato.nombre << " " << actual->dato.segundoNombre
            << ", Apellido: " << actual->dato.apellido
            << ", Cedula: " << actual->dato.cedula << std::endl;

        ss << "Correo: " << actual->dato.getCorreo() << "@espe.edu.ec"
            << ", Contrasenia inicial: " << actual->dato.getContrasenaInicial()
            << ", Contrasenia: " << actual->dato.getContrasena() << std::endl;

        actual = actual->siguiente;
        if (esCircular && actual == cabeza) break;
    }
    return ss.str();
}

void Lista::imprimir() const {
    Nodo* actual = cabeza;
    do {
        std::cout << "Nombre: " << actual->dato.nombre << " " << actual->dato.segundoNombre
            << ", Apellido: " << actual->dato.apellido
            << ", Cedula: " << actual->dato.cedula << std::endl;

        std::cout << "Correo: " << actual->dato.getCorreo() << "@espe.edu.ec"
            << ", Contrasenia inicial: " << actual->dato.getContrasenaInicial()
            << ", Contrasenia: " << actual->dato.getContrasena() << std::endl;

        actual = actual->siguiente;
        if (esCircular && actual == cabeza) break;
    } while (actual != nullptr);
}

void Lista::guardarEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo);

    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        archivo << "Nombre: " << actual->dato.nombre << " " << actual->dato.segundoNombre
            << ", Apellido: " << actual->dato.apellido
            << ", Cedula: " << actual->dato.cedula << std::endl;

        archivo << "Correo: " << actual->dato.getCorreo() << "@espe.edu.ec"
            << ", Contrasenia inicial: " << actual->dato.getContrasenaInicial()
            << ", Contrasenia: " << actual->dato.getContrasena() << std::endl;

        actual = actual->siguiente;
        if (esCircular && actual == cabeza) break;
    }
}

void Lista::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    std::string nombre, segundoNombre, apellido, cedula, correo, contrasenaInicial, contrasena;
    std::string dummy;
    while (archivo >> dummy >> nombre >> segundoNombre >> dummy >> apellido >> dummy >> cedula) {
        archivo >> dummy >> correo >> dummy >> dummy >> contrasenaInicial >> dummy >> contrasena;
        correo = correo.substr(0, correo.find('@'));
        Persona persona(nombre, segundoNombre == "null" ? "" : segundoNombre, apellido, cedula);
        persona.setCorreo(correo);
        persona.setContrasena(contrasena);
        persona.setContrasenaInicial(contrasenaInicial);
        insertarDesdeArchivo(persona);
    }
}

void Lista::insertarDesdeArchivo(Persona dato) {
    Nodo* nuevo = new Nodo(dato);
    if (!cabeza) {
        cabeza = nuevo;
        cola = nuevo;
        if (esCircular) {
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        }
    }
    else {
        if (esCircular) {
            nuevo->siguiente = cabeza;
            nuevo->anterior = cola;
            cola->siguiente = nuevo;
            cabeza->anterior = nuevo;
            cola = nuevo;
        }
        else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
    }

    cedulasRegistradas.insert(dato.cedula);
}

void Lista::crearBackup(const std::string& nombreArchivo, const std::string& contenido) {
    std::string backupNombreArchivo = nombreArchivo + ".backup";
    std::ofstream backupArchivo(backupNombreArchivo);
    if (!backupArchivo) {
        std::cerr << "No se pudo crear el archivo de backup " << backupNombreArchivo << std::endl;
        return;
    }
    backupArchivo << contenido;
}

void Lista::agregarAlArchivo(const Persona& dato) const {
    std::ofstream archivo(nombreArchivo, std::ios::app);

    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    archivo << "Nombre: " << dato.nombre << " " << dato.segundoNombre
        << ", Apellido: " << dato.apellido
        << ", Cedula: " << dato.cedula << std::endl;

    archivo << "Correo: " << dato.getCorreo() << "@espe.edu.ec"
        << ", Contrasenia inicial: " << dato.getContrasenaInicial()
        << ", Contrasenia: " << dato.getContrasena() << std::endl;
}

void Lista::ordenarIntercambio(int criterio) {
    if (criterio >= 1 && criterio <= 3) {
        intercambioPersonas(cabeza, cola, esCircular, criterio);
        guardarEnArchivo(nombreArchivo); // Guardar en el archivo original
    }
    else if (criterio == 4) {
        ordenarCaracteresIntercambio();
    }
}

void Lista::ordenarCaracteresIntercambio() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        intercambio(actual->dato.nombre);
        intercambio(actual->dato.apellido);
        actual = actual->siguiente;
        if (esCircular && actual == cabeza) break;
    }

    std::string contenidoOrdenado = obtenerContenidoOrdenado();
    crearBackup(nombreArchivo, contenidoOrdenado); // Crear un backup con los datos ordenados
}