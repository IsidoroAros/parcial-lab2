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

using namespace rlutil;
using namespace std;


void menu(){

    while(true){
        cls();
        title("MENU PRINCIPAL",BLACK,CYAN);
        gotoxy(1,3);
        cout<<"1 - USUARIOS"<<endl;
        cout<<"2 - ENTRENAMIENTOS"<<endl;
        cout<<"3 - REPORTES"<<endl;
        cout<<"4 - CONFIGURACION"<<endl;
        cout<<"5 - MODELO PARCIAL"<<endl;
        cout<<"6 - PARCIAL"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"0 - SALIR   "<<endl;
        int opcion;
        cout<<"> ";
        cin>>opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            menuUsuarios();
            break;
        case 2:
            menuRutinas();
            break;
        case 4:
            menuConfig();
        case 5:
            menuPreParcial();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}

void menuUsuarios(){

    while(true){

        system("cls");
        title("MENU USUARIOS",BLACK,CYAN);
        gotoxy(1,3);
        cout<<"1 - NUEVO USUARIO "<<endl;
        cout<<"2 - MODIFICAR USUARIO "<<endl;
        cout<<"3 - LISTAR USUARIO POR ID "<<endl;
        cout<<"4 - LISTAR TODOS LOS USUARIOS"<<endl;
        cout<<"5 - ELIMINAR USUARIO "<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        int opcion;
        cout<<"> ";
        cin>> opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            guardarUsuario();
            break;
        case 2:
            modificarUsuario();
            break;
        case 3:
            listarId();
            break;
        case 4:
            listarUsuarios();
            break;
        case 5:
            eliminarUsuario();
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    }
}

void menuRutinas(){
        int opcion;
        do {
        cls();
        title("ENTRENAMIENTOS", 0, 42);
        gotoxy(1, 3); /// El puntero arranca a partir de esta posicion
        cout << "--------------------------------" << endl;
        cout << "1) NUEVO ENTRENAMIENTO" << endl;
        cout << "2) MODIFICAR ENTRENAMIENTO" << endl;
        cout << "3) LISTAR ENTRENAMIENTO POR ID" << endl;
        cout << "4) LISTAR ENTRENAMIENTOS POR ID USUARIO" << endl;
        cout << "5) LISTAR TODOS LOS ENTRENAMIENTOS" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl;

        cout << "> ";
        cin >> opcion;
        system("cls");
        switch (opcion){
        case 1:
            guardarRutina();
            break;
        case 2:
            modificarEntrenamiento();
            break;
        case 3:
             listarRutinaXId();
            break;
        case 4:
             listarRutinaXIdUsuario();
            break;
        case 5:
            listarRutinas();
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    } while (opcion != 0);
}

void menuPreParcial(){

int opcion;
        do {
        cls();
        title("MODELO PARCIAL", 0, 45);
        gotoxy(1, 3); /// El puntero arranca a partir de esta posicion
        cout << "--------------------------------" << endl;
        cout << "1) PUNTO A" << endl;
        cout << "2) PUNTO B" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl;

        cout << "> ";
        cin >> opcion;
        system("cls");
        switch (opcion){
        case 1:
            tiempoPromedio();
            break;
        case 2:
            entrenamientos2020();
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    } while (opcion != 0);
}

void menuConfig(){
int opcion;
        do {
        cls();
        title("MENU CONFIGURACION", 0, 42);
        gotoxy(1, 3);
        cout << "--------------------------------" << endl;
        cout << "1) REALIZAR COPIA DE SEGURIDAD" << endl;
        cout << "2) RESTAURAR COPIA DE SEGURIDAD" << endl;
        cout << "3) CREDITOS" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl;
        cout << "> ";
        cin >> opcion;
        system("cls");
        switch (opcion){
        case 1:
            hacerCopia();
            break;
        case 2:
            restaurarCopia();
            break;
        case 3:
            creditos();
            break;
        case 0:
            return;

        default:
            break;
        }
    } while (opcion != 0);
}


