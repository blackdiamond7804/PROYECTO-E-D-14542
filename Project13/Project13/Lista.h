#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <string>
#include "Nodo.h"
#include "Persona.h"
#include "Ordenamientos.h"
#include "Generaciones.h"

class Lista {
private:
    Nodo* cabeza;
    Nodo* cola;
    bool esCircular;
    std::unordered_set<std::string> cedulasRegistradas;
    std::string nombreArchivo;

    void crearBackup(const std::string& nombreArchivo, const std::string& contenido);

public:
    Lista(bool circular = false, const std::string& nombreArchivo = "datos_personas.txt");
    ~Lista();

    bool verificarCedula(const std::string& cedula);
    void insertar(Persona dato);
    void ordenar(int criterio);
    void ordenarCaracteres();
    std::string obtenerContenidoOrdenado() const;
    void imprimir() const;
    void guardarEnArchivo(const std::string& nombreArchivo) const;
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    void insertarDesdeArchivo(Persona dato);
    void agregarAlArchivo(const Persona& dato) const;
};

#endif // LISTA_H