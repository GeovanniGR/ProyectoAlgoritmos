/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pais.h
 * Author: raquel
 *
 * Created on 9 de junio de 2020, 22:13
 */

#ifndef PAIS_H
#define PAIS_H
#include <iostream>
#include <string>
#include <gtkmm.h>
using namespace std;

class Pais {
public:
    Pais();
    Pais(string pais);
    void draw(const Cairo::RefPtr<Cairo::Context>& cr);
    //setter&getter
    string getPais();

    int getPosX();

    void setPosX(int posX);

    int getPosY();

    void setPosY(int posY);
    void setPais(string pais);
private:
    Glib::RefPtr<Gdk::Pixbuf> image;
    int posX;
    int posY;
    string pais;
};

#endif /* PAIS_H */

