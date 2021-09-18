#include <string>
using namespace std;

#ifndef cita_h
#define cita_h

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

const string BD = "citas.txt";

void cargar(tAgenda& agenda, bool& ok);

tCitas nuevo(string& cadenaE, tAgenda agenda);

string aMayuscula(string cadena);

int menu3();

void insertar(tAgenda& agenda, tCitas& cita, bool &ok);

void eliminarCitas(tAgenda& agenda, int pos, bool& ok);

void ordenarCitas (tAgenda& agenda, int cantidad);

void agendados(const tAgenda& agenda, const string cadenaE);

void guardar(const tAgenda& agenda);

void citas_(string& cadenaE);