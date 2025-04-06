#ifndef NUMERO_HPP
#define NUMERO_HPP

#include <string>
#include <memory>
#include <sstream>
#include <stdexcept>

using namespace std;

class Numero {
public:
    virtual shared_ptr<Numero> suma(const Numero& valorB) const = 0;
    virtual shared_ptr<Numero> resta(const Numero& valorB) const = 0;
    virtual shared_ptr<Numero> multiplicacion(const Numero& valorB) const = 0;
    virtual string toString() const = 0;
    virtual ~Numero() = default;
};

#endif