/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaEscogerAerolinea.h
 * Author: geovanni
 *
 * Created on 8 de junio de 2020, 04:02 PM
 */

#ifndef VENTANAESCOGERAEROLINEA_H
#define VENTANAESCOGERAEROLINEA_H
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/fixed.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include <gtkmm-3.0/gtkmm/entry.h>
#include <gtkmm-3.0/gtkmm/comboboxtext.h>
#include <gtkmm-3.0/gtkmm/box.h>
#include <gtkmm.h>
#include <glibmm-2.4/glibmm/refptr.h>
#include <gtkmm-3.0/gtkmm/liststore.h>
#include "ListaAerolineas.h"
#include "Aerolinea_1.h"
#include "Grafo.h"
#include "Usuario.h"
class VentanaEscogerAerolinea : public Gtk::Window {
public:
    VentanaEscogerAerolinea(Usuario* usuario);
    void init();
    void onButtonClickedUp();
    void onButtonClickedDown();
    void onButtonClickedConfirm();
    void loadaerolineas();
    void onButtonClickedReestablecer();
    void onButtonClickedConfirmarVuelo();
    void llenarComboPaisOrigen();
    void llenarComboPaisDestino();
    void clear();
    void cargarItinerario();

protected:

    class ModelColumns : public Gtk::TreeModel::ColumnRecord {
    public:

        ModelColumns() {
            add(m_col_salida);
            add(m_col_llegada);
        }

        Gtk::TreeModelColumn<Glib::ustring> m_col_salida;
        Gtk::TreeModelColumn<int> m_col_llegada;

    };
private:
    ListaAerolineas aerolineas;
    Gtk::Fixed fixed;

    Gtk::Button btnArriba;
    Gtk::Button btnAbajo;
    Gtk::Button btnConfirmarAerolinea;

    Gtk::Entry etAerolinea;

    Gtk::Label lblPaisOrigen;
    Gtk::Label lblPaisDestino;

    Gtk::Button btnCargarItinerario;
    Gtk::Button btnReestablecer;
    Gtk::Button btnConfirmarVuelo;

    Gtk::ComboBoxText cbPaisOrigen;
    Gtk::ComboBoxText cbPaisDestino;

    //tabla
    ModelColumns m_Columns;
    //Child widgets de la tabla:
    Gtk::Box m_VBox;

    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TreeView m_TreeView;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
    Gtk::ButtonBox m_ButtonBox;
    Gtk::Button m_Button_Quit;

    vector<int> horas;
    vector<Pais> nombrePais;
    vector<PaisDestino> PaisesDes;
    //aerolineas
    Aerolinea a1;
    Aerolinea a2;
    Aerolinea a3;
    Aerolinea a4;
    Aerolinea a5;

    Pais p;
    Pais p1;
    Pais p2;
    Pais p3;

    PaisDestino pd1;
    PaisDestino pd2;
    PaisDestino pd3;
    PaisDestino pd4;
    Usuario* usuario;
    string nacionalidad;
    Grafo* grafo=Grafo::getInstance();
};

#endif /* VENTANAESCOGERAEROLINEA_H */

