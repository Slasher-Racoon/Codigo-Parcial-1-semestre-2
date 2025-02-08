
#include <iostream>
using namespace std;

class Vector {
private:
    int* v;
    int capacity;
    int size;
//*****Partes de un vector******//    
    
public:

 // *******Creacion de un vector*******// 
    Vector() {
        capacity = 10;  
        size = 0;
        v = new int[capacity];
    }
    

 // *****Imprimir el Vector*****//  
    void print(){
        for(int i =0; i<size ; i++){
            cout <<v[i]<<"\t";
        }
    }
 
 
  // *****Agrandar el Vector*****// 
    void resize() {
        capacity *= 2; 
        int* temp = new int[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = v[i];  
        }
        delete[] v;  
        v = temp;   
    }
   
    // *****Añadir tamaño al vector********// 
    void add(int d) {
        if (size == capacity) {
            resize();  
        }
        v[size++] = d;
    }
    
     // *****para un valor index en ese numero de posicion se guardara un dato*******// 
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
    
     // ******Borrar un dato en posicion index********// 
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
    
     // *****Conseguir el index de un numero********// 
    
    int getI(int index) {
        if (index >= 0 && index < size) {
            return v[index];
        } else {
            cout << "Índice fuera de rango." << endl;
            return -1; 
        }
    }
    
 // *****Borrar y ahorrar la memoria******// 
~Vector() {
        delete[] v;
    }
};


int main() {
    srand(time(0));
    Vector v;
    int datos;
    
    for (int i =0; i<10; i++){
        v.add(rand()%100);
    }
    cout<<"Lista de precios:"<<endl;
    
    v.print();
    
    
    
    
    
    
    
    return 0;
}



