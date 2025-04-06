#include "ejercicio1.hpp"

using namespace std;

// PIDE Y TESTEA EL TIPEMPO 
int pedirEntero(const string mensaje, int min, int max) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (valor < min || valor > max) {
            cout << "Valor inválido. Debe estar entre " << min << " y " << max << ". Intente de nuevo.\n";
        } else {
            return valor;
        }
    }
}

string pedirPeriodo() {
    string p;
    while (true) {
        cout << "Ingrese el periodo (a.m. / p.m.): ";
        cin >> p;
        if (p == "a.m." || p == "p.m.") {
            return p;
        } else {
            cout << "Periodo inválido. Intente de nuevo.\n";
        }
    }
}

// CONSTRUCTORES:
Hora::Hora(): hora(0), minutos(0), segundos(0), periodo("a.m."){}

Hora::Hora(int h): hora(h), minutos(0), segundos(0), periodo("a.m."){}

Hora::Hora(int h, int m): hora(h), minutos(m), segundos(0), periodo("a.m."){}

Hora::Hora(int h, int m, int s): hora(h), minutos(m), segundos(s), periodo("a.m."){}

Hora::Hora(int h, int m, int s, string p): hora(h), minutos(m), segundos(s), periodo(p){}

// GET'S DE HORAS INDIVIDUALMENTE:
int Hora::getHora() const {
    return hora;
}

int Hora::getMinutos() const {
    return minutos;
}

int Hora::getSegundos() const {
    return segundos;
}

string Hora::getPeriodo() const {
    return periodo;
}

// SET'S DE HORAS INDIVIDUALMENTE:
void Hora::setHora(int h) {
    hora = h;
}

void Hora::setMinutos(int m) {
    minutos = m;
}

void Hora::setSegundos(int s) {
    segundos = s;
}

void Hora::setPeriodo(const std::string& p) {
    periodo = p;
}

// METODOS DE IMPRECION DEL RELOJ:
// Imprecion con a.m/p.m:
void Hora::mostrarHora() {
    cout << setw(2) << setfill('0') << hora << "h : " << setw(2) << setfill('0') << minutos << "m : " << setw(2) << setfill('0') << segundos << "s " << periodo << endl;
}

// Imprecion del reloj en 24 horas:
void Hora::reloj24Horas(){
    if (getPeriodo() == "p.m."){
        cout << setw(2) << setfill('0') << getHora() + 12 << "hs : " << setw(2) << setfill('0') << getMinutos() << "m : " << setw(2) << setfill('0') << getSegundos() << "s " << endl;
    }else {
        cout << setw(2) << setfill('0') << getHora() << "hs : " << setw(2) << setfill('0') << getMinutos() << "m : " << setw(2) << setfill('0') << getSegundos() << "s " << endl;
    }
}