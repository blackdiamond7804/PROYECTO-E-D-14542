#ifndef GENERACIONES_H
#define GENERACIONES_H

#include "Persona.h"
#include "Nodo.h"
#include <string>
#include <memory>
#define WIN32_LEAN_AND_MEAN
#include <algorithm>

std::string generarCorreo(Nodo* cabeza, Persona& persona, bool esCircular);
std::string generarContrasena(Persona& persona);
std::string desencriptarContrasena(Persona& persona);

#endif // GENERACIONES_H