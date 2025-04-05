#include <iostream>
#include <iomanip> 
#include "ejercicio1.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    Hora reloj;
    int opcion;

    do {
        cout << "\n===== MENU DE RELOJ =====\n";
        cout << "1. Establecer hora\n";
        cout << "2. Establecer minutos\n";
        cout << "3. Establecer segundos\n";
        cout << "4. Establecer periodo (a.m./p.m.)\n";
        cout << "5. Mostrar hora en formato 12h\n";
        cout << "6. Mostrar hora en formato 24h\n";
        cout << "7. Mostrar valores individuales (getters)\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                reloj.setHora(pedirEntero("Ingrese la hora (0-12): ", 0, 12));
                break;
            case 2:
                reloj.setMinutos(pedirEntero("Ingrese los minutos (0-59): ", 0, 59));
                break;
            case 3:
                reloj.setSegundos(pedirEntero("Ingrese los segundos (0-59): ", 0, 59));
                break;
            case 4:
                reloj.setPeriodo(pedirPeriodo());
                break;
            case 5:
                cout << "Hora en formato 12h:\n";
                reloj.mostrarHora();
                break;
            case 6:
                cout << "Hora en formato 24h:\n";
                reloj.reloj24Horas();
                break;
            case 7:
                cout << "Lectura individual:\n";
                cout << "Hora: " << reloj.getHora() << "h\n";
                cout << "Minutos: " << reloj.getMinutos() << "m\n";
                cout << "Segundos: " << reloj.getSegundos() << "s\n";
                cout << "Periodo: " << reloj.getPeriodo() << "\n";
                break;
            case 8:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }

    } while (opcion != 8);

    return 0;
}