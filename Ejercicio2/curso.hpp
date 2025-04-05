#ifndef CURSO_HPP
#define CURSO_HPP

#include <vector>
#include <string>

using namespace std;

class Estudiante;
class Curso {
private:
    string nombreCurso;
    vector<Estudiante*> estudiantes;

public:
    Curso(string nombreCurso);

    string getNombreCurso();
    int alumnoPertenece(int legajo);
    void agregarEstudiante(Estudiante* e);
    void sacarEstudiante(int legajo);

    bool cursoCompleto();
    void ordenarEstudiantes();
    void listarEstudiantes() const;

    Curso(const Curso& otro);    // Constructor de copia
    //Curso& operator=(const Curso& otro);  // Operador de asignación  --> EN DUDA, SI ES NECESARIO O SOLO CON UN DEEPCOPY  DESDE 0 VA.
    ~Curso();         // Destructor
};  

#endif