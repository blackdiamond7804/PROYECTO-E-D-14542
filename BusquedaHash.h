#pragma once

#include <fstream>
#include <iostream>
#include "Lista.h"
#include "Persona.h"

class Hash {
private:
    
    Lista* listaHashTable;
    int tamanoTabla;
public:
    Hash(int tamanoTabla): tamanoTabla(tamanoTabla) {
        listaHashTable = new Lista[tamanoTabla];
    }

    ~Hash() {
        delete[] listaHashTable; // Liberar la memoria asignada
    }

    int contarElementos() {
        std::ifstream archivo("Datos_Personas.txt");

        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo " << std::endl;
            return -1;
        }
        int contador = 0;
        std::string nombre, segundoNombre, apellido, cedula, correo, contrasenaInicial, contrasena;
        std::string dummy;
        while (archivo >> dummy >> nombre >> segundoNombre >> dummy >> apellido >> dummy >> cedula) {
            archivo >> dummy >> correo >> dummy >> dummy >> contrasenaInicial >> dummy >> contrasena;
           
            contador++;
        }
        tamanoTabla = contador;
        return tamanoTabla;
    }

    
    int HashFuncion(const char* key) {
        int sum = 0;
        int len = strlen(key);
        const char* puntero = key;
        for (int i = 0; i < len; i++) {
            sum += *(puntero + i);
        }
        return sum % tamanoTabla;
    }

    void insertarH(const char* key, Persona valor) {
        int indice = HashFuncion(key);  
        Lista* listaPtr = listaHashTable + indice;
        listaPtr->insertarClaveValor(key,valor);
    }

    Persona* buscarH(const char* key) {
        int indice = HashFuncion(key);
        Lista* listaPtr = listaHashTable + indice;
        return listaPtr->buscarValor(key);
    }

    void leerArchivoEInsertarH() {
        std::ifstream archivo("Datos_Personas.txt");

        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo "<< std::endl;
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

            //std::cout << "Insertando Persona"<<persona.cedula<< "en tabla hash" << std::endl;
            insertarH(persona.cedula.c_str(), persona);
        }

        archivo.close();
    }

    void imprimirPersona(Persona* persona) {
        if (persona != nullptr) {
            cout << "Cedula Encontrada!" << endl;
            cout << "Nombre: " << persona->getNombre() << ", Apellido: " << persona->getApellido() << endl;

            cout << "Correo: " << persona->getCorreo() << "@espe.edu.ec"
                << ", Contrasenia inicial: " << persona->getContrasenaInicial()
                << ", Contrasenia: " << persona->getContrasena() << std::endl;
            
        }
        else {
            cout << "Usuario no encontrado." << endl;
        }
    }
};