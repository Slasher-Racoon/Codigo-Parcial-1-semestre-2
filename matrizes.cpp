#include <iostream>
using namespace std;

class Matriz{
private:
    int* m;
    int columnas;
    int filas;
    int capacity;
    int size;
public:
    Matriz() {
        columnas= 5;
        filas = 5;
        capacity = 5;
        size = 0;
        m = new int[capacity];
    }
    
    int getCapacity() { return capacity; };
    int getSize() { return size; } ;
    int getFilas() { return filas; };
    int getColumnas() { return columnas; };
    
    void resize() {
        capacity *= 2;
        int* new_m = new int[capacity];
        for (int i = 0; i < size; i++) {
            new_m[i] = m[i];
        }
        delete[] m;
        m = new_m;
    }
    
    void add(int d) {
        if (size == capacity) {
            resize();  
        }
        m[size++] = d;
    }


    
    void print() {
        int index = 0;
        for (int j = 0; j < filas; j++) {
            for (int i = 0; i < columnas; i++) {
                if (index < size) {
                    cout << m[index++] << "\t";
                } else {
                    cout << "0\t";  
                }
            }
            cout << "" << endl;
        }

        cout << endl;
    }
    
void añadir(int valor, int lat, int lon) {
        if (lat < 0 || lat > columnas) {
            cout << "Índice fuera de rango!" << endl;
            return;
        }
        
        if(lon < 0 || lon> filas){
          cout << "Índice fuera de rango!" << endl;
            return;  
        }

        if (size == capacity) {
            resize();  
        }

        for (int j = lon; j < filas - 1; j++) {
            for (int i = lat; i < columnas - 1; i++) {
                m[i] = m[i + 1];
            }
        }
        

        m[lat] = valor;
        size++;  
    }
    
~Matriz() {
        delete[] m;
    }
};



int main(){
    srand(time(0));
    Matriz m;
    m.getFilas();
    

    
    for(int j= 0; j<m.getFilas(); j++){
        for (int i = 0; i < m.getColumnas(); i++) {
            m.add(rand() % 100);
        }
    }

    m.print();
    
    int valor;
    cout << "Ingrese el número que desea añadir: ";
    cin >> valor;

    int lat;
    cout << "Ingrese la latitud del numero que quiere añadir: ";
    cin >> lat;
    
    int lon;
    cout << "Ingrese la longitud al que desea añadir: ";
    cin >> lon;
    

    m.añadir(valor, lat, lon);
    m.print();
    
    return 0;
}
