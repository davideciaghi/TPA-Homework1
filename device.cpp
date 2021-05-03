#include <iostream>
#include "libraries/guida.h"

using namespace std;

int main() {

    GuidaPrismatica * myguida;

    myguida = guida_init(0, 0, 400, 130, 40, 40);

    guida_to_SVG(myguida, "test", false);

    GuidaPrismatica * g = guida_parse_svg("test", true);
    guida:guida_visualizza_info( g );

    guida_distruggi( g );
    guida_distruggi( myguida );
    return EXIT_SUCCESS;
}

