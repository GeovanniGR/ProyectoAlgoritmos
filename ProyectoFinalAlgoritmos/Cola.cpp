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
}

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
    }
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

std::vector<string*> Cola::mostrarCola() {
    std::vector<string*> horarios;
    int numero;
    struct nodo *aux;
    aux = c.delante;
    while (aux != NULL) {
        if (aux->numero>0 && aux->numero <12) {
            horarios.push_back("am");
        } else {
            if (aux->numero >=12 && aux->numero <=24) {
                 horarios.push_back("pm");
            }
        }

        aux = aux->sgte;
    }
    return horarios;
}//mostrarCola

void Cola::destruirCola() {
    struct nodo *aux;
    while (c.delante != NULL) {
        aux = c.delante;
        c.delante = aux->sgte;
        delete(aux);

    }
    c.delante = NULL;
    c.atras = NULL;
    contador = 0;
}//destruirCola

int Cola::getSize() {
    return contador + 1;
}//getSize

bool Cola::isEmpty() {
    if (contador <= 0)
        return false;
    else {
        return true;
    }
}//isEmpty

bool Cola::exits(int n) {
    bool existe;
    struct nodo *aux;
    int num;
    aux = c.delante;
    while (aux != NULL) {
        if (aux->numero == n) {
            return true;
        }
        aux = aux->sgte;
    }//while
    return false;

}//exis

int Cola::front() {
    int frente;
    frente = c.delante->numero;
    return frente;
}//front






