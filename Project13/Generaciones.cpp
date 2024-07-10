#include "Generaciones.h"

std::string generarCorreo(Nodo* cabeza, Persona& persona, bool esCircular) {
    Nodo* auxiliar = cabeza;
    std::string inicialesNombre = "";
    inicialesNombre.push_back(tolower(persona.nombre[0]));
    if (!persona.segundoNombre.empty()) {
        inicialesNombre.push_back(tolower(persona.segundoNombre[0]));
    }
    std::string correo = inicialesNombre + persona.apellido;
    std::string correoBase = correo;
    int contador = 0;

    while (auxiliar != nullptr) {
        if (auxiliar->dato.getCorreo() == correo) {
            contador++;
            correo = correoBase + std::to_string(contador);
        }
        auxiliar = auxiliar->siguiente;
        if (esCircular && auxiliar == cabeza) break;
    }

    return correo;
}

std::string generarContrasena(Persona& persona) {
    static bool primerUsuario = true;
    static int contador = 1;

    std::string apellido = persona.apellido;
    std::string primerNombre = persona.nombre;
    std::string segundoNombre = persona.segundoNombre;

    char ultimaLetraApellido = tolower(apellido.back());
    char primeraLetraPrimerNombre = tolower(primerNombre.front());
    char ultimaLetraSegundoNombre = !segundoNombre.empty() ? tolower(segundoNombre.back()) : '\0';

    std::string restoApellido = apellido.substr(0, apellido.size() - 1);
    std::reverse(restoApellido.begin(), restoApellido.end());
    std::transform(restoApellido.begin(), restoApellido.end(), restoApellido.begin(), ::tolower);

    std::string contrasenaBase = std::string(1, ultimaLetraApellido) + primeraLetraPrimerNombre;
    if (ultimaLetraSegundoNombre != '\0') {
        contrasenaBase += ultimaLetraSegundoNombre;
    }
    contrasenaBase += restoApellido;

    std::string contrasenaEncriptada = "";

    int shift = 2;
    for (char c : contrasenaBase) {
        if (isalnum(c)) {
            char base = (isdigit(c) ? '0' : (isupper(c) ? 'A' : 'a'));
            char encryptedChar = (c - base + shift) % 26 + base;
            contrasenaEncriptada += encryptedChar;
        }
        else {
            contrasenaEncriptada += c;
        }
    }

    if (!primerUsuario) {
        contrasenaBase += std::to_string(contador);
        contador++;
    }

    primerUsuario = false;

    persona.setContrasena(contrasenaEncriptada);
    persona.setContrasenaInicial(contrasenaBase);
    return contrasenaEncriptada;
}

std::string desencriptarContrasena(Persona& persona) {
    std::string contrasenaBase = persona.getContrasenaInicial();
    std::string contrasenaDesencriptada = "";

    int shift = 2;
    for (char c : persona.getContrasena()) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char decryptedChar = (c - base - shift + 26) % 26 + base;
            contrasenaDesencriptada += decryptedChar;
        }
        else {
            contrasenaDesencriptada += c;
        }
    }

    return contrasenaDesencriptada;
}