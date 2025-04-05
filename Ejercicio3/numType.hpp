#ifndef NUMTYPES_HPP
#define NUMTYPES_HPP

#include "numero.hpp"

using namespace std;

class Entero : public Numero {
private:
    int valor; 

public:
    Entero(int v);
    shared_ptr<Numero> suma(const Numero& valorB) const override;
    shared_ptr<Numero> resta(const Numero& valorB) const override;
    shared_ptr<Numero> multiplicacion(const Numero& valorB) const override;
    string toString() const override;
};

class Real : public Numero {
private:
    double valor;

public:
    Real(double v);
    shared_ptr<Numero> suma(const Numero& valorB) const override;
    shared_ptr<Numero> resta(const Numero& valorB) const override;
    shared_ptr<Numero> multiplicacion(const Numero& valorB) const override;
    string toString() const override;
};

class Complejo : public Numero {
private:
    double real;
    double imaginario;

public:
    Complejo(double r, double i);
    shared_ptr<Numero> suma(const Numero& valorB) const override;
    shared_ptr<Numero> resta(const Numero& valorB) const override;
    shared_ptr<Numero> multiplicacion(const Numero& valorB) const override;
    string toString() const override;
};

#endif