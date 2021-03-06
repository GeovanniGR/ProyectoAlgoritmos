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
#include "Pais.h"
#include "PaisDestino.h"
#include <iostream>
#include <vector>
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
    static Grafo* getInstance();
    void agregarNodo(string elemento);
    void agregarArista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo);
    void vaciarAristas(Tnodo &aux);
    void insertarArista(string ini, string fin);
    bool isEmpty();
    void eliminarNodo(string eliminar);
    void eliminarArista(string ini, string fin);
    void mostrarGrafo();
    void mostrarAristas(string nodo);
    bool existe(string nodo);

    vector<string> arista(string nodo);

    void setNombresNodos(vector<Pais> nombresNodos);
    vector<Pais> getNombresNodos();

    void setPaisDes(vector<PaisDestino> paisDes);
    vector<PaisDestino> getPaisDes();

    void setHorarioSalida(vector<int> horarioSalida);
    vector<int> getHorarioSalida();

    void setHorarioLlegada(vector<int> horarioLlegada);
    vector<int> getHorarioLlegada();

    void horarios(vector<int> horarioSalida, vector<int> horarioLlegada);

    void setHoraDibujar(string hora);
    string getHoraDibujar();

    void setHoraDibujarLlegada(string horaLlegada);
    string getHoraDibujarLlegada();
private:
    vector<Pais> nombresNodos;
    vector<PaisDestino> paisDes;

    vector<int> horarioSalida;
    vector<int> horarioLlegada;

    string hora;
    string horaLlegada;

    Grafo();
    Tnodo p; //puntero cabeza
    Tarista p2;
    static Grafo* instance;
};

#endif /* GRAFO_H */

