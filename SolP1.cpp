// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<math.h>
#include"Lista.h"
#include"Vector.h"

class Jugador{
private:
    int id;
    int nivel;
    int puntaje;
public:

    Jugador(){
        id=-1;
        nivel=-1;
        puntaje=-1;
    }
    
    Jugador(int i){
        id=i;
        nivel=0;
        puntaje=0;
    }
    
    int get_id(){
        return id;
    }
    
    int get_puntaje(){
        return puntaje;
    }
    
    int get_nivel(){
        return nivel;
    }
    
    void add_puntaje(int p){
        
        puntaje += p;
        if(puntaje <=0){
            nivel = 0;
        }else{
            calc_nivel();
        }
        /*
        Alterar el puntaje con el valor p (positivo si se suma, negativo si se resta).
        Si el puntaje es 0 o negativo, el nivel debe llevarse a 0 para evitar problemas con los logaritmos.
        Sino, se debe calcular el nivel del nivel.
        */
    }
    
    
    void calc_nivel(){
        /*
        Implementar la fórmula del nivel
        */
        nivel = log(puntaje) + log10(puntaje);
    }
    
    Jugador& operator=(const Jugador& f) { 
		/*
		Asignar cada uno de los atributos del objeto f al propio. Ver ejemplos en código previos.
		*/
		id = f.id;
		nivel = f.nivel;
		puntaje = f.puntaje;
		return *this;
	}
	
	string to_string() {
		return " "+std::to_string(id)+", "+std::to_string(puntaje)+", "+std::to_string(nivel);
	}

	friend std::ostream& operator<<(std::ostream& os, Jugador& b) {
		return os << b.to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Jugador* b) {
		return os << b->to_string();
	}
    
};


class Equipo{
private:
    /*
    Atributos de equipo. Preferiblemente, en su Vector trabaje con apuntadores de jugadores, para poder
    garantizar que sus atributos puedas actualizarse durante ejecución, como en el preparcial 3
    */
    int id_grupo;
    Vector<Jugador*> jugadores;

public:
    Equipo(){
        id_grupo = -1;
    }
    
    Equipo(int i){
        id_grupo = i;
    }
    
    int get_id_grupo(){
        return id_grupo;
    }
    
    void add(Jugador* j){
        /*
        Añadir un jugador al vector de jugadores
        */
        jugadores.add(j);
    }
    
    Jugador* get(int i){
        /*
        Retornar el jugador i del vector
        */
        return jugadores.get(i);
    }
    
    void print(){
        /*
        Imprimir la lista de jugadores
        */
        int s = jugadores.get_size();
        for (int i = 0; i < s; i++) {
            cout<<jugadores.get(i)->to_string()<<endl;
        }
    }
    
    void update(bool win){
        /*
        Actualizar los puntajes de los jugadores del equipo. 
        El parámetro "win" define si el equipo ganó o perdió la batalla
        */
        int s = jugadores.get_size();
        int p = 0;
        if(win){
            p = 50;
        }else{
            p = -10;
        }
        for (int i = 0; i < s; i++) {
            jugadores.get(i)->add_puntaje(p);
        }
        
    }
    
};

class Batalla{
private:
    Equipo* e1;
    Equipo* e2;
    float area_e1;
public:
    Batalla(){
        e1 = NULL;
        e2 = NULL;
        area_e1 = 0;
    }
    
    Batalla(Equipo* eq1, Equipo* eq2, float a){
        e1 = eq1;
        e2 = eq2;
        area_e1 = a;
    }
    
    float get_area(){
        return area_e1;
    }
    
    int get_ganador(){
        /*
        Verificar el valor del área y dependiendo de eso, actualizar el estado de cada equipo
        llamando a su método update.
        Retorne el id del grupo del equipo ganador.
        */
        if(area_e1< 0.5){
            e1->update(false);
            e2->update(true);
            return e2->get_id_grupo();
        }else{
            e1->update(true);
            e2->update(false);
            return e1->get_id_grupo();
        }
        
    }
    
};

class Grupo{
private:
    int id;
    string nombre;
    Lista<Jugador*> jugadores;
    int puntaje;

public:
    Grupo(){
        id = -1;
        nombre = "";
        puntaje = 0;
    }
    
    Grupo(int i, string n){
        id = i;
        nombre = n;
        puntaje = 0;
    }
    
    int get_id(){
        return id;
    }
    
    string get_nombre(){
        return nombre;
    }
    
    int get_puntaje(){
        return puntaje;
    }
    
    void add_puntaje(int val){
        puntaje+=val;
    }
    
    void add(Jugador* j){
        /*
        Añadir el jugador j a la lista
        */
        jugadores.add(j);
    }
    
    Jugador* get(int i){
        /*
        Retornar el jugador almacenado en en nodo i de la lista
        */
        return jugadores.get(i)->get_dato();
    }
    
