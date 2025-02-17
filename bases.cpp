#include <iostream>
using namespace std;

class Vector {
private:
    int* v;
    int capacity;
    int size;

public:
    Vector() {
        capacity = 10;  
        size = 0;
        v = new int[capacity];
    }

    Vector(int c) {
        capacity = c;  
        size = 0;
        v = new int[capacity];
    }

    void añadir(int valor, int index) {
        if (index < 0 || index > size) {
            cout << "Índice fuera de rango!" << endl;
            return;
        }

        if (size == capacity) {
            resize();  
        }

        for (int i = size; i > index; i--) {
            v[i] = v[i - 1];
        }

        v[index] = valor;
        size++;  
    }

    void quitar(int borrar) {
        if (borrar < 0 || borrar >= size) {
            cout << "Índice fuera de rango!" << endl;
            return;
        }

        for (int i = borrar; i < size - 1; i++) {
            v[i] = v[i + 1];
        }

        size--;  
    }

    void add(int d) {
        if (size == capacity) {
            resize();  
        }
        v[size++] = d;
    }

    void print(){
        for(int i = 0; i < size; i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }

    void resize() {
        capacity *= 2;
        int* new_v = new int[capacity];
        for (int i = 0; i < size; i++) {
            new_v[i] = v[i];
        }
        delete[] v;
        v = new_v;
    }

    ~Vector() {
        delete[] v;
    }

    int getCapacity() { return capacity; }
    int getsize() { return size; }
    int getI(int index) {
        if (index >= 0 && index < size) {
            return v[index];
        } else {
            cout << "Índice fuera de rango." << endl;
            return -1; 
        }
    }
};

int main() {
    srand(time(0));
    Vector v;
    int datos;

    for (int i = 0; i < 10; i++) {
        v.add(rand() % 100);
    }

    cout << "La capacidad es: " << v.getCapacity() << endl;
    cout << "El tamaño del vector es: " << v.getsize() << endl;

    int index;
    cout << "Ingrese el número de la posición para obtener su valor: ";
    cin >> index;

    v.print();
    cout << "**************" << endl;

    int value = v.getI(index);

    if (value != -1) { 
        cout << "El valor en la posición " << index << " es: " << value << endl;
    }

    int cambio;
    cout << "Ingrese el número que desea añadir: ";
    cin >> cambio;

    int ins;
    cout << "Ingrese el índice al que desea añadir: ";
    cin >> ins;

    v.añadir(cambio, ins);

    cout << "La capacidad es: " << v.getCapacity() << endl;
    cout << "El tamaño del vector es: " << v.getsize() << endl;

    cout << "Ingrese el número de la posición para obtener su valor: ";
    cin >> index;
    int value1 = v.getI(index);
    if (value1 != -1) { 
        cout << "El valor en la posición " << index << " es: " << value1 << endl;
    }

    v.print();

    int borrar;
    cout << "Ingrese el índice del número que quiere borrar: ";
    cin >> borrar;

    v.quitar(borrar);

    cout << "Vector después de borrar: ";
    v.print();

    return 0;
    }
