#include <string>
using namespace std;

#ifndef medicos_h
#define medicos_h

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

const string bd_medicos = "medicos.txt";

void mostrar(int pos, tmedico medico, const string cadenaE);

void mostrar(const tLista &lista, const string cadenaE);

bool operator>(tmedico opIzq, tmedico opDer);

bool operator<(tmedico opIzq, tmedico opDer);

tmedico nuevo(string& cadenaE);

void insertar(tLista &lista, tmedico medico, bool &ok);

void eliminar(tLista &lista, int pos, bool &ok);

int buscarMedico(tLista lista, string nombre);

void cargar(tLista &lista, bool &ok);

void guardar(tLista lista);

void ordenarMedicos (tLista &lista, int cantidad);

void medicos(string &cadenaE);

