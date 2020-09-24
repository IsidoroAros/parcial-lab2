#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <cctype>
#include <algorithm>
#include "rutinas.h"
#include "usuarios.h"
#include "menus.h"
#include "fechas.h"
#include "ui.h"
#include "rlutil.h"
#include "modeloParcial.h"
#include "configuracion.h"

using namespace std;
using namespace rlutil;

void tiempoPromedio(){

    FILE *p;
    int acuTiempoTraino=0, contRutinas = 0, guardo;
    float tiempProm;
    Rutina regAux, *vecRutinas;

	contRutinas = contarRutinas();
    p=fopen("archivos/Entrenamientos.dat","rb");

    vecRutinas = (Rutina *)malloc(contRutinas*sizeof(Rutina));
		if(vecRutinas==NULL){
            cout << "Error al reservar memoria\n";
            system("pause");
            cls();
            return;
		}
		guardo=fread(vecRutinas,sizeof(Rutina),contRutinas,p);
			if(guardo!=contRutinas){
				system("pause");
                cout << "Error de carga de archivos\n";
                cls();
                return;
			}

		fclose(p);

		for(int i=1;i<=contRutinas;i++){
			acuTiempoTraino += vecRutinas[i].tiempo;
            }

		tiempProm = ((float)acuTiempoTraino / (float)contRutinas);
		cout << "Tiempo promedio " << tiempProm << endl;

		for(int j=1;j<=contRutinas;j++){
            if(vecRutinas[j].tiempo>tiempProm){
                mostrarRutina(vecRutinas[j]);
            }
		}

		free(vecRutinas);

		system("pause");

}


void entrenamientos2020(){

    Rutina registro;
    FILE *p;
    Rutina *vecRutinas;
    int idAux,cantReg;
    int guardo;

    title("LISTAR ENTRENAMIENTOS 2020");
    gotoxy(1,3);cout <<"Ingrese ID Usuario:\t";
    cin >> idAux;

            while(buscarID(idAux) == -2){
                msj("ID inexistente",WHITE,RED,29,TEXT_LEFT);
                cls();
                title("LISTAR ENTRENAMIENTOS 2020");
                gotoxy(1,3);cout << "Ingrese otro ID:\t";
                fflush(stdin);
                cin >> idAux;
            } /// registra que exista el usuario, sino retorna -2

    cantReg = contarRutinas(); /// buscamos la cantidad de registros que hay en el archivo de rutinas
    vecRutinas = (Rutina *) malloc(cantReg*sizeof(Rutina)); /// reservar espacios de un vector para esa cantidad de registros
        if(vecRutinas==NULL){
                msj("No hay espacio en memoria",WHITE,RED,29,TEXT_LEFT);
                cls();
                system("pause");
                return;
        }


    p=fopen("archivos/Entrenamientos.dat","rb+");
        if(p==NULL){
                cout << "Error al abrir el archivo \n";
                system("pause");
                return;
        }

        guardo = fread(vecRutinas,sizeof(Rutina),cantReg,p); /// en el vecRutinas cargo todos los reg
            if(guardo!=cantReg){
                msj("Error al guardar registros",WHITE,RED,29,TEXT_LEFT);
                cls();
                system("pause");
                return;
            }

        fclose(p);

        for(int i=0;i<cantReg;i++){
			if(vecRutinas[i].idUsuario == idAux){
				if(vecRutinas[i].fechaRutina.anio == 2020){
					mostrarRutina(vecRutinas[i]);
				}
			}
        }
        getch();
        free(vecRutinas);
        return;

}
