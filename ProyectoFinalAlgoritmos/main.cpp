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
#include <vector>
#include <string>
#include "VentanaPrincipal.h"
#include "Itinerario.h"
#include "Cola.h"
#include "Grafo.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
            Glib::RefPtr<Gtk::Application> app =
                Gtk::Application::create(argc, argv, "titulo");
        VentanaPrincipal window;
        return app->run(window);
//    Grafo g;
//    g.agregarNodo("Hola1");
//    g.agregarNodo("Hola2");
//    g.agregarNodo("Hola3");
//    g.agregarNodo("Hola4");
//    g.agregarNodo("Hola5");
//    g.mostrarGrafo();
//    cout << endl;
//
//    g.insertarArista("Hola1", "Hola2");
//    g.insertarArista("Hola3", "Hola1");
//    g.insertarArista("Hola3", "Hola2");
//    cout << endl;
//
//    g.eliminarNodo("Hola5");
//    g.eliminarArista("Hola3", "Hola1");
//    g.mostrarGrafo();
//    cout << endl;
//
//    g.mostrarAristas("Hola1");
//    g.mostrarAristas("Hola3");
//
//    cout << endl;
//    g.mostrarGrafo();
//
//    return 0;

    //    Aerolinea a = Aerolinea("Delta");
    //    Pais p = Pais("Mexico");
    //    PaisDestino pd = PaisDestino("Emiratos");
    //    Cola c;
    //    c.encolar("7am --- 9am");
    //    c.encolar("8am --- 10am");
    //    c.encolar("12am --- 15pm");
    //    c.encolar("15pm --- 17pm");
    //
    //    cout << a.getNombre() << endl;
    //    Itinerario i = Itinerario(a, p, pd);
    //    i.SetCantEspacios(5);
    //    i.SetHorarios(c);
    //    cout << i.toString() << endl;
    //    //    std::vecto<string> hora = c.mostrarCola();
    //    vector<string> horario = c.mostrarCola();
    //    for (int k = 0; k < horario.size(); k++) {
    //        cout<<horario.at(k)<<endl;
    //
    //    }
}
