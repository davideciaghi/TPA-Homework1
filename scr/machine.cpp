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

Machine * machine_init(float posx1, float posx2, float posy, float alt1, float larg1, float larg2, float altS, float altD, float spess, float lung) {

    Machine * machine = new Machine;

    // Inizializzazione della livella
    machine->livella = livella_init(posx1, posx2, posy, alt1, larg1, larg2, altS, altD, spess, lung);

    // Calcolo della corsa, lunghezze e posizione della guida prismatica
    machine->aggancio = aggancio_init(machine);

    // Inizializzazione della guida prismatica
    machine->guida = guida_init (machine->aggancio->posx, machine->aggancio->posy, machine->aggancio->est, machine->aggancio->corsa, spess*0.7, spess*0.7);

    return machine;
}


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



void machine_to_svg(Machine * livellaMac, string fileName, char measures) {

    ofstream mySVG( fileName + ".svg");
    mySVG << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>" << endl;
    mySVG << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">" << endl;

    mySVG << machine_to_ParamSVG( livellaMac, measures);

    mySVG << "</svg>";
    mySVG.close();

}


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


string rotated_guida(Machine * livella2, bool measures) {

    string str="";

    str += "<g transform=\"rotate(" +  to_string(livella2->livella->myplate->angle) + "," + to_string(livella2->livella->mypiston1->pos_cx) + "," + to_string(livella2->livella->mypiston1->pos_cy) + ")\"> \n";
    str += guida_to_SVGstring(livella2->guida, measures);
    str += "</g>";

    return str;
}


void machine_print_info(Machine * livella2) {

    cout << endl << "Informazioni sulla livella:" << endl << endl;
    info_parti(livella2->livella);
    cout << endl << "Informazioni sulla guida:" << endl << endl;
    guida_visualizza_info(livella2->guida);

}


