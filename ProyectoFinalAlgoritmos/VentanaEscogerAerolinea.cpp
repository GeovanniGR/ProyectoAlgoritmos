/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaEscogerAerolinea.cpp
 * Author: geovanni
 * 
 * Created on 8 de junio de 2020, 04:02 PM
 */

#include "VentanaEscogerAerolinea.h"
#include "ListaAerolineas.h"
#include "Aerolinea_1.h"
#include "Pais.h"
#include "PaisDestino.h"
#include "Cola.h"
#include "Itinerario.h"
#include  <chrono>
#include <ctime>

VentanaEscogerAerolinea::VentanaEscogerAerolinea(Usuario* usuario) {
    this->set_size_request(800, 600);
    this->set_title("Aerolineas Disponibles");
    this->usuario = usuario;
    loadaerolineas();
    init();
}//Constructor

void VentanaEscogerAerolinea::init() {
    this->fixed.put(this->cbPaisDestino, 400, 100);
    this->fixed.put(this->cbPaisOrigen, 400, 50);

    this->btnCargarItinerario.set_label("Cargar Itinerario");
    this->btnCargarItinerario.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::cargarItinerario));
    this->fixed.put(this->btnCargarItinerario, 300, 450);

    this->btnConfirmarVuelo.set_label("Confirmar Vuelo");
    this->btnConfirmarVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedConfirmarVuelo));
    this->fixed.put(this->btnConfirmarVuelo, 450, 450);

    this->etAerolinea.set_text(this->aerolineas->firstInlist().getNombre());
    this->fixed.put(this->etAerolinea, 20, 150);

    this->lblPaisOrigen.set_text("Despegue");
    this->fixed.put(this->lblPaisOrigen, 300, 50);

    this->lblPaisDestino.set_text("Destino");
    this->fixed.put(this->lblPaisDestino, 300, 100);

    this->btnArriba.add_pixlabel("assets/arriba.png", "");

    this->btnArriba.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedUp));
    this->fixed.put(this->btnArriba, 50, 50);

    this->btnAbajo.add_pixlabel("assets/abajo.png", "");
    this->btnAbajo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedDown));
    this->fixed.put(this->btnAbajo, 50, 200);

    this->btnConfirmarAerolinea.set_label("Confirmar Aerolinea");
    this->btnConfirmarAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedConfirm));
    this->fixed.put(this->btnConfirmarAerolinea, 20, 350);

    this->btnReestablecer.set_label("Reestablecer");
    this->btnReestablecer.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedReestablecer));
    this->fixed.put(this->btnReestablecer, 20, 400);

    this->m_TreeView.set_size_request(200, 200);

    this->fixed.put(this->m_TreeView, 300, 200);

    this->add(this->fixed);
    this->show_all_children();
}//init

