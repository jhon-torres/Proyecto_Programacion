#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "pacientes.h"
using namespace std;

tpaciente nuevo() {
   tpaciente paciente;
   cout << "Ingrese el historia clinico: ";
   cin >> paciente.historial;
   cout<<"FORMATO: APELLIDOS Y NOMBRES"<<endl;
   cout << "Ingrese el nombre del paciente: ";
   cin.get();
   getline(cin,paciente.nombre);
   cout << "Ingrese el numero de telefono: ";
   cin.get();
   getline(cin,paciente.telf);

   return paciente;
}

int menu() {
   int op;
   cout<<"\n______________BIENVENIDO AL INGRESO DE PACIENTES_____________"<<endl;
   cout <<"|               1 - Insertar                                 |"  << endl;
   cout <<"|               2 - Eliminar                                 |"  << endl;
   cout <<"|               3 - Mostrar                                  |"  << endl;
   cout <<"|               0 - Salir                                    |" << endl;
   cout <<"|____________________________________________________________|"<<endl;
   do { 
      cout << "Opcion: ";
      cin >> op;
   } while ((op < 0) || (op > 3));
   return op;
}

void insertar(tListaP &listap, tpaciente paciente, bool &ok) {
   ok = true;
   if (listap.cont == MAXI) {
      ok = false;
   }
   else {
      int i = 0;
      while ((i < listap.cont) && (listap.pacientes[i] < paciente)) {
         i++;
      }
      for (int j = listap.cont; j > i; j--) { 
         listap.pacientes[j] = listap.pacientes[j - 1];
      }
      listap.pacientes[i] = paciente;
      listap.cont++;
   }
}

void eliminar(tListaP &listap, int pos, bool &ok) { 
   ok = true;
   if ((pos < 1) || (pos > listap.cont)) {
      ok = false;
   }
   else {
      pos--; 
      for (int i = pos + 1; i < listap.cont; i++) { 
         listap.pacientes[i - 1] = listap.pacientes[i];
      }
      listap.cont--;
   }
}

int buscarPaciente(tListaP &listap, string nombre) {
   int ini = 0, fin = listap.cont - 1, mitad;
   bool encontrado = false;
   while ((ini <= fin) && !encontrado) {
      mitad = (ini + fin) / 2; 
      if (nombre == listap.pacientes[mitad].nombre) {
         encontrado = true;
      }
      else if (nombre < listap.pacientes[mitad].nombre) {
         fin = mitad - 1;
      }
      else {
         ini = mitad + 1;
      }
   }
   if (encontrado) {
      mitad++;
   }
   else {
      mitad = -1;
   }
   return mitad;
}

void mostrar(int pos, tpaciente paciente) {
   cout<<"_____________________________________________________________"<<endl;
   cout << setw(3) << pos << ": "
        << setw(3) << paciente.historial<<endl;
        cout<< setw(3)<< pos << ": " << paciente.nombre<<endl;
        cout<< setw(3)<< pos << ": " << paciente.telf<<endl;
   cout<<"|____________________________________________________________"<<endl;
       
}

void mostrar(const tListaP &listap) {
   for (int i = 0; i < listap.cont; i++) {
      mostrar(i + 1, listap.pacientes[i]);
   }
}

bool operator>(tpaciente opIzq, tpaciente opDer) {
   return opIzq.nombre > opDer.nombre;
}

bool operator<(tpaciente opIzq, tpaciente opDer) {
   return opIzq.nombre < opDer.nombre;
}

void cargar(tListaP &listap, bool &ok) {
   ifstream archivo;
   ok = true;
   listap.cont = 0;
   archivo.open(bd_pacientes.c_str());
   if (!archivo.is_open()) {
      ok = false;
   }
   else {
      tpaciente reg;
      archivo >> reg.historial;
      while ((listap.cont < MAXI) && (reg.historial != -1)) {
         archivo.get();
         getline(archivo, reg.nombre);
         getline(archivo, reg.telf);
         listap.pacientes[listap.cont] = reg;
         listap.cont++;
         
         archivo >> reg.historial;
      }
      archivo.close();
   }
} 

void guardar(tListaP &listap) {
   ofstream salida;
   salida.open(bd_pacientes.c_str());
   for (int i = 0; i < listap.cont; i++) {
      salida << listap.pacientes[i].historial<<endl;
      salida << listap.pacientes[i].nombre << endl;
      salida << listap.pacientes[i].telf<<endl;
   }
   salida << -1 << endl;
   salida.close();
}

void ordenarPacientes (tListaP& listap, int cantidad ){
   tpaciente temp;
   for(int i=0;i<cantidad;i++)
    {
        for(int j=0;j<cantidad-1;j++)
        {
            if(listap.pacientes[j].nombre>listap.pacientes[j+1].nombre)
            {
            temp=listap.pacientes[j];
            listap.pacientes[j]=listap.pacientes[j+1];
            listap.pacientes[j+1]=temp;
            }
        }
       
    }
}

void pacientes_(){

   tListaP lista;
   bool ok;
   int op, pos;
   
   cargar(lista, ok);
   ordenarPacientes(lista, lista.cont);
   if (!ok) {
      cout << "No se ha podido abrir el archivo!" << endl;
   }
   else {
      do {
         op = menu();
         switch(op){
         case 1: {
            system("cls");
            tpaciente paciente = nuevo();
            insertar(lista, paciente, ok);
            ordenarPacientes(lista, lista.cont);
            mostrar(lista);
            if (!ok) {
               cout << "Error: Lista llena!" << endl;
            }
            break;
         }
         case 2: {
            system("cls");
            cout << "Posicion: ";
            cin >> pos;
            eliminar(lista, pos, ok);
            if (!ok) {
               cout << "Error: Posición inexistente!" << endl;
            }
            break;
         }
         case 3: {
            system("cls");
            cin.sync();
            mostrar(lista);
          }
         }
      } while (op != 0);
      guardar(lista);
   }
}