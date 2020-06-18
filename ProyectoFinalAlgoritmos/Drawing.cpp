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
    this->image1 = Gdk::Pixbuf::create_from_file("assets/airplane.png");
}

Drawing::Drawing(const Drawing& orig) {
}

Drawing::~Drawing() {
}

bool Drawing::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    if (!this->grafo->getNombresNodos().empty()) {
        //        cout<<"no esta vacio"<<endl;
        for (int i = 0; i < this->grafo->getNombresNodos().size(); i++) {
            //                        cout<<this->grafo->getNombresNodos().at(i).getPosX();
            //                        cout<<this->grafo->getNombresNodos().at(i).getPosY();
            this->grafo->getNombresNodos().at(i).draw(cr);
            cr->set_source_rgb(0, 0, 0);
            this->draw_text(cr, this->grafo->getNombresNodos().at(i).getPosX(), this->grafo->getNombresNodos().at(i).getPosY(), this->grafo->getNombresNodos().at(i).getPais());
            if (this->grafo->existe(this->grafo->getNombresNodos().at(i).getPais())) {
                vector<string> nombres = this->grafo->arista(this->grafo->getNombresNodos().at(i).getPais());
                for (int j = 0; j < nombres.size(); j++) {
                    for (int k = 0; k < this->grafo->getPaisDes().size(); k++) {
                        if (nombres.at(j).compare(this->grafo->getPaisDes().at(k).getNombrePais()) == 0) {
                            Gdk::Cairo::set_source_pixbuf(cr, this->image, this->grafo->getNombresNodos().at(i).getPosX() + 150, this->grafo->getNombresNodos().at(i).getPosY());
                            cr->rectangle(this->grafo->getNombresNodos().at(i).getPosX() + 150, this->grafo->getNombresNodos().at(i).getPosY(), 40, 40);
                            cr->fill();
                            cr->set_source_rgb(0, 0, 0);
                            this->draw_text(cr, this->grafo->getNombresNodos().at(i).getPosX() + 150, this->grafo->getNombresNodos().at(i).getPosY(), this->grafo->getPaisDes().at(k).getNombrePais());
                        }
                        //                        this->grafo->getPaisDes().at(k).draw(cr);
                    }
                }

                Gdk::Cairo::set_source_pixbuf(cr, this->image1, this->grafo->getNombresNodos().at(i).getPosX() + 65, this->grafo->getNombresNodos().at(i).getPosY());
                cr->rectangle(this->grafo->getNombresNodos().at(i).getPosX() + 65, this->grafo->getNombresNodos().at(i).getPosY(), 40, 40);
                cr->fill();
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

