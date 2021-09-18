#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "medicos.h"
using namespace std;

tmedico nuevo(string& cadenaE) {
   tmedico medico;
   int op;
   cout<<"FORMATO: APELLIDOS Y NOMBRES"<<endl;
   cout << "Introduce el nombre: ";
   cin.get();
   getline(cin,medico.nombre);
   medico.especialidad=cadenaE;
return medico;
}
int menu2() {
   int op;
   cout<<"\n______________BIENVENIDO AL INGRESO DE MEDICOS_______________"<<endl;
   cout <<"|"<<setw(30)<< "1 - Insertar"<<setw(30)<<"|"  << endl;
   cout <<"|"<<setw(30)<< "2 - Eliminar"<<setw(30)<<"|"  << endl;
   cout <<"|"<<setw(30)<< "3 - Mostrar "<<setw(30)<<"|"  << endl;
   cout <<"|"<<setw(30)<< "0 - Salir   "<<setw(30)<<"|" << endl;
   cout<<"|___________________________________________________________|"<<endl;
   do { 
      cout << "Opcion: ";
      cin >> op;
   } while ((op < 0) || (op > 3));
   return op;
}

void insertar(tLista &lista, tmedico medico, bool &ok) {
   ok = true;
   if (lista.cont == MAX) {
      ok = false;
   }
   else {
      int i = 0;
      while ((i < lista.cont) && (lista.medicos[i] < medico)) {
         i++;
      }
      for (int j = lista.cont; j > i; j--) { 
         lista.medicos[j] = lista.medicos[j - 1];
      }
      lista.medicos[i] = medico;
      lista.cont++;
   }
}

void eliminar(tLista &lista, int pos, bool &ok) { 
   ok = true;
   if ((pos < 1) || (pos > lista.cont)) {
      ok = false;
   }
   else {
      pos--; 
      for (int i = pos + 1; i < lista.cont; i++) { 
         lista.medicos[i - 1] = lista.medicos[i];
      }
      lista.cont--;
   }
}

int buscarMedico(tLista lista, string nombre) {
   int ini = 0, fin = lista.cont - 1, mitad;
   bool encontrado = false;
   while ((ini <= fin) && !encontrado) {
      mitad = (ini + fin) / 2; 
      if (nombre == lista.medicos[mitad].nombre) {
         encontrado = true;
      }
      else if (nombre < lista.medicos[mitad].nombre) {
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

void mostrar(int pos, tmedico medico, const string cadenaE) {
   if (medico.especialidad==cadenaE){
   cout<<"_____________________________________________________________"<<endl;
   cout <<"|"<< setw(3)<<pos << ": "<<"NOMBRE DEL ESPECIALISTA: "<< medico.nombre <<endl;
   cout <<"|"<< setw(3)<<pos << ": "<< "ESPECIALIDAD: "<<medico.especialidad << endl;
   cout<<"|____________________________________________________________"<<endl;
   }

}

void mostrar(const tLista &lista, const string cadenaE) {
   for (int i = 0; i < lista.cont; i++) {
      mostrar(i + 1, lista.medicos[i], cadenaE);
   }
}

bool operator>(tmedico opIzq, tmedico opDer) {
   return opIzq.nombre > opDer.nombre;
}

bool operator<(tmedico opIzq, tmedico opDer) {
   return opIzq.nombre < opDer.nombre;
}

void cargar(tLista &lista, bool &ok) {
   ifstream archivo;
   ok = true;
   lista.cont = 0;
   archivo.open(bd_medicos.c_str());
   if (!archivo.is_open()) {
      ok = false;
   }
   else {
      tmedico reg;
      getline(archivo, reg.nombre);
      while ((lista.cont < MAX) && (reg.nombre!= "XXX")) {
         getline(archivo, reg.especialidad);
         lista.medicos[lista.cont] = reg;
         lista.cont++;
         getline(archivo, reg.nombre);
      }
      archivo.close();
   }
} 

void guardar(tLista lista) {
   ofstream salida;
   salida.open(bd_medicos.c_str());
   for (int i = 0; i < lista.cont; i++) {
      salida << lista.medicos[i].nombre << endl
             << lista.medicos[i].especialidad << endl;
   }
   salida << "XXX" << endl;
   salida.close();
}

void ordenarMedicos (tLista &lista, int cantidad){
   tmedico temp;
   for(int i=0;i<cantidad;i++)
    {
        for(int j=0;j<cantidad-1;j++)
        {
            if(lista.medicos[j].nombre>lista.medicos[j+1].nombre)
            {
            temp=lista.medicos[j];
            lista.medicos[j]=lista.medicos[j+1];
            lista.medicos[j+1]=temp;
            }
        }
       
    }
}

void medicos(string& cadenaE){
   tLista lista;
   bool ok;
   int op, pos;
   cargar(lista, ok);
   ordenarMedicos(lista, lista.cont);
   if (!ok) {
      cout << "No se ha podido abrir el archivo!" << endl;
   }
   else {
      do {
         op = menu2();
         switch(op){
         case 1: {
            system("cls");
            tmedico medico = nuevo(cadenaE);
            insertar(lista, medico, ok);
            mostrar(lista, cadenaE);
            ordenarMedicos(lista, lista.cont);
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
            mostrar(lista, cadenaE);
            /*string nombre;
            cin.sync();
            cout << "Nombre: ";
            cin >> nombre;
            pos = buscarMedico(lista, nombre);
            if (pos == -1) {
               cout << "No se ha encontrado!" << endl;
            }
            else {
               cout << "Encontrado en la posición " << pos << endl;
            }*/
            break;
          }
         }
      } while (op != 0);
      guardar(lista);
   }
}

