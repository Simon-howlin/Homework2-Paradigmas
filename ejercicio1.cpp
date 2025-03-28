#include <iostream>
#include <iomanip> 
#include "ejercicio1.hpp"

using namespace std;

int Hora::testHora(int h) {
    if (h >= 0 && h <= 12) {
        return h;
    } else {
        return 0; // Si la hora no es válida, se pone por defecto 0
    }
}

int Hora::testMinutos(int m) {
    if (m >= 0 && m < 60) {
        return m;
    } else {
        return 0;  // Si los minutos no son válidos, se pone 0
    }
}

int Hora::testSegundos(int s) {
    if (s >= 0 && s < 60) {
        return s;
    } else {
        return 0;   // Si los segundos no son válidos, se pone 0
    }
}

string Hora::testPeriodo(string p) {
    if (p == "a.m." || p == "p.m.") {
        return p;
    } else {
       return "a.m.";  // Valor por defecto si el periodo no es válido
    }
}

// Constructor sin parámetros (por defecto)
Hora::Hora() {  
    hora = 0;
    minutos = 0;
    segundos = 0;
    periodo = "a.m.";
}

// Constructor con hora 
Hora::Hora(int h) {
    hora = testHora(h);
    minutos = 0;
    segundos = 0;
    periodo = "a.m.";
}

// Constructor con hora y minutos
Hora::Hora(int h, int m) {
    hora = testHora(h);
    minutos = testMinutos(m);
    segundos = 0;
    periodo = "a.m.";
}

// Constructor con hora, minutos y segundos
Hora::Hora(int h, int m, int s) {
    hora = testHora(h);
    minutos = testMinutos(m);
    segundos = testSegundos(s);
    periodo = "a.m.";
}

// Constructor con hora, minutos, segundos y periodo (a.m./p.m.)
Hora::Hora(int h, int m, int s, string p) {
    hora = testHora(h);
    minutos = testMinutos(m);
    segundos = testSegundos(s);
    periodo = testPeriodo(p);
}

void Hora::mostrarHora() {
    cout << setw(2) << setfill('0') << hora << "h : "
            << setw(2) << setfill('0') << minutos << "m : "
            << setw(2) << setfill('0') << segundos << "s "
            << periodo << endl;
}
