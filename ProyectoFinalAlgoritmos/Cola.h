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
        int numero;
        struct nodo *sgte; //apuntador al siguiente nodo,enlace a otra "caja"
    };

    struct cola {
        nodo *delante;
        nodo *atras;
    };
public:
    void encolar(int valor);
    void ejecutar();
    void menu();
    void playMenu();
    int desencolar();
    std::vector<int> mostrarCola();
    void destruirCola();
    int getSize(); //muestra numero de elementos en la cola
    bool isEmpty(); //true si la cola esta vaci
    bool exits(int n); //verifica si existe un elemento
    int front(); //me duelve el valor del frente de la cola
    Cola();
    int getElemento(int n);

private:
    struct cola c;
    nodo *delante;
    nodo *atras;
    int contador;
};

#endif /* COLA_H */

