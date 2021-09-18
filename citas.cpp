#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "citas.h"
using namespace std;

void cargar(tAgenda& agenda, bool& ok) {
    ok = true;
   ifstream archivo;
   agenda.contador = 0;
   archivo.open(BD.c_str());
   if (!archivo.is_open()) {
      ok = false;
   }
   else {
      tCitas citas;
      archivo >> citas.d;
      while ((agenda.contador < N) && (citas.d != -1)) {
         archivo >> citas.m;
         archivo >> citas.a;
         archivo >> citas.h;
         archivo >> citas.min;
         citas.fecha=(citas.a*100000000) + (citas.m*1000000) + (citas.d*10000)+ (citas.h*100) + citas.min; //tranforma la fecha en un numero
         archivo.get();
         getline(archivo, citas.asunto);
         getline(archivo, citas.nombre_medico);
         getline(archivo, citas.nombre_paciente);
         agenda.elementos[agenda.contador] = citas;
         agenda.contador++;
         archivo >> citas.d;
      }
      archivo.close();
   }
}

tCitas nuevo(string& cadenaE, tAgenda agenda) {
   tCitas cita;
   int rep=3;
   cin.get();
   while (rep!=0){
      cout<<"Ingrese el dia: ";
      cin>>cita.d;
      cout<<"Ingrese el mes: ";
      cin>>cita.m;
      cout<<"Ingrese el anio: ";
      cin>>cita.a;
      cout<<"Ingrese la hora: ";
      cin>>cita.h;
      cout<<"Ingrese los minutos: ";
      cin>>cita.min;
      cin.get();
      cita.fecha=(cita.a*100000000) + (cita.m*1000000) + (cita.d*10000)+ (cita.h*100) + cita.min; //tranforma la fecha en un numero
      cout<<"Nombre del medico: ";
      getline(cin, cita.nombre_medico);
      rep=0;
      for (int i=0; i<agenda.contador; i++){
         if((cita.fecha==agenda.elementos[i].fecha) && (aMayuscula(cita.nombre_medico)==aMayuscula(agenda.elementos[i].nombre_medico))){
            rep+=1;
         }
      }      
      if (rep!=0){
         cout<<"\t\t___________________________________________________________"<<endl;
         cout<<"\t\t        ** El medico ya tiene una cita esa fecha **"<<endl;
         cout<<"\t\t           ** Ingresa otra fecha u otro medico **"<<endl;
         cout<<"\t\t___________________________________________________________"<<endl;

      } 
      else{
         cita.asunto=cadenaE;
         cout<<"Nombre del paciente: ";
         getline(cin, cita.nombre_paciente);
         cin.sync();
      }
   }
return cita;
}

string aMayuscula(string cadena) {
  for (int i = 0; i < cadena.length(); i++) cadena[i] = toupper(cadena[i]);
  return cadena;
}

int menu3() {
	int op;
	do {
      cout << "\t\t__________________________________" << endl;
		cout << "\t\t|1 - Ingresar una nueva cita     |" << endl;
		cout << "\t\t|2 - Eliminar una cita           |" << endl;
		cout << "\t\t|3 - Mostrar Agenda              |" << endl;
		cout << "\t\t|0 - Salir                       |" << endl;
      cout << "\t\t|________________________________|" << endl;
		cout << "Opcion: ";
		cin >> op;
	} while ((op < 0) || (op > 3));
	return op;
}

void insertar(tAgenda& agenda, tCitas& cita, bool &ok){
   ok = true;
	if (agenda.contador == N) {
		ok = false;
	}
	else {
		agenda.elementos[agenda.contador] = cita;
		agenda.contador++;
	}
}

void eliminarCitas(tAgenda& agenda, bool& ok){
   int pos{0};
   cout<<"Ingrese la posicion que desea eliminar: ";
   cin>>pos;
   pos-=1; //transforma a la posicion de arreglo
	if ((pos < 0) || (pos > agenda.contador - 1)) {
		ok = false; // no existente
	}
	else {
		ok = true;
		for (int i = pos; i < agenda.contador - 1; i++) {
			agenda.elementos[i] = agenda.elementos[i + 1];
		}
		agenda.contador--;
	}
}

void ordenarCitas (tAgenda& agenda, int cantidad){
   tCitas temp;
   for (int i=0; i<cantidad; i++){
      for (int j=0; j<cantidad-1; j++){
         if (agenda.elementos[j].fecha>agenda.elementos[j+1].fecha){
            temp=agenda.elementos[j];
            agenda.elementos[j]=agenda.elementos[j+1];
            agenda.elementos[j+1]=temp;
         }
      }
   }
}

void agendados(const tAgenda& agenda, const string cadenaE){
   system("cls");
   cout << setw(3) << right<<" N";
   cout << setw(19) << left << "  Fecha";
   cout << setw(31) << left << "Asunto";
   cout << setw(31) << left << "Medico";
   cout << setw(30) << left << "Paciente"<<endl<<endl;
   for (int i = 0; i < agenda.contador; i++) {
      if (agenda.elementos[i].asunto==cadenaE){
         cout << setw(3) << right << i + 1 << ": ";
         cout << setw(2) << right << agenda.elementos[i].d<<"/";
         cout << setw(2) << right << agenda.elementos[i].m<<"/";
         cout << setw(3) << right << agenda.elementos[i].a<<" ";
         cout << setw(2) << right << agenda.elementos[i].h<<":";
         cout << setw(2) << right << agenda.elementos[i].min<<" ";
         cout << setw(30) << left << agenda.elementos[i].asunto<<" ";
         cout << setw(30) << left << agenda.elementos[i].nombre_medico<<" ";
         cout << setw(30) << left << agenda.elementos[i].nombre_paciente;
         cout << endl;
      }
	}
}

void guardar(const tAgenda& agenda){
   ofstream salida;
   salida.open(BD.c_str());
   for (int i = 0; i < agenda.contador; i++) {
      salida << agenda.elementos[i].d << " "
             << agenda.elementos[i].m << " "
             << agenda.elementos[i].a << " "
             << agenda.elementos[i].h << " "
             << agenda.elementos[i].min << endl
             << agenda.elementos[i].asunto << endl
             << agenda.elementos[i].nombre_medico << endl
             << agenda.elementos[i].nombre_paciente << endl;
   }
   salida << -1 << endl;
   salida.close();
}

void citas_(string& cadenaE){
   tAgenda agenda;
   bool exito;
	int op, pos;
   cargar(agenda, exito);
   ordenarCitas(agenda, agenda.contador);
   if (!exito) {
      cout << "No se ha podido cargar la lista!" << endl;
   }
   else {
      do {
         op = menu3();
         switch (op)
         {
         case 1:{
            tCitas cita = nuevo(cadenaE, agenda);
            insertar(agenda, cita, exito);
            if (!exito) {
					cout << "Lista llena: imposible insertar" << endl;
				}
            ordenarCitas(agenda, agenda.contador);
            break;
         }
         case 2:
            eliminarCitas(agenda, exito);
            if (!exito) {
					cout << "Elemento inexistente!" << endl;
				}
            break;
            case 3:
            agendados(agenda, cadenaE);
            break;
         }
      } while (op != 0);
      guardar(agenda);
   }
}