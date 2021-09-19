#include <string>
using namespace std;

#ifndef medicos_h
#define medicos_h
//Declaracion de num max del arreglo y estructuras
const int MAX = 100;

typedef struct {
   string nombre;
   string especialidad;
} tmedico;

typedef struct {
   tmedico medicos[MAX]; 
   int cont;
} tLista;
#endif
//Declaracion el nombre del archivo
const string bd_medicos = "medicos.txt";

//Funcionalidad para obtener datos del nuevo medico con argumento de especialidad segun el departamento
tmedico nuevo(string& cadenaE);
//Menu para acceder a las funcionalidades principales para medicos
int menu2();
//Funcionalidad para insertar el nuevo medico en el arreglo 
void insertar(tLista &lista, tmedico medico, bool &ok);
//Elimina al medico, dado la posicion > 0
void eliminar(tLista &lista, int pos, bool &ok);
//Funcionalidad para buscar un medico dado el nombre, retorna la posicion, -1 si no es encontrado
int buscarMedico(tLista lista, string nombre);
//Formato de presentacion individual para cada medico imprimiendo solamente segun especialidad
void mostrar(int pos, tmedico medico, const string cadenaE);
//Imprime todos los medicos del arreglo definido en estructura
void mostrar(const tLista &lista, const string cadenaE);

bool operator>(tmedico opIzq, tmedico opDer);
bool operator<(tmedico opIzq, tmedico opDer);
//Carga los datos del archivo medicos.txt con centinela "XXX"
void cargar(tLista &lista, bool &ok);
//Guarda los datos modificado en el archivo medicos.txt con centinela -1
void guardar(tLista lista);
//Ordena a los medicos por apellidos
void ordenarMedicos (tLista &lista, int cantidad);
//Se estructura todas las funcionalidades de medicos
void medicos(string &cadenaE);

