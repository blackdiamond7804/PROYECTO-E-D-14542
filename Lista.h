#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include "Persona.h"
#include "Ordenamientos.h"
#include "Generaciones.h"
#include <iostream>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <string>
#include <functional>
#include <vector>


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
    void ordenarRadix(int criterio);
    //void ordenarRadixx();
    void ordenarRadixx(std::string& nombre);
    void ordenarBurbuja(int criterio);
    void ordenarQuicksort(int criterio);
    void ordenarCaracteresQuicksort();
    void ordenarIntercambio(int criterio);
    void ordenarCaracteresIntercambio();
    std::string obtenerContenidoOrdenado() const;
    void imprimir() const;
    void guardarEnArchivo(const std::string& nombreArchivo) const;
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    void insertarDesdeArchivo(Persona dato);
    void agregarAlArchivo(const Persona& dato) const;

    void eliminar(int);
    int cantidad();
    Persona datoEn(int);
    void recorrer(std::function<void(Persona)> callback);
    void insertarOrdenado(Persona per, int);
    Persona eliminarPrimero();
    void insertarUltimo(Persona persona);
    void ordenarDistribucion(int criterio);
   
};

#endif // LISTA_H