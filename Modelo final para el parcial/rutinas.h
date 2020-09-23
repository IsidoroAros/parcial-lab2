#ifndef RUTINAS_H_INCLUDED
#define RUTINAS_H_INCLUDED

#include "fechas.h"
#include "usuarios.h"

struct Rutina{
    int id;
    int idUsuario;
    Fecha fechaRutina;
    int  actividad;
    float calorias;
    int tiempo;
};

void guardarRutina(); /// Guarda una rutina que recibe de cargarRutina

Rutina cargarRutina(); /// Se carga una rutina y se la envía a guardar a guardarRutina

int crearId(); /// Crea un ID autonumerico para cada rutina cargada solo si el usuario tiene estado TRUE

void listarRutinas(); /// Muestra todas las rutinas

int buscarIDRutina(int id); /// Busca y retorna la posicion de una rutina en el archivo

void mostrarRutina(Rutina reg); /// muesta una rutina recibida por parametro --> listarRutinaXID y listarRutinaXIdUsuario()

void listarRutinaXId(); /// Lista una rutina recibida por ID

Rutina copiarEntrenamiento(int posicion); /// Copia el registro de una rutina en un registro auxiliar

void modificarEntrenamiento(); /// Modifica un entrenamiento que recibe por ID de rutina

int contarRutinas(); /// Cuenta cuantas rutinas hay en el archivo

void listarRutinaXIdUsuario(); /// Lista todas las rutinas de un usuario que recibe por ID de usuario

#endif // RUTINAS_H_INCLUDED
