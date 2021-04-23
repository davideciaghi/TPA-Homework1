#include "Livella.h"
#include <iostream>
#include <string.h> 
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;


Piston* piston_init (float posx, float posy, float alt1, float larg1, float alt2, float larg2){

    // Creo le istanze del pistone
    Piston * pistonC  = new Piston;

    // Associo le grandezze in input alle relative grandezze della struct
    pistonC->pos_x1 = posx;
    pistonC->pos_y1 = posy;

    pistonC->pos_x2 = posx + ((larg1 + larg2)/2);
    pistonC->pos_y2 = posy - alt2;

    // Centri delle coppie rotoidali
    pistonC->pos_cx = pistonC->pos_x2 + (larg2/2);
    pistonC->pos_cy = pistonC->pos_y2;

    pistonC->alt_1 = alt1;
    pistonC->larg_1 = larg1;

    pistonC->alt_2 = alt2;
    pistonC->larg_2 = larg2;

    // Ritorno l'oggetto del pistone inizializzato
    return pistonC;

}

Plate* plate_init (float spess, float lungh, Piston * mypiston1, Piston * mypiston2) {

    // Creo l'istanza della piastra
    Plate * plateC  = new Plate;

    // Associo le grandezze in input alle relative grandezze della struct
    plateC->spessore = spess;
    plateC->lunghezza = lungh;

    // Centro di rotazione dell'asta
    plateC->xC = mypiston1->pos_cx + (mypiston2->pos_cx - mypiston1->pos_cx)/2;
    plateC->yC = mypiston1->pos_cy + (mypiston2->pos_cy - mypiston1->pos_cy)/2;

    // Angolo di rotazione
    plateC->angle = atan((mypiston2->pos_cy - mypiston1->pos_cy)/(mypiston2->pos_cx - mypiston1->pos_cx));

    // Ritorno l'oggetto della piastra inizializzato
    return plateC;

}



void info_parti ( Piston * mypiston1, Piston * mypiston2, Plate * myplate ){
    
    cout << "Pistone di Sinistra: \t\t " << endl;
    cout << "Posizione pistone:  \t\t" << "x: " << mypiston1->pos_x1 <<  ", y: " << mypiston1->pos_y1 <<  endl;
    cout << "Cilindro esterno: \t\t" << "diametro: " << mypiston1->larg_1 << ", altezza: " << mypiston1->alt_1 << endl;
    cout << "Cilindro Interno: \t\t" << "diametro: " << mypiston1->larg_2 << ", altezza: " << mypiston1->alt_2 << endl;
    cout << "Coordinate coppia rotoidale: \t\t" << "x: " << mypiston1->pos_cx <<  ", y: " << mypiston1->pos_cy <<  endl;

    cout << "Pistone di Destra: \t\t " << endl;
    cout << "Posizione pistone:  \t\t" << "x: " << mypiston2->pos_x1 <<  ", y: " << mypiston2->pos_y1 <<  endl;
    cout << "Cilindro esterno: \t\t" << "diametro: " << mypiston2->larg_1 << ", altezza: " << mypiston2->alt_1 << endl;
    cout << "Cilindro Interno: \t\t" << "diametro: " << mypiston2->larg_2 << ", altezza: " << mypiston2->alt_2 << endl;
    cout << "Coordinate coppia rotoidale: \t" << "x: " << mypiston2->pos_cx <<  ", y: " << mypiston2->pos_cy <<  endl;

    cout << "Piastra: \t\t " << endl;
    cout << "Spessore piastra: \t 30" <<  endl;
    cout << "Lunghezza piastra: \t\t 500" << endl;
    cout << "Angolo di inclinazione: \t\t" << myplate->angle << endl;

}
