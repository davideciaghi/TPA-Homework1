#include <iostream>
#include "Livella.h"
#include "guida.h"
#include "machine.h"

using namespace std;

int main() {

    //                                  posx1 posx2  posy alt1 larg1 larg2  altS  altD spess  lungh
    Machine * livellaMac = machine_init( 100,  250,  400,  150,  50,   20,   30,  100,  30,    500);

    machine_print_info(livellaMac);

    string NameFile = "";
    char with_measures;
    cout << "Inserire il nome del file .svg che verrà creato: ";
    cin >> NameFile;
    cout << "Includere le misure nel file .svg ?  Y/n: ";
    cin >> with_measures;

    machine_to_svg(livellaMac, "../" + NameFile, with_measures);
    
    machine_destroy(livellaMac);

    return 0;

}