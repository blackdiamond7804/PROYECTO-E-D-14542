
#ifndef MENUS_H
#define MENUS_H

#include "Lista.h"
#include "Persona.h"
#include "Validacion.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <memory>
#define WIN32_LEAN_AND_MEAN

void setConsoleColor(WORD color);
void mostrarMenu(int opcion);
void mostrarSubMenu(int opcion);
void mostrarMenuOrden(int opcion);
void ingresarDatos(Lista& lista);
bool cedulaRegistradaEnArchivo(const string& cedula);

void MenuShellMain();
void subMenuListaShell(Lista& lista);

void MenuRadixMain();
void subMenuListaRadix(Lista& lista);

void MenuIntercambio();
void subMenuListaIntercambio(Lista& lista);

void MenuQuicksortMain();
void subMenuListaQuicksort(Lista& lista);

void MenuDistribucion();
void subMenuListaDistribucion(Lista& lista);

void MenuBurbujaMain();
void subMenuListaBurbuja(Lista& lista);

#endif

