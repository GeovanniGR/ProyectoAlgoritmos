/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaAdministracion.h
 * Author: raquel
 *
 * Created on 2 de julio de 2020, 17:32
 */

#ifndef VENTANAADMINISTRACION_H
#define VENTANAADMINISTRACION_H
#include  <gtkmm.h>
#include "iostream"
#include <string>
#include "Pais.h"
#include "PaisDestino.h"
#include "Aerolinea_1.h"
#include "ListaAerolineas.h"
#include <vector>
using namespace std;

class VentanaAdministracion : public Gtk::Window {
public:
    VentanaAdministracion();
    void init();
    void onButtonaddPaises();
    void onButtonGuardar();
    //    VentanaAdministracion(const VentanaAdministracion& orig);
    //    virtual ~VentanaAdministracion();
private:
     ListaAerolineas* aerolineas=ListaAerolineas::getInstance();
    
    Pais paisOrigen;
    PaisDestino paisDestino;
    
    Gtk::Entry etNombre;
    Gtk::Label lblNombre;
    Gtk::Entry etPaisOrigen;
    Gtk::Label lblPaisOrigen;
    Gtk::Entry etPaisDestino;
    Gtk::Label lblPaisDestino;
    Gtk::Entry etMigracion;
    Gtk::Label lblMigracion;
    
    Gtk::ComboBoxText cbPaisOrigen;
    Gtk::ComboBoxText cbPaisDestino;
    
    Aerolinea aerolinea;
    
    vector<Pais> paisesOrigen;
    vector<PaisDestino> paisesDestino;
    
    Gtk::Fixed fixed;
    
    Gtk::Button btnGuardarAerolinea;
    Gtk::Button btnAgregarPaises;
};

#endif /* VENTANAADMINISTRACION_H */

