#include <iostream>
#include "libraries/Livella.h"

using namespace std;

int main() {

    Piston * mypiston1;
    Piston * mypiston2;
    Plate * myplate;

    cout << "Distanza fissa tra i pistoni di: 350" << endl;

    //                       posx  posy  alt1 larg1  alt2  larg2
    mypiston1 = piston_init( 100,  400,  150,  50,   130,   20);
    mypiston2 = piston_init( 500,  400,  150,  50,   70,   20);

    myplate = plate_init(30, 500, mypiston1, mypiston2);


    // Informazioni sulle parti del meccanismo
    cout << "Informazioni su pistoni e piastra:" << endl;
    info_parti( mypiston1, mypiston2, myplate );


    // Creazione del file .svg

    string NameFile = "ProvaSVG";

    livella_to_svg( mypiston1, mypiston2, myplate, NameFile);

    return 0;

}
