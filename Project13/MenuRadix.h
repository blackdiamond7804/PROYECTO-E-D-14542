#pragma once
#ifndef MENURADIX_H
#define MENURADIX_H

#include <iostream>
#include <windows.h>
#include "Lista.h"
#include "Persona.h"
#include "Validacion.h"

void Color(WORD color);
void MenuRadixMain();
void mostrarMenuRadix(int opcion);
void mostrarSubMenuRadix(int opcion);
void mostrarMenuOrdenRadix(int opcion);
void ingresarDatosRadix(Lista& lista);
void subMenuListaRadix(Lista& lista);

#endif // MENU_H
