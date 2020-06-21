/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Drawing.h
 * Author: raquel
 *
 * Created on 16 de junio de 2020, 20:22
 */

#ifndef DRAWING_H
#define DRAWING_H
#include <gtkmm.h>
#include "iostream"
#include <glibmm-2.4/glibmm/refptr.h>
#include <pangomm-1.4/pangomm/layout.h>
#include "Grafo.h"
using namespace std;

class Drawing : public Gtk::DrawingArea {
public:
    Drawing();
    void updateDrawingArea();

protected:
    void draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int posX, int posY, string text);
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
    void dibujarAvion(const Cairo::RefPtr<Cairo::Context>& cr);
    void dibujarNodoDestino(const Cairo::RefPtr<Cairo::Context>& cr);
    void dibujarNodoOrigen(const Cairo::RefPtr<Cairo::Context>& cr);

private:
    Glib::RefPtr<Gdk::Pixbuf> image;
    Glib::RefPtr<Gdk::Pixbuf> image1;
    Grafo* grafo = Grafo::getInstance();

};

#endif /* DRAWING_H */

