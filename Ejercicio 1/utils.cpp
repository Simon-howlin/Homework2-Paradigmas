#include <iostream>
#include <limits>
#include "utils.hpp"

using namespace std;

// Funcion para pedir un numero dentro de un rango
int pedirEntero(const string mensaje, int min, int max) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail() || valor < min || valor > max) {
            cin.clear(); // Limpia error de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta input invalido
            cout << "Valor inválido. Debe estar entre " << min << " y " << max << ". Intente de nuevo.\n";
        } else {
            return valor;
        }
    }
}

// Funcion para pedir "a.m." o "p.m."
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