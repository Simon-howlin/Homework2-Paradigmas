#ifndef EJERCICIO1_H  // Directivas para evitar inclusión múltiple
#define EJERCICIO1_H

#include <iostream>
#include <string>

using namespace std;

class Hora {
private:
    int hora;
    int minutos;
    int segundos;
    string periodo;  // "a.m." o "p.m."

public:
    // Check de horario correcto
    int testHora(int h);
    int testMinutos(int m);
    int testSegundos(int s);
    string testPeriodo(string p);

    // Constructores
    Hora();  // Constructor sin parámetros
    Hora(int h);  // Constructor con solo la hora
    Hora(int h, int m);  // Constructor con hora y minutos
    Hora(int h, int m, int s);  // Constructor con hora, minutos y segundos
    Hora(int h, int m, int s, string p);  // Constructor con hora, minutos, segundos y periodo

    // devolver individualmente
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
    void mostrarHora();  // Método para mostrar la hora
};

#endif // EJERCICIO1_H