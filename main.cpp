#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "citas.h"
#include "medicos.h"
#include "pacientes.h"
using namespace std;

void titulo();
int menuPrincipal();
int menuOpc();
void eleccion(string cadenaE);

int main() {
    system("color 71");
    string espec;
    titulo();
    int opc = menuPrincipal();
    while (opc != 4){
        switch (opc)
        { //Se divide por deparamentos Pediatria, Neurologia y Odontologia
            case 1:
                {
                    system("cls");
                    cout << "---------------------------------Pediatria---------------------------------"<<endl;
                    espec="Pediatria";
                    eleccion(espec);
                    sleep (2);
                    break;
                }
            case 2:
                {
                    system("cls");
                    cout << "--------------------------------Neurologia----------------------------------"<<endl;
                    espec="Neurologia";
                    eleccion(espec);
                    sleep (2);
                    break;
                }    
            case 3:
                {
                    system("cls");
                    cout << "--------------------------------Odontologia----------------------------------"<<endl;
                    espec="Odontologia";
                    eleccion(espec);
                    sleep (2);
                    break;
                }
        }
        opc = menuPrincipal();
    }
    return 0;
}

void titulo(){
    cout<<"\t\t***********************************************************"<<endl;
    cout<<"\t\t                       CLINICA 'EPN'"<<endl;
    cout<<"\t\t                   BIENVENIDO AL SISTEMA"<<endl;
    cout<<"\t\t***********************************************************"<<endl;
}

int menuPrincipal(){
    int op = -1;
    while (op < 1 || op >4){
        cout << "\t_____________________________" << endl;
        cout << "\t| SELECIONE UN DEPARTAMENTO.|" << endl;
        cout << "\t| 1. Pediatria              |"<<endl; 
        cout << "\t| 2. Neurologia             |"<<endl;
        cout << "\t| 3. Odontologia            |"<<endl;
        cout << "\t| 4. Salir                  |"<<endl;
        cout << "\t|___________________________|" << endl;
        cout << "\t\t>Ingrese su opcion: ";
        cin >> op;
        if ((op < 1 || op >4)){
            cout << "No tenemos esa opcion." << endl;
        }
    }
    return op;
}

int menuOpc(){
    int op = -1;
    while (op < 1 || op >4){
        cout << "\t\t_____________________________" << endl;
        cout << "\t\t| SELECIONE UNA OPCION.     |" << endl;
        cout << "\t\t| 1. SECCION MEDICOS        |"<<endl; 
        cout << "\t\t| 2. SECCION PACIENTES      |"<<endl;
        cout << "\t\t| 3. SECCION CITAS          |"<<endl;
        cout << "\t\t| 4. Salir                  |"<<endl;
        cout << "\t\t|___________________________|" << endl;
        cout << "\t\t\t >Ingrese su opcion: ";
        cin >> op;
        if ((op < 1 || op >4)){
            cout << "No tenemos esa opcion." << endl;
        }
    }
    return op;
}

void eleccion(string cadenaE){
    //Se divide por secciones Medicos, Pacientes y Citas
    int op = menuOpc();
    while (op != 4){
        switch (op)
        {
            case 1:
                {
                    system("cls");
                    cout << "-----------------------------------"<<cadenaE<<"-----------------------------------"<<endl;
                    cout << "---------------------------------SECCION MEDICOS---------------------------------"<<endl;
                    medicos(cadenaE);//se llama conjuntamete todas las funcionalidades de medicos
                    break;
                }
            case 2:
                {
                    system("cls");
                    cout << "-----------------------------------"<<cadenaE<<"-----------------------------------"<<endl;
                    cout << "---------------------------------SECCION PACIENTES---------------------------------"<<endl;
                    pacientes_();//se llama conjuntamete todas las funcionalidades de pacientes
                    break;
                }    
            case 3:
                {
                    system("cls");
                    cout << "-----------------------------------"<<cadenaE<<"-----------------------------------"<<endl;
                    cout << "--------------------------------SECCION CITAS----------------------------------"<<endl;
                    citas_(cadenaE);//se llama conjuntamete todas las funcionalidades de citas
                    break;
                }
        }
        op = menuOpc();
    }
}