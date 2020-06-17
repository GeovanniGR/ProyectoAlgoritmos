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
#include "iostream"
Drawing::Drawing() {
    this->set_size_request(800, 600);
}

Drawing::Drawing(const Drawing& orig) {
}

Drawing::~Drawing() {
}

bool Drawing::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

}

void Drawing::updateDrawingArea() {
    this->queue_draw();
}

