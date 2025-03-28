#include <iostream>
#include <iomanip>  // Para usar setw, setfill
#include "ejercicio1.cpp" // Si tienes la clase Hora en otro archivo

int main() {
    // Probar la clase con diferentes constructores
    Hora hora1;  // Sin parámetros, se inicializa en 0h, 0m, 0s a.m.
    hora1.mostrarHora();

    Hora hora2(10);  // Solo la hora, los minutos y segundos serán 0
    hora2.mostrarHora();

    Hora hora3(10, 30);  // Hora y minutos, segundos serán 0
    hora3.mostrarHora();

    Hora hora4(10, 30, 45);  // Hora, minutos y segundos
    hora4.mostrarHora();

    Hora hora5(10, 30, 45, "p.m.");  // Hora, minutos, segundos y "p.m."
    hora5.mostrarHora();

    return 0;
}