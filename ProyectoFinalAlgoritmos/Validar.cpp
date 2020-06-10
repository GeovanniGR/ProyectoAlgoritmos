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

Validar::Validar() {
}
//
//Validar::Validar(const Validar& orig) {
//}
//
//Validar::~Validar() {
//}

  /*static*/ bool Validar::validar_Es_Numero(string numero) {
        bool esNumero = false;
        // string numero = "0123456789";
        for (int i = 0; i < numero.size(); i++) {
            if (numero[i] == '0' || numero[i] == '1' || numero[i] == '2' ||
                    numero[i] == '3' || numero[i] == '4' || numero[i] == '5' ||
                    numero[i] == '6' || numero[i] == '7' || numero[i] == '8' || numero[i] == '9') {
                esNumero = true;
            }
        }
        return esNumero;
    }

    /*static*/ bool Validar::validar_Es_Letra(string palabra) {
        bool esPalabra = false;
        for (int i = 0; i < palabra.size(); i++) {
            char letra = palabra[i];
            if (isalpha(letra)) {
                esPalabra = true;
            }
        }
        return esPalabra;
    }


