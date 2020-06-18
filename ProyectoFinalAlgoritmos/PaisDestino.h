/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PaisDestino.h
 * Author: raquel
 *
 * Created on 10 de junio de 2020, 16:28
 */

#ifndef PAISDESTINO_H
#define PAISDESTINO_H
#include <iostream>
#include <string>
#include <gtkmm.h>
using namespace std;

class PaisDestino {
public:
   PaisDestino();

    PaisDestino(string nombrePais);
    void draw(const Cairo::RefPtr<Cairo::Context>& cr);
    //setter&getter
    string getNombrePais();
    void setNombrePais(string nombrePais);
    int getPosX();

    void setPosX(int posX);

    int getPosY();

    void setPosY(int posY);

private:
    string nombrePais;
    Glib::RefPtr<Gdk::Pixbuf> image;
    int posX;
    int posY;
};

#endif /* PAISDESTINO_H */

