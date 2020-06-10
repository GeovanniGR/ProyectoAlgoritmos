/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: geovanni
 *
 * Created on 9 de junio de 2020, 07:55 PM
 */

#include <cstdlib>
#include <list>
#include <string>
#include <iostream>

#include "VentanaPrincipal.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Glib::RefPtr<Gtk::Application> app =
                Gtk::Application::create(argc, argv, "titulo");
        VentanaPrincipal window;
        return app->run(window);
//    return 0;
}

