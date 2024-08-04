#ifndef BUSQUEDAS_H
#define BUSQUEDAS_H

#include <string>
#include "Persona.h"
#include "Lista.h"
#include "Ordenamientos.h"

class Busquedas {
public:
    Persona* busquedaSecuencial(const std::string& nombreArchivo, const std::string& cedula);
    void imprimirPersona(Persona* persona);
    int LeerArchivoContar();
    void InsertarBinario(const std::string& cedula, Persona persona);
    void LeerArhivoInsertarBin();
    void BusquedaBinar(std::string& cedula, const Lista& listaptr);

private:
    Persona* buscarCedulaRecursiva(std::ifstream& archivo, const std::string& cedula);
    
};

#endif
