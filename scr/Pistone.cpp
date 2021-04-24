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

    pistonC->pos_x2 = posx + ((larg1 - larg2)/2);
    pistonC->pos_y2 = posy - alt2;

    // Centri delle coppie rotoidali
    pistonC->pos_cx = pistonC->pos_x2 + (larg2/2);
    pistonC->pos_cy = pistonC->pos_y2;

    // Dimensioni del cilindro interno
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

    // Posizione x e y della piastra prima della rotazione
    plateC->pos_x = mypiston1->pos_cx - 50;
    plateC->pos_y = mypiston1->pos_cy - 15;

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



void livella_to_svg (Piston * mypiston1, Piston * mypiston2, Plate * myplate, string fileName ){

    ofstream mySVG( fileName + ".svg");
    
    mySVG << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>" << endl;

    mySVG << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">" << endl;

    mySVG << livella_to_ParamSVG( mypiston1, mypiston2, myplate );

    mySVG << "</svg>";

    mySVG.close();

}


string livella_to_ParamSVG ( Piston * mypiston1, Piston * mypiston2, Plate * myplate ){

    string str = "";
    
    // Pistone di Sinistra
    str += "<rect  x=\"" + to_string(mypiston1->pos_x2) + "\" y=\"" + to_string(mypiston1->pos_y2) + "\" width=\"" + to_string(mypiston1->larg_2) + "\" height=\"" + to_string(mypiston1->alt_2) +  "\" style=\"fill:rgb(200,200,200);stroke-width:3;stroke:rgb(0,0,0)\" /> \n";
    str += "<rect  x=\"" + to_string(mypiston1->pos_x1) + "\" y=\"" + to_string(mypiston1->pos_y1) + "\" width=\"" + to_string(mypiston1->larg_1) + "\" height=\"" + to_string(mypiston1->alt_1) +  "\" style=\"fill:rgb(0,200,0);stroke-width:3;stroke:rgb(0,0,0)\" /> \n";

    // Pistone di Destra
    str += "<rect  x=\"" + to_string(mypiston2->pos_x2) + "\" y=\"" + to_string(mypiston2->pos_y2) + "\" width=\"" + to_string(mypiston2->larg_2) + "\" height=\"" + to_string(mypiston2->alt_2) +  "\" style=\"fill:rgb(200,200,200);stroke-width:3;stroke:rgb(0,0,0)\" /> \n";
    str += "<rect  x=\"" + to_string(mypiston2->pos_x1) + "\" y=\"" + to_string(mypiston2->pos_y1) + "\" width=\"" + to_string(mypiston2->larg_1) + "\" height=\"" + to_string(mypiston2->alt_1) +  "\" style=\"fill:rgb(0,200,0);stroke-width:3;stroke:rgb(0,0,0)\" /> \n";
    
    // Lastra:
    str += "<g transform=\"rotate(" + to_string(myplate->angle) + "," + to_string(myplate->xC) + "," + to_string(myplate->yC) + ")\"> \n";
    str += "<rect  x=\"" + to_string(myplate->pos_x) + "\" y=\"" + to_string(myplate->pos_y) + "\" width=\"" + to_string(myplate->lunghezza) + "\" height=\"" + to_string(myplate->spessore) + "\" style=\"fill:rgb(0,120,0);stroke-width:3;stroke:rgb(200,200,200)\" /> \n";
    str += "<rect  x=\"" + to_string(myplate->pos_x) + "\" y=\"" + to_string(myplate->pos_y - 28) + "\" width=\"" + to_string(myplate->lunghezza) + "\" height=\"0.1\"" + " style=\"fill:rgb(0,0,0);stroke-width:1;stroke:rgb(225,225,225)\" /> \n";

    // Coppie rotoidali
    str += "<circle cx=\"" + to_string(mypiston1->pos_cx) + "\" cy=\"" + to_string(mypiston1->pos_cy) + "\" r=\"20\" stroke=\"black\" stroke-width=\"3\" fill=\"lightgrey\" /> \n";
    str += "<circle cx=\"" + to_string(mypiston2->pos_cx) + "\" cy=\"" + to_string(mypiston2->pos_cy) + "\" r=\"20\" stroke=\"black\" stroke-width=\"3\" fill=\"lightgrey\" /> \n";
    str += "</g> \n";

    return str;
}
