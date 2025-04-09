#include<iostream>
#include"Vector.h"

using namespace std;

class Estudiante {
    int id;
    int numNotas;
    Vector<float> notas;
    int ordAtrib;
    bool ordAsc;

public:
    Estudiante() {
        id = -1;
        numNotas = 3;
        ordAtrib = -1;
        ordAsc = true;
    }

    Estudiante(int i, int nN) {
        id = i;
        numNotas = nN;
        ordAtrib = -1;
        ordAsc = true;
    }

    float getNota(int i) {
        return notas[i];
    }

    void addNota(float n) {
        notas.add(n);
    }

    int getID() {
        return id;
    }

    void setOrdOrderAsc() {
        ordAsc = true;
    }

    void setOrdOrderDesc() {
        ordAsc = false;
    }

    void setOrdAtrib(int i) {
        ordAtrib = i;
    }

    float promedio() {
        float sum = 0.0f;
        for (int i = 0; i < numNotas; i++) {
            sum += notas[i];
        }
        return sum / numNotas;
    }

    string to_string() {
        string s = std::to_string(id) + " - ";
        for (int i = 0; i < numNotas; i++) {
            s += std::to_string(notas[i]) + ", ";
        }
        s += "Promedio: " + std::to_string(promedio());
        return s;
    }

    int compareTo(Estudiante e) {
        float thisVal, eVal;
        if (ordAtrib == -1) {
            thisVal = id;
            eVal = e.id;
        } else {
            thisVal = promedio();
            eVal = e.promedio();
        }
        if (ordAsc) {
            if (thisVal < eVal) return -1;
            else if (thisVal > eVal) return 1;
            else return 0;
        } else {
            if (thisVal > eVal) return -1;
            else if (thisVal < eVal) return 1;
            else return 0;
        }
    }

    bool operator>(Estudiante& other) {
        if (this != &other) {
            if (compareTo(other) == 1) {
                return true;
            }
        }
        return false;
    }

    bool operator>=(Estudiante& other) {
        if (this != &other) {
            if (compareTo(other) >= 0) {
                return true;
            }
        }
        else {
            return true;
        }
        return false;
    }

    bool operator<(Estudiante& other) {
        if (this != &other) {
            if (compareTo(other) == -1) {
                return true;
            }
        }
        return false;
    }

    bool operator<=(Estudiante& other) {
        if (this != &other) {
            if (compareTo(other) <= 0) {
                return true;
            }
        }
        else {
            return true;
        }
        return false;
    }

    bool operator==(Estudiante& other) {
        if (this != &other) {
            if (compareTo(other) == 0) {
                return true;
            }
        }
        else {
            return true;
        }
        return false;
    }

    bool operator!=(Estudiante& other) {
        if (this != &other) {
            if (compareTo(other) != 0) {
                return true;
            }
        }
        return false;
    }

    Estudiante& operator=(Estudiante other) {
        this->id = other.id;
        this->numNotas = other.numNotas;
        this->ordAtrib = other.ordAtrib;
        this->ordAsc = other.ordAsc;
        this->notas.clear();
        for (int i = 0; i < other.numNotas; i++) {
            this->notas.add(other.notas[i]);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, Estudiante& b) {
        return os << b.to_string();
    }
};

class Curso {
    int id;
    Vector<Estudiante> estudiantes;
    int numNotas;
    int numEstudiantes;

public:
    Curso() {
        id = -1;
        numNotas = 0;
        numEstudiantes = 0;
    }

    Curso(int i, int nN, int nE) {
        id = i;
        numNotas = nN;
        numEstudiantes = nE;
    }

    void setOrdOrderAsc() {
        for (int i = 0; i < numEstudiantes; i++) {
            estudiantes[i].setOrdOrderAsc();
        }
    }

    void setOrdOrderDesc() {
        for (int i = 0; i < numEstudiantes; i++) {
            estudiantes[i].setOrdOrderDesc();
        }
    }

    void setOrdAtrib(int j) {
        for (int i = 0; i < numEstudiantes; i++) {
            estudiantes[i].setOrdAtrib(j);
        }
    }

    void addEstudiante(Estudiante& e) {
        estudiantes.add(e);
    }

    Estudiante& getEstudiante(int i) {
        return estudiantes[i];
    }

    float promedio() {
        float sum = 0.0f;
        for (int i = 0; i < numEstudiantes; i++) {
            sum += estudiantes[i].promedio();
        }
        return sum / numEstudiantes;
    }

    string to_string() {
        string s = "***** Curso " + std::to_string(id) + " *****\n";
        for (int i = 0; i < numEstudiantes; i++) {
            s += estudiantes[i].to_string() + "\n";
        }
        s += "Promedio: " + std::to_string(promedio()) + "\n";
        s += "NumEstudiantes: " + std::to_string(numEstudiantes) + "\n";
        return s;
    }

    int getNumEstudiantes() {
        return numEstudiantes;
    }

    int compareTo(Curso other) {
        if (numEstudiantes < other.numEstudiantes) return -1;
        else if (numEstudiantes > other.numEstudiantes) return 1;
        else {
            float thisProm = promedio();
            float otherProm = other.promedio();
            if (thisProm > otherProm) return -1;
            else if (thisProm < otherProm) return 1;
            else return 0;
        }
    }

    bool operator>(Curso& other) {
        if (this != &other) {
            if (compareTo(other) == 1) {
                return true;
            }
        }
        return false;
    }

