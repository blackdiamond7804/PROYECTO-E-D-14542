#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <string>
<<<<<<< Updated upstream:Project13/Project13/Lista.h
#include "Nodo.h"
#include "Persona.h"
#include "Ordenamientos.h"
#include "Generaciones.h"
=======
#include <memory>
#define WIN32_LEAN_AND_MEAN
#include <functional>
#include <vector>
#include"I_Mezclar.h"

>>>>>>> Stashed changes:Lista.h

class Lista:public Mezclar {
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
    void ordenarBurbuja(int criterio);
    void ordenarCaracteresBurbuja();
    void ordenarCaracteres();
    std::string obtenerContenidoOrdenado() const;
    void imprimir() const;
    void guardarEnArchivo(const std::string& nombreArchivo) const;
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    void insertarDesdeArchivo(Persona dato);
    void agregarAlArchivo(const Persona& dato) const;
<<<<<<< Updated upstream:Project13/Project13/Lista.h
=======

    void eliminar(int);
    int cantidad();
    Persona datoEn(int);
    void recorrer(std::function<void(Persona)> callback);
    void insertarOrdenado(Persona per, int);
    Persona eliminarPrimero();
    void insertarUltimo(Persona persona);
    void ordenarDistribucion(int criterio);
   void MezclaPares() override;
>>>>>>> Stashed changes:Lista.h
};

#endif // LISTA_H