void VentanaEscogerAerolinea::loadaerolineas() {
    //paises Origen
    this->p = Pais("Mexico");
    this->p1 = Pais("Colombia");
    this->p2 = Pais("Emiratos");
    this->p3 = Pais("Costa Rica");

    this->pd1 = PaisDestino("Mexico", "Guatemala");
    this->pd2 = PaisDestino("Colombia", "Venezuela");
    this->pd3 = PaisDestino("Emiratos", "Inglaterra");
    this->pd4 = PaisDestino("Costa Rica", "Colombia");
    pd1.setPosX(4);
    pd1.setPosY(50);
    pd2.setPosX(40);
    pd2.setPosY(250);
    pd3.setPosX(75);
    pd3.setPosY(450);
    pd4.setPosX(400);
    pd4.setPosY(100);
    this->PaisesDes.push_back(pd1);
    this->PaisesDes.push_back(pd2);
    this->PaisesDes.push_back(pd3);
    this->PaisesDes.push_back(pd4);
    vector<Pais> paisOrigen;
    vector<PaisDestino> paisDestino;

    //cargarGrafo
    p.setPosX(4);
    p.setPosY(50);
    p1.setPosX(40);
    p1.setPosY(250);
    p2.setPosX(75);
    p2.setPosY(450);
    p3.setPosX(400);
    p3.setPosY(100);
    this->grafo->agregarNodo("Mexico");
    this->grafo->agregarNodo("Colombia");
    this->grafo->agregarNodo("Emiratos");
    this->grafo->agregarNodo("Costa Rica");
    this->nombrePais.push_back(p);
    this->nombrePais.push_back(p1);
    this->nombrePais.push_back(p2);
    this->nombrePais.push_back(p3);
    this->grafo->setNombresNodos(this->nombrePais);
    this->grafo->setPaisDes(this->PaisesDes);
    //a1 "Avianca"
    paisOrigen.push_back(p);
    paisOrigen.push_back(p1);
    paisDestino.push_back(pd4);
    paisDestino.push_back(pd1);
    a1 = Aerolinea("Avianca", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();

    //a2 "CopaAirlines"
    paisOrigen.push_back(p3);
    paisOrigen.push_back(p2);
    paisDestino.push_back(pd2);
    paisDestino.push_back(pd1);
    a2 = Aerolinea("CopaAirlines", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();

    //a3 "Emiratos"
    paisOrigen.push_back(p);
    paisOrigen.push_back(p2);
    paisDestino.push_back(pd2);
    paisDestino.push_back(pd4);
    a3 = Aerolinea("Emiratos", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();

    //a4 "BlueJet"
    paisOrigen.push_back(p1);
    paisOrigen.push_back(p3);
    paisDestino.push_back(pd4);
    paisDestino.push_back(pd1);
    a4 = Aerolinea("BlueJet", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();

    //a5 "Delta"
    paisOrigen.push_back(p);
    paisOrigen.push_back(p1);
    paisDestino.push_back(pd2);
    paisDestino.push_back(pd3);
    a5 = Aerolinea("Delta", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();

    this->aerolineas->insert(a1);
    this->aerolineas->insert(a2);
    this->aerolineas->insert(a3);
    this->aerolineas->insert(a4);
    this->aerolineas->insert(a5);
}//loadaerolineas

void VentanaEscogerAerolinea::onButtonClickedConfirm() {
    llenarComboPaisDestino();
    llenarComboPaisOrigen();
}//onButtonClickedConfirm

void VentanaEscogerAerolinea::onButtonClickedDown() {
    this->etAerolinea.set_text(this->aerolineas->showNext(this->etAerolinea.get_text().raw()));
}//onButtonClickedDown

void VentanaEscogerAerolinea::onButtonClickedUp() {
    this->etAerolinea.set_text(this->aerolineas->showPrevious(this->etAerolinea.get_text().raw()));
}//onButtonClickedDown

void VentanaEscogerAerolinea::clear() {
    this->m_refTreeModel.clear();
}//clear

void VentanaEscogerAerolinea::llenarComboPaisOrigen() {
    if (this->etAerolinea.get_text().raw() == this->aerolineas->resultado(this->etAerolinea.get_text().raw())) {
        vector<Pais> pd = this->aerolineas->paisesO(this->etAerolinea.get_text().raw());
        for (int i = 0; i < pd.size(); i++) {
            this->cbPaisOrigen.append(pd.at(i).getPais());
        }//forexport
    }//if
}//llenarComBoxOrigen

void VentanaEscogerAerolinea::llenarComboPaisDestino() {

    if (this->etAerolinea.get_text().raw() == this->aerolineas->resultado(this->etAerolinea.get_text().raw())) {
        vector<PaisDestino> pd = this->aerolineas->paisesD(this->etAerolinea.get_text().raw());
        for (int i = 0; i < pd.size(); i++) {
            this->cbPaisDestino.append(pd.at(i).getNombrePais());
        }//for
    }//if

}//llenarComboBoxDestino

void VentanaEscogerAerolinea::onButtonClickedConfirmarVuelo() {
    string prueba;
    string prueba2;
    //como obtener los datos para el grafo
    if (this->usuario->getNacionalidad() != this->nacionalidad) {
        this->grafo->insertarArista(this->cbPaisOrigen.get_active_text(), this->cbPaisDestino.get_active_text());
        Glib::RefPtr<Gtk::TreeSelection> selection = this->m_TreeView.get_selection();
        Gtk::TreeModel::iterator selectedRow = selection->get_selected();
        Gtk::TreeModel::Row row = *selectedRow;
        Glib::ustring port = row.get_value(m_Columns.m_col_salida);
        for (int i = 0; i < port.length(); i++) {
            if (port.at(i) != ':') {
                prueba += port.at(i);
            } else {
                break;
            }
        }
        for (int j = 0; j < port.length(); j++) {
            if (port.at(j) == '>') {
                for (int k = 9; k < port.length(); k++) {
                    if (port.at(k) != ':') {
                        prueba2 += port.at(k);
                    } else {
                        break;
                    }
                }
            }
        }

        //        cout << "Soy prueba 2: " << prueba2 << endl;

        this->grafo->setHoraDibujar(prueba);
        this->grafo->setHoraDibujarLlegada(prueba2);

        //        cout << endl << "HoraDibujar: " << this->grafo->getHoraDibujar() << endl;
        //        cout << endl << "HoraDibujarLlegada: " << this->grafo->getHoraDibujarLlegada() << endl;

    } else {
        Gtk::MessageDialog dialogo(*this, "Su nacionalidad le prohibe la entrada al pais destino", false, Gtk::MESSAGE_QUESTION);
        dialogo.set_secondary_text("");
        dialogo.run();
    }
    Gtk::MessageDialog dialogo(*this, "Buen Viaje", false, Gtk::MESSAGE_QUESTION);
    dialogo.set_secondary_text("");
    dialogo.run();
}//onButtonClickedConfirmarVuelo

void VentanaEscogerAerolinea::onButtonClickedReestablecer() {
    this->cbPaisDestino.remove_all();
    this->cbPaisOrigen.remove_all();
    this->m_TreeView.remove_all_columns();
}//onButtonClickedReestablecer

void VentanaEscogerAerolinea::cargarItinerario() {
    //crear el tree model
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);

    Cola colaSalida;
    Cola colaLlegada;

    //Itinerario Avianca
    colaSalida.encolar(15);
    colaSalida.encolar(5);
    colaLlegada.encolar(20);
    colaLlegada.encolar(8);
    Itinerario it1(a1, p, pd4);
    it1.setHorariosSalida(colaSalida);
    it1.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    // Itinerario Avianca
    colaSalida.encolar(17);
    colaSalida.encolar(15);
    colaLlegada.encolar(22);
    colaLlegada.encolar(19);
    Itinerario it2(a1, p1, pd1);
    it2.setHorariosSalida(colaSalida);
    it2.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "CopaAirlines"
    colaSalida.encolar(0);
    colaSalida.encolar(16);
    colaLlegada.encolar(5);
    colaLlegada.encolar(20);
    Itinerario it3(a2, p3, pd2);
    it3.setHorariosSalida(colaSalida);
    it3.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "CopaAirlines"
    colaSalida.encolar(2);
    colaSalida.encolar(16);
    colaLlegada.encolar(7);
    colaLlegada.encolar(21);
    Itinerario it4(a2, p2, pd1);
    it4.setHorariosSalida(colaSalida);
    it4.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "Emiratos"
    colaSalida.encolar(18);
    colaSalida.encolar(8);
    colaLlegada.encolar(23);
    colaLlegada.encolar(12);
    Itinerario it5(a3, p, pd2);
    it5.setHorariosSalida(colaSalida);
    it5.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "Emiratos"
    colaSalida.encolar(13);
    colaSalida.encolar(14);
    colaLlegada.encolar(16);
    colaLlegada.encolar(17);
    Itinerario it6(a3, p2, pd4);
    it6.setHorariosSalida(colaSalida);
    it6.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "BlueJet"
    colaSalida.encolar(15);
    colaSalida.encolar(1);
    colaLlegada.encolar(22);
    colaLlegada.encolar(6);
    Itinerario it7(a4, p1, pd4);
    it7.setHorariosSalida(colaSalida);
    it7.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "BlueJet"
    colaSalida.encolar(20);
    colaSalida.encolar(23);
    colaLlegada.encolar(23);
    colaLlegada.encolar(2);
    Itinerario it8(a4, p3, pd1);
    it8.setHorariosSalida(colaSalida);
    it8.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "Delta"
    colaSalida.encolar(15);
    colaSalida.encolar(19);
    colaLlegada.encolar(20);
    colaLlegada.encolar(23);
    Itinerario it10(a5, p1, pd3);
    it10.setHorariosSalida(colaSalida);
    it10.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "Delta"
    colaSalida.encolar(3);
    colaSalida.encolar(23);
    colaLlegada.encolar(20);
    colaLlegada.encolar(5);
    Itinerario it9(a5, p, pd2);
    it9.setHorariosSalida(colaSalida);
    it9.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //vector de itinerarios
    vector<Itinerario> horarios;
    horarios.push_back(it1);
    horarios.push_back(it2);
    horarios.push_back(it3);
    horarios.push_back(it4);
    horarios.push_back(it5);
    horarios.push_back(it6);
    horarios.push_back(it7);
    horarios.push_back(it8);
    horarios.push_back(it9);
    horarios.push_back(it10);

    //vector de horas (salida --> llegada)
    vector<int> vectorHorarioDeSalida;
    vector<int> vectHorarioDeLlegada;

    vector<string> prueba;
    stringstream s;
    time_t now = time(0);
    tm calendar_time = *std::localtime(std::addressof(now));

    for (int i = 0; i < horarios.size(); i++) {
        if (horarios.at(i).getAerolinea().getNombre() == this->etAerolinea.get_text().raw() &&
                horarios.at(i).getPaisorigen().getPais() == this->cbPaisOrigen.get_active_text() &&
                horarios.at(i).getPaisdestino().getNombrePais() == this->cbPaisDestino.get_active_text()) {
            this->nacionalidad = horarios.at(i).getPaisdestino().getNacionalidadMigracion();
//            cout << this->nacionalidad;
            vectorHorarioDeSalida = horarios.at(i).getHorariosSalida().mostrarCola();
            vectHorarioDeLlegada = horarios.at(i).getHorariosLlegada().mostrarCola();
            this->grafo->setHorarioLlegada(vectHorarioDeLlegada);
            this->grafo->setHorarioSalida(vectorHorarioDeSalida);
            for (int i = 0; i < vectorHorarioDeSalida.size(); i++) {
                if (vectorHorarioDeSalida.at(i) >= calendar_time.tm_hour || vectorHorarioDeSalida.at(i) == 0) {
                    s << vectorHorarioDeSalida.at(i) << ":00" << "--->" << vectHorarioDeLlegada.at(i) << ":00";
                    prueba.push_back(s.str());
                    s.str("");
                }//if
            }//for

            for (int i = 0; i < prueba.size(); i++) {
                Gtk::TreeModel::Row row = *(m_refTreeModel->append());
                row[m_Columns.m_col_salida] = prueba.at(i);
            }//for
        }//if
    }//for

    m_TreeView.append_column("HORARIOS", m_Columns.m_col_salida);
}//cargarItinerario
