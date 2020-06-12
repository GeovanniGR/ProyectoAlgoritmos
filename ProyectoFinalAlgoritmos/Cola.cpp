/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.cpp
 * Author: raquel
 * 
 * Created on 12 de mayo de 2020, 11:32
 */

#include "Cola.h"
#include <iostream>

Cola::Cola() {
    c.atras = NULL;
    c.delante = NULL;
    contador = 0;
}//constructor

int Cola::getElemento(int n) {
    if (isEmpty()) {
        cout << "vacida" << endl;
    } else {

        //NodoListas aux = inicio; //lista
        struct nodo *aux = new(struct nodo);
        int posicion = 1; //contador

        while (aux != this->atras) {
            if (posicion == n) { //encuentra
                return aux->numero;
            }
            aux = aux->sgte;
            posicion++;
        }// while

        if (aux == atras) {
            return 0;
        }// if
    }//else

    return 0; // si no lo encuentra
}//getElemento

void Cola::encolar(int valor) {

    struct nodo *aux = new(struct nodo);
    aux->numero = valor;
    aux->sgte = NULL;
    if (c.delante == NULL) {
        c.delante = aux; //encola el primero elemento
        c.atras = aux;
    } else {
        (c.atras)->sgte = aux;
        c.atras = aux; //ultimo elemento
    }//else
    contador++;
}//encolar

int Cola::desencolar() {
    int numero;
    struct nodo *aux;
    aux = c.delante;
    numero = aux->numero;
    c.delante = (c.delante)->sgte;
    delete(aux);
    return numero;
}//desencolar

std::vector<int> Cola::mostrarCola() {
    vector<int> horario;
    struct nodo *aux;
    aux = c.delante;
    while (aux != NULL) {
        horario.push_back(aux->numero);
        aux = aux->sgte;
    }

    return horario;
}//mostrarCola

void Cola::destruirCola() {
    c.delante = NULL;
    c.atras = NULL;
    contador = 0;
}//destruirCola

int Cola::getSize() {
    return contador;
}//getSize

bool Cola::isEmpty() {
    if (contador <= 0)
        return false;
    else {
        return true;
    }//else
}//isEmpty

bool Cola::exits(int n) {
    struct nodo *aux;
    aux = c.delante;
    while (aux != NULL) {
        if (aux->numero == n) {
            return true;
        }//if
        aux = aux->sgte;
    }//while
    return false;
}//exis

int Cola::front() {
    int frente;
    frente = c.delante->numero;
    return frente;
}//front
