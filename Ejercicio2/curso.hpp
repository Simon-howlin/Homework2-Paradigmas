#ifndef CURSO_HPP
#define CURSO_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory> 

using namespace std;

class Estudiante;
class Curso {
private:
    string nombreCurso;
    vector<shared_ptr<Estudiante>> estudiantes;

public:
    Curso(string nombreCurso);

    string getNombreCurso();
    int alumnoPertenece(int legajo);
    bool agregarEstudiante(shared_ptr<Estudiante> e);
    void sacarEstudiante(int legajo);
    vector<shared_ptr<Estudiante>> getEstudiantes();

    bool cursoCompleto();
    void ordenarEstudiantes();
    void listarEstudiantes(vector<shared_ptr<Estudiante>> sortEstudiantes) const;

    Curso(const Curso& otro);    // Constructor de copia
};  

#endif