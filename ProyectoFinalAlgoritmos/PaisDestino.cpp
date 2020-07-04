/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PaisDestino.cpp
 * Author: raquel
 * 
 * Created on 10 de junio de 2020, 16:28
 */

#include "PaisDestino.h"

PaisDestino::PaisDestino() {
}//constructor

PaisDestino::PaisDestino(string nombrePais, string nacionalidadMigracion) {
    this->nombrePais = nombrePais;
    this->nacionalidadMigracion = nacionalidadMigracion;
    this->image = Gdk::Pixbuf::create_from_file("assets/airport.png");
    this->posX = 0;
    this->posY = 0;
}//constructor

void PaisDestino::draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    Gdk::Cairo::set_source_pixbuf(cr, this->image, this->posX, this->posY);
    cr->rectangle(this->posX, this->posY, 40, 40);
    cr->fill();
}//draw

//setter&&getter

void PaisDestino::setPosX(int posX) {
    this->posX = posX;
}//setPosX

int PaisDestino::getPosY() {
    return posY;
}//getPosY

int PaisDestino::getPosX() {
    return posX;
}//getPosX

void PaisDestino::setPosY(int posY) {
    this->posY = posY;
}//setPosY

void PaisDestino::setNombrePais(string nombrePais) {
    this->nombrePais = nombrePais;
}//setNombrePais

string PaisDestino::getNombrePais() {
    return this->nombrePais;
}//getNombrePais

string PaisDestino::getNacionalidadMigracion() {
    return nacionalidadMigracion;
}//getNacionalidadMigracion

void PaisDestino::setNacionalidadMigracion(string nacionalidadMigracion) {
    this->nacionalidadMigracion = nacionalidadMigracion;
}//setNacionalidadMigracion
