#include <iostream>
#include <iomanip> 
#include <thread>
#include <chrono>
#include "ejercicio1.hpp"

using namespace std;

void presionarEnter() {
    cout << "Presione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

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
        cout << "8. Crear reloj con constructor personalizado\n";
        cout << "9. Salir\n";
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
                presionarEnter();
                break;
            case 6:
                cout << "Hora en formato 24h:\n";
                reloj.reloj24Horas();
                presionarEnter();
                break;
            case 7:
                cout << "Lectura individual:\n";
                cout << "Hora: " << reloj.getHora() << "h\n";
                cout << "Minutos: " << reloj.getMinutos() << "m\n";
                cout << "Segundos: " << reloj.getSegundos() << "s\n";
                cout << "Periodo: " << reloj.getPeriodo() << "\n";
                presionarEnter();
                break;
            case 8: {
                int h, m, s;
                string p;
                int tipo;

                do {
                    cout << "\n===== Menu del constructor =====\n";
                    cout << "1. Solo hora\n";
                    cout << "2. Hora y minutos\n";
                    cout << "3. Hora, minutos y segundos\n";
                    cout << "4. Hora, minutos, segundos y periodo (a.m./p.m.)\n";
                    cout << "5. Volver al menu principal\n";
                    cout << "Seleccione que dato quiere ingresar: ";
                    cin >> tipo;

                    switch (tipo) {
                        case 1: {
                            h = pedirEntero("Ingrese la hora (0-12): ", 0, 12);
                            Hora nuevoReloj(h);
                            cout << "Reloj creado: ";
                            nuevoReloj.mostrarHora();
                            cout << "\n";
                            presionarEnter();
                            break;
                        }
                        case 2: {
                            h = pedirEntero("Ingrese la hora (0-12): ", 0, 12);
                            m = pedirEntero("Ingrese los minutos (0-59): ", 0, 59);
                            Hora nuevoReloj(h, m);
                            cout << "Reloj creado: ";
                            nuevoReloj.mostrarHora();
                            cout << "\n";
                            presionarEnter();
                            break;
                        }
                        case 3: {
                            h = pedirEntero("Ingrese la hora (0-12): ", 0, 12);
                            m = pedirEntero("Ingrese los minutos (0-59): ", 0, 59);
                            s = pedirEntero("Ingrese los segundos (0-59): ", 0, 59);
                            Hora nuevoReloj(h, m, s);
                            cout << "Reloj creado: ";
                            nuevoReloj.mostrarHora();
                            cout << "\n";
                            presionarEnter();
                            break;
                        }
                        case 4: {
                            h = pedirEntero("Ingrese la hora (0-12): ", 0, 12);
                            m = pedirEntero("Ingrese los minutos (0-59): ", 0, 59);
                            s = pedirEntero("Ingrese los segundos (0-59): ", 0, 59);
                            p = pedirPeriodo();
                            Hora nuevoReloj(h, m, s, p);
                            cout << "Reloj creado: ";
                            nuevoReloj.mostrarHora();
                            cout << "\n";
                            presionarEnter();
                            break;
                        }
                        case 5: {
                            cout << "Volviendo al menu principal...\n";
                            this_thread::sleep_for(std::chrono::seconds(2));
                            break;
                        }
                        default:
                            cout << "Opción inválida.\n";
                            break;
                    }
                } while (tipo != 5);
                
                break;
            }
            case 9:
                cout << "Saliendo del programa...\n";
                this_thread::sleep_for(std::chrono::seconds(2));
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }

    } while (opcion != 9);

    return 0;
}