#include <iostream>
#include "Livella.h"
#include "guida.h"
#include "machine.h"

using namespace std;

int main() {

    //                                  posx1 posx2  posy alt1 larg1 larg2  altS  altD spess  lungh
    //Machine * livellaMac = machine_init( 100,  500,  400,  150,  50,   20,   30,  70,  30,    500);
    Machine * livellaMac = machine_from_console();

    // Stampa informazioni relative alla livella e alla guida
    machine_print_info(livellaMac);

    // Creazione del file svg
    machine_to_svg(livellaMac);
    
    // Distruzione della machine
    machine_destroy(livellaMac);

    return EXIT_SUCCESS;

}