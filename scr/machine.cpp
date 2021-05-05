#include "Livella.h"
#include "guida.h"
#include "machine.h"
#include <iostream>
#include <string.h> 
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;


// Funzione di inizializzazione della machine
Machine * machine_init(float posx1, float posx2, float posy, float alt1, float larg1, float larg2, float altS, float altD, float spess, float lung) {

    Machine * machine = new Machine;

    // Inizializzazione della livella e controllo integrità dei parametri
    machine->livella = livella_init(posx1, posx2, posy, alt1, larg1, larg2, altS, altD, spess, lung);
    
    // Controllo e modifica dei parametri della livella, solo se la livella è consistente allora posso costruire la guida prismatica
    param_control(machine->livella);
    device_control(machine->livella);

    // Calcolo della corsa, lunghezze e posizione della guida prismatica
    machine->aggancio = aggancio_init(machine);

    // Inizializzazione della guida prismatica
    machine->guida = guida_init (machine->aggancio->posx, machine->aggancio->posy, machine->aggancio->est, machine->aggancio->corsa, spess*0.7, spess*0.7);
    
    if( machine->guida == NULL ) {
        cout << "Errore nei parametri! Non sono riuscito a creare una struttura consistente, riprovare." << endl << endl;
        machine = NULL;
    }

    return machine;
}


// Funzione che definisce i principali parametri di posizionamento della guida prismatica sulla piastra della livella 
Connection * aggancio_init(Machine * machine) {

    Connection * conn = new Connection;

    // La lunghezza della guida prismatica coincide con la distanza della prima coppia rotoidale e la fine delal piastra della livella
    conn->est = machine->livella->myplate->lunghezza - 50 - (machine->livella->myplate->spessore)/2;
    // Coordinate centro della guida prismatica
    conn->posx = machine->livella->mypiston1->pos_cx + (conn->est)/2;
    conn->posy = machine->livella->mypiston1->pos_cy;
    // Corsa della guida prismatica
    conn->corsa = (machine->livella->mypiston2->pos_cx - machine->livella->mypiston1->pos_cx)/ cos((machine->livella->myplate->angle)*M_PI/180);

    return conn;

}


// Funzione che realizza il file svg
void machine_to_svg(Machine * livellaMac, string fileName, char measures) {

    ofstream mySVG( fileName + ".svg");
    mySVG << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>" << endl;
    mySVG << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">" << endl;

    mySVG << machine_to_ParamSVG( livellaMac, measures);

    mySVG << "</svg>";
    mySVG.close();

}

// Funzione che implementa nel file svg la livella e la guida
string machine_to_ParamSVG(Machine * livellaMac, char measures) {
    
    string str = "";

    str += livella_to_ParamSVG(livellaMac->livella);
    if (measures == 'Y') {        
        str += rotated_guida(livellaMac, 1);
        str += livella_to_MeasureSVG(livellaMac->livella);
    } else {
        str += rotated_guida(livellaMac, 0);
    }

    return str;
    
}

// Stringa file svg di rotazione della guida prismatica
string rotated_guida(Machine * livellaMac, bool measures) {

    string str="";

    str += "<g transform=\"rotate(" +  to_string(livellaMac->livella->myplate->angle) + "," + to_string(livellaMac->livella->mypiston1->pos_cx) + "," + to_string(livellaMac->livella->mypiston1->pos_cy) + ")\"> \n";
    str += guida_to_SVGstring(livellaMac->guida, measures);
    str += "</g>";

    return str;
}


// Funzione che stampa i parametri della machine 
void machine_print_info(Machine * livellaMac) {

    cout << endl << "Informazioni sulla livella:" << endl << endl;
    info_parti(livellaMac->livella);
    cout << endl << "Informazioni sulla guida:" << endl << endl;
    guida_visualizza_info(livellaMac->guida);

}


// Funzione distruggi machine
void machine_destroy(Machine * livellaMac) {
    
    delete livellaMac->livella->mypiston1;
    delete livellaMac->livella->mypiston2;
    delete livellaMac->livella->myplate;
    delete livellaMac->guida;
    delete livellaMac;
    
}