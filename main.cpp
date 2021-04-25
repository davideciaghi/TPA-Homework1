#include <iostream>
#include "libraries/Livella.h"

using namespace std;

int main() {

    Piston * mypiston1;
    Piston * mypiston2;
    Plate * myplate;
    Param * myparam;




    // Inizializzazione dei parmetri dei dispositivi
    int nPar = 10; // Number of parameters
    myparam = parameters_init( nPar );
    
    //                           posx               posy                alt1            larg1               alt2                larg2
    mypiston1 = piston_init( myparam->arr[0],  myparam->arr[1],  myparam->arr[3],  myparam->arr[2],   myparam->arr[6],   myparam->arr[5]);
    mypiston2 = piston_init( myparam->arr[4],  myparam->arr[1],  myparam->arr[3],  myparam->arr[2],   myparam->arr[7],   myparam->arr[5]);

    //                          spess.              lungh.
    myplate = plate_init( myparam->arr[8],   myparam->arr[9], mypiston1, mypiston2);


    // Informazioni sulle parti del meccanismo
    cout << "Informazioni su pistoni e piastra:" << endl;
    info_parti( mypiston1, mypiston2, myplate );


    // Creazione del file .svg
    string NameFile = "";
    cout << "Inserire il nome del file .svg che verrà creato: ";
    cin >> NameFile;

    livella_to_svg(mypiston1, mypiston2, myplate, NameFile);


    // 
    livella_destroy(mypiston1, mypiston2, myplate, myparam);

    return 0;

}
