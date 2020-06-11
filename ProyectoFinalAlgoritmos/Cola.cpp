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

void Cola::encolar(string valor) {

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

string Cola::desencolar() {
    string numero;
    struct nodo *aux;
    aux = c.delante;
    numero = aux->numero;
    c.delante = (c.delante)->sgte;
    delete(aux);
    return numero;
}//desencolar

std::vector<string> Cola::mostrarCola() {
    vector<string> horario;
    struct nodo *aux;
    aux = c.delante;
    while (aux != NULL) {
        //if (aux->numero > 0 && aux->numero < 12) {
        horario.push_back(aux->numero);
        //} else {
        //  if (aux->numero >= 12 && aux->numero <= 24) {
        //horario.push_back(aux->numero);
        //}
        aux = aux->sgte;
    }

    return horario;
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

//string Cola::getSize() {
//    return contador + 1;
//}//getSize

bool Cola::isEmpty() {
    if (contador <= 0)
        return false;
    else {
        return true;
    }
}//isEmpty

bool Cola::exits(string n) {
    bool existe;
    struct nodo *aux;
    string num;
    aux = c.delante;
    while (aux != NULL) {
        if (aux->numero == n) {
            return true;
        }
        aux = aux->sgte;
    }//while
    return false;

}//exis

string Cola::front() {
    string frente;
    frente = c.delante->numero;
    return frente;
}//front






