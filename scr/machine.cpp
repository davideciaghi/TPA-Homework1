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

    machine->pos_x1 = posx1;
    machine->pos_x2 = posx2;
    machine->pos_y = posy;
    machine->alt_1 = alt1;
    machine->larg_1 = larg1;
    machine->alt_sx = altS;
    machine->alt_dx = altD;
    machine->spessore = spess;
    machine->lunghezza = lung;

    // Inizializzazione della livella
    machine->livella = livella_init(posx1, posx2, posy, alt1, larg1, larg2, altS, altD, spess, lung);

    // Calcolo della corsa, lunghezze e posizione della guida prismatica
    machine->aggancio = aggancio_init(machine);

    // Inizializzazione della guida prismatica
    machine->guida = guida_init (machine->aggancio->posx, machine->aggancio->posy, machine->aggancio->est, machine->aggancio->corsa, spess, spess);

    return machine;
}


Connection * aggancio_init(Machine * machine) {

    Connection * conn = new Connection;

    // La lunghezza della guida prismatica coincide con la distanza della prima coppia rotoidale e la fine delal piastra della livella
    conn->est = machine->livella->myplate->lunghezza - 50 - (machine->livella->myplate->spessore)/2;

    // Il centro della guida prismatica
    conn->posx = machine->livella->mypiston1->pos_cx + (conn->est)/2;
    conn->posy = machine->livella->mypiston1->pos_cy;
    
    // Corsa della guida prismatica
    conn->corsa = (machine->livella->mypiston1->pos_cx - machine->livella->mypiston2->pos_cx)/ cos(machine->livella->myplate->angle);
    
    


    return conn;

}

