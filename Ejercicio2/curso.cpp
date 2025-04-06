#include "curso.hpp"
#include "estudiante.hpp"

using namespace std;

// CREAR CURSO Y VER SU NOMBRE:
Curso::Curso(string nombreCurso): nombreCurso(nombreCurso){}

string Curso::getNombreCurso() {
    return nombreCurso;
}

// CAPACIDAD MAXIMA DE ESTUDIANTES DEL CURSO ALCANZADA:
bool Curso::cursoCompleto() {
    return estudiantes.size() == 20;
}

// VER SI EL ALUMNO PERTENECE A ESE CURSO (-1 si no pertenece):
int Curso::alumnoPertenece(int legajo) {
    for (size_t i = 0; i < estudiantes.size(); i++) {
        if (estudiantes[i]->getLegajo() == legajo) {
            return i;
        }
    }

    return -1;
}

// AGREGAR / SACAR ESTUDIANTE DE UN CURSO:
bool Curso::agregarEstudiante(shared_ptr<Estudiante> e) {
    if (cursoCompleto()) {
        cout << "[ERROR]: El curso esta completo\n";
        return false;
    }
    else if (alumnoPertenece(e->getLegajo()) != -1) {
        cout << "[ERROR]: El alumno ya pertenece\n";
        return false;
    }

    estudiantes.push_back(e);
    return true;
}

void Curso::sacarEstudiante(int legajo) {
    int posEstudiante = alumnoPertenece(legajo);
    if (posEstudiante != -1) {
        estudiantes.erase(estudiantes.begin() + posEstudiante);
        cout << "Estudiante eliminado del curso.\n";
        return;
    } else {
        cout << "Estudiante no encontrado.\n";
    }
}

vector<shared_ptr<Estudiante>> Curso::getEstudiantes(){
    return estudiantes;
}

// PARA LA IMPRECION DE LA LISTA DE ALUMNOS ORDENADA ALFABETICAMENTE:
void Curso::ordenarEstudiantes() {
    vector<shared_ptr<Estudiante>> sortEstudiantes = estudiantes;
    sort(sortEstudiantes.begin(), sortEstudiantes.end(), [](shared_ptr<Estudiante> a, shared_ptr<Estudiante> b) {
        return a->getNombre() < b->getNombre();
    });

    listarEstudiantes(sortEstudiantes);
}

void Curso::listarEstudiantes(vector<shared_ptr<Estudiante>> estudiantes) const {
    for (const shared_ptr<Estudiante>& e : estudiantes) {
        cout << "Nombre: " << e->getNombre() << " | Legajo: " << e->getLegajo() << " | Promedio: " << e->getPromedio() << endl;
    }
}

// SHALLOW COPY
Curso::Curso(const Curso& otro) {
    nombreCurso = otro.nombreCurso;
    estudiantes = otro.estudiantes;
}