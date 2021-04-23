#include <iostream>
#include "libraries/Livella.h"

using namespace std;

int main() {

    Piston * mypiston1;
    Piston * mypiston2;
    Plate * myplate;

    cout << "Distanza fissa tra i pistoni di: 350" << endl;
    cout << "Spessore della piastra di: 30" << endl;

    //                       posx  posy  alt1 larg1  alt1  larg1
    mypiston1 = piston_init( 100,  400,  150,  50,   100,   20);
    mypiston2 = piston_init( 500,  400,  150,  50,   100,   20);

    myplate = plate_init(10, 80);

    float angolo = Plate_angle(mypiston1, mypiston2);

    cout << "Angolo: " << angolo << endl;

    return EXIT_SUCCESS;

}
