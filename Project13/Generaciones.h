#ifndef GENERACIONES_H
#define GENERACIONES_H

#include "Persona.h"
#include "Nodo.h"
#include <string>
#include <algorithm>

std::string generarCorreo(Nodo* cabeza, Persona& persona, bool esCircular);
std::string generarContrasena(Persona& persona);
std::string desencriptarContrasena(Persona& persona);

#endif // GENERACIONES_H