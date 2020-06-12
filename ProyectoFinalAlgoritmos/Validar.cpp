/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Validar.cpp
 * Author: gerald
 * 
 * Created on 8 de junio de 2020, 08:12 PM
 */

#include "Validar.h"

Validar::Validar() {}//Validar

bool Validar::validar_Es_Numero(string numero) {
    bool esNumero = false;
    for (int i = 0; i < numero.size(); i++) {
        if (numero[i] == '0' || numero[i] == '1' || numero[i] == '2' ||
                numero[i] == '3' || numero[i] == '4' || numero[i] == '5' ||
                numero[i] == '6' || numero[i] == '7' || numero[i] == '8' || numero[i] == '9') {
            esNumero = true;
        }//if
    }//for
    return esNumero;
}//validar_Es_Numero

bool Validar::validar_Es_Letra(string palabra) {
    bool esPalabra = false;
    for (int i = 0; i < palabra.size(); i++) {
        char letra = palabra[i];
        if (isalpha(letra)) {
            esPalabra = true;
        }//if
    }//for
    return esPalabra;
}//validar_Es_Letra
