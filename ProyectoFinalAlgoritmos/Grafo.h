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
using namespace std;

struct nodo {
    string nombre; //nombre del vertice o nodo
    struct nodo *sgte;
    struct arista *ady; //puntero hacia la primera arista del nodo
};

struct arista {
    struct nodo *destino; //puntero al nodo de llegada
    struct arista *sgte;
};

class Grafo {
    typedef struct nodo *Tnodo; //  Tipo Nodo
    typedef struct arista *Tarista; //Tipo Arista


public:
    Grafo();

    void agregarNodo(string elemento);
    void agregarArista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo);
    void vaciarAristas(Tnodo &aux);
    void insertarArista(string ini, string fin);

private:
    Tnodo p; //puntero cabeza
    Tarista p2;
};

#endif /* GRAFO_H */

