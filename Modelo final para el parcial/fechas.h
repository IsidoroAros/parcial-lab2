#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

///------------------- STRUCTS -------------------

struct Fecha{

	int dia;
	int mes;
    int anio;

};

///------------------- FUNCIONES -------------------

Fecha hoy(); /// Pone en un registro la fecha del dia de hoy

bool validarEdad(int  dia, int mes, int anio); /// Valida que un usuario no sea menor de 13 años

bool validarFecha( int dia, int mes, int anio); /// Función que valida una fecha no sea mayor a hoy



#endif // FECHAS_H_INCLUDED
