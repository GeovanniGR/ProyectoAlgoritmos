/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Drawing.cpp
 * Author: raquel
 * 
 * Created on 16 de junio de 2020, 20:22
 */

#include "Drawing.h"
#include <gtkmm.h>
#include <glibmm-2.4/glibmm/refptr.h>
#include <pangomm-1.4/pangomm/layout.h>
#include "iostream"

Drawing::Drawing() {
    this->set_size_request(800, 600);
    this->image = Gdk::Pixbuf::create_from_file("assets/airport.png");
    this->image1 = Gdk::Pixbuf::create_from_file("assets/avionAbajo.png");
}

Drawing::Drawing(const Drawing& orig) {
}

Drawing::~Drawing() {
}

bool Drawing::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    int posXnodo = 0;
    int posYnodo = 0;
    int posXavion = 0;
    int posYavion = 0;
    if (!this->grafo->getNombresNodos().empty()) {
        for (int i = 0; i < this->grafo->getNombresNodos().size(); i++) {
            posXnodo = rand() % 700;
            posYnodo = rand() % 500;
//            posXnodo = i * 80;
//            posYnodo = j * 80;
            Gdk::Cairo::set_source_pixbuf(cr, this->image, posXnodo, posYnodo);
            cr->rectangle(posXnodo, posYnodo, 40, 40);
            cr->fill();
            cr->set_source_rgb(0, 0, 0);
            this->draw_text(cr, i * 80, i * 80, this->grafo->getNombresNodos().at(i).getPais());
            if (this->grafo->existe(this->grafo->getNombresNodos().at(i).getPais())) {
//                posXavion = i * 40;
//                posYavion = j * 40;
                Gdk::Cairo::set_source_pixbuf(cr, this->image1, posXavion, posYavion);
                cr->rectangle(posXavion, posYavion, 40, 40);
                cr->fill();
                cr->set_source_rgb(0, 0, 0);
            }
        }
    }
}

void Drawing::draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int posX, int posY, string text) {
    Pango::FontDescription font;

    font.set_size(10 * Pango::SCALE);
    font.set_family("Mukti Narrow"); //Monospace Mukti Narrow
    font.set_weight(Pango::WEIGHT_BOLD);


    Glib::RefPtr<Pango::Layout> layout = create_pango_layout(text);

    layout->set_font_description(font);

    int text_width;
    int text_height;

    //get the text dimensions (it updates the variables -- by reference)
    layout->get_pixel_size(text_width, text_height);

    // Position the text in the middle
    cr->move_to(posX, posY);

    layout->show_in_cairo_context(cr);

} // draw_text

void Drawing::updateDrawingArea() {
    this->queue_draw();
}

