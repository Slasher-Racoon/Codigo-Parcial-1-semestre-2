// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;


class Nodo{
    int dato;
    Nodo* next;
    
public:

    Nodo(){
        dato = 0;
        next = nullptr;
    }
    
    Nodo(int d){
        dato = d;
        next = nullptr;
    }
    
    int getDato(){
        return dato;
    }
    
    void setDato(int d){
         dato = d;
    }
    
    
    Nodo* getNext(){
        return next;
    }
    
    void setNext(Nodo* n){
        next = n;
    }
    
    string to_string(){
        return std::to_string(dato);
    }
};
class Lista {
    Nodo *ptr;
    
public: 
    Lista(){
        ptr = nullptr;
    }
    
    void add(int d){
        Nodo * n = new Nodo(d);
        if(ptr == nullptr){
            ptr = n; 
        }
        else{
            Nodo* temp = ptr; 
            while(temp-> getNext() != nullptr){
                temp = temp -> getNext();  
            }
            temp-> setNext(n);
            
            }
        }
void print(){
    Nodo* temp = ptr; 
    
    while(temp !=  nullptr){
        cout<< temp -> getDato()<< "\t";
        temp = temp -> getNext();  
    }
}

int get(int a){
    a -= 1;
    int i = 0; 
    int res = 0;
    Nodo* temp = ptr;
    while (i < a && (temp-> getNext() != nullptr)){
        temp = temp -> getNext();
        i++;
    }
    res = temp -> getDato();
    return res;
}
void set(int a, int b){
    a -= 1;
    int i = 0; 
    int res = b;
    Nodo* temp = ptr;
    while (i < a && (temp-> getNext() != nullptr)){
        temp = temp -> getNext();
        i++;
    }
    temp->setDato(b);
}


void insert(int ins, int pos) {
    Nodo* nuevo = new Nodo(ins);
    
    if (pos <= 1 wh|| ptr == nullptr) {
        nuevo->setNext(ptr);
        ptr = nuevo;
        return;
    }

    Nodo* temp = ptr;
    for (int i = 1; temp->getNext() != nullptr && i < pos - 1; i++) {
        temp = temp->getNext();
    }

    nuevo->setNext(temp->getNext());
    temp->setNext(nuevo);
    }
    
void alt_f4(int pos){
    if (ptr == nullptr || pos < 0){
        cout<<"posicion fuera de rango"<<endl;
    }

    if (pos == 0) {
        Nodo* temp = ptr;
        ptr = ptr->getNext();
        delete temp;
        return;
    }

    Nodo* temp = ptr;
    for (int i = 1; temp->getNext() != nullptr && i < pos - 1; i++) {
        temp = temp->getNext();
    }

    if (temp->getNext() == nullptr) return;

    Nodo* nodoEliminar = temp->getNext();
    temp->setNext(nodoEliminar->getNext());
    delete nodoEliminar;
    }
    
};


int main()
{
    srand(time(0));
    Nodo n;
    /*
    n.setDato(5);
    cout<<n.getNext()<<endl;
    cout<<n.to_string()<<endl;
    
    
    Nodo n2(6);
    n.setNext(&n2);
    cout<<&n2<<" "<<n.getNext()<<endl;
    cout<<n.getNext()->to_string()<<endl;
    
    n2.setNext(new Nodo(7));
    cout<<n2.getNext()->to_string()<<endl;
*/
    Lista l; 
    for (int i = 0;i < 10;i++ ){
        l.add(rand()%100);
    }
    l.print();
    cout<<endl<<l.get(5)<<endl;
    l.set(5,5);
    l.print();
    
    cout<<"\t"<<endl;
    
    
    int ins, pos;
    cout << "Ingrese el numero que desea insertar: ";
    cin >> ins;
    cout << "Ingrese la posicion donde desea insertarlo: ";
    cin >> pos;

    l.insert(ins, pos);
    l.print();
    
    cout<<"\t"<<endl;
    cout << "Ingrese la posicion que desea eliminiar: ";
    cin >> pos;
    
    l.alt_f4(pos);
    l.print();
    
    

    return 0;
}
