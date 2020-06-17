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
using namespace std;
class Drawing : public Gtk::DrawingArea{
public:
    Drawing();
    Drawing(const Drawing& orig);
    virtual ~Drawing();
    void updateDrawingArea();
protected:
     bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
private:
    
};

#endif /* DRAWING_H */

