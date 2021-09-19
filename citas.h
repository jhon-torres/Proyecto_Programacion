#include <string>
using namespace std;

#ifndef cita_h
#define cita_h
//Declaracion de num max del arreglo y estructuras
const int N = 100;

typedef struct { 
    int d;
    int m;
    int a;
    int h;
    int min;
    long long int fecha;
    string asunto;
    string nombre_medico;
    string nombre_paciente;
} tCitas;

typedef struct {
	tCitas elementos[N];
	int contador;
}tAgenda;
#endif
//Declaracion el nombre del archivo
const string BD = "citas.txt";

//Carga los datos del archivo citas.txt con centinela -1
void cargar(tAgenda& agenda, bool& ok);
//Funcionalidad para obtener datos del nueva cita
tCitas nuevo(string& cadenaE, tAgenda agenda);
//Funcion para convertir una cadena a mayusculas
string aMayuscula(string cadena);
//Menu para acceder a las funcionalidades principales para citas
int menu3();
//Funcionalidad para insertar el nueva cita en el arreglo 
void insertar(tAgenda& agenda, tCitas& cita, bool &ok);
//Elimina la cita, dado la posicion > 0
void eliminarCitas(tAgenda& agenda, int pos, bool& ok);
//Ordena a las citas por fechas
void ordenarCitas (tAgenda& agenda, int cantidad);
//Imprimiendo solamente las citas segun la seccion
void agendados(const tAgenda& agenda, const string cadenaE);
//Guarda los datos modificado en el archivo citas.txt con centinela -1
void guardar(const tAgenda& agenda);
//Se estructura todas las funcionalidades de citas
void citas_(string& cadenaE);