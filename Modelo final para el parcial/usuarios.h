#ifndef FUNCIONESTP_H_INCLUDED
#define FUNCIONESTP_H_INCLUDED
#include "fechas.h"


///------------------- STRUCTS -------------------

struct Usuario{

    int id;
    char nombres[50];
    char apellidos[50];
    Fecha fecha;
    float altura;
    float peso;
    char perfAct;
    bool aptoMedico;
    bool estado;

};

///------------------- FUNCIONES -------------------

Usuario cargarUsuario(); /// Ingresar datos del usuario

void guardarUsuario(); /// Guarda los datos del usuario en el archivo

void modificarUsuario(); /// Modificar un usuario por numero de ID

bool rangoId(int id); /// Chequea que el rango del ID sea valido

int buscarID(int); /// Busca coincidencias de ID en un archivo y retorna la posición

Usuario leerUsuario(int pos); /// Devuelve un registro mediante una posición dada

void listarUsuarios(); /// Lista todos los usuarios del archivo

void listarId(); /// Lista las características de un usuario por su ID

void mostrarReg(Usuario reg); /// Muestra un registro que recibe por parametro

void eliminarUsuario(); /// Genera la baja lógica de un usuario mediante un ID

bool validarNombresApellidos(char *nombres, int tam); /// Valida que una cadena de caracteres no esté vacía

int contarRegistro(); /// cuenta cuantos registros hay en un archivo

void vectorIdsUsuarios(); /// Mediante Malloc crea un vector con todos los ID's de los usuarios ---------> función reutilizable

void leerVector(int *vec, int cantidadRegistros); /// Lee un vector de registros

#endif // FUNCIONESTP_H_INCLUDED
