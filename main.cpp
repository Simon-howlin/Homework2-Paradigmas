#include <iostream>
#include <iomanip>  // Para usar setw, setfill
#include "ejercicio1.cpp" // Si tienes la clase Hora en otro archivo

int main() {
    cout << "\nReloj predeterminado: "<< endl;
    // Probar la clase con diferentes constructores
    Hora reloj1;  // Sin parametros, se inicializa en 0h, 0m, 0s a.m.
    reloj1.mostrarHora();

    Hora reloj2(10);  // Solo la hora, los minutos y segundos serán 0
    reloj2.mostrarHora();

    Hora reloj3(10, 30);  // Hora y minutos, segundos seran 0
    reloj3.mostrarHora();

    Hora reloj4(10, 30, 45);  // Hora, minutos y segundos
    reloj4.mostrarHora();

    Hora reloj5(10, 30, 45, "p.m.");  // Hora, minutos, segundos y "p.m."
    reloj5.mostrarHora();

    cout << "\n\nReloj individual: " << endl;
    Hora reloj;
    reloj.setHora(8);
    reloj.setMinutos(30);
    reloj.setSegundos(40);
    reloj.setPeriodo("p.m.");

    cout << "Hora: " << reloj.getHora() << "h" << endl;
    cout << "Minutos: " << reloj.getMinutos() << "m" << endl;
    cout << "Segundos: " << reloj.getSegundos() << "s" << endl;
    cout << "Periodo: " << reloj.getPeriodo() << endl;

    cout << "\nHora completa p.m/a.m: " << endl;
    reloj.mostrarHora();  // Ejemplo: 8h : 30m : 40s p.m.
    cout << "" << endl;

    cout << "\nReloj 24hs: " << endl;
    reloj.reloj24Horas();
    cout << "" << endl;

    return 0;
}