#include <iostream>
#include <memory>
#include "numType.hpp"
#include "numero.hpp"

using namespace std;

int main() {
    // ===== PRUEBA CON ENTEROS =====
    cout << "===== PRUEBA CON ENTEROS =====\n";
    shared_ptr<Numero> e1 = make_shared<Entero>(5);
    shared_ptr<Numero> e2 = make_shared<Entero>(3);

    cout << "Entero 1: " << e1->toString() << endl;
    cout << "Entero 2: " << e2->toString() << endl;
    cout << "\n";
    cout << "Suma: " << e1->suma(*e2)->toString() << endl;
    cout << "\n";
    cout << "Resta: " << e1->resta(*e2)->toString() << endl;
    cout << "\n";
    cout << "Multiplicación: " << e1->multiplicacion(*e2)->toString() << endl;

    cout << "\n";

    // ===== PRUEBA CON REALES =====
    cout << "===== PRUEBA CON REALES =====\n";
    shared_ptr<Numero> r1 = make_shared<Real>(4.5);
    shared_ptr<Numero> r2 = make_shared<Real>(2.2);

    cout << "Real 1: " << r1->toString() << endl;
    cout << "Real 2: " << r2->toString() << endl;
    cout << "\n";
    cout << "Suma: " << r1->suma(*r2)->toString() << endl;
    cout << "\n";
    cout << "Resta: " << r1->resta(*r2)->toString() << endl;
    cout << "\n";
    cout << "Multiplicación: " << r1->multiplicacion(*r2)->toString() << endl;

    cout << "\n";

    // ===== PRUEBA CON COMPLEJOS =====
    cout << "===== PRUEBA CON COMPLEJOS =====\n";
    shared_ptr<Numero> c1 = make_shared<Complejo>(3.0, 2.0);
    shared_ptr<Numero> c2 = make_shared<Complejo>(1.0, 4.0);

    cout << "Complejo 1:\n" << c1->toString() << endl;
    cout << "Complejo 2:\n" << c2->toString() << endl;
    cout << "\n";
    cout << "Suma:\n" << c1->suma(*c2)->toString() << endl;
    cout << "\n";
    cout << "Resta:\n" << c1->resta(*c2)->toString() << endl;
    cout << "\n";
    cout << "Multiplicación:\n" << c1->multiplicacion(*c2)->toString() << endl;

    cout << "\n";
    return 0;
}