    bool operator>=(Curso& other) {
        if (this != &other) {
            if (compareTo(other) >= 0) {
                return true;
            }
        }
        else {
            return true;
        }
        return false;
    }

    bool operator<(Curso& other) {
        if (this != &other) {
            if (compareTo(other) == -1) {
                return true;
            }
        }
        return false;
    }

    bool operator<=(Curso& other) {
        if (this != &other) {
            if (compareTo(other) <= 0) {
                return true;
            }
        }
        else {
            return true;
        }
        return false;
    }

    bool operator==(Curso& other) {
        if (this != &other) {
            if (compareTo(other) == 0) {
                return true;
            }
        }
        else {
            return true;
        }
        return false;
    }

    bool operator!=(Curso& other) {
        if (this != &other) {
            if (compareTo(other) != 0) {
                return true;
            }
        }
        return false;
    }

    Curso& operator=(Curso other) {
        this->id = other.id;
        this->numNotas = other.numNotas;
        this->numEstudiantes = other.numEstudiantes;
        this->estudiantes.clear();
        for (int i = 0; i < other.getNumEstudiantes(); i++) {
            this->estudiantes.add(other.estudiantes[i]);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, Curso& b) {
        return os << b.to_string();
    }

    void sort() {
        estudiantes.sort();
    }
};

class RegiNotas {
    Vector<Curso> cursos;

public:
    RegiNotas() {}

    void addCurso(Curso& c) {
        cursos.add(c);
    }

    Curso& getCurso(int i) {
        return cursos[i];
    }

    void setOrdOrderAsc() {
        for (int i = 0; i < cursos.getSize(); i++) {
            cursos[i].setOrdOrderAsc();
        }
    }

    void setOrdOrderDesc() {
        for (int i = 0; i < cursos.getSize(); i++) {
            cursos[i].setOrdOrderDesc();
        }
    }

    void setOrdAtrib(int j) {
        for (int i = 0; i < cursos.getSize(); i++) {
            cursos[i].setOrdAtrib(j);
        }
    }

    void sort() {
        cursos.sort();
        for (int i = 0; i < cursos.getSize(); i++) {
            cursos[i].sort();
        }
    }

    string to_string() {
        string s = "***** Lista de Cursos *****\n";
        for (int i = 0; i < cursos.getSize(); i++) {
            s += cursos[i].to_string() + "\n";
        }
        return s;
    }

    friend std::ostream& operator<<(std::ostream& os, RegiNotas& b) {
        return os << b.to_string();
    }
};

int main() {
    srand(1234);
    int numEstudiantes = 10;
    int numNotas = 5;

    RegiNotas r;
    Curso* tc = nullptr;
    Estudiante* te = nullptr;
    
    tc = new Curso(0, numNotas+1, numEstudiantes);
    for (int j = 0; j < numEstudiantes; j++) {
        te = new Estudiante(0 * (numEstudiantes) + j, numNotas+1);
        for (int k = 0; k < numNotas+1; k++) {
            te->addNota((float)(rand() % 51) / 10);
        }
        tc->addEstudiante(*te);
    }
    r.addCurso(*tc);
    
    tc = new Curso(1, numNotas, numEstudiantes+1);
    for (int j = 0; j < numEstudiantes; j++) {
        te = new Estudiante(1 * (numEstudiantes+1) + j, numNotas);
        for (int k = 0; k < numNotas; k++) {
            te->addNota((float)(rand() % 51) / 10);
        }
        tc->addEstudiante(*te);
    }
    r.addCurso(*tc);

    tc = new Curso(2, numNotas, numEstudiantes);
    for (int j = 0; j < numEstudiantes; j++) {
        te = new Estudiante(2 * (numEstudiantes) + j, numNotas);
        for (int k = 0; k < numNotas; k++) {
            te->addNota((float)(rand() % 51) / 10);
        }
        tc->addEstudiante(*te);
    }
    r.addCurso(*tc);
    
    tc = new Curso(3, numNotas, numEstudiantes);
    for (int j = 0; j < numEstudiantes; j++) {
        te = new Estudiante(3 * (numEstudiantes) + j, numNotas);
        for (int k = 0; k < numNotas; k++) {
            te->addNota((float)(rand() % 51) / 10);
        }
        tc->addEstudiante(*te);
    }
    r.addCurso(*tc);
    
    tc = new Curso(4, numNotas, numEstudiantes+3);
    for (int j = 0; j < numEstudiantes+3; j++) {
        te = new Estudiante(4 * (numEstudiantes+3) + j, numNotas);
        for (int k = 0; k < numNotas; k++) {
            te->addNota((float)(rand() % 51) / 10);
        }
        tc->addEstudiante(*te);
    }
    r.addCurso(*tc);
    tc = new Curso(5, numNotas, numEstudiantes+3);
    for (int j = 0; j < numEstudiantes+3; j++) {
        te = new Estudiante(4 * (numEstudiantes+3) + j, numNotas);
        for (int k = 0; k < numNotas; k++) {
            te->addNota((float)(rand() % 51) / 10);
        }
        tc->addEstudiante(*te);
    }
    r.addCurso(*tc);
    
    
    cout << r;
    r.setOrdOrderAsc();
    r.setOrdAtrib(-1);
    
    cout << endl;
    cout << "*********** Cursos ordenados **************" << endl;
    cout << endl;
    
    r.sort();
    
    cout << r;

    return 0;
}