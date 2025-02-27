#include<iostream>

using namespace std;

class Transaccion{
  /* 
  Definir atributos
  */
  
  int origen;
  int destino;
  float monto;
  
  public:
  
  Transaccion(){
      //Inicializar atributos en 0
      origen = -1;
      destino = -1;
      monto = -1;
  }
  
  Transaccion(int o, int d, float m){
      //Inicializar atributos con parámetros de entrada
      origen = o;
      destino = d;
      monto = m;
  }
  
  int get_origen(){
      return origen;
  }
    
  void set_origen(int o){
      origen = o;
  }
  
  int get_destino(){
      return destino;
  }
    
  void set_destino(int d){
      destino = d;
  }
  
  float get_monto(){
      return monto;
  }
    
  void set_monto(int m){
      monto = m;
  }
    
  Transaccion& operator=(const Transaccion& f) { 
        origen = f.origen;
        destino = f.destino;
        monto = f.monto;
        return *this; 
    }
  
  
  string to_string() {
        return "("+std::to_string(origen) + "," + std::to_string(destino)+ "," + std::to_string(monto)+")";
    }
    
  friend std::ostream& operator<<(std::ostream& os, Transaccion& b) {
        return os << b.to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Transaccion* b) {
        return os << b->to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Transaccion b) {
        return os << b.to_string();
    }
    
};

template <typename T>
class Node{
    T dato;
    Node* next;
public:
    Node(){
        next = NULL;
    }
    
    Node(T d){
        dato = d;
        next = NULL;
    }
    
    ~Node(){
        //delete dato;
    }
    
    T getDato(){
        return dato;
    }
    
    void setDato(T d){
        dato = d;
    }
    
    Node* getNext(){
        return next;
    }
    
    void setNext(Node* n){
        next = n;
    }
};

template <typename T>
class Lista{
    Node<T>* ptr;
    int size;
public:
    Lista(){
        ptr = NULL;
        size = 0;
    }
    
    void add(T d){
        if(ptr == NULL){
            ptr = new Node<T>(d);
        }else{
            Node<T>* temp = ptr;
            while(temp->getNext() != NULL){
                temp = temp->getNext();
            }
            temp->setNext(new Node<T>(d));
        }
        size++;
    }
    
    Node<T>* get(int i){
        if(i >= 0 && i < size){
            int cont=0;
            Node<T>* temp = ptr;
            while(cont < i && temp != NULL){
                temp = temp->getNext();
                cont++;
            }
            return temp;
        }
        
        return NULL;
    }
    
    void print(){
        Node<T>* temp = ptr;
        while(temp != NULL){
            cout<<temp->getDato()<<endl;
            temp = temp->getNext();
        }
    }
    
};

int main()
{
    srand(1234);
    int num_emp = 4; //Número de empresas
    int num_trans = 100; //Número de transacciones
    int error = 16; //Variable para incluir errores en las transacciones
    int monto_max = 100000; //Variable para definir el máximo valor de un monto
    
    float** mat_bank; //Declaración de la matriz con información reportada por el banco, calculada con las transacciones originales
    float** mat_alt; //Declaración de la matriz con información alterada, reportada por la empresa, calculada con las transacciones alteradas
    
    
    Lista<Transaccion*> t;
    Transaccion* temp;
    int o,d;
    float m;
    
    //Creación de transacciones. Valide que no haya transacciones con un mismo origen y destino, y que el monto no pase del máximo establecido: monto = rand()%100000;
    for(int i=0; i<num_trans; i++){
        o = rand()%num_emp;
        do{
            d = rand()%num_emp;
        }while(o == d);
        m = rand()%monto_max;
        temp = new Transaccion(o,d,m);
        t.add(temp);
    }
    
    
    //Imprimir lista de transacciones originales
    for(int i=0; i<num_trans; i++){
        cout<<t.get(i)->getDato()<<endl;
    }
    
    //Calcular monto total de transacciones entre empresas en mat_bank
    
    mat_bank = new float*[num_emp];
    for(int i=0; i<num_emp; i++){
        mat_bank[i] = new float[num_emp];
        for(int j=0; j<num_emp; j++){
            mat_bank[i][j] = 0;
        }
    }
    
    for(int i=0; i<num_trans; i++){
        temp = t.get(i)->getDato();
        mat_bank[temp->get_origen()][temp->get_destino()] += temp->get_monto(); 
    }
    
    
    //Imprimir la matriz mat_bank
    
    for(int i=0; i<num_emp; i++){
        for(int j=0; j<num_emp; j++){
            cout<<mat_bank[i][j]<<"\t";
        }    
        cout<<endl;
    }
    
    //Alterar las transacciones cuyo indice%error == 0, disminuyendo su valor en 25% (monto*0.75)    
    
    for(int i=0; i<num_trans; i++){
        if(i%error == 0){
            m = t.get(i)->getDato()->get_monto()*0.75;
            t.get(i)->getDato()->set_monto(m);
        }
    }
    
    //Imprimir lista de transacciones alteradas
    for(int i=0; i<num_trans; i++){
        cout<<t.get(i)->getDato()<<endl;
    }
    
    //Calcular monto total de transacciones alteradas entre empresas en mat_alt
    
    mat_alt = new float*[num_emp];
    for(int i=0; i<num_emp; i++){
        mat_alt[i] = new float[num_emp];
        for(int j=0; j<num_emp; j++){
            mat_alt[i][j] = 0;
        }
    }
    
    for(int i=0; i<num_trans; i++){
        temp = t.get(i)->getDato();
        mat_alt[temp->get_origen()][temp->get_destino()] += temp->get_monto(); 
    }
    
    //Imprimir la matriz mat_alt

    for(int i=0; i<num_emp; i++){
        for(int j=0; j<num_emp; j++){
            cout<<mat_alt[i][j]<<"\t";
        }    
        cout<<endl;
    }

    //Imprimir las diferencias encontradas entre ls matrices
    for(int i=0; i<num_emp; i++){
        for(int j=0; j<num_emp; j++){
            if(mat_bank[i][j] != mat_alt[i][j])
                cout<<"Diferencia en total de transacciones entre empresas "<<i<<" y "<<j<<" por "<<(mat_alt[i][j]-mat_bank[i][j])<<endl;
        }
    }
    
    return 0;
}
