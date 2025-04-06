#include "numType.hpp"

using namespace std;

// NUMERO ENTERO:

Entero::Entero(int v) : valor(v) {}

shared_ptr<Numero> Entero::suma(const Numero& valorB) const {
    const Entero& e = dynamic_cast<const Entero&>(valorB);
    return make_shared<Entero>(valor + e.valor);
}

shared_ptr<Numero> Entero::resta(const Numero& valorB) const {
    const Entero& e = dynamic_cast<const Entero&>(valorB);
    return make_shared<Entero>(valor - e.valor);
}

shared_ptr<Numero> Entero::multiplicacion(const Numero& valorB) const {
    const Entero& e = dynamic_cast<const Entero&>(valorB);
    return make_shared<Entero>(valor * e.valor);
}

string Entero::toString() const {
    return to_string(valor);
}


// NUMERO REAL:

Real::Real(double v) : valor(v) {}

shared_ptr<Numero> Real::suma(const Numero& valorB) const {
    const Real& r = dynamic_cast<const Real&>(valorB);
    return make_shared<Real>(valor + r.valor);
}

shared_ptr<Numero> Real::resta(const Numero& valorB) const {
    const Real& r = dynamic_cast<const Real&>(valorB);
    return make_shared<Real>(valor - r.valor);
}

shared_ptr<Numero> Real::multiplicacion(const Numero& valorB) const {
    const Real& r = dynamic_cast<const Real&>(valorB);
    return make_shared<Real>(valor * r.valor);
}

string Real::toString() const {
    return to_string(valor);
}


// NUMERO COMPLEJO:

Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

shared_ptr<Numero> Complejo::suma(const Numero& valorB) const {
    const Complejo& c = dynamic_cast<const Complejo&>(valorB);
    double resultadoReal = real - c.real;
    double resultadoImag = imaginario - c.imaginario;
    return make_shared<Complejo>(resultadoReal, resultadoImag);
}

shared_ptr<Numero> Complejo::resta(const Numero& valorB) const {
    const Complejo& c = dynamic_cast<const Complejo&>(valorB);
    double resultadoReal = real - c.real;
    double resultadoImag = imaginario - c.imaginario;
    return make_shared<Complejo>(resultadoReal, resultadoImag);
}

shared_ptr<Numero> Complejo::multiplicacion(const Numero& valorB) const {
    const Complejo& c = dynamic_cast<const Complejo&>(valorB);
    double resultadoReal = real * c.real - imaginario * c.imaginario;
    double resultadoImag = real * c.imaginario + imaginario * c.real;
    return make_shared<Complejo>(resultadoReal, resultadoImag);
}

string Complejo::toString() const {
    return "Parte Real: " + to_string(real) + "\nParte Imaginaria:" + to_string(imaginario);
}