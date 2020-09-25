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
#include "parcialLabII.h"

using namespace rlutil;
using namespace std;


void entrenamientoMasCalorias(){
///1) A partir de un IDUsuario que se ingresa por teclado, listar el entrenamiento de mayor cantidad de calorías y la fecha en que las registró.
///Si hay dos registro con misma cantidad, mostrar el primero de ellos.

    Rutina registro;
    FILE *p;
    Rutina *vecEntrenamientos;
    int idAux,cantRegis;
    int guardo;
    float maxCalorias=0;
    Fecha fechaAux;

    title("Entrenamiento con máximas calorías quemadas");
    gotoxy(1,3);cout <<"Ingrese ID Usuario:\t";
    cin >> idAux;

            while(buscarID(idAux) == -2){
                msj("ID inexistente",WHITE,RED,29,TEXT_LEFT);
                cls();
                title("NUEVA RUTINA");
                gotoxy(1,3);cout << "Ingrese otro ID:\t";
                fflush(stdin);
                cin >> idAux;
            }

		p=fopen("archivos/Entrenamientos.dat","rb");
			if(p==NULL){
				cout << "Error al abrir el archivo \n";
				return;
			}

			cantRegis = contarRutinas();
			vecEntrenamientos = (Rutina *) malloc(cantRegis*sizeof(Rutina));
				        if(vecEntrenamientos==NULL){
                msj("No hay espacio en memoria",WHITE,RED,29,TEXT_LEFT);
                cls();
                return;
			}
			guardo = fread(vecEntrenamientos,sizeof(Rutina),cantRegis,p);
            if(guardo!=cantRegis){
                msj("Error al guardar registros",WHITE,RED,29,TEXT_LEFT);
                cls();
                fclose(p);
                return;
            }

            fclose(p);

				for(int i=0;i<cantRegis;i++){
					if(vecEntrenamientos[i].idUsuario == idAux && vecEntrenamientos[i].calorias > maxCalorias){
						maxCalorias = vecEntrenamientos[i].calorias;
						fechaAux = vecEntrenamientos[i].fechaRutina;
					}
				}

                free(vecEntrenamientos);

				cout << "Para el usuario:\t" << idAux << endl;
                cout << "Las maximas calorias quemadas fueron:\t" << maxCalorias << endl;
                cout << "En el dia:\t" << fechaAux.dia << "/" << fechaAux.mes << "/" << fechaAux.anio << endl;

                getch();
                return;
}

void actividadPorPerfil(){

        FILE *p, *u;
        const int filas=5, columnas=3;
        int matAct[filas][columnas]={0};
        Rutina regAux, *vecEntrenamientos;
        Usuario *vecUsuarios;
		int idAux,cantRegis, cantRegisUser;
		int guardo, guardoUser;

			p=fopen("archivos/Entrenamientos.dat","rb");
			if(p==NULL){
				cout << "Error al abrir el archivo entrenamientos \n";
				return;
			}
			u=fopen("archivos/Usuarios.dat","rb");
			if(u==NULL){
				cout << "Error al abrir el archivo usuarios \n";
				return;
			}
			/// Crear vector rutinas
			cantRegis = contarRutinas();
			vecEntrenamientos = (Rutina *) malloc(cantRegis*sizeof(Rutina));
				        if(vecEntrenamientos==NULL){
                msj("No hay espacio en memoria rutinas",WHITE,RED,29,TEXT_LEFT);
                cls();
                return;
			}
			guardo = fread(vecEntrenamientos,sizeof(Rutina),cantRegis,p);
            if(guardo!=cantRegis){
                msj("Error al guardar registros",WHITE,RED,29,TEXT_LEFT);
                cls();
                fclose(p);
                return;
            }
            /// Crear vector usuarios
            cantRegisUser = contarRegistro();
			vecUsuarios = (Usuario *) malloc(cantRegisUser*sizeof(Usuario));
				        if(vecUsuarios==NULL){
                msj("No hay espacio en memoria usuarios",WHITE,RED,29,TEXT_LEFT);
                cls();
                return;
			}
			guardoUser = fread(vecUsuarios,sizeof(Usuario),cantRegisUser,u);
            if(guardoUser!=cantRegisUser){
                msj("Error al guardar registros",WHITE,RED,29,TEXT_LEFT);
                cls();
                fclose(u);
                return;
            }

            fclose(p);
            fclose(u);

            for(int i=0;i<cantRegis;i++){
                for(int j=0;j<cantRegisUser;j++){
                    if(vecEntrenamientos[i].actividad==i+1){
                        switch(vecUsuarios[j].perfAct){
							case 'A':
								matAct[vecEntrenamientos->actividad-1][0]++;
							break;
							case 'a':
								matAct[vecEntrenamientos->actividad-1][0]++;
							break;
							case 'B':
								matAct[vecEntrenamientos->actividad-1][1]++;
							break;
							case 'b':
								matAct[vecEntrenamientos->actividad-1][1]++;
							break;
							case 'C':
								matAct[vecEntrenamientos->actividad-1][2]++;
							break;
							case 'c':
								matAct[vecEntrenamientos->actividad-1][2]++;
							break;
                        }
                    }
                }
            }

            for(int x=0;x<filas;x++){
				for(int z=0;z<columnas;z++){

                    if(matAct[x][z]>0){

						switch(z){
							case 0:
								cout << "Actividad\t" << x+1 << " perfil A" <<  endl;
								cout << "Cantidad de entrenamientos: " << matAct[x][z]<<endl<<endl;
							break;
							case 1:
								cout << "Actividad\t" << x+1 << " perfil B" <<  endl;
								cout << "Cantidad de entrenamientos: " << matAct[x][z]<<endl<<endl;
							break;
							case 2:
								cout << "Actividad\t" << x+1 << " perfil C" <<  endl;
								cout << "Cantidad de entrenamientos: " << matAct[x][z]<<endl;
							break;

						}

                    }
				}
            }

                free(vecEntrenamientos);
                free(vecUsuarios);

                getch();
                return;
}

//2)