    void print(){
        cout<<"*****Grupo "<<nombre<<"******"<<endl;
        jugadores.print();
    }
    
    Equipo* crear_equipo(){
        int indices[4];
        int tamJuga = jugadores.get_size();
        int temp;
        int temp_i;
        for (int i = 0; i < 4; i++) {
            if(i==0){
                indices[i] = rand()%tamJuga;
            }else{
                temp = rand()%tamJuga;
                temp_i = 0;
                while(temp_i < i && temp != indices[temp_i]){
                    temp_i++;
                }
                if(temp_i == i){
                    indices[i] = temp;
                }else{
                    i--;
                }
            }
        }
            Equipo* e = new Equipo(id);
            for (int i = 0; i < 4; i++) {
                e->add(get(indices[i]));
            }
            
            return e;
            
        
        
        /*
        Crear un equipo con 4 integrantes del grupo.
        Se debe garantizar que los 4 integrantes sean diferentes.
        Retornar un nuevo equipo con los integantes asignados.
        
        Pista: Trate de generar una lista de 4 números entre 0 y 
        el tamaño de la lista de jugadores del grupo de tal manera que no se repitan.
        Con base en esa lista de índices, cree un grupo vacío y agréguele los jugadores
        con esos indices.
        */
        
    }
    
    
};


class Splatfest{
private:
  Vector<Grupo*> grupos;
  Lista<Batalla*> batallas;
  int num_batallas;
  int num_jugadores;
 public:
 
 Splatfest(){
     num_jugadores = 100;
     num_batallas = 1000;
     grupos.add(new Grupo(0,"Ajiaco"));
     grupos.add(new Grupo(1,"Changua"));
     grupos.add(new Grupo(2,"Cuchuco"));
     init_grupos();
     init_batallas();
     calc_ganador();
 }
 
 Splatfest(int nj, int nb){
     num_jugadores = nj;
     num_batallas = nb;
     grupos.add(new Grupo(0,"Ajiaco"));
     grupos.add(new Grupo(1,"Changua"));
     grupos.add(new Grupo(2,"Cuchuco"));
     init_grupos();
     init_batallas();
     calc_ganador();
 }
 
 void init_grupos(){
     /*
     Cree y distribuya los jugadores en su respectivo grupo. Recuerde que un jugador i 
     será asignado al grupo i%3
     */
     
     for (int i = 0; i < num_jugadores; i++) {
        grupos.get(i%3)->add(new Jugador(i));
     }
     
 }
 
 void init_batallas(){
     
     /*
     Genere y almacene las num_batallas batallas en la lista de batallas.
     De dos grupos seleccionados de manera aleatoria (y diferentes entre sí), se generan
     los equipos aleatorios y se le asignan a la batalla. También se calcula el porcentaje de
     cubrimiento de área de la batalla y se le pasa por parámetro.
     */
     int g1, g2;
     
     for (int i = 0; i < num_batallas; i++) {
         g1 = rand()%3;
         do{
             g2 = rand()%3;
         }while(g2 == g1);
         
         batallas.add(new Batalla(grupos.get(g1)->crear_equipo(), grupos.get(g2)->crear_equipo(),rand()/RAND_MAX));
     }
     
     /*
     Se recorre la lista de batallas y actualiza el puntaje de cada grupo
     */
     int t;
     for (int i = 0; i < num_batallas; i++) {
         t = batallas.get(i)->get_dato()->get_ganador();
         grupos.get(t)->add_puntaje(100);
     }
     
 }
 
 void calc_ganador(){
    int i=0;
    bool ganador = false;
    while(!ganador && i<3){
        if(grupos.get(i)->get_puntaje() > grupos.get((i+1)%3)->get_puntaje() && 
        grupos.get(i)->get_puntaje() > grupos.get((i+2)%3)->get_puntaje()){
            ganador = true;
            cout<<"El equipo ganador es "<<grupos.get(i)->get_nombre()<<" con "<<grupos.get(i)->get_puntaje()<<" puntos."<<endl;
        }else{
            i++;
        }
    }
     
     
 }
 
 Grupo* get_grupo(int i){
     return grupos.get(i);
 }
 
 
 
    
};

using namespace std;

int main()
{
    
    srand(clock());
    //srand(1234);
    int nj = 100;
    int nb = 1000;
    
    Splatfest s = Splatfest(nj, nb);
    
    for(int i=0; i<3; i++){
        s.get_grupo(i)->print();
    }
    
    /*
    Jugador a(3);
    cout<<a.to_string()<<endl;
    a.add_puntaje(-10);
    cout<<a.to_string()<<endl;
    a.add_puntaje(50);
    cout<<a.to_string()<<endl;
    */
    /*
    Equipo e(1);
    for (int i = 0; i < 10; i++) {
        e.add(new Jugador(i));
    }
    e.print();
    e.update(true);
    e.print();
    e.update(false);
    e.print();
    */
    
    return 0;
}
