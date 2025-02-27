
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;


int main()
{
    /*
    //Direcciones de memoria de variables y  vectores estáticos
    int tam = 5;
    int v[tam];
    
    cout<<tam<<" "<<&tam<<endl;
    cout<<v<<" "<<&v<<endl;
    for(int i=0; i<tam; i++){
        cout<<"Contenido y dirección de "<<i<<": "<<v[i]<<" "<<&v[i]<<endl;
    }*/
    
    
    //Apuntadores de variables
    int* p;
    cout<<&p<<" "<<p<<endl;
    p = new int(1);
    cout<<&p<<" "<<p<<" "<<*p<<endl;
    
    //Vectores dinámicos con apuntadores
    int tam = 5;
    int* v = new int[tam];
    for(int i=0; i<tam; i++){
        cout<<&v[i]<<" "<<v[i]<<"\n";
    }
    delete[] v;
    cout<<"*********"<<endl;
    tam = 6;
    v = new int[tam];
    for(int i=0; i<tam; i++){
        v[i]=0;
    }
    for(int i=0; i<tam; i++){
        cout<<&v[i]<<" "<<v[i]<<"\n";
    }
    
    delete[] v;
    
    //Matrices dinámicas con apuntadores
    int fil = 5;
    int col = 4;
    int** m = new int*[fil];
    for(int i=0; i<fil; i++){
        m[i] = new int[col];
        for(int j=0; j<col;j++){
            m[i][j] = 0;
        }
    }
    
    
    for(int i=0; i<fil; i++){
        delete[] m[i];
    }
    delete[] m;
    
    
    
    return 0;
}
