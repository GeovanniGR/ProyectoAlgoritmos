/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaTransito.cpp
 * Author: raquel
 * 
 * Created on 16 de junio de 2020, 20:21
 */

#include "VentanaTransito.h"

VentanaTransito::VentanaTransito() {
        this->set_title("Transito Aereo");
        this->d.show_all();
        this->add(this->d);
        this->add_events(Gdk::KEY_PRESS_MASK);
        this->start();
}

void* VentanaTransito::run(void* arg) {
     VentanaTransito* mv=reinterpret_cast<VentanaTransito*>(arg);
        mv->updateWindows();
        return 0;
}

void VentanaTransito::start() {
    pthread_create(&thread, 0, run, this);

}

void VentanaTransito::updateWindows() {
    while(true){
            this->d.updateDrawingArea();
            usleep(100000);
        } // while
}

void VentanaTransito::wait() {
     (void)pthread_join(thread, NULL);

}

//VentanaTransito::VentanaTransito(const VentanaTransito& orig) {
//}
//
//VentanaTransito::~VentanaTransito() {
//}

