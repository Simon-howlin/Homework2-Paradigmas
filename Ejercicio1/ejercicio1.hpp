#ifndef EJERCICIO1_HPP  // Directivas para evitar inclusion multiple
#define EJERCICIO1_HPP

#include <iostream>
#include <iomanip> 
#include <limits>
#include <string>

using namespace std;

class Hora {
private:
    int hora;
    int minutos;
    int segundos;
    string periodo;  // "a.m." o "p.m."

public:

    // Constructores
    Hora();  // Constructor sin parametros
    Hora(int h);  // Constructor con solo la hora
    Hora(int h, int m);  // Constructor con hora y minutos
    Hora(int h, int m, int s);  // Constructor con hora, minutos y segundos
    Hora(int h, int m, int s, string p);  // Constructor con hora, minutos, segundos y periodo

    // Devolver individualmente
    int getHora() const;
    int getMinutos() const;
    int getSegundos() const;
    string getPeriodo() const;

    // Modificar individualmente
    void setHora(int h);
    void setMinutos(int m);
    void setSegundos(int s);
    void setPeriodo(const string& p);

    // Métodos
    void mostrarHora();  // Metodo para mostrar la hora
    void reloj24Horas(); // Metodo para mosterar la hora en 24hs
};

// Check de horario correcto y pedir
int pedirEntero(const string mensaje, int min, int max);
string pedirPeriodo();

#endif // EJERCICIO1_H