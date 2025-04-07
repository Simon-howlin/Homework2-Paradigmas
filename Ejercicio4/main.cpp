
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <chrono>
#include "santander.hpp"

using namespace std;

int main() {
    string nombreTitular;
    double saldoInicial;

    cout << "Bienvenido al sistema bancario\n";
    cout << "Ingrese el nombre del titular de la cuenta: ";
    getline(cin, nombreTitular);

    cout << "Ingrese el saldo inicial: ";
    cin >> saldoInicial;
    while (saldoInicial < 0){
        if (saldoInicial < 0) {
            cout << "[ERROR]: el saldo inicial no puede ser negativo.\n";
        }

        cout << "Ingrese el saldo inicial: ";
        cin >> saldoInicial;
    }

    // Crear las cuentas
    auto caja = make_shared<CajaDeAhorro>(nombreTitular, saldoInicial);
    CuentaCorriente corriente(nombreTitular, saldoInicial, caja);

    int opcion;
    do {
        cout << "\n===== MENÚ PRINCIPAL =====\n";
        cout << "1. Cuenta Corriente\n";
        cout << "2. Caja de Ahorro\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int subopcion;
                cout << "\n--- Cuenta Corriente ---\n";
                cout << "1. Depositar dinero\n";
                cout << "2. Retirar dinero\n";
                cout << "3. Mostrar información\n";
                cout << "Seleccione una opción: ";
                cin >> subopcion;

                if (subopcion == 1) {
                    double monto;
                    cout << "Ingrese el monto a depositar: ";
                    cin >> monto;
                    while(monto < 0){
                        if(monto < 0){
                            cout << "[ERROR]: no se puede depositar un monto negativo.\n";
                        }
                        cout << "Ingrese el monto a depositar: ";
                        cin >> monto;
                    }
                    corriente.depositar(monto);
                } else if (subopcion == 2) {
                    double monto;
                    cout << "Ingrese el monto a retirar: ";
                    cin >> monto;
                    while (monto < 0) {
                        if (monto < 0) {
                            cout << "[ERROR]: No se puede retirar un monto negativo.\n";
                        }

                        cout << "Ingrese el monto a retirar: ";
                        cin >> monto;
                    }
                    corriente.retirar(monto);
                } else if (subopcion == 3) {
                    corriente.mostrarInfo();
                } else {
                    cout << "Opción inválida.\n";
                }
                break;
            }

            case 2: {
                int subopcion;
                cout << "\n--- Caja de Ahorro ---\n";
                cout << "1. Depositar dinero\n";
                cout << "2. Retirar dinero\n";
                cout << "3. Mostrar información\n";
                cout << "Seleccione una opción: ";
                cin >> subopcion;

                if (subopcion == 1) {
                    double monto;
                    cout << "Ingrese el monto a depositar: ";
                    cin >> monto;
                    while(monto < 0){
                        if(monto < 0){
                            cout << "[ERROR]: no se puede depositar un monto negativo.\n";
                        }

                        cout << "Ingrese el monto a depositar: ";
                        cin >> monto;
                    }
                    caja->depositar(monto);
                } else if (subopcion == 2) {
                    double monto;
                    cout << "Ingrese el monto a retirar: ";
                    cin >> monto;
                    while (monto < 0) {
                        if (monto < 0) {
                            cout << "[ERROR]: No se puede retirar un monto negativo.\n";
                        }

                        cout << "Ingrese el monto a retirar: ";
                        cin >> monto;
                    }
                    caja->retirar(monto);
                } else if (subopcion == 3) {
                    caja->mostrarInfo();
                } else {
                    cout << "Opción inválida.\n";
                }
                break;
            }

            case 3:
                cout << "Cerrando cuenta bancaria...\n";
                this_thread::sleep_for(chrono::seconds(2));
                break;

            default:
                cout << "Opción inválida.\n";
                break;
        }

    } while (opcion != 3);

    return 0;
}
