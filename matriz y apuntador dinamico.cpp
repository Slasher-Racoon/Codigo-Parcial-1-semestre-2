
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

class Matriz{
    int** m;
    int fils;
    int cols;
    //Más atributos por definir...
public:
    Matriz(){
        fils = 5;
        cols = 4;
        m = new int*[fils];
        for(int i=0; i<fils; i++){
            m[i] = new int[cols];
            for(int j=0; j<cols;j++){
                m[i][j] = 0;
            }
        }
    }
    
    Matriz(int f, int c){
        fils = f;
        cols = c;
        m = new int*[fils];
        for(int i=0; i<fils; i++){
            m[i] = new int[cols];
            for(int j=0; j<cols;j++){
                m[i][j] = 0;
            }
        }
    }
    
    ~Matriz(){
        for(int i=0; i<fils; i++){
            delete[] m[i];
        }
        delete[] m;
    }
    
    void print(){
        for(int i=0; i<fils;i++){
            for(int j=0; j<cols; j++){
                cout<<m[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    
    int get(int f, int c){
        if(f < fils && f >=0){
            if(c < cols && c >=0){
                return m[f][c];
            }
        }
    }
    
    void set(int f, int c, int d){
        if(f < fils && f >=0){
            if(c < cols && c >=0){
                m[f][c] = d;
            }
        }
    }
    
    void addFila(){
        
    }
    
    void addColumna(){
        
    }
    
    void add(int d){
        
    }
    
};

int main()
{
    srand(time(0));
    int f = 8;
    int c = 3;
    Matriz m(f,c);
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            m.set(i,j,rand()%100);
        }
    }
    m.print();
    
    return 0;
}
