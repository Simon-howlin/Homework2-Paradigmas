#ifndef SANTANDER_HPP
#define SANTANDER_HPP

#include <iostream>
#include <string>

using namespace std;

class Santander {
protected:
    double balance;
    string titularCuenta;

public:
    Santander(string titular, double saldo);
    void depositar(double monto);
    virtual bool retirar(double monto) = 0;
    virtual void mostrarInfo() = 0;
    virtual ~Santander() = default;
};

class CajaDeAhorro: public Santander {
private:
    int contadorInfo;

public:
    CajaDeAhorro(string titular, double saldo);
    bool retirar(double monto) override;
    void mostrarInfo() override;
    friend class CuentaCorriente;
};

class CuentaCorriente: public Santander {
private:
    shared_ptr<CajaDeAhorro> cajaVinculada;

public:
    CuentaCorriente(string titular, double saldo, shared_ptr<CajaDeAhorro> cajaVinculada);
    bool retirar(double monto) override;
    void mostrarInfo() override;
};

#endif