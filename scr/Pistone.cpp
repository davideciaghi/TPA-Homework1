#include "Livella.h"
#include <iostream>
#include <string.h> 
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;


float Plate_angle (Piston * mypiston1, Piston * mypiston2) {

    float angle = mypiston1->alt_1 + mypiston2->alt_2;

    return angle;

}


Piston* piston_init (float posx, float posy, float alt1, float larg1, float alt2, float larg2){

    // Creo le istanze del pistone
    Piston * pistonC  = new Piston;

    // Associo le grandezze in input alle relative grandezze della struct
    pistonC->pos_x1 = posx;
    pistonC->pos_y1 = posy;

    pistonC->pos_x2 = posx + ((larg1 + larg2)/2);
    pistonC->pos_y2 = posy - alt2;

    pistonC->pos_cx = pistonC->pos_x2 + (larg2/2);
    pistonC->pos_cy = pistonC->pos_y2;

    pistonC->alt_1 = alt1;
    pistonC->larg_1 = larg1;

    pistonC->alt_2 = alt2;
    pistonC->larg_2 = larg2;

    // Ritorno l'oggetto del pistone inizializzato
    return pistonC;

}

Plate* plate_init (float spess, float lungh, float a) {

    // Creo l'istanza della piastra
    Plate * plateC  = new Plate;

    // Associo le grandezze in input alle relative grandezze della struct
    plateC->spessore = spess;
    plateC->lunghezza = lungh;
    plateC->cd = a;




    // Ritorno l'oggetto della piastra inizializzato
    return plateC;

}
