#ifndef GENERACIONES_H
#define GENERACIONES_H

#include <string>
#include <algorithm>
#include "Persona.h"
#include "Nodo.h"

std::string generarCorreo(Nodo* cabeza, Persona& persona, bool esCircular);
std::string generarContrasena(Persona& persona);
std::string desencriptarContrasena(Persona& persona);

#endif // GENERACIONES_H