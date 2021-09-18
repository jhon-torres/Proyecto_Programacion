#include <string>
using namespace std;

#ifndef pacientes_h
#define pacientes_h

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

const string bd_pacientes = "pacientes.txt";

void mostrar(int pos, tpaciente paciente);

void mostrar(const tListaP &listap);

bool operator>(tpaciente opIzq, tpaciente opDer);

bool operator<(tpaciente opIzq, tpaciente opDer);

tpaciente nuevo();

void insertar(tListaP &listap, tpaciente paciente, bool &ok);

void eliminar(tListaP &listap, int pos, bool &ok);

int buscarPaciente(tListaP &listap, string nombre);

void cargar(tListaP &listap, bool &ok);

void guardar(tListaP &listap);

void ordenarPacientes (tListaP& listap, int cantidad );

void pacientes_();