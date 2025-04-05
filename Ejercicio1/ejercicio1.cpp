#include <iostream>
#include <iomanip> 
#include "ejercicio1.hpp"

using namespace std;

// TEST'S DE HORAS CORRECTAS:
int Hora::testHora(int h) {
    if (h >= 0 && h <= 12) {
        return h;
    } else {
        return 0; // Si la hora no es valida, se pone por defecto 0
    }
}

int Hora::testMinutos(int m) {
    if (m >= 0 && m < 60) {
        return m;
    } else {
        return 0;  // Si los minutos no son validos, se pone 0
    }
}

int Hora::testSegundos(int s) {
    if (s >= 0 && s < 60) {
        return s;
    } else {
        return 0;   // Si los segundos no son validos, se pone 0
    }
}

string Hora::testPeriodo(string p) {
    if (p == "a.m." || p == "p.m.") {
        return p;
    } else {
       return "a.m.";  // Valor por defecto si el periodo no es valido
    }
}

// CONSTRUCTORES:
Hora::Hora(): hora(0), minutos(0), segundos(0), periodo("a.m."){}

Hora::Hora(int h): hora(testHora(h)), minutos(0), segundos(0), periodo("a.m."){}

Hora::Hora(int h, int m): hora(testHora(h)), minutos(testMinutos(m)), segundos(0), periodo("a.m."){}

Hora::Hora(int h, int m, int s): hora(testHora(h)), minutos(testMinutos(m)), segundos(testSegundos(s)), periodo("a.m."){}

Hora::Hora(int h, int m, int s, string p): hora(testHora(h)), minutos(testMinutos(m)), segundos(testSegundos(s)), periodo(testPeriodo(p)){}

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
    hora = testHora(h);
}

void Hora::setMinutos(int m) {
    minutos = testMinutos(m);
}

void Hora::setSegundos(int s) {
    segundos = testSegundos(s);
}

void Hora::setPeriodo(const std::string& p) {
    periodo = testPeriodo(p);
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