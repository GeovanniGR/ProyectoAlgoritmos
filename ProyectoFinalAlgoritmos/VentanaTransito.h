/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaTransito.h
 * Author: raquel
 *
 * Created on 16 de junio de 2020, 20:21
 */

#ifndef VENTANATRANSITO_H
#define VENTANATRANSITO_H
#include <gtkmm.h>
#include "Drawing.h"
class VentanaTransito : public Gtk::Window {
public:
    VentanaTransito();
    void start();
    void wait();
    //    VentanaTransito(const VentanaTransito& orig);
    //    virtual ~VentanaTransito();
private:
    void updateWindows();
    static void* run(void* arg);
     
    Drawing d;

    pthread_t thread;
};

#endif /* VENTANATRANSITO_H */

