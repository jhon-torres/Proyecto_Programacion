#include <string>
using namespace std;

#ifndef pacientes_h
#define pacientes_h
//Declaracion de num max del arreglo y estructuras
const int MAXI = 100;

typedef struct {
   int historial;
   string nombre;
   string telf;
} tpaciente;

typedef struct {
   tpaciente pacientes[MAXI]; 
   int cont;
} tListaP;
#endif
//Declaracion el nombre del archivo
const string bd_pacientes = "pacientes.txt";

//Funcionalidad para obtener datos del nuevo paciente
tpaciente nuevo();
//Menu para acceder a las funcionalidades principales para pacientes
int menu();
//Funcionalidad para insertar el nuevo paciente en el arreglo 
void insertar(tListaP &listap, tpaciente paciente, bool &ok);
//Elimina al paciente, dado la posicion > 0
void eliminar(tListaP &listap, int pos, bool &ok);
//Funcionalidad para buscar un paciente dado el nombre, retorna la posicion, -1 si no es encontrado
int buscarPaciente(tListaP &listap, string nombre);
//Formato de presentacion individual para cada paciente
void mostrar(int pos, tpaciente paciente);
//Imprime todos los pacientes del arreglo definido en estructura
void mostrar(const tListaP &listap);

bool operator>(tpaciente opIzq, tpaciente opDer);
bool operator<(tpaciente opIzq, tpaciente opDer);

//Carga los datos del archivo pacientes.txt con centinela -1
void cargar(tListaP &listap, bool &ok);
//Guarda los datos modificado en el archivo pacientes.txt con centinela -1
void guardar(tListaP &listap);
//Ordena a los pacientes por apellidos
void ordenarPacientes (tListaP& listap, int cantidad );
//Se estructura todas las funcionalidades de pacientes
void pacientes_();