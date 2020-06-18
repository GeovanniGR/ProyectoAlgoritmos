/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pais.cpp
 * Author: raquel
 * 
 * Created on 9 de junio de 2020, 22:13
 */

#include "Pais.h"

Pais::Pais() {
}//constructor

Pais::Pais(string pais) {
    this->pais = pais;
     this->image = Gdk::Pixbuf::create_from_file("assets/airport.png");
    this->posX = 0;
    this->posY = 0;
}//constructor

void Pais::draw(const Cairo::RefPtr<Cairo::Context>& cr) {
 Gdk::Cairo::set_source_pixbuf(cr, this->image, this->posX, this->posY);
            cr->rectangle(this->posX, this->posY, 40, 40);
            cr->fill();
}

//setter&&getter





void Pais::setPosX(int posX) {
    this->posX = posX;
}

int Pais::getPosY() {
    return posY;
}

int Pais::getPosX() {
    return posX;
}
 void Pais::setPosY(int posY) {
        this->posY = posY;
    }

void Pais::setPais(string pais) {
    this->pais = pais;
}//setPais

string Pais::getPais() {
    return pais;
}//getPais
