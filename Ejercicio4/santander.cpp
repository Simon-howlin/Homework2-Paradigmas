#include "santander.hpp"

Santander::Santander(string titular, double saldo): balance(saldo), titularCuenta(titular) {}

void Santander::depositar(double monto) {
    balance += monto;

    cout << "Se a efectuado el deposito correctamente!\n";
    cout << "El saldo actual es de " << balance << " pesos.\n" << endl;

    return;
}

CajaDeAhorro::CajaDeAhorro(string titular, double saldo): Santander(titular, saldo), contadorInfo(0) {}

bool CajaDeAhorro::retirar(double monto) {
    if (monto > balance) {
        cout << "No se a podido retirar el monto, fondos insuficientes.\n";
        return false;
    } else {
        balance -= monto;
        cout << "Se pudo retirar el monto deseado correctamente!\n";
        cout << "El saldo actual es de " << balance << " pesos.\n" << endl;
        return true;
    }
}

void CajaDeAhorro::mostrarInfo() {
    contadorInfo ++;
    if ((contadorInfo % 3) == 0) {  // tomo modulo 3, porque coincidero que cada vez que le cobro, el contador arranca de nuevo.
        cout << "Se le a cobrado una comision de 20 pesos.\n";

        if (balance < 20) {
            balance -= 20;
            cout << "Su saldo es negativo. Usted debe, " << balance << " pesos.\n";
        } else {
            balance -= 20;
        }
    }

    cout << "Tipo de cuenta: Caja de ahorro" << " | " << "Titular de la cuenta: " << titularCuenta << " | " << "Saldo actual: " << balance << " pesos\n\n";

    return;
}

CuentaCorriente::CuentaCorriente(string titular, double saldo, shared_ptr<CajaDeAhorro> cajaVinculada): Santander(titular, saldo), cajaVinculada(cajaVinculada) {}

bool CuentaCorriente::retirar(double monto) {
    if (monto > balance || monto < 0) {
        if (monto < 0) {
            cout << "[ERROR]: No se puede retirar valor negativo.\n";
            return false;
        }

        monto -= balance;
        if (monto > cajaVinculada->balance ) {
            cout << "No se pudo retirar el monto, fondos insuficientes.\n";
            return false;
        } else {
            balance = 0;
            cajaVinculada->balance -= monto;
            cout << "Se pudo retirar el monto deseado correctamente con ayuda de la caja de ahorro!\n";
            cout << "El saldo actual de la cuenta corriente es de " << balance << " pesos.\n" << endl;
            cout << "El saldo actual de la caja de ahorro es de " << cajaVinculada->balance << " pesos.\n" << endl;
        }
    } else {
        balance -= monto;
        cout << "Se pudo retirar el monto deseado correctamente!\n";
        cout << "El saldo actual es de " << balance << " pesos.\n" << endl;
    }

    return true;
}

void CuentaCorriente::mostrarInfo() {
    cout << "Tipo de cuenta: Corriente" << " | " << "Titular de la cuenta: " << titularCuenta << " | " << "Saldo actual: " << balance << " pesos\n\n";
    
    return;
}