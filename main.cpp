#include <iostream>
#include "Livella.h"

using namespace std;


int main() {
    
    //Livella *  mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);
    Livella * mylivella = livella_from_console();
  
    info_parti(mylivella);

    livella_to_svg(mylivella);

    livella_destroy(mylivella);

    return EXIT_SUCCESS;

}
