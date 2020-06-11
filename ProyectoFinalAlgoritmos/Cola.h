/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.h
 * Author: raquel
 *
 * Created on 12 de mayo de 2020, 11:32
 */

#ifndef COLA_H
#define COLA_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Cola {

    struct nodo {
        string numero;
        struct nodo *sgte; //apuntador al siguiente nodo,enlace a otra "caja"
    };

    struct cola {
        nodo *delante;
        nodo *atras;
    };
//    typedef cola *ptrCola;
public:
    void encolar( string valor);
    void ejecutar();
    void menu();
    void playMenu();
    string desencolar();
    std::vector<string> mostrarCola();
    void destruirCola();
    string getSize();//muestra numero de elementos en la cola
    bool isEmpty();//true si la cola esta vaci
    bool exits(string n);//verifica si existe un elemento
    string front();//me duelve el valor del frente de la cola
    Cola();
//    Cola(const Cola& orig);
//    virtual ~Cola();
private:
    struct cola c;
    nodo *delante;
    nodo *atras;
//    ptrCola cola;
     int contador;
};

#endif /* COLA_H */

