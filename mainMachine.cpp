#include <iostream>
#include "Livella.h"
#include "guida.h"
#include "machine.h"

using namespace std;

int main() {

    //                                posx1 posx2  posy  alt1 larg1 larg2  altS altD spess lungh
    Machine * livella2 = machine_init( 100,  500,  400,  150,  50,   20,    30,  70,  30,   500);


    string NameFile = "";
    char with_measures;
    cout << "Inserire il nome del file .svg che verrà creato: ";
    cin >> NameFile;
    cout << "Includere le misure nel file .svg ?  Y/n: ";
    cin >> with_measures;

    machine_to_svg(livella2, "../" + NameFile, with_measures);





    /*
    my_destroy_device(livella);
    my_destroy_device(guida);


     delete[] arr;
    */

   

    return 0;

}