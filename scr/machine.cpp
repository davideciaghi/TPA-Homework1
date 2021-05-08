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


Machine * machine_from_console(){

    Machine * first_machine;

    float posx1, posx2, posy, alt1, larg1, larg2, altS, altD, spess, lung;
    
     cout << "Inserire posizione x del primo pistone: ";
     cin >> posx1;
     cout << "Inserire posizione x del secondo pistone: ";
     cin >> posx2;
     cout << "Inserire posizione y dei due pistoni: ";
     cin >> posy;
     cout << "Inserire altezza del cilindro esterno: ";
     cin >> alt1;
     cout << "Inserire larghezza del cilindro esterno: ";
     cin >> larg1;
     cout << "Inserire larghezza del cilindo interno: ";
     cin >> larg2;
     cout << "Inserire estensione del del primo pistone: ";
     cin >> altS;
     cout << "Inserire estensione del secondo pistone: ";
     cin >> altD;
     cout << "Inserire spessore della piastra: ";
     cin >> spess;
     cout << "Inserire lunghezza della piastra: ";
     cin >> lung;

    first_machine = machine_init(posx1, posx2, posy, alt1, larg1, larg2, altS, altD, spess, lung);

    return first_machine;
    
}



// Funzione di inizializzazione della machine
Machine * machine_init(float posx1, float posx2, float posy, float alt1, float larg1, float larg2, float altS, float altD, float spess, float lung) {

    Machine * machine = new Machine;

    // Inizializzazione della livella e controllo integrità dei parametri direttmente dentro la funzione init.
    machine->livella = livella_init(posx1, posx2, posy, alt1, larg1, larg2, altS, altD, spess, lung);
    
    // Solo se la livella è corretta vado a costruire la guida
    if (machine->livella == NULL) {

        cout << endl << "Procedo con la distruzione della machine." << endl;
        livella_destroy(machine->livella);
        return NULL;

    } else {

        // Calcolo della corsa, lunghezze e posizione della guida prismatica
        machine->aggancio = aggancio_init(machine);

        // Inizializzazione della guida prismatica
        machine->guida = guida_init (machine->aggancio->posx, machine->aggancio->posy, machine->aggancio->est, machine->aggancio->corsa, spess*0.7, spess*0.7);
        
        return machine;

    }
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


// Funzione che stampa i parametri della machine 
void machine_print_info(Machine * livellaMac) {
    
    if (livellaMac == NULL) {

        cout << endl << "Impossibile riportare le informazioni della machine." << endl;

    } else {

        cout << endl << "Informazioni sulla livella:" << endl << endl;
        info_parti(livellaMac->livella);
        cout << endl << "Informazioni sulla guida:" << endl << endl;
        guida_visualizza_info(livellaMac->guida);
    }
}



// Funzione che realizza il file svg
void machine_to_svg(Machine * livellaMac) {

    if (livellaMac == NULL) {

        cout << endl << "Impossibile creare la livella nel file svg." << endl;

    } else {

        string fileName = "";
        char measures;
        cout << endl << "Inserire il nome del file .svg che verrà creato: ";
        cin >> fileName;
        cout << endl << "Includere le misure nel file .svg ?  Y/n: ";
        cin >> measures;

        ofstream mySVG("../" + fileName + ".svg");
        mySVG << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>" << endl;
        mySVG << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">" << endl;

        mySVG << machine_to_ParamSVG( livellaMac, measures);

        mySVG << "</svg>";
        mySVG.close();


    }
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



// Funzione distruggi machine
void machine_destroy(Machine * livellaMac) {
    
    if (livellaMac == NULL) {

        cout << endl << "Machine distrutta correttamente." << endl << endl;
        return;
    } 

    delete livellaMac->livella->mypiston1;
    delete livellaMac->livella->mypiston2;
    delete livellaMac->livella->myplate;
    delete livellaMac->guida;
    delete livellaMac;

    cout << endl << "Machine distrutta correttamente." << endl << endl; 
    
}