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

Drawing::Drawing() {
    this->set_size_request(800, 600);
    this->image = Gdk::Pixbuf::create_from_file("assets/airport.png");
    this->image1 = Gdk::Pixbuf::create_from_file("assets/airplane.png");
}//constructor

bool Drawing::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    if (!this->grafo->getNombresNodos().empty()) {
        for (int i = 0; i < this->grafo->getNombresNodos().size(); i++) {
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
                    }
                }

                time_t now = time(0);
                tm calendar_time = *std::localtime(std::addressof(now));
                for (int m = 0; m < this->grafo->getHorarioSalida().size(); m++) {
                    for (int n = 0; n < this->grafo->getHorarioLlegada().size(); n++) {
                        int hora1 = stoi(this->grafo->getHoraDibujar().c_str());
                        int hora2 = stoi(this->grafo->getHoraDibujarLlegada().c_str());

                        if (hora1 >= calendar_time.tm_hour && hora2 < calendar_time.tm_hour) {
                            //                            if (hora2 < calendar_time.tm_hour) {
                            Gdk::Cairo::set_source_pixbuf(cr, this->image1, this->grafo->getNombresNodos().at(i).getPosX() + 65, this->grafo->getNombresNodos().at(i).getPosY());
                            cr->rectangle(this->grafo->getNombresNodos().at(i).getPosX() + 65, this->grafo->getNombresNodos().at(i).getPosY(), 40, 40);
                            cr->fill();
                            // 2    >=  hora1  ---  hora2     <   3
                            //                            }//if
                        }//for
                    }//for
                }//for
            }//if
        }//for
    }//if
}//on_draw

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
