/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafo.h
 * Author: gerald
 *
 * Created on 16 de junio de 2020, 04:29 PM
 */

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <string>

using namespace std;
class Grafo {
public:
    Grafo();
    Grafo(const Grafo& orig);
    virtual ~Grafo();

    struct nodo {
        string nombre; //nombre del vertice o nodo
        struct nodo *sgte;
        struct arista *ady; //puntero hacia la primera arista del nodo
    };

    struct arista {
        struct nodo *destino; //puntero al nodo de llegada
        struct arista *sgte;
    };
    
    typedef struct nodo *Tnodo; //  Tipo Nodo
    typedef struct arista *Tarista; //Tipo Arista
    
    
    
    
    Tnodo p;//puntero cabeza
    
private:

};

#endif /* GRAFO_H